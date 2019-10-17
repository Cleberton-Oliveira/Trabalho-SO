// Trabalo SO Produtor de Musica 

#include <pthread.h> 
#include <stdio.h> 

#define NUM_REPETICOES  1000

pthread_t prod0, prod1, prod2;  
 
void *criaMusica(){  
  for (long i = 0; i < NUM_REPETICOES; i++){
    
	//traca o sistema com semaforo 
	// espera 5 segundos 
	// cria nova musica 
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