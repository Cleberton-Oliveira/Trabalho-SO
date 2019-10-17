// Trabalo SO Consumidor de Musica 
#include <stdio.h> 

#define NUM_REPETICOES  30

pthread_t reprodutor; 
int musica;

void *reproduzMusica(){  
  for (long i = 0; i < NUM_REPETICOES; i++){
    // espera 5 segundos 
	//traca o sistema com semaforo 
	// reproduz a musica
	// imprime a musica que preoduziu 
	// musica++
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