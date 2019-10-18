// Trabalo SO Produtor de Musica 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>


#include <sys/shm.h>



#define NUM_REPETICOES  10
pthread_t prod0, prod1, prod2;  
int novaMusica = 0;

struct musica { 
    char *nomeMusica; 
    char *autorMusica;   
    char *generoMusica;
    char *duracao; 
};

void *criaMusica(void* thread ){  
   
	char *valor = (char *)thread;

  for (long i = 0; i < NUM_REPETICOES; i++){
  	
    // espera 3 segundos 
	sleep(3);
	//traca o sistema com semaforo 

	// cria nova musica
	

		// novaMusica++;
		// char caractere = novaMusica+'0'; 
    
    if(valor == "Rock") {
	    	struct musica musicaRock;
	    	musicaRock.nomeMusica = "Musica Rock \n"; 
	        musicaRock.autorMusica = "Pink Floyd\n";
	        musicaRock.generoMusica = "Rock\n";
	        musicaRock.duracao = "11:26\n";
	   
	   }else if(valor == "Sertanejo"){
	  
	    	struct musica musicaSertanejo;
	    	musicaSertanejo.nomeMusica = "Musica Sertanejo \n"; 
	        musicaSertanejo.autorMusica = "Jorge e Matheus\n";
	        musicaSertanejo.generoMusica = "Sertanejo\n";
	        musicaSertanejo.duracao = "4:42\n";
	      
	    }else{
	
	    	struct musica musicaFunk;
	        musicaFunk.nomeMusica = "Musica Funk \n"; 
	        musicaFunk.autorMusica = "Mc Kevinho\n";
	        musicaFunk.generoMusica = "Funk\n";
	        musicaFunk.duracao = "3:02\n";
		}      
    
    }
	// passar musica por pipe;

	// destranca o sistema
 	printf("Criado uma nova musica\n");
}


int main(){ 

   void *shmat(int shm_id, const void *shm_addr, int shmflg);


   pthread_create(&prod0, NULL, criaMusica,  (void *)"Rock") ; 
   pthread_create(&prod1, NULL, criaMusica,  (void *)"Sertanejo") ; 
   pthread_create(&prod2, NULL, criaMusica,  (void *)"Funk") ; 
   pthread_join(prod0,NULL);  
   pthread_join(prod1,NULL);
   pthread_join(prod2,NULL); 
   printf("Fim do programa"); 
   return 0;
}