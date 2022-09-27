#pragma once
#include "server.h"


/********** Implement server-side accounts' database **********/
/**************************************************************/

ST_accountsDB_t accountDatabase[MAX_ACCOUNTS] = {
	{ 4000, "4556754566818772431"},
	{ 8650, "4716405472349537" },
	{ 9800, "4003600000000014" },
	{ 560, "5139863821116492" },
	{ 440, "2720996892660246" },
	{ 15320, "5575538775229662" },
	{ 90, "344220880503056" },
	{ 6000, "342634228693365" },
	{ 3200, "345086435097558" }
};

/**************************************************************/
/**************************************************************/



/********** Implement server - side transactions' database **********/
/********************************************************************/

ST_transaction_t transactionDatabase[MAX_ACCOUNTS] = { {{0}}, {0}, 0, 0};


EN_transState_t recieveTransactionData(ST_transaction_t* transData, ST_cardData_t* cardData) {


}


EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	printf("Checking the validity of the account number whether it is stored on the database...\n\n");
	printf("PAN is: %s\n", cardData->primaryAccountNumber);

	int result = 1;
	for (int i = 0; i < 10; i++) {
		result = strcmp(cardData->primaryAccountNumber, accountDatabase[i].primaryAccountNumber);
		if (result = 0) {
			printf("Card is valid and is verified!\n");
			return SERVER_OK;
		}
	}
	if (result != 0) {
		printf("Card PAN was not found in the database!\n");
		return ACCOUNT_NOT_FOUND;
	}
}


EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	printf("Checking if there is enough balance in the account...\n\n");
	printf("Amount entered is: %f\n", termData->transAmount);
	printf("Retrieving account balance...\n\n");



}


EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	// lets think about it, if i want to save the transaction
	// i need to know the cardData of the current transaction occuring
	// so i will retrieve the PAN now
	// then i must retrieve the transaction date
	// then i must increment the transactionseq number by one
	// then i will return the transtate of whatever happened to the transaction
	
	printf("Saving the transaction data in the account...\n\n");
	printf("This transaction belongs to %s account number.\n",
		transactionDatabase->cardHolderData.primaryAccountNumber);
	printf("This transaction amount is: %f\n",
		transactionDatabase->terminalData.transAmount);
	printf("This transaction occurred on: %s\n",
		transactionDatabase->terminalData.transactionDate);

	// we need to save the stuff inside the
	// ST_transaction_t transactionDatabase[MAX_ACCOUNTS];
	
	transactionDatabase->transactionSequenceNumber = 1;

	printf("This transaction serial number is: %l\n",
		transactionDatabase->transactionSequenceNumber);







}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData) {


}
























// I will go for the optional task, which is
// create an account's database and save it
// into a txt file.
// I will use the fwrite() function

/* open the file for writing the struct inside it.
FILE* outfile;
outfile = fopen("Accounts_DB.txt", "w");
if (outfile == NULL) {
	fprintf(stderr, "\nError accessing file.\n");
	exit(1);
}
for (int i = 0; i < 10; i++) {
	// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	fwrite(&accountDatabase[i], sizeof(struct ST_transaction_t), 1, outfile);
}
if (fwrite != 0) {
	printf("Struct contents were saved to the file successfully!\n");
}
else {
	printf("There was an unexpected error that occurred while writing to the file!\n");
}
fclose(outfile);
*/
/*
// accountDatabase[0] = (ST_accountsDB_t) { .balance = 4000, .primaryAccountNumber = "4556754566818772431" };
// accountDatabase[1] = (ST_accountsDB_t) { 8650, "4716405472349537" };
// accountDatabase[2] = { 9800, "4003600000000014" };
accountDatabase[3] = { 560, "5139863821116492" };
accountDatabase[4] = { 440, "2720996892660246" };
accountDatabase[5] = { 15320, "5575538775229662" };
accountDatabase[6] = { 90, "344220880503056" };
accountDatabase[7] = { 6000, "342634228693365" };
accountDatabase[8] = { 3200, "345086435097558" };
*/




// i want to compare the inputted PAN with the all of
// the PANs in the database to see if it exists or not

// so what i have in mind is that i need to convert the string to int
// and convert all PANs in the database into int and then
// compare them all with the inputted PAN

// or another idea is just to compare the inputted PAN string
// with each PAN in the database.

// i guess the latter method takes less processing time.
// i will use the strcmp() function,
// if the strings are identical, it will output '0'

/*
FILE* infile;

// Open person.dat for reading
infile = fopen("Accounts_DB.txt", "r");
if (infile == NULL) {
	fprintf(stderr, "\nError accessing file.\n");
	exit(1);
}
// read file contents till end of file

// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
fread(&accountDatabase[i], sizeof(struct ST_transaction_t), 1, outfile);
// close file
fclose(infile);
*/



/////////////////////////////////////////////////////////////////////////////////////////

/* open the file for writing the struct inside it.
FILE* outfile;
outfile = fopen("Transactions_DB.txt", "w");
if (outfile == NULL) {
	fprintf(stderr, "\nError accessing file.\n");
	exit(1);
}
for (int i = 0; i < 10; i++) {
	// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	fwrite(&accountDatabase[i], sizeof(struct ST_transaction_t), 1, outfile);
}
if (fwrite != 0) {
	printf("Struct contents were saved to the file successfully!\n");
}
else {
	printf("There was an unexpected error that occurred while writing to the file!\n");
}

fclose(outfile);
*/

//ST_transaction_t transactionDatabase[255];

//transactionDatabase[0]. = { cardData, terminalData, transState, transactionSequenceNumber }
//accountDatabase[0].cardHolderData.primaryAccountNumber

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// C:\Users\Administrator\Desktop\ITIDA Embedded System Scholarship\Payment_Project