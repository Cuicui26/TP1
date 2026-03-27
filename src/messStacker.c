#include <stdio.h>
#include <stdint.h>
#include "messStacker.h"

#define MESS_STACKER_VERSION "v0.0.01"
#define SIZE_MAX_DATA 57

void getMessStackerVersion(){
    //Donne la version de MessStacker
    printf("%s \n", MESS_STACKER_VERSION);
};

struct message{
    uint8_t cmd;
    char data[SIZE_MAX_DATA];
    uint8_t size;
    uint8_t checksum;
}Message;