#pragma once
#include "server.h"

/********** Implement server-side accounts' database **********/
/**************************************************************/

ST_accountsDB_t extractedDatabase[SAMPLE_TEST];
ST_accountsDB_t* tempAccounts = NULL;
ST_transaction_t transactionDatabase[MAX_ACCOUNTS] = {0};
EN_transState_t transactionVerifer = NULL;


ST_accountsDB_t accountDatabase[SAMPLE_TEST] = {
	{ 560, "4556754566818772431", RUNNING},
	{ 8650, "4716405472349537", RUNNING},
	{ 9800, "4003600000000014", RUNNING},
	{ 4000, "5139863821116492", BLOCKED},
	{ 440, "2720996892660246", RUNNING},
	{ 15320, "5575538775229662", BLOCKED},
	{ 90, "344220880503056", RUNNING},
	{ 6000, "342634228693365", BLOCKED},
	{ 3200, "345086435097558", RUNNING},
	{ 7400, "345000005097558", RUNNING}
};


const char* FORMAT_OUT_ACCOUNTS = "{\n\tBalance: %f, State: %i, PAN: %s\n}\n";
const char* FORMAT_IN_ACCOUNTS  = "{\n\tBalance: %f, State: %i, PAN: %s\n}\n";
// if the string was before the balance, i would say 
// const char* FORMAT_OUT = "(%[^,], %f)\n";
const char* FORMAT_OUT_Trans = "{\n\tCard Holder Name: %s\tPAN: %s\n\tCard Expiry Date: %s\n\tTransaction Amount: %f\n\tMax Allowed Amount: %f\n\tTransaction Date: %s\n\tTransaction State: %i\n\tTransaction Serial Code: %ld\n}\n";
const char* FORMAT_IN_Trans  = "{\n\tCard Holder Name: %s\tPAN: %s\n\tCard Expiry Date: %s\n\tTransaction Amount: %f\n\tMax Allowed Amount: %f\n\tTransaction Date: %s\n\tTransaction State: %i\n\tTransaction Serial Code: %ld\n}\n";


void structToFile() {
	FILE* databaseFile;
	fclose(fopen("Accounts_V1_DB.txt", "w"));
	//this fclose function is to delete the database if i opened the app after closing it
	fopen_s(&databaseFile, "Accounts_V1_DB.txt", "a");

	if (databaseFile == NULL) {
		fprintf_s(stderr, "\nError accessing file.\n");
		return 1;
	}
	for (int i = 0; i < SAMPLE_TEST; i++) {
		// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		//fwrite(&accountDatabase[i], sizeof(struct ST_transaction_t), 1, databaseFile);
		fprintf_s(databaseFile, FORMAT_OUT_ACCOUNTS,
			accountDatabase[i].balance,
			accountDatabase[i].state,
			accountDatabase[i].primaryAccountNumber);

		fseek(databaseFile, 0, SEEK_SET);

		fscanf_s(databaseFile, FORMAT_IN_ACCOUNTS,
			&extractedDatabase[i].balance,
			&extractedDatabase[i].state,
			&extractedDatabase[i].primaryAccountNumber, 20);
		
	}
	if (fprintf_s != 0) {
		printf("\Global Database Array of Structs was saved to the Database file successfully!\n");
	}
	else {
		printf("There was an unexpected error that occurred while writing to the file!\n");
	}
	fclose(databaseFile);
	printf("\n");
}

void getStructFromFile() {
	printf("############## Printing the Data from the Accounts Database ##############\n\n");
	
	FILE* databaseFile;
	fopen_s(&databaseFile, "Accounts_V1_DB.txt", "r");

	if (databaseFile == NULL) {
		fprintf_s(stderr, "\nError accessing file.\n");
		return 1;
	}
	for (int i = 0; i < SAMPLE_TEST; i++) {
		
		fscanf_s(databaseFile, FORMAT_IN_ACCOUNTS,
					&extractedDatabase[i].balance,
					&extractedDatabase[i].state,
					&extractedDatabase[i].primaryAccountNumber, 20);
		
		printf("%i. Balance: %f, PAN: %s, State: %i\n",
				i + 1,
				extractedDatabase[i].balance,
				&extractedDatabase[i].primaryAccountNumber,
				extractedDatabase[i].state);
	}
	if (fprintf_s != 0) {
		printf("\nDatabase contents were retrieved & saved to another Global Array of Structs successfully!\n");
		printf("	You can now start your operations!\n");
	}
	else {
		printf("There was an unexpected error that occurred while retrieving data from the file!\n");
	}
	fclose(databaseFile);
	printf("\n##############                Done Printing                 ##############\n");
}

