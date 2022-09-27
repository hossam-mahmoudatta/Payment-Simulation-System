#pragma once
#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("\n\nRetrieving system's current date & transaction date...\n");
	// char currentDate[11]; // Stores the date in the format of DD/MM/YYYY : 10 chars
	// and a null character

	time_t timeNow;
	// this is a ready struct that is specialized in time operations

	timeNow = time(NULL);
	/* Retrieve the current time */

	struct tm* t = localtime(&timeNow);

	strftime(termData->transactionDate, sizeof(termData->transactionDate), "%d/%m/%Y", t);
	/* Saves the current DD/MM/YYYY into the currentDate string */
	// I went here for the optional task, which is to take the current date from
	// the computer, not entered manually by the user.
	//printf("Current Date: %s\n", termData->transactionDate);

	size_t dateLength = strlen(termData->transactionDate);

	if (dateLength == NULL || dateLength < 10) {
		printf("\n*** The current date you entered is invalid, ");
		printf("please check the length & try again!\n");
		return WRONG_DATE;
	}
	else if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/') {
		printf("\n*** The Expiration Date you entered is invalid, ");
		printf("please check the format & try again!\n");
		return WRONG_DATE;
	}
	else {
		printf("\nSystem's current date is: %s\n", termData->transactionDate);
		printf("Proceeding now.\n");
		return TERM_OK;
	}
	/* Output a message with the current date to the user */
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	printf("\n\nChecking if the card is expired...\n");
	// here i will use the data from the expiration date from the card module
	// i will take the mm/yy from the transaction date i have so that i can
	// compare it with the expiry date

	char* currentMonth[2];
	char* currentYear[2];
	// i want to create 2 new strings that will each hold the month MM & year YY

	strncpy(currentMonth, &termData.transactionDate[3], 2);
	// transactiondate + 3 bcz after the 3rd char is the MM
	strncpy(currentYear, &termData.transactionDate[8], 2);
	// transactiondate + 8 bcz after the 8th char is the YY

	int currentMonth_Integer = atoi(currentMonth);
	int currentYear_Integer = atoi(currentYear);
	// i converted the numbers in the string to integers so that i can
	// later compare those numbers in any other operations req.

	char* expMonth[2];
	char* expYear[2];
	// i want to create 2 new strings that will each hold the month MM & year YY

	strncpy(expMonth, &cardData.cardExpirationDate[0], 2);
	strncpy(expYear, &cardData.cardExpirationDate[3], 2);
	// here i copied the parts i needed from the cardExpirationDate string

	int expMonth_Integer = atoi(expMonth);
	int expYear_Integer = atoi(expYear);
	// i converted the numbers in the string to integers so that i can
	// later compare those numbers in any other operations req.

	if (expYear_Integer < currentYear_Integer) {
		// I'm comparing the curent year with the card's expiration year
		printf("\n*** Your card is expired!\n");
		printf("*** Transaction can't proceed, please enter a valid card.\n");
		printf("*** Program will now exit.\n");
		return EXPIRED_CARD;
	}
	else if (expYear_Integer == currentYear_Integer) {
		if (expMonth_Integer < currentMonth_Integer) {
			// I'm comparing the curent year with the card's expiration year
			// so in this case the years are the same, but the months can be different
			// so I'm checkin this case.
			printf("\n*** Your card is expired!\n");
			printf("*** Transaction can't proceed, please enter a valid card.\n");
			return EXPIRED_CARD;
		}
		else {
			printf("\n*** Card is valid!\n");
			printf("*** Transaction can now proceed!\n");
			return TERM_OK;
		}
	}
	else {
		printf("\n*** Card is valid!\n");
		printf("*** Transaction can now proceed!\n");
		return TERM_OK;
	}
}

