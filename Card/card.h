#pragma once


#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#ifndef CARD_H_
#define CARD_H_

#define NAME_LIMIT 25
#define DATE_LIMIT 6
#define NUM_LIMIT 20

typedef enum EN_cardError_t {
	CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
// In the enum, what it implies is that the ok == 0,
// wrong_name == 1, and so on in the increments of 1
// Which basically says, that if the code is correct,
// and no problems were found, then return OK,
// which means return 0, which means code was
// executed successfully!
// and then basically when u return anything else than 0
// it means that the code was not executed successfully..


typedef struct ST_cardData_t {
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;
// typedef here gave me an alias to work with
// so that everytime i need to create a
// new variable for this struct, i will say
// typedef struct ST_cardData_t


EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
// here in the function prototypes, the parameters are pointers to structures
// which means i can access any data in the structure to modify its value
// when the return variable of the function is enum
// from what i understand that it will
// return either a 0 or any number.


#endif // !CARD_H