#include <stdio.h>
#include <stdint.h>
#include "messStacker.h"

//définition des constantes
#define MESS_STACKER_VERSION "v0.0.01"
#define SIZE_MAX_DATA 57
#define SIZE_STACK 30

void getMessStackerVersion(){
    //Donne la version de MessStacker
    printf("%s \n", MESS_STACKER_VERSION);
};

//Structure message
typedef struct message{
    uint8_t cmd;
    char data[SIZE_MAX_DATA];
    uint8_t size;
    uint8_t checksum;
}Message;

//déclaration des variables internes
Message stackMess[SIZE_STACK];
int lastPos = -1;
int curPos = 0;
int messCount = 0;

bool haveMessage(){
    //Vérifie si il y a un message dans la file
    if(lastPos==-1) return false;
    else return true;
}