/*
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
	printf("\nChecking the validity of the account number whether it is fake or fraud...\n\n");
	// this is the optional req, using the luhn's algorithm
	// i have to check if the card is fraud or not
	// since the argument of this function is the struct of the cardData
	// i can use the PAN which i inputted in the card module


	// Now i will implement the Luhn's algorithm
	// that if the procedure didnt yield the result of '0'
	// then this card is invalid
	int stepone = 0;
	int m = 0;
	int n = 0;
	size_t PAN_Length = 0;
	int sum = 0;
	int count = 0;
	int digit = 0;
	char sumstr[2];
	int zero;
	char revstr[20] = { '0' };
	/*
		Luhn's algorithm i used is:

		1. Multiply every other digit by 2, starting with the number’s
			second-to-last digit, and then add those products’ digits together.
		2. Add the sum to the sum of the digits that weren’t multiplied by 2.
		3. If the total’s last digit is 0 (or, put more formally,
			if the total modulos 10 is congruent to 0), the number is valid!

		***That’s kind of confusing, so let’s try an example with a Visa Card: 400 360 000 000 0014.***

			4003600000000014

		1. Okay, let’s multiply each of the other digit,
			starting with the number’s second-to-last digit by 2:

			1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

			That gives us:

			2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

			Now let’s add those products’ digits (i.e., not the products themselves) together:

			2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

		2. Now let’s add that sum (13) to the sum of the digits
			that weren’t multiplied by 2 (starting from the end):

			13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

		3. Yup, the last digit in that sum (20) is a 0, so the Visa card is legit!
	

	PAN_Length = strlen(cardData->primaryAccountNumber);
	// This piece of code is used to store the 
	// primaryAccountNumber into a new reversed string
	for (int i = PAN_Length; i >= 0; i--) {
		revstr[i] = cardData->primaryAccountNumber[PAN_Length - i];
		// this code will save the string in reverse order
		// and will start by the second to last digit
		// i think i could've done this operation 1st step
		// without the reversed string, nut lets stick for this for now
	}

	// this block of code is the process of selecting
	// the 2nd digit to last and multiplying it by 2
	// and then adding them with each other
	for (int k = 0; k <= PAN_Length - 1; k = k + 2) {
		printf("%c  ", revstr[k + 2]);
		stepone = revstr[k + 2];// -'0';
		printf("String into Integer: %d ", stepone);
		stepone = stepone * 2;
		printf("Multiplied by 2: %d ", stepone);

		while (stepone > 0) {
			m = stepone % 10;
			sum = sum + m;
			stepone = stepone / 10;
			// in this loop, this will check the number if it is
			// 2-digit, so we'll seperate them into 2 digits
			// then add them with the other numbers
		}
		// printf("Sum is: %d\n", sum);
	}

	// this piece of code adds the sum that we
	// got above with the rest of the digits that we have
	// in the beginning of the Luhn's Algorithm procedure
	for (int u = 0; u <= PAN_Length - 1; u = u + 2) {
		sum = sum + (revstr[u + 1] - '0');
		//printf("Sum is= %d\n", sum);
	}
	//here i'm printing the sum just to check it.
	//printf("Sum is: %d\n", sum);

	sprintf(sumstr, "%d", sum);
	//printf("Inside Sum String: %c\n", sumstr[1]);
	zero = sumstr[1] - '0';
	//printf("Zero: %d\n", zero);

	if (zero == 0) {
		printf("Account Number is Luhn Verified!\n");
		return TERM_OK;
	}
	else {
		printf("Card didn't pass the Luhn verification!\n");
		return INVALID_CARD;
	}
}
*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("\n\nEnter Payment Amount: ");
	scanf_s("%f", &termData->transAmount);
	printf(" $\n");

	if (termData->transAmount <= 0) {
		printf("\nTransaction amount is invalid.\n");
		printf("Transaction can't proceed.\n");
		return INVALID_AMOUNT;
	}
	else {
		printf("\nPayment Amount is: %f\n", termData->transAmount);
		printf("Proceeding now.\n");
		return TERM_OK;
	}
}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	printf("\n\nEnter the maximum allowable payment amount: ");
	scanf_s("%f", &termData->maxTransAmount);
	printf(" $\n");

	if (termData->maxTransAmount <= 0) {
		printf("\nThe maximum transaction amount set is invalid.\n");
		return INVALID_MAX_AMOUNT;
	}
	else {
		printf("Maximum Payment Amount is %f\n", termData->maxTransAmount);
		printf("Proceeding now.\n");
		return TERM_OK;
	}
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	printf("\n\nChecking the validity of the payment...\n");
	if (termData->maxTransAmount < termData->transAmount) {
		printf("\nYour payment exceeded the maximum allowable amount per transaction.\n");
		return EXCEED_MAX_AMOUNT;
	}
	else {
		printf("\nPayment is approved!\n");
		printf("Proceeding now.\n");
		return TERM_OK;
	}
}

