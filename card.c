#pragma once
#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	
	int nameInputCounter = 0;
	while (True) {
		printf("Please Enter Your Card Name: ");
		fgets(cardData->cardHolderName, NAME_LIMIT, stdin);
		//printf("\n");
		// Inputting the string into cardholdername
		// fgets() takes the input string including whitespaces
		// unlike the fscan() function, it will take
		// the string untill the first whitespace

		size_t nameLength = strlen(cardData->cardHolderName);
		// strlen() here tells me the length of my name

		if ( (nameLength == NULL) || (nameLength < 20) || (nameLength > 24) ) {
			
			nameInputCounter++;

			if (nameInputCounter > 2) {
				printf("You entered an INVALID card name several times!\n");
				printf("Program will now be terminated.\n\n");
				exit(WRONG_NAME);
			}

			else if (nameInputCounter <= 2) {
				printf("The card name you entered is INVALID, ");
				printf("please enter a valid name again!\n");
				continue;
			}
		}
		else {
			printf("	Proceeding now.\n\n");
			return CARD_OK;
		}
		// if-conditions that satisfies the required constraints asked
	}
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	// I initialized the account number with zeros so that i dont have any garbage
	int PANInputCounter = 0;
	while (True) {
		printf("Please Enter Your Card Number: ");
		scanf_s("%s", cardData->primaryAccountNumber, NUM_LIMIT);
		// fgets(cardData->primaryAccountNumber, NUM_LIMIT, stdin);
		//printf("\n");
		// Inputing into the string

		size_t numLength = strlen(cardData->primaryAccountNumber);
		// strlen() here tells me the length of my number

		if ( (numLength == NULL) || (numLength < 16) || (numLength > 19) ) {
			
			PANInputCounter++;

			if (PANInputCounter > 2) {
				printf("You entered an INVALID PAN several times!\n");
				printf("Program will now be terminated.\n\n");
				exit(WRONG_PAN);
			}

			else if (PANInputCounter <= 2) {
				printf("The PAN you entered is INVALID, ");
				printf("please enter a valid PAN again!\n");
				continue;
			}
		}
		else {
			printf("	Proceeding now.\n\n");
			return CARD_OK;
		}
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	
	int expDateInputCounter = 0;
	while (True) {
		printf("Please Enter Your Card Expiration Date in 'MM/YY' Format: ");
		scanf_s("%s", cardData->cardExpirationDate, DATE_LIMIT);
		//fgets(cardData->cardExpirationDate, DATE_LIMIT, stdin);
		//printf("\n");
		// Inputing into the string the date in the format of MM/YY

		size_t dateLength = strlen(cardData->cardExpirationDate);
		// strlen() here tells me the length of my expiration string

		if ( (dateLength == NULL) || (dateLength < 5) || (dateLength > 5) ) {
			
			expDateInputCounter++;

			if (expDateInputCounter > 2) {
				printf("You entered an INVALID Expiry Date Format several times!\n");
				printf("Program will now be terminated.\n\n");
				exit(WRONG_EXP_DATE);
			}
			
			else if (expDateInputCounter <= 2) {
				printf("The Expiry Date Format you entered is INVALID, ");
				printf("please enter the valid format again!\n");
				continue;
			}
		}
		else if (cardData->cardExpirationDate[2] != '/') {
			
			expDateInputCounter++;
			
			if (expDateInputCounter > 2) {
				printf("You entered an INVALID Expiry Date Format several times!\n");
				printf("Program will now be terminated.\n\n");
				exit(WRONG_EXP_DATE);
			}

			else if (expDateInputCounter <= 2) {
				printf("The Expiry Date Format you entered is INVALID, ");
				printf("please enter the valid format again!\n");
				continue;
			}
		}
		else {
			printf("	Proceeding now.\n\n");
			return CARD_OK;
		}
	}
}