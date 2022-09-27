#pragma once

#include "card.h"
#include <time.h> /* This is the library responsible for the time */

#ifndef TERMINAL_H_
#define TERMINAL_H_

typedef enum EN_terminalError_t {
	TERM_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD,
	INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;
// In the enum, what it implies is that the ok == 1,
// wrong_date == 2, and so on in the increments of 1
// Which basically says, that if the code is correct,
// and no problems were found, then return OK,
// which means return 0, which means code was
// executed successfully!
// and then basically when u return anything else than 0
// it means that the code was not executed successfully..


typedef struct ST_terminalData_t {
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
	//ST_cardData_t cardHolderData; // i added this because
	// i needed this in the server module
	// when asking about the isAmountAvailable()
}ST_terminalData_t;
// typedef here gave me analias to work with
// so that everytime i need to create a
// new variable for this struct, i will say
// ST_terminalData_t p1


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData); //DONE
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData); //DONE
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData); //NEEDS REVISION
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData); //DONE
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData); //DONE
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData); //DONE
// here in the function prototypes, the parameters are pointers to structures
// which means i can access any data in the structure to modify its value
// when the return variable of the function is enum
// from what i understand that it will
// return either a 0 or any number.


#endif // !"terminal.h"