void getUpdatedStructFromFile() {
	printf("########## Printing the Updated Data from the Accounts Database ##########\n\n");

	FILE* databaseFile;
	fopen_s(&databaseFile, "Accounts_V1_DB.txt", "r");

	if (databaseFile == NULL) {
		fprintf_s(stderr, "\nError accessing file.\n");
		return 1;
	}
	for (int i = 0; i < SAMPLE_TEST; i++) {

		fscanf_s(databaseFile, FORMAT_IN_ACCOUNTS,
			&extractedDatabase[i].balance,
			&extractedDatabase[i].state,
			&extractedDatabase[i].primaryAccountNumber, 20);

		printf("%i. Balance: %f, PAN: %s, State: %i\n",
			i + 1,
			extractedDatabase[i].balance,
			&extractedDatabase[i].primaryAccountNumber,
			extractedDatabase[i].state);
	}
	if (fprintf_s != 0) {
		printf("\nDatabase contents were retrieved & saved to another Global Array of Structs successfully!\n");
		printf("	Update is now complete!\n");
	}
	else {
		printf("There was an unexpected error that occurred while retrieving data from the file!\n");
	}
	fclose(databaseFile);

	printf("\n##############                Done Printing                 ##############\n");
}

void TransDBToFile() {
	FILE* databaseFile;
	fclose(fopen("Trans_DB.txt", "w"));
	//this fclose function is to delete the database if i opened the app after closing it
	fopen_s(&databaseFile, "Trans_DB.txt", "a");

	if (databaseFile == NULL) {
		fprintf_s(stderr, "\nError accessing file.\n");
		return 1;
	}
	for (int i = 0; i < 1; i++) {
		// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		//fwrite(&accountDatabase[i], sizeof(struct ST_transaction_t), 1, databaseFile);
		
		fprintf_s(databaseFile, FORMAT_OUT_Trans,
			transactionDatabase[i].cardHolderData.cardHolderName,
			transactionDatabase[i].cardHolderData.primaryAccountNumber,
			transactionDatabase[i].cardHolderData.cardExpirationDate,
			transactionDatabase[i].terminalData.transAmount,
			transactionDatabase[i].terminalData.maxTransAmount,
			transactionDatabase[i].terminalData.transactionDate,
			transactionDatabase[i].transState,
			transactionDatabase[i].transactionSequenceNumber);

		fseek(databaseFile, 0, SEEK_SET);

		fscanf_s(databaseFile, FORMAT_IN_Trans,
			transactionDatabase[i].cardHolderData.cardHolderName,
			transactionDatabase[i].cardHolderData.primaryAccountNumber,
			transactionDatabase[i].cardHolderData.cardExpirationDate,
			transactionDatabase[i].terminalData.transAmount,
			transactionDatabase[i].terminalData.maxTransAmount,
			transactionDatabase[i].terminalData.transactionDate,
			transactionDatabase[i].transState,
			transactionDatabase[i].transactionSequenceNumber);

	}
	if (fprintf_s != 0) {
		printf("\Transaction Data was saved to the Database file successfully!\n");
	}
	else {
		printf("There was an unexpected error that occurred while writing to the file!\n");
	}
	fclose(databaseFile);
	printf("\n");
}


/********************************************************************/
/********************************************************************/




