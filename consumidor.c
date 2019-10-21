// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct musica { 
    long mesg_type; 
    char *nomeMusica; 
    char *autorMusica;   
    char *generoMusica;
    char *duracao; 
}new_musica;
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
  
    // msgrcv to receive message 
    msgrcv(msgid, &new_musica, sizeof(new_musica), 1, 0); 
  
    // display the message 
    printf("Data Received is : %s \n",  
                    new_musica.nomeMusica); 
  
    // to destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 
  
    return 0; 
} 