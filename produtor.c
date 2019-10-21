#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 


int novaMusica = 0;
char tipo_musica[6][10] = {"Rock", "Pagode", "Sertanejo","Forro", "Funk", "MPB"};
char autor[6][20] = {"Vitor e Leo", "The Beatles", "Arrastapé","Mc Kevinho", "Caetano Veloso", "Revelação"};
char tempo[6][10] = {"3:14", "4:12", "5:43","3:56", "4:31", "2:59"};


#define NUM_THREADS 6
int res;
pthread_t produtor[NUM_THREADS]; 
void *thread_result;
int lots_of_threads;

void *criaMusica(void *arg);


struct musica { 
	long mesg_type; 
    char *nomeMusica; 
    char *autorMusica;   
    char *generoMusica;
    char *duracao; 
}new_musica;



int main(){ 




	key_t key; 
 	int msgid;
 	key = ftok("progfile", 65); 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    new_musica.mesg_type = 1; 
    printf("Write Data : "); 
    	gets(new_musica.nomeMusica); 
  
    // msgsnd to send message 
    msgsnd(msgid, &new_musica, sizeof(new_musica), 0); 
  
    // display the message 
    printf("Data send is : %s \n", new_musica.nomeMusica); 
 


   for(lots_of_threads = 0; lots_of_threads < NUM_THREADS; lots_of_threads++) {
        res = pthread_create(&(produtor[lots_of_threads]), NULL, criaMusica, (void *)&lots_of_threads);
        if (res != 0) {
            perror("Criacao de Thread falhou");
            exit(EXIT_FAILURE);
        };
        sleep(1);


    printf("Esperando por thread finalizar...\n");
    for(lots_of_threads = NUM_THREADS - 1; lots_of_threads >= 0; lots_of_threads--) {
        res = pthread_join(produtor[lots_of_threads], &thread_result);
        if (res == 0) {
            printf("Pegou uma thread\n");
        }else {
           perror("Thread falhou no join");
        };
    };



    printf("Todas terminaram\n");
    exit(EXIT_SUCCESS);

   printf("Fim do programa"); 
   return 0;
	};
}


void *criaMusica(void *arg){  
  while(1){
    // espera 0 à 4 segundos 
	sleep(rand()%4);
	//cria Musica
	struct musica new_musica;
	char nome[30];
	sprintf(nome, "Musica %d", novaMusica);
	novaMusica++; 
	new_musica.nomeMusica = nome; 
    new_musica.autorMusica = autor[rand() % 6];
    new_musica.generoMusica = tipo_musica[rand() % 6];
    new_musica.duracao = tempo[rand() % 6];
	

printf("Musica: %s\n"
    "Autor: %s\n"
    "Genero: %s\n"
    "Duração: %s\n--------------------\n",    
    new_musica.nomeMusica,
    new_musica.autorMusica, 
    new_musica.generoMusica,
    new_musica.duracao

    );
    // envia musica por mensagem 
 	printf("Criado uma nova musica\n");
};
};