/********** Implement server - side transactions' database **********/
/********************************************************************/

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

	if ((isValidAccount(&transData -> cardHolderData) == ACCOUNT_NOT_FOUND)) {
		transactionVerifer = FRAUD_CARD;
	}
	else if ((isValidAccount(&transData -> cardHolderData) == SERVER_OK)) {
		
		if ((isAmountAvailable(&transData -> terminalData) == LOW_BALANCE)) {
			transactionVerifer = DECLINED_INSUFFECIENT_FUND;
		}
		else if ((isAmountAvailable(&transData -> terminalData) == SERVER_OK)) {
			
			if ((isBlockedAccount(&tempAccounts -> state) == BLOCKED_ACCOUNT)) {
				transactionVerifer = DECLINED_STOLEN_CARD;
			}
			else {
				printf("			Transaction is approved!\n");
				transactionVerifer = APPROVED;
			}
		}
	}

	printf("\n*************** Transcation Data was received successfully. **************\n");
	printf("**************************************************************************\n\n");

	printf("	Your Balance before transaction was: %f\n", tempAccounts -> balance);
	tempAccounts -> balance = (tempAccounts -> balance) - (transData->terminalData.transAmount);
	printf("	Your Balance now is:                 %f\n", tempAccounts -> balance);
	
	printf("\nUpdating the balance amount into the Main Database...\n");

	int result;
	for (int i = 0; i < SAMPLE_TEST; i++) {
		//printf("\nCurrent PAN iteration-%d in DB is: %s\n", i, accountDatabase[i].primaryAccountNumber);
		result = strcmp(transData->cardHolderData.primaryAccountNumber, accountDatabase[i].primaryAccountNumber);
		//printf("Result in iteration-%d is: %d\n", i, result);
		if (result == 0) {
			//printf("	Account Number is Valid & Registered in the Database!\n");
			accountDatabase[i].balance = tempAccounts->balance;
		}
	}
	printf("\n");

	structToFile();
	getUpdatedStructFromFile();

	return transactionVerifer;
}


EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	printf("Checking Account Number if it's Stored on the Main Database...\n");
	int result;
	for (int i = 0; i < SAMPLE_TEST; i++) {
		//printf("\nCurrent PAN iteration-%d in DB is: %s\n", i, accountDatabase[i].primaryAccountNumber);
		result = strcmp(cardData->primaryAccountNumber, accountDatabase[i].primaryAccountNumber);
		if (result == 0) {
			printf("	Account Number is Valid & Registered in the Database!\n");
			tempAccounts = &(accountDatabase[i]);
			return SERVER_OK;
		}
	}
	if (result != 0) {
		printf("	Account Number is Invalid & is Not Found in the Database!\n");
		printf("		Program will now be terminated.\n\n");
		exit(ACCOUNT_NOT_FOUND);
	}
}


EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountReference) {
	printf("\n");
	printf("Checking if the card is stolen...\n");
	printf("	Checking the state of the entered PAN's Account: %s\n", &tempAccounts -> primaryAccountNumber);
	printf("		Retrieving Account State...\n");

	if (tempAccounts -> state == BLOCKED) {
		printf("		Activity on your account has been suspended because your Account is blocked!\n\n");
		printf("			Program will now be terminated.\n\n");
		exit(BLOCKED_ACCOUNT);
	}
	else if (tempAccounts->state == RUNNING) {
		printf("			Your account state is running stable.\n\n");
		return SERVER_OK;
	}
}


EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	printf("\n");
	printf("Checking for Credit in the Account...\n");
	printf("	Amount entered was: %f\n", termData -> transAmount);
	printf("		Retrieving Account Balance...\n");
	
	if (tempAccounts -> balance < termData -> transAmount) {
		printf("		Your Credit is Insufficent to Complete Transaction!\n\n");
		printf("			Program will now be terminated.\n\n");
		exit(LOW_BALANCE);
	}
	else if (tempAccounts -> balance >= termData -> transAmount) {
		printf("			Please Wait While the Transaction Finishes Processing!\n");
		return SERVER_OK;
	}
}


EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	
	static int iterationNum = 1;

	printf("\nSaving the Transaction Data into the Transaction Database...\n\n");
	
	for (int i = 0; i < 1; i++) {
		
		memcpy(transactionDatabase[i].cardHolderData.cardHolderName,
			transData->cardHolderData.cardHolderName,
			sizeof(transData->cardHolderData.cardHolderName));
		memcpy(transactionDatabase[i].cardHolderData.primaryAccountNumber,
			transData->cardHolderData.primaryAccountNumber,
			sizeof(transData->cardHolderData.primaryAccountNumber));
		memcpy(transactionDatabase[i].cardHolderData.cardExpirationDate,
			transData->cardHolderData.cardExpirationDate,
			sizeof(transData->cardHolderData.cardExpirationDate));
		
		transactionDatabase[i].terminalData.transAmount =
			transData->terminalData.transAmount;
		transactionDatabase[i].terminalData.maxTransAmount =
			transData->terminalData.maxTransAmount;
		memcpy(transactionDatabase[i].terminalData.transactionDate,
			transData->terminalData.transactionDate,
			sizeof(transData->terminalData.transactionDate));

		transactionDatabase[i].transactionSequenceNumber = iterationNum;

		transactionDatabase[i].transState = transactionVerifer;


		printf("\tName: %s\tPAN: %s\n\tEXP: %s\n\tTransAmount: %f\n",
			transactionDatabase[i].cardHolderData.cardHolderName,
			transactionDatabase[i].cardHolderData.primaryAccountNumber,
			transactionDatabase[i].cardHolderData.cardExpirationDate,
			transactionDatabase[i].terminalData.transAmount);

		printf("\tMax Allowed: %f\n\tDate: %s\n\tStatus: %i\n\tTransaction Serial: %ld\n\n",
			transactionDatabase[i].terminalData.maxTransAmount,
			transactionDatabase[i].terminalData.transactionDate,
			transactionDatabase[i].transState,
			transactionDatabase[i].transactionSequenceNumber);
	}
	TransDBToFile();
}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData) {

	/*
	static int iterationNum = 1;
	if (iterationNum > SAMPLE_TEST) {
		return SAVING_FAILED;
	}

	printf("\nSaving the Transaction Data in the Accounts Database...\n");

	transactionDatabase.cardHolderData.cardHolderName =
		transData->cardHolderData.cardHolderName;
	*transactionDatabase.cardHolderData.primaryAccountNumber =
		transData->cardHolderData.primaryAccountNumber;
	*transactionDatabase.cardHolderData.cardExpirationDate =
		transData->cardHolderData.cardExpirationDate;

	transactionDatabase.terminalData.transAmount =
		transData->terminalData.transAmount;
	transactionDatabase.terminalData.maxTransAmount =
		transData->terminalData.maxTransAmount;
	*transactionDatabase.terminalData.transactionDate =
		transData->terminalData.transactionDate;

	transactionDatabase[iterationNum - 1].transactionSequenceNumber = iterationNum;

	if (transData->transState == APPROVED) {
		transactionDatabase[iterationNum - 1].transState = APPROVED;
	}
	else if (transData->transState == DECLINED_INSUFFECIENT_FUND) {
		transactionDatabase[iterationNum - 1].transState = DECLINED_INSUFFECIENT_FUND;
	}
	else if (transData->transState == INTERNAL_SERVER_ERROR) {
		transactionDatabase[iterationNum - 1].transState = INTERNAL_SERVER_ERROR;
	}
	printf("Name: %s, PAN: %s, EXP: %s, Transaction Amount: %f, Max Allowed: %f, Date: %s, Status: %i, Seq No: %ld\n",
		transactionDatabase[iterationNum - 1].cardHolderData.cardHolderName,
		transactionDatabase[iterationNum - 1].cardHolderData.primaryAccountNumber,
		transactionDatabase[iterationNum - 1].cardHolderData.cardExpirationDate,
		transactionDatabase[iterationNum - 1].terminalData.transAmount,
		transactionDatabase[iterationNum - 1].terminalData.maxTransAmount,
		transactionDatabase[iterationNum - 1].terminalData.transactionDate,
		transactionDatabase[iterationNum - 1].transState,
		transactionDatabase[iterationNum - 1].transactionSequenceNumber);
	*/

	/*
	printf("This transaction belongs to %s account number.\n",
		transData->cardHolderData.primaryAccountNumber);
	printf("This transaction amount is: %f\n",
		transData->terminalData.transAmount);
	printf("This transaction occurred on: %s\n",
		transData->terminalData.transactionDate);
	printf("This transaction occurred on: %s\n",
		transData->terminalData.transactionDate);
	*/
	// we need to save the stuff inside the
	// ST_transaction_t transactionDatabase[MAX_ACCOUNTS];
	//transactionDatabase->transactionSequenceNumber = 1;
	//printf("This transaction serial number is: %l\n",
	//transactionDatabase->transactionSequenceNumber);

}

