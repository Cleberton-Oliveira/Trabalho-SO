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
char nome[6][10] = {"musica 1","musica 2","musica 3", "musica 4","musica 5","musica 6"};


#define NUM_THREADS 6
int res;
pthread_t produtor[NUM_THREADS];
void *thread_result;
int lots_of_threads;



struct musica {
	long mesg_type;
    char nomeMusica[50];
    char autorMusica[50];
    char generoMusica[50];
    char duracao[50];
} new_musica;


key_t key;
int msgid;



void *criaMusica(void *arg) {
  while(1){

    // espera de 0 a 4 segundos
	sleep(rand() % 4);

	//instacia de Musica
	struct musica new_musical;

	new_musical.mesg_type = 1;
	sprintf(new_musical.nomeMusica, "%s", nome[rand() % 6]);

	sprintf(new_musical.autorMusica, "%s", autor[rand() % 6]);

	sprintf(new_musical.generoMusica, "%s", tipo_musica[rand() % 6]);
    sprintf(new_musical.duracao, "%s", tempo[rand() % 6]);



    printf("==========================================================\n");
	printf("CRIANDO NOVA MUSICA:\n");
	printf("................................\n");
	printf("Musica: %s\n"
    "Autor: %s\n"
    "Genero: %s\n"
    "Duração: %s\n",
    new_musical.nomeMusica,
    new_musical.autorMusica,
    new_musical.generoMusica,
    new_musical.duracao
    );


    //send the message
    msgsnd(msgid, &new_musical, sizeof(new_musical)-sizeof(long), 0);

    // display the message
    printf("Criando nova Musica : %s \n", new_musical.nomeMusica);

	};
};


int main(){


    // ftok gera uma key unica. Ambos os processos usam o mesmo valor de key.
    key = ftok("progfile", 65);


    // msgid retorna o identificador
    msgid = msgget(key, IPC_CREAT | 0666);

   for(lots_of_threads = 0; lots_of_threads < NUM_THREADS; lots_of_threads++) {
        res = pthread_create(&(produtor[lots_of_threads]), NULL, criaMusica, (void *)&lots_of_threads);


        if (res != 0) {
            perror("Criacao de Thread falhou");
            exit(EXIT_FAILURE);
        };

        sleep(1);
 	 }

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
