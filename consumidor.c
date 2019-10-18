// Trabalo SO Consumidor de Musica 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>

#define NUM_REPETICOES  30

pthread_t reprodutor; 
int musica = 0;

void *reproduzMusica(){  
  for (long i = 0; i < NUM_REPETICOES; i++){
    // espera 5 segundos 
  	unsigned sleep(500);
	//traca o sistema com semaforo 

	// reproduz a musica

	// imprime a musica que preoduziu
	printf("Está escutando a musica: %s\n")
	printf("Nome da Musica: %s\n", nomeMusica);
	printf("Autor da Musica: %s\n", autorMusica);
	printf("Genero da Musuca %s\n", generoMusica);
	printf("Tempo de duração: %s\n", duracao);
	// musica++
	musica++;
	// destranca o sistema 
  }
  printf("Já reproduziu a musica\n");

}


int main(){ 
   pthread_create(&reprodutor, NULL, reproduzMusica, NULL) ; 
   pthread_join(reprodutor,NULL);  
   printf("Fim do programa"); 
   return 0;
}