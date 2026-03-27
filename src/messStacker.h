
#ifndef MESS_STACKER
#define MESS_STACKER

//Donne la version de MessStacker
void getMessStackerVersion();

bool sendMessage(uint8_t cmd, char data[],uint8_t size);

//Vérifie si il y a un message dans la file
bool haveMessage();

bool nextMessage();

uint8_t curMessageCmd();

uint8_t curMessageSize();

uint8_t curMessageChecksum();

bool curMessageData(unsigned char buff[],  int lenghtMax);

uint8_t checksumMessage(uint8_t cmd, char data[],uint8_t size);

#endif