#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

uint8_t checksumMessage(uint8_t cmd, char data[],uint8_t size){
    //calcul un checksum sur les valeurs cmd et data
    uint8_t sum = cmd; 
    for(int i=0; i<size; i++){
        sum += (uint8_t)data[i];
    }
    return sum;
}

bool sendMessage(uint8_t cmd, char data[],uint8_t size){
    //Envoi un message dans la file 
    if(messCount>=SIZE_STACK) return false;
    int pos = lastPos+1;
    stackMess[pos].cmd = cmd;
    memcpy(stackMess[pos].data, data, size);
    stackMess[pos].size = size;
    stackMess[pos].checksum = checksumMessage(cmd, data, size);
    messCount += 1;
    lastPos += 1;
    if(lastPos==SIZE_STACK) lastPos=0;
    return true;
}

uint8_t curMessageCmd(){
    //Renvoi le cmd du message courant
    if(!haveMessage()) return 0;
    uint8_t cmd = stackMess[curPos].cmd;
    return cmd;
}
uint8_t curMessageSize(){
    //Renvoi la size du message courant
    if(!haveMessage()) return 0;
    uint8_t size = stackMess[curPos].size;
    return size;
}
uint8_t curMessageChecksum(){
    //Renvoi le checksum du message courant
    if(!haveMessage()) return 0;
    uint8_t checksum = stackMess[curPos].checksum;
    return checksum;
}

bool curMessageData(unsigned char buff[],  int lenghtMax){
    //Remplis le tableau buff avec les valeurs du tableau data du message courant
    if(!haveMessage() || lenghtMax<curMessageSize())return false;
    for(int i=0; i<curMessageSize(); i++){
        buff[i] = stackMess[curPos].data[i]; //copie case par case le tableau
    }
    return true;
}


bool nextMessage(){
    //passe au message suivant dans la file
    if(!haveMessage()) return false;
    curPos += 1;
    if(curPos == SIZE_STACK) curPos = 0;
    messCount -= 1; //le message précédent est jeté
    return true;
}