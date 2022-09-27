#pragma once
#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Please enter card name: ");
	fgets(cardData->cardHolderName, NAME_LIMIT, stdin);
	printf("\n");
	// Inputting the string into cardholdername
	// fgets() takes the input string including whitespaces
	// unlike the fscan() function, it will take
	// the string untill the first whitespace

	size_t nameLength = strlen(cardData->cardHolderName);
	// strlen() here tells me the length of my name

	if (nameLength == NULL || nameLength < 20 || nameLength > 24) {
		printf("\n*** The card name you entered is invalid, ");
		printf("please check the typed name length & try again later!\n");
		return WRONG_NAME;
	}
	else {
		printf("\n*** Card name you entered is: %s\n", cardData->cardHolderName);
		printf("Proceeding now.\n");
		return CARD_OK;
	}
	// if-conditions that satisfies the required constraints asked
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	
	// I initialized the account number with zeros so that i dont have any garbage

	printf("\n\nPlease enter card number: \n");
	fgets(cardData->primaryAccountNumber, NUM_LIMIT, stdin);
	// Inputing into the string

	size_t numLength = strlen(cardData->primaryAccountNumber);
	// strlen() here tells me the length of my number

	if (numLength == NULL || numLength < 16 || numLength > 19) {
		printf("\n*** The account number you entered is invalid, ");
		printf("please check the typed PAN length & try again!\n");
		return WRONG_PAN;
	}
	else {
		printf("\n*** PAN you entered is: %s\n", cardData->primaryAccountNumber);
		printf("Proceeding now.\n");
		return CARD_OK;
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("\n\nPlease enter card expiration date in the format 'MM/YY': ");
	fgets(cardData->cardExpirationDate, DATE_LIMIT, stdin);
	printf("\n");
	// Inputing into the string the date in the format of MM/YY

	size_t dateLength = strlen(cardData->cardExpirationDate);
	// strlen() here tells me the length of my expiration string
	

	if (dateLength == NULL || dateLength < 5 || dateLength > 5) {
		printf("\n *** The Expiration Date you entered is invalid, ");
		printf("please check the typed length & try again!\n");
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[2] != '/') {
		printf("\n *** The Expiration Date you entered is invalid, ");
		printf("please check the typed format & try again!\n");
		return WRONG_EXP_DATE;
	}
	else {
		printf("\n*** Expiration Date you entered is: %s\n", cardData->cardExpirationDate);
		printf("Proceeding now.\n");
		return CARD_OK;
		// printf("Your string length is %d\n", dateLength);
	}
}