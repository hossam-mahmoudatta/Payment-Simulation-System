# Payment System Simulation

## System Description

This is the Payment System Simulation for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C Language using Microsoft Visual Studio.

Simulating the process between the client and an ATM Machine.

## System Flowchart

![payment-flowchart](https://user-images.githubusercontent.com/36197508/192575778-f8b6573b-1e27-43ad-a885-75dafd1c43a3.jpeg)

As you can see from the flowchart that the system is divided into 3 stages.

## System Implementation & Functionality

### The Program starts in the 1st stage, the `Card` Module by retrieving user info by the following methods:
- `getCardHolderName( )`: gets the name of the cardholder.
- `getCardPAN( )`: gets the primary account number related to the card.
- `getCardExpiryDate( )`: gets the expiry date of the card.

![image](https://user-images.githubusercontent.com/36197508/192577949-134176e3-4e07-4e70-95aa-aba9fd4cfc5a.png)

### The Program then enters into the 2nd stage, the `Terminal` Module by retrieving transaction environment info by the following methods:
- `setMaxAmount( )`: sets the maximum amount that the user can use.
- `getTransactionDate( )`: gets the current date of the system as the transaction's date.
- `isCardExpired( )`: checks if the card is expired or not.
- `getTransactionAmount( )`: gets the transaction amount that the user needs.
- `isBelowMaxAmount( )`: checks if the amount entered by the user didn't exceed the maximum daily amount.

![image](https://user-images.githubusercontent.com/36197508/192580781-c3b5a490-0f92-464a-999c-6aceec4ddd9d.png)

### The Program then enters into the final stage, the `Server` Module by retrieving details about post-transaction info by the following methods:
- `isValidAccount( )`: checks if the entered PAN matches one of the stored PANs on the Accounts' Database.
- `isBlockedAccount( )`: checks if the account was reported to be stolen and whether it was closed or not.
- `isAmountAvailable( )`: checks if the amount entered by the user is sufficient by comparing it to the account's balance.
- `recieveTransactionData( )`: gets the transaction amount and updates the balance of the corresponding PAN.
- `saveTransaction( )`: saves the transaction data serialized into an external database.
- `getTransaction( )`: gets the transaction serial number by user to retrieve the transactions information.

![image](https://user-images.githubusercontent.com/36197508/192580872-2340b1fe-d923-420a-bae2-a30780f70f86.png)

![image](https://user-images.githubusercontent.com/36197508/192580993-140fba16-be8f-4c96-8157-d8409c66216a.png)

![image](https://user-images.githubusercontent.com/36197508/192581231-bc22cd1f-9745-43ef-abbc-5b1579ce370e.png)

![image](https://user-images.githubusercontent.com/36197508/192581344-567df092-c458-4edf-88a8-814ced04a042.png)



### Input Accounts' Database:

![image](https://user-images.githubusercontent.com/36197508/192575154-beb3e8aa-55b3-46cb-bab8-a06e98f52925.png)

### Output Accounts' Database:

![image](https://user-images.githubusercontent.com/36197508/192573354-5b668414-698f-44d4-a10a-8dc638d1853e.png)


## Feel free to contact me regarding the project's implementation!
