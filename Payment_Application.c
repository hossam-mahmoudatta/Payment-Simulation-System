// Payment_Application.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "card.h"
#include "terminal.h"
#include "server.h"

int main() {

	char prompt = 0;
	int progIteration = 0;
	int acc = 0;
	ST_transaction_t clientData[SAMPLE_TEST] = {0};
	ST_accountsDB_t extractedDatabase[SAMPLE_TEST] = { 0 };
	
	printf("\n");
	printf("******************** Welcome to Hossam's POS System! *********************\n");

	structToFile();
	getStructFromFile();

	do {
		fflush(stdin);		
		printf("\n");
		printf("**************************** Transacation: %d *****************************\n", progIteration + 1);
		printf("**************************************************************************\n");

		//*   Card Phase   *
		printf("********************* Retrieving Your Card Details...*********************\n");
		printf("\n");
		getCardHolderName(&clientData[progIteration].cardHolderData);
		getCardPAN(&clientData[progIteration].cardHolderData);
		getCardExpiryDate(&clientData[progIteration].cardHolderData);
		printf("**************************************************************************\n");
		
		//*   Terminal Phase   *
		printf("*************** Retrieving Your Terminal Payment Details...***************\n");
		printf("\n");
		getTransactionDate(&clientData[progIteration].terminalData);
		printf("\n");
		setMaxAmount(&clientData[progIteration].terminalData);
		printf("\n");
		isCardExpired(clientData[progIteration].cardHolderData, clientData[progIteration].terminalData);
		printf("\n");
		//isValidCardPAN(&client.terminalData);
		getTransactionAmount(&clientData[progIteration].terminalData);
		printf("\n");
		isBelowMaxAmount(&clientData[progIteration].terminalData);
		printf("\n");
		printf("**************************************************************************\n");
		
		//*   Server Phase   *
		printf("*********** Validating Your Account's Data from the Server...*************\n");
		printf("\n");
		isValidAccount(&clientData[progIteration].cardHolderData);
		isAmountAvailable(&clientData[progIteration].terminalData);
		isBlockedAccount(&extractedDatabase[progIteration]);
		
		printf("****************** Receiving all Transcation Data now. *******************\n");
		printf("**************************************************************************\n");
		printf("\n");
		recieveTransactionData(&clientData[progIteration]);
		saveTransaction(&clientData[progIteration]);
		printf("**************************************************************************\n");



		printf("\nPress Y or y to enter another transaction. Press any Key To Exit.\n");
		//prompt = getch();
		scanf_s(" %c", &prompt, 1); // dont forget type &
		//fgets(&prompt, 10, stdin);

		progIteration++;
		
	} while (prompt == 'y' || prompt == 'Y');

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file