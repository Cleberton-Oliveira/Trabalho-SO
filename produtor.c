// Trabalo SO Produtor de Musica 
#include <pthread.h> 
#include <stdio.h> 

#define NUM_REPETICOES  10
pthread_t prod0, prod1, prod2;  
int novaMusica = 0;
pid_t pid;

typedef struct { 
    char nomeMusica[30]; 
    char autorMusica[30];   
    char generoMusica[30];
    char duracao[30]; 
} Musica;

Musica SetMusica(char nomeMusica, char autorMusica, char generoMusica, char duracao) 
{  
    char musica = pessoa + novaMusica;
    Musica musica;
    musica.nomeMusica = nomeMusica;  
    musica.autorMusica = autorMusica;  
    musica.generoMusica = generoMusica;  
    musica.duracao = duracao;  

    novaMusica++;
    return musica; // retorna a struct contendo os dados passados por parâmetro
}


void *criaMusica(){  
  for (long i = 0; i < NUM_REPETICOES; i++){
  
    // espera 3 segundos 
	sleep(3);
	//traca o sistema com semaforo 
	
	// cria nova musica
	novaMusica++;
	char caractere = novaMusica+'0'; 
    
    pid = fork();
    switch(pid) {
	    case -1:
	    	nomeMusica = "Musica\n", caractere; 
	        autorMusica = "Pink Floyd\n";
	        generoMusica = "Rock\n";
	        duracao = "11:26";
	        break;
	    case 0:
	    	nomeMusica = "Musica\n", caractere; 
	        autorMusica = "Jorge e Matheus\n";
	        generoMusica = "Sertanejo\n";
	        duracao = "4:42";
	        break;
	    default:
	        nomeMusica = "Musica\n", caractere; 
	        autorMusica = "Mc Kevinho\n";
	        generoMusica = "Funk\n";
	        duracao = "3:02"
	        break;
    }

  	SetMusica(nomeMusica, autorMusica, generoMusica, duracao);
	// add musica ao array;


	// destranca o sistema


  }
 	printf("Criado uma nova musica\n");
}


int main(){ 
   pthread_create(&tid0, NULL, criaMusica, NULL) ; 
   pthread_create(&tid1, NULL, criaMusica, NULL) ; 
   pthread_create(&tid2, NULL, criaMusica, NULL) ; 
   pthread_join(tid0,NULL);  
   pthread_join(tid1,NULL);
   pthread_join(tid2,NULL)  
   printf("Fim do programa"); 
   return 0;
}