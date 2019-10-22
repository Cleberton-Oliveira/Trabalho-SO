 #include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>

// structure a ser compartilhada
struct musica {
    long mesg_type;
    char nomeMusica[50];
    char autorMusica[50];
    char generoMusica[50];
    char duracao[50];
}new_musica;


int main(int argc, char * argv[]) {

    key_t key;
    int msgid;

    // ftok gera identificador unico
    key = ftok("progfile", 65);


    msgid = msgget(key, IPC_CREAT | 0666);

    // msgrcv to receive message
     printf("%ld", sizeof( new_musica)-sizeof(long));
     msgrcv(msgid, &new_musica, (sizeof( new_musica)-sizeof(long)), 1, 0);

    while( msgrcv(msgid, &new_musica, (sizeof( new_musica)-sizeof(long)), 1, 0) != -1){


        printf("Musica: %s\n"
        "Autor: %s\n"
        "Genero: %s\n"
        "Duração: %s\n--------------------\n",
        new_musica.nomeMusica,
        new_musica.autorMusica,
        new_musica.generoMusica,
        new_musica.duracao

        );

    // to destroy the message queue
    //msgctl(msgid, IPC_RMID, NULL);
    }

    printf("saiu");
    return 0;
}
