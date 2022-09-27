#pragma once

#include "terminal.h"

#ifndef SERVER_H_
#define SERVER_H_

#define MAX_ACCOUNTS 255
#define SAMPLE_TEST 10

typedef enum EN_transState_t {
	APPROVED, DECLINED_INSUFFECIENT_FUND,
	DECLINED_STOLEN_CARD, FRAUD_CARD,
	INTERNAL_SERVER_ERROR
} EN_transState_t;

typedef enum EN_serverError_t {
	SERVER_OK, SAVING_FAILED,
	TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND,
	LOW_BALANCE, BLOCKED_ACCOUNT
} EN_serverError_t;

typedef enum EN_accountState_t {
	RUNNING,
	BLOCKED
} EN_accountState_t;


typedef struct ST_accountsDB_t {
	float balance;
	uint8_t primaryAccountNumber[20];
	EN_accountState_t state;

} ST_accountsDB_t;


typedef struct ST_transaction_t {
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState; // returns 0 or whatever, either approved or failed trans
	uint32_t transactionSequenceNumber; //serial number for the transaction
} ST_transaction_t;


EN_transState_t  recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountReference);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber,
								ST_transaction_t* transData);

void structToFile(void);
void getStructFromFile(void);
void getUpdatedStructFromFile(void);

void TransDBToFile(void);

#endif // !SERVER_H_



 