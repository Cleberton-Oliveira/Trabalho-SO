// Trabalo SO Consumidor de Musica 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>
#include <sys/sem.h>

#define NUM_REPETICOES  30

pthread_t reprodutor; 
int musica = 0;


void *reproduzMusica(){  
  for (long i = 0; i < NUM_REPETICOES; i++){
    // espera 3 segundos 
  	sleep(3);
	//traca o sistema com semaforo 

	//receber musica por pipe

	// imprime a musica que preoduziu
	printf("Está escutando a musica: %s\n")
	printf("Nome da Musica: %s\n", nomeMusica);
	printf("Autor da Musica: %s\n", autorMusica);
	printf("Genero da Musuca %s\n", generoMusica);
	printf("Tempo de duração: %s\n", duracao);
	
	// proxima musica
	musica++;
	// destranca o sistema 

  }
  printf("Fim da musica\n");

}


int main(){ 

	int shmdt(const void *shm_addr);


   pthread_create(&reprodutor, NULL, reproduzMusica, NULL)v; 
   pthread_join(reprodutor,NULL);  
   printf("Fim do programa"); 
   return 0;
}; 