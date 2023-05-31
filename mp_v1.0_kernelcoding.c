/************************************************************
This is to certify that this project is my own work, 
based on my personal efforts in studying and applying
the concepts learned. I have constructed the functions
and their respective algorithms and corresponding code
by myself. The program was run, tested, and debugged by
my own efforts. I further certify that I have not copied 
in part or whole or otherwise plagiarized the work of
other students and/or persons.

					Gleezell Vina A. Uy, DLSU ID 12133663
************************************************************/

/* 
DESCRIPTION: This program simulates a vending machine that
		lets the user order a pizza with different types
		of crusts, sizes, toppings, and stuffings. 
		It also computes the total cost that must
		be paid by the user which dispenses change
		if applicable, prints out a receipt,
		and displays a countdown for the time
		required in baking the pizza order.
		
PROGRAMMED BY: GLEEZELL VINA A. UY 	S21
DATE LAST MODIFIED: FEB. 6, 2022
VERSION: 3.0
*/

#include <stdio.h>

#define SMALLCRUST_PRICE			100.00
#define MEDIUMCRUST_PRICE			175.00
#define LARGECRUST_PRICE			225.00
#define HAM_PRICE					10.00
#define PINEAPPLE_PRICE				6.00
#define SAUSAGE_PRICE				15.00
#define CHEESE_PRICE				12.00
#define OLIVES_PRICE				10.00
#define CHEESESTUFFING_PRICE		30.00
#define SPAMSTUFFING_PRICE			25.00
#define CHEESESPAMSTUFFING_PRICE	35.00

int		chooseCrustType	 (int 	*pExit);
char 	chooseCrustSize	 (float *pCrustSizePrice, 
						  char 	*pStop);
float 	chooseToppings	 (int 	*pHamCnt, 
						  int 	*pPineappleCnt,
					 	  int 	*pSausageCnt, 
					 	  int 	*pCheeseCnt,
					 	  int 	*pOlivesCnt, 
					 	  float *pHamPrice, 
					 	  float *pPineapplePrice, 
					 	  float *pSausagePrice, 
					 	  float *pCheesePrice, 
					 	  float *pOlivesPrice,
					 	  char 	 cCrustSize, 
					 	  char 	*pStop);
void	chooseCheeseType (int 	*pMozCnt, 
					  	  int 	*pGorCnt, 
					  	  int 	*pFonCnt, 
					  	  int 	*pParCnt, 
					  	  int 	 nCheeseCnt, 
					  	  char 	*pStop);
char 	chooseStuffing   (float *pCheeseStuffingCost, 
						  float *pSpamStuffingCost,
						  float *pCheeseSpamStuffingCost, 
						  char 	*pStop);
void 	insertPayment  	 (float  fTotal, 
				  		  int 	*pExit, 
				  		  float *pChange);
void 	displayReceipt   (int 	*pTransactionNumber, 
						  int 	 nCrustType, 
						  int 	 nPineappleCnt,
			   			  int 	 nSausageCnt, 
						  int 	 nCheeseCnt, 
						  int 	 nOlivesCnt, 
						  int 	 nHamCnt,
			  	 		  int 	 nMozCnt, 
						  int 	 nGorCnt, 
						  int 	 nFonCnt, 
						  int 	 nParCnt,
			   			  float  fCrustSizePrice, 
						  float  fHamPrice, 
						  float  fPineapplePrice, 
			   			  float  fSausagePrice, 
						  float  fCheesePrice, 
						  float  fOlivesPrice, 
			   			  float  fCheeseStuffingCost, 
						  float  fSpamStuffingCost,
			   			  float  fCheeseSpamStuffingCost, 
						  float  fTotal, 
						  float  fChange,
			   			  char 	 cStuffing, 
						  char 	 cCrustSize);
float	getChange		 (float  fUserPayment,
						  float  fTotal);
void 	countdown		 (int 	 nHamCnt, 
			   			  int 	 nPineappleCnt, 
			   			  int 	 nSausageCnt,
			   			  int 	 nCheeseCnt, 
			   			  int 	 nOlivesCnt, 
			   			  char   cStuffing);
void 	cheeseBreakdown  (char   cCrustSize);

/* This main function resets the value of the variables
   so that the program can still be used when repeated
   
   This main function calls and proceeds
   to the other functions after verifying 
   that the user does not intend to cancel 
   the order or execute machine maintenance
*/
int
main (void)
{
	/* cStop starts as 'a'
	   If cStop becomes 'x' the program
	   will repeat from the start
	   
	   nExit starts as 1
	   If nExit becomes 80808 the program
	   will stop and undergo maintenance
	
	   nTransactionNumber starts at 1
	   and goes up for each completed order
	*/
	char cStop = 'a';
	int nExit = 0,
		nTransactionNumber = 1;
	
	/* program repeats as long as nExit is 1,
	   if cStop is x, or if nExit is not 80808
	*/
	while (nExit == 0 || 
			cStop == 'x' || 
			nExit != 80808) {
			
			//reset to default values
			cStop = 'a';
			nExit = 0;
	
		// variable declaration
		char cCrustSize,
			 cStuffing;
		
		//reset to default values
		float fCrustSizePrice = 0,
			  fToppingsPrice = 0,
		  	  fHamPrice = 0,
		  	  fPineapplePrice = 0,
		  	  fSausagePrice = 0,
		  	  fCheesePrice = 0,
		  	  fOlivesPrice = 0,
		  	  fCheeseStuffingCost = 0,
		  	  fSpamStuffingCost = 0,
		  	  fCheeseSpamStuffingCost = 0,
		  	  fTotal = 0,
		  	  fChange = 0;
	
		//reset to default values
		int nHamCnt = 0,
			nPineappleCnt = 0,
			nSausageCnt = 0,
			nCheeseCnt = 0,
			nOlivesCnt = 0,
			nMozCnt = 0,
			nFonCnt = 0,
			nGorCnt = 0,
			nParCnt = 0,
			nCrustType = 0;
	
		//ask user for type of crust
		nCrustType = chooseCrustType (&nExit);
	
		//proceed if user did not enter 80808
		if (nExit != 80808) {
			printf("\n**********\n"); 
		
			//ask user for size of crust
			cCrustSize = chooseCrustSize (&fCrustSizePrice, 
									 	  &cStop);
			
			//proceed if user did not cancel order or enter x
			if (cStop != 'x') {
				printf("\n**********\n"); 
	
				//ask user for choice of toppings
				fToppingsPrice = chooseToppings (&nHamCnt, 
												 &nPineappleCnt,
			   									 &nSausageCnt, 
												 &nCheeseCnt,
			   									 &nOlivesCnt, 
												 &fHamPrice,
												 &fPineapplePrice, 
												 &fSausagePrice,
												 &fCheesePrice, 
												 &fOlivesPrice,
												  cCrustSize, 
												 &cStop);
			}
			
			//proceed if user did not cancel order or enter x
			if (cStop != 'x') {
				
				//call function if user chose at least 1 cheese topping
				if (nCheeseCnt > 0) {
					printf("\n**********\n"); 
					chooseCheeseType (&nMozCnt, 
								 	  &nGorCnt, 
								 	  &nFonCnt,
						 		 	  &nParCnt, 
								 	   nCheeseCnt, 
								 	  &cStop);
				}
			}
		
			/* proceed if user did not cancel order
			   or if user did not execute maintenance code
			*/
			if (cStop != 'x' && nExit != 80808) {
				printf("\n**********\n"); 
						 
				//call function if user chose thick crust
				if (nCrustType == 2) {
					cStuffing = chooseStuffing (&fCheeseStuffingCost, 
										   	    &fSpamStuffingCost,
								  	 	   		&fCheeseSpamStuffingCost, 
										   	    &cStop);
				}
			}
		
			//proceed if user did not cancel order
			if (cStop != 'x') {
				
				//compute for total cost of pizza
				fTotal = fCrustSizePrice + 
				fToppingsPrice +
			 	fCheeseStuffingCost + 
				fSpamStuffingCost +
			 	fCheeseSpamStuffingCost;
			
				printf ("Total cost is %.2f\n", 
						fTotal);
			
				printf("\n**********\n");
	
				//ask user to insert payment
				//change will be computed if applicable
				insertPayment (fTotal, 
							  &nExit, 
							  &fChange);
			
				printf("\n**********\n");
				
				/*proceed if user did not execute maintenance code
				  or did not cancel order
				
				*/
				if (nExit != 80808 && nExit != 1) {
					displayReceipt (&nTransactionNumber, 
						   		 	 nCrustType, 
						   		 	 nPineappleCnt,
			   			   		 	 nSausageCnt, 
						   		 	 nCheeseCnt,
						   			 nOlivesCnt, 
						   		 	 nHamCnt,
			   			   		 	 nMozCnt, 
						   		 	 nGorCnt, 
						   		 	 nFonCnt, 
						   		 	 nParCnt,
			   			   		 	 fCrustSizePrice, 
						   		 	 fHamPrice, 
						   		 	 fPineapplePrice, 
			   			   		 	 fSausagePrice, 
						   		 	 fCheesePrice, 
						   		 	 fOlivesPrice, 
			   			   		 	 fCheeseStuffingCost, 
						   		 	 fSpamStuffingCost,
			   			   		 	 fCheeseSpamStuffingCost, 
						   		 	 fTotal, 
						   		 	 fChange,
			   			   		 	 cStuffing, 
						   		 	 cCrustSize);
			   
				printf("\n**********\n");
			
				//display countdown while baking pizza
				countdown (nHamCnt, 
					  	   nPineappleCnt, 
					  	   nSausageCnt,
			  		  	   nCheeseCnt, 
					  	   nOlivesCnt, 
					  	   cStuffing);
				}
			}
		}
	}
	
	return 0;
}

/*  This function determines the type of crust
	that is chosen by the user: 1 for thin crust,
	2 for thick crust
	
	Precondition: user input is a positive integer
				that must either be 1, 2, or 80808
				to proceed
	@param *pExit serves as the termination variable
			that stops the entire program if its value
			becomes 80808
	@return the type of crust
*/
int
chooseCrustType (int *pExit)
{
	//variable declaration
	int nCrustType;
	
	//display instructions
	printf ("Choose type of crust:\n");
	printf ("Enter [1] for thin crust\n");
	printf ("Enter [2] for thick crust\n");
	
	//ask user's choice
	scanf ("%d", &nCrustType);
	
	/* show error message when input is invalid
	   ask for input until user enters 1, 2, or 80808
	*/
	while (nCrustType != 1 && 
			nCrustType != 2 && 
			nCrustType != 80808 && 
			nCrustType != 80808) {
				printf ("Invalid key\n");
				scanf ("%d", &nCrustType); //ask again
	}
	
	//display user's choice 
	switch (nCrustType) {
		case 1:
			printf ("You picked thin crust\n");
			break;
		case 2:
			printf ("You picked thick crust\n");
			break;
		case 80808:
			printf ("System is undergoing maintenance\n");
		   *pExit = 80808; //change pointer value to maintenance code
			break;
	}
	
	//return user's option			
	return nCrustType;
}

/*  This function determines the size of crust
	chosen by the user: s/S for small, m/M for medium,
	l,L for large
	
	This function computes for the cost of the
	chosen size of crust: Php 100 for small, 
	Php 175 for medium, Php 225 for large

	Precondition: user input is a char that must
				 either be s,S,m,M,l,L,x,X
				 to proceed
   
	@param *pCrustSizePrice is the cost of the 
			chosen size of crust
   	@param *pStop determines if the order
   			is cancelled or is equal to x
   	@return the size of the crust
   			  
*/
char 
chooseCrustSize (float *pCrustSizePrice, 
				 char  *pStop)
{
	//variable declaration
	char cCrustSize;
	
	//display instructions and ask for input
	printf ("Choose size of crust:\n");
	printf ("Enter [s] or [S] for small\n");
	printf ("Enter [m] or [M] for medium\n");
	printf ("Enter [l] or [L] for large\n");
	
	//ask user's choice
	scanf (" %c", &cCrustSize);
	
	/* show error message when input is invalid
	   ask for input until user enters s,S,m,M,l,L,X,x
	*/
	while (cCrustSize != 's' && 
			cCrustSize != 'S' &&
			cCrustSize != 'm' && 
			cCrustSize != 'M' &&
			cCrustSize != 'l' && 
			cCrustSize != 'L' && 
		  	cCrustSize != 'x' && 
		  	cCrustSize != 'X') {
				printf("Invalid key\n");
				scanf(" %c", &cCrustSize); //ask again
	}
	
	//display user's choice and store price in pointer
	switch (cCrustSize) {
		//for small
		case 's':
		case 'S':
			printf ("You picked small\n");
		   *pCrustSizePrice = SMALLCRUST_PRICE;
			break;
			//for medium
		case 'm':
		case 'M':
			printf ("You picked medium\n");
		   *pCrustSizePrice = MEDIUMCRUST_PRICE;
			break;
			//for large
		case 'l':
		case 'L':
			printf ("You picked large\n");
		   *pCrustSizePrice = LARGECRUST_PRICE;
			break;
			//for order cancellation
		case 'x':
		case 'X':
			printf ("You cancelled the order\n");
			printf ("\n**********\n");
		   *pStop = 'x'; //update pointer to show order was cancelled
			break;
	}
	
	//return user's choice
	return cCrustSize;
}
/*	This function lets user choose unlimited pizza
	toppings until n or N is entered
	
	This function computes both the individual and
	overall cost of the chosen toppings
	
	This function counts the amount of toppings
	picked individually
	
	This function shows an error message
	if user enters an invalid key to
	asks again for valid inputs:
	h,H,p,P,s,S,c,C,o,O,x,X,n,N

	Precondition: only char data type is accepted
	@param *pHamCnt counts the amount of ham toppings
	@param *pPineappleCnt counts the amount of pineapple toppings
	@param *pSausageCnt counts the amount of sausage toppings
	@param *pCheeseCnt counts the amount of cheese toppings
	@param *OlivesCnt counts the amount of olives topppings
	@param *pHamPrice stores the total cost of ham toppings
	@param *pPineapplePrice stores the total cost of pineapple toppings
	@param *pSausagePrice stores the total cost of sausage toppings
	@param *pCheesePrice stores the total cost of cheese toppings
	@param *pOlivesPrice stores the total cost of olives toppings
	@param cCrustSize is the size of the pizza crust
	@param *pStop determines if the order is cancelled
			or is equal to x
	@return the overall cost of the chosen toppings
*/
float 
chooseToppings (int   *pHamCnt, 
			    int   *pPineappleCnt,
			    int   *pSausageCnt, 
			    int   *pCheeseCnt,
			    int   *pOlivesCnt, 
			    float *pHamPrice, 
			    float *pPineapplePrice, 
			    float *pSausagePrice, 
			    float *pCheesePrice, 
			    float *pOlivesPrice,
			    char   cCrustSize, 
			    char  *pStop)
{
	//variable declaration
	float fToppingsPrice;
	char cToppingsChoice,
		 cNext = '0'; /*set to default value
		 			    so program knowns when
		 			    at least 1 topping
		 			    is picked
		 			  */
	
	//display instructions
	printf ("Choose choice of toppings:\n");
	printf ("Enter [h] or [H] for ham\n");
	printf ("Enter [p] or [P] for pineapple\n");
	printf ("Enter [s] or [S] for sausage\n");
	printf ("Enter [c] or [C] for cheese\n");
	printf ("Enter [o] or [O] for olives\n");
	
	//repeat until user enters h,H,p,P,s,S,c,C,o,O,x,X,n,N
	do {		
	
		//ask user's choice
		scanf (" %c", &cToppingsChoice);
		
		/*	show error message and repeat 
			until user enters n,N,p,P,s,S,c,C,o,O
		*/
		while (cToppingsChoice != 'h' && 
				cToppingsChoice != 'H' &&
				cToppingsChoice != 'p' && 
			  	cToppingsChoice != 'P' &&
			  	cToppingsChoice != 's' && 
			  	cToppingsChoice != 'S' &&
			  	cToppingsChoice != 'c' && 
			  	cToppingsChoice != 'C' &&
			  	cToppingsChoice != 'o' && 
			  	cToppingsChoice != 'O' &&
			  	cToppingsChoice != 'x' && 
			  	cToppingsChoice != 'X' &&
				cToppingsChoice != 'n' &&
				cToppingsChoice != 'N') {
					printf ("Invalid key\n");
					scanf (" %c", &cToppingsChoice); //ask again
		}
		
		//display user's choice and store price in pointer
		switch (cToppingsChoice) {
			//for order cancellation
			case 'x':
			case 'X':
				printf ("You cancelled the order\n");
				printf ("\n**********\n");
			   *pStop = 'x'; //update pointer to show order was cancelled
				break;
			//for ham
			case 'h':
			case 'H':
				printf ("You picked ham\n");
				cNext = '2'; //update to show at least 1 topping was picked
			   *pHamCnt += 1; //update ham count
				
				//compute according to pizza size
				switch (cCrustSize) {
					case 's':
					case 'S':
					   *pHamPrice += HAM_PRICE;
						break;
					case 'm':
					case 'M':
					   *pHamPrice += HAM_PRICE * 1.5;
						break;
					case 'l':
					case 'L':
					   *pHamPrice += HAM_PRICE * 1.75;
					    break;
				}
				break;
			//for pineapple
			case 'p':
			case 'P':
				printf ("You picked pineapple\n");
				cNext = '2'; //update to show at least 1 topping was picked
			   *pPineappleCnt += 1; //update pineapple count
				
				//compute according to pizza size
				switch (cCrustSize) {
					case 's':
					case 'S':
					   *pPineapplePrice += PINEAPPLE_PRICE;
						break;
					case 'm':
					case 'M':
						*pPineapplePrice += PINEAPPLE_PRICE * 1.5;
						break;
					case 'l':
					case 'L':
						*pPineapplePrice += PINEAPPLE_PRICE * 1.75;
						break;
				}
				break;
			//for sausage
			case 's':
			case 'S':
				printf ("You picked sausage\n");
				cNext = '2'; //update to show at least 1 topping was picked
			   *pSausageCnt += 1; //update sausage count
				
				//compute according to pizza size
				switch (cCrustSize) {
					case 's':
					case 'S':
					   *pSausagePrice += SAUSAGE_PRICE;
						break;
					case 'm':
					case 'M':
					   *pSausagePrice += SAUSAGE_PRICE * 1.5;
						break;
					case 'l':
					case 'L':
					   *pSausagePrice += SAUSAGE_PRICE * 1.75;
						break;
				}
				break;	
			//for cheese
			case 'c':
			case 'C':
				printf ("You picked cheese\n");
				cNext = '2'; //update to show at least 1 topping was picked
			   *pCheeseCnt += 1; //update cheese count
				
				//compute according to pizza size
				switch(cCrustSize) {
					case 's':
					case 'S':
					   *pCheesePrice += CHEESE_PRICE;
						break;
					case 'm':
					case 'M':
					   *pCheesePrice += CHEESE_PRICE * 1.5;
						break;
					case 'l':
					case 'L':
					   *pCheesePrice += CHEESE_PRICE * 1.75;
						break;
				}
				break;
			//for olives
			case 'o':
			case 'O':
				printf ("You picked olives\n");
				cNext = '2'; //update to show at least 1 topping was picked
				*pOlivesCnt += 1; //update olives count
				
				//compute according to pizza size
				switch (cCrustSize) {
					case 's':
					case 'S':
					   *pOlivesPrice += OLIVES_PRICE;
						break;
					case 'm':
					case 'M':
					   *pOlivesPrice += OLIVES_PRICE * 1.5;
						break;
					case 'l':
					case 'L':
					   *pOlivesPrice += OLIVES_PRICE * 1.75;
						break;
				}
				break;
			//to stop picking toppings
			case 'n':
			case 'N':
				//n or N is invalid if at least 1 topping has not been picked
				if (cNext == '0') {
					printf("Invalid key\n");
					printf("Choose at least 1 topping first\n");
				} else 
					cNext = '1'; //update variable to end the loop
				break;
		}
		//display additional instructions if at least 1 topping has been picked
		if (cNext == '2') {
			printf ("\n");
			printf ("Enter [n] or [N] when done\n");
			printf ("Otherwise, keep choosing toppings:\n");
		}
	//continue to ask for toppings if order is not cancelled
	//or if user has not yet finished picking toppings				
	} while (cNext != '1' && 
			*pStop != 'x');
	
	//compute for total cost of chosen toppings
	fToppingsPrice = *pHamPrice + *pPineapplePrice +
					 *pSausagePrice + *pCheesePrice +
					 *pOlivesPrice;
	
	//return total cost of chosen toppings
	return fToppingsPrice;
}

/*	This function determines the type of cheese
	and may repeatedly ask depending on the amount
	of cheese topping picked
	
	function keeps asking for input until valid keys
	m,M,g,G,f,F,p,P are entered
	
	Precondition: user input or cCheeseType must be
				  a char where only m,M,g,G,f,F,p,P
				  are the valid keys to proceed and
				  x,X to cancel the order
	@param *pMozCnt is the amount of Mozzarella toppings
	@param *pGorCnt is the amount of Gorgonzola toppings
	@param *pFonCnt is the amount of Fontina toppings
	@param *pParCnt is the amount of Parmesan toppings
	@param nCheeseCnt is the amount of Cheese toppings
	@param *pStop determines if the order should be cancelled
*/
void 
chooseCheeseType (int   *pMozCnt, 
				  int   *pGorCnt, 
				  int   *pFonCnt, 
				  int   *pParCnt, 
				  int    nCheeseCnt, 
				  char  *pStop)
{
	//variable declaration
	int i;
	char cCheeseType;
	
	//display instructions
	printf ("Pick the type of cheese:\n");
	printf ("Enter [m] or [M] for mozzarella\n");
	printf ("Enter [g] or [G] for gorgonzola\n");
	printf ("Enter [f] or [F] for fontina\n");
	printf ("Enter [p] or [P] for parmesan\n");
	printf ("You may choose the same topping ");
	printf ("more than once,\n");
	printf ("if you added more than 1 cheese topping\n");
	
	/*	ask for type of cheese depending on the amount
		of chosen cheese toppings
	*/
	for (i = 0; i < nCheeseCnt; i++) {
			scanf (" %c", &cCheeseType);
		
		/*	show error message on invalid input 
			and ask user's choice again
		*/
		while (cCheeseType != 'm' && 
				cCheeseType != 'M' &&
				cCheeseType != 'g' && 
				cCheeseType != 'G' &&
				cCheeseType != 'f' && 
				cCheeseType != 'F' &&
				cCheeseType != 'p' && 
				cCheeseType != 'P' &&
				cCheeseType != 'x' && 
				cCheeseType != 'X') {
					printf("Invalid key\n");
					scanf(" %c", &cCheeseType);
		}
		
		//display user's choice
		//update amount of toppings if input is valid
		switch (cCheeseType) {
			case 'm':
			case 'M':
				printf ("You chose mozzarella\n");
			   *pMozCnt += 1;
				break;
			case 'g':
			case 'G':
				printf ("You chose gorgonzola\n");
			   *pGorCnt += 1;
				break;
			case 'f':
			case 'F':
				printf ("You chose fontina\n");
			   *pFonCnt += 1;
				break;
			case 'p':
			case 'P':
				printf ("You chose parmesan\n");
			   *pParCnt += 1;
				break;
			case 'x':
			case 'X':
				printf ("You cancelled the order\n");
			   *pStop = 'x'; //update pointer to show order was cancelled
				printf ("\n**********\n");
				break;
		}
	}
}					  

/*	This function determines if user wants 
	additional crust stuffing and what type
	if thick crust is picked at the start
	of the vending machine program
	
	This function computes the additional cost
	depending on the choice of stuffing
   
	Precondition: User must have picked thick crust 
				  to call this function 
				  User can only enter char values where
				  c,C,s,S,b,B are valid keys and 
				  n,N to skip this program
	@param *pCheeseStuffingCost is the total cost of
			cheese stuffing
	@param *pSpamStuffingCost is the total cost of
			spam stuffing
	@param *pCheeseSpamStuffingCost is the total cost
			of both cheese and spam stuffing
	@param *pStop determines if order is cancelled
			or if it equals to x
	@return the type of crust stuffing or if user
			chooses not to add additional crust stuffing
*/				  
char				  
chooseStuffing (float *pCheeseStuffingCost, 
				float *pSpamStuffingCost,
			   	float *pCheeseSpamStuffingCost, 
			   	char  *pStop)
{
	//variable declaration
	char cStuffing;
	
	//display instructions
	printf ("Do you want additional crust stuffing?\n");
	printf ("Enter [c] or [C] for cheese stuffing\n");
	printf ("Enter [s] or [S] for spam stuffing\n");
	printf ("Enter [b] or [B] for both "); 
	printf ("cheese and spam stuffing\n");
	printf ("Enter [n] or [N] if no\n");
	
	//ask user's choice
	scanf (" %c", &cStuffing);
	
	/*	show error message if invalid input 
		is entered and ask again
	*/
	while (cStuffing != 'c' && 
			cStuffing != 'C' &&
			cStuffing != 's' && 
			cStuffing != 'S' &&
			cStuffing != 'b' && 
			cStuffing != 'B' &&
			cStuffing != 'n' && 
			cStuffing != 'N' &&
			cStuffing != 'x' && 
			cStuffing != 'X') {
				printf ("Invalid key\n");
				scanf (" %c", &cStuffing);
	}
	
	//display user's choice and update cost of order
	switch (cStuffing) {
		case 'c':
		case 'C':
			printf ("You chose cheese stuffing\n");
		   *pCheeseStuffingCost += CHEESESTUFFING_PRICE;
			break;
		case 's':
		case 'S':
			printf ("You chose spam stuffing\n");
		   *pSpamStuffingCost += SPAMSTUFFING_PRICE;
			break;
		case 'b':
		case 'B':
			printf ("You chose both cheese and spam stuffing\n");
		   *pCheeseSpamStuffingCost = CHEESESPAMSTUFFING_PRICE;
			break;
		case 'n':
		case 'N':
			printf ("You chose not to add any crust stuffing\n");
			break;
		case 'x':
		case 'X':
			printf ("You cancelled the order\n");
			printf ("\n**********\n");
		   *pStop = 'x'; //update pointer to show order was cancelled
			break;
	}
	
	//return user's choice of stuffing
	return cStuffing;
}
			
/*	This function simulates a physical payment situation
	that determines the bills inserted by the user:
	1 for 1000, 2 for 500, 3 for 100, 4 for 50,
	5 for 20, 6 for 10, 7 for 5, 8 for 1,
	9 for 0.25, 10 for 0.10, 11 for 0.05,
	12 for 0.01

	This function determines if dispensing
	change is applicable and calls the function
	responsible for dispensing change
	
	Precondition: integers from 0 to 12 to proceed 
	@param fTotal is the total cost of the order
	@param *pExit determines if order is cancelled
			or if it equals to x
	@param *pChange is the bill's change
*/		  
void
insertPayment (float  fTotal, 
			   int 	 *pExit,
			   float *pChange)
{ 
//variable declaration
	int nPayment;
	int BILLS[12] = {1, 2, 3, 4, 
					 5, 6, 7, 8, 9, 
					 10, 11, 12};
	float fUserPayment = 0; //reset to default value
	
	printf ("Enter [0] to cancel the order\n");
	printf ("Enter [1] to insert 1000\n");
	printf ("Enter [2] to insert 500\n");
	printf ("Enter [3] to insert 100\n");
	printf ("Enter [4] to insert 50\n");
	printf ("Enter [5] to insert 20\n");
	printf ("Enter [6] to insert 10\n");
	printf ("Enter [7] to insert 5\n");
	printf ("Enter [8] to insert 1\n");
	printf ("Enter [9] to insert 0.25\n");
	printf ("Enter [10] to insert 0.10\n");
	printf ("Enter [11] to insert 0.05\n");
	printf ("Enter [12] to insert 0.01\n");

	do {
		scanf ("%d", &nPayment);
		
		while (nPayment != 0 && 
				nPayment != BILLS[1] && 
			  	nPayment != BILLS[2] && 
			  	nPayment != BILLS[3] && 
			  	nPayment != BILLS[4] && 
				nPayment != BILLS[5] &&
		  	  	nPayment != BILLS[6] && 
				nPayment != BILLS[7] && 
			  	nPayment != BILLS[8] && 
				nPayment != BILLS[9] && 
			  	nPayment != BILLS[10] && 
				nPayment != BILLS[11] &&
		  	  	nPayment != BILLS[12] &&
				nPayment != 80808) {
					printf ("Invalid key\n");
					scanf ("%d", &nPayment);
		}
		
		//proceed if user did not cancel order
		if (nPayment != 0) {
			switch (nPayment) {
				case 1: //for Php 1000
					fUserPayment += 1000;
					break;
				case 2: //for Php 500
					fUserPayment += 500;
					break;
				case 3: //for Php 100
					fUserPayment += 100;
					break;
				case 4: //for Php 50
					fUserPayment += 50;
					break;
				case 5: //for Php 20
					fUserPayment += 20;
					break;
				case 6: //for Php 10
					fUserPayment += 10;
					break;
				case 7: //for Php 5
					fUserPayment += 5;
					break;
				case 8: //for Php 1
					fUserPayment += 1;
					break;
				case 9: //for Php 0.25
					fUserPayment += 0.25;
					break;
				case 10: //for Php 0.10
					fUserPayment += 0.10;
					break;
				case 11: //for Php 0.05
					fUserPayment += 0.05;
					break;
				case 12: //for Php 0.01
					fUserPayment += 0.01;
					break;
				case 80808: //if user entered maintenance code
				   *pExit = nPayment; //update pointer to maintenance code
					printf ("System is undergoing maintenance\n");
					break;
			}
			
			//proceed if user did not enter maintenance code
			if (*pExit != 80808) {
					printf ("You inserted a total of %.2f\n", 
							fUserPayment);
					
					//compute for change if applicable
					if (fUserPayment > fTotal) {
							printf ("\n**********\n");
							printf ("Dispensing change:\n");
		
							*pChange = getChange(fUserPayment, 
										 fTotal);
					}
			}
		
		//do not proceed if order was cancelled					
		} else {
		   *pExit = 1; //update pointer to show order cancellation 
			printf ("You cancelled the order\n");
			printf ("\n**********\n");
		}
			
	//ask user to insert payment until total cost is reached
	//or if user cancels order or executes maintenance code
	} while (fTotal > fUserPayment && 
			 nPayment != 0 &&
			*pExit != 80808);
}

/* This function displays and computes for the change
   that will be dispensed by the machine/program
   with the least amount of bills
   
   Precondition: fUserPayment is a positive integer 
   				 larger than fTotal that is also
   				 a positive integer
	@param fUserPayment is the payment given by the user
	@param fTotal is the total cost of the order
	@return is the total change computed
*/
float
getChange (float fUserPayment,  
		   float fTotal)
{
	//variable declaration
	int n1000,
		n500,
		n100,
		n50,
		n20,
		n10,
		n5,
		n1;
		
	float f025,
		  f010,
		  f005,
		  f001;
		  
	float fChange;
	
	//compute for change to be dispensed
	fUserPayment -= fTotal;
   	fChange = fUserPayment;
		
	//compute for least amount of bills
	if (fUserPayment >= 1000) {
			n1000 = fUserPayment / 1000;
			fUserPayment -= n1000 * 1000;
			printf ("%d - Php 1000\n", n1000); //count Php 1000
	}
		
	if (fUserPayment >= 500) {
			n500 = fUserPayment / 500;
			fUserPayment -= n500 * 500;
			printf ("%d - Php 500\n", n500); //count Php 500
	}
		
	if (fUserPayment >= 100) {
			n100 = fUserPayment / 100;
			fUserPayment -= n100 * 100;
			printf ("%d - Php 100\n", n100); //count Php 100
	}
		
	if (fUserPayment >= 50) {
			n50 = fUserPayment / 50;
			fUserPayment -= n50 * 50;
			printf ("%d - Php 50\n", n50); //count Php 50
	}
		
	if (fUserPayment >= 20) {
			n20 = fUserPayment / 20;
			fUserPayment -= n20 * 20;
			printf ("%d - Php 20\n", n20); //count Php 20
	}
		
	if (fUserPayment >= 10) {
			n10 = fUserPayment / 10;
			fUserPayment -= n10 * 10;
			printf ("%d - Php 10\n", n10); //count Php 10
	}
		
	if (fUserPayment >= 5) {
			n5 = fUserPayment / 5;
			fUserPayment -= n5 * 5;
			printf ("%d - Php 5\n", n5); //count Php 5
	}
		
	if (fUserPayment >= 1) {
			n1 = fUserPayment;
			fUserPayment -= n1;
			printf ("%d - Php 1\n", n1); //count Php 1
	}
		
	if (fUserPayment >= 0.25) {
			f025 = fUserPayment / 0.25;
			fUserPayment -= f025 * 0.25;
			printf ("%.0f - Php 0.25\n", f025); //count Php 0.25
	}
		
	if (fUserPayment >= 0.10) {
			f010 = fUserPayment / 0.10;
			fUserPayment -= f010 * 0.10;
			printf ("%.0f - Php 0.10\n", f010); //count 0.10
	}
		
	if (fUserPayment >= 0.05) {
			f005 = fUserPayment / 0.05;
			fUserPayment -= f005 * 0.05;
			printf ("%.0f - Php 0.05\n", f005); //count 0.05
	}
		
	if (fUserPayment >= 0.01) {
			f001 = fUserPayment / 0.01;
			fUserPayment -= f001 * 0.01;
			printf ("%.0f - Php 0.01\n", f001); //count 0.01
	}
	
	//return computed change
	return fChange;
}

/* This function displays the receipt of the
	processing order
	
	Precondition: *pTransactionNumber, nCrustType, nPineappleCnt,
				  nSausageCnt, nCheeseCnt, nOlivesCnt, nHamCnt,
				  nMozCnt, nGorCnt, nFonCnt, nParCnt, fCrustSizePrice,
				  fHamPrice, fPineapplePrice, fSausagePrice, fCheesePrice,
				  fOlivesPrice, fCheeseStuffingCost, fTotal, and fChange
				  are non-negative values
	@param *pTransactionNumber is the transaction number
	@param nCrustType is the type of crust: 1 for thin, 2 for thick
	@param nPineappleCnt is the amount of pineapple toppings
	@param nSausageCnt is the amount of sausage toppings
	@param nCheeseCnt is the amount of cheese toppings
	@param nOlivesCnt is the amount of olives toppings
	@param nHamCnt is the amount of ham toppings
	@param nMozCnt is the amount of Mozzarella toppings
	@param nGorCnt is the amount of Gorgonzola toppings
	@param nFonCnt is the amount of Fontina toppings
	@param nParCnt is the amount of Parmesan toppings
	@param fCrustSizePrice is the cost of the crust size
	@param fHamPrice is the cost of the ham toppings
	@param fPineapplePrice is the cost of pineapple toppings
	@param fSausagePrice is the cost of sausage toppings
	@param fCheesePrice is the cost of cheese toppings
	@param fOlivesPrice is the cost of olives toppings
	@param fCheeseStuffingCost is the cost of
			additional cheese stuffing
	@param fSpamStuffingCost is the cost of 
			additional spam stuffing
	@param fCheeseSpamStuffingCost is the cost of
			both additional cheese and spam stuffing
	@param fTotal is the total cost of the order
	@param fChange is the total change dispensed
	@param cStuffing is the type of additional stuffing
	@param cCrustSize is the size of the crust
*/
void 
displayReceipt (int  *pTransactionNumber, 
			    int   nCrustType, 
			    int   nPineappleCnt,
			    int   nSausageCnt, 
			    int   nCheeseCnt, 
			    int   nOlivesCnt, 
			    int   nHamCnt,
			    int   nMozCnt, 
			    int   nGorCnt, 
			    int   nFonCnt, 
			    int   nParCnt,
			    float fCrustSizePrice, 
			    float fHamPrice, 
			    float fPineapplePrice, 
			    float fSausagePrice, 
			    float fCheesePrice, 
			    float fOlivesPrice, 
			    float fCheeseStuffingCost, 
			    float fSpamStuffingCost,
			    float fCheeseSpamStuffingCost, 
			    float fTotal, 
			    float fChange,
			    char  cStuffing, 
			    char  cCrustSize)
{
	printf ("Transaction #%d\n", *pTransactionNumber);
	printf ("\n");
	
	//display type of crust and size
	switch (nCrustType) {
		case 1:
			printf ("1 \t Thin Crust (%c) ", 
					cCrustSize);
			break;
		case 2:
			printf("1 \t Thick Crust (%c) ", 
				   cCrustSize);
			break;
	}
	
	//display cost of crust size
	printf ("\t\t %.2f\n", fCrustSizePrice);
	
	//display type of toppings
	if (nHamCnt > 0)
			printf ("%d \t Ham \t\t\t\t %.2f\n", 
					nHamCnt, fHamPrice);
	if (nPineappleCnt > 0)
			printf ("%d \t Pineapple \t\t\t %.2f\n", 
					nPineappleCnt, fPineapplePrice);
	if (nSausageCnt > 0)
			printf ("%d \t Sausage \t\t\t %.2f\n", 
					nSausageCnt, fSausagePrice);
	if (nCheeseCnt > 0) {
			if(nMozCnt > 0) {
				printf ("%d \t Mozzarella \t\t\t ", 
				   		nMozCnt);
				   		
			//compute for cost of each type of cheese topping  
			cheeseBreakdown (cCrustSize);
		}	
	//display types of cheese chosen with their cost
	if (nGorCnt > 0) {
			printf ("%d \t Gorgonzola \t\t\t ", 
					nGorCnt);
					
			//compute for cost of each type of cheese topping     
			cheeseBreakdown (cCrustSize);
	}	
	if (nFonCnt > 0) {
			printf ("%d \t Fontina \t\t\t ", 
					nFonCnt);
					
			//compute for cost of each type of cheese topping  	   
			cheeseBreakdown (cCrustSize);
		}
	if(nParCnt > 0) {
			printf("%d \t Parmesan \t\t\t ", 
				   nParCnt);
				   
			//compute for cost of each type of cheese topping  	   
			cheeseBreakdown (cCrustSize);
		}
	}
	if (nOlivesCnt > 0)
			printf ("%d \t Olives \t\t\t %.2f\n", 
					nOlivesCnt, fOlivesPrice);
	
	//display stuffing if thick crust was picked
	//display their individual costs
	if (nCrustType == 2) {
		switch (cStuffing) {
			case 'c':
			case 'C':
				printf ("1 \t Cheese Stuffing ");
				printf ("\t\t %.2f\n", 
						fCheeseStuffingCost);
				break;
			case 's':
			case 'S':
				printf ("1 \t Spam Stuffing \t");
				printf ("\t\t %.2f\n", 
						fSpamStuffingCost);
				break;
			case 'b':
			case 'B':
				printf ("1 \t Cheese & Spam Stuffing \t ");
				printf ("%.2f\n", 
						fCheeseSpamStuffingCost);
				break;				
		}
	}
	
	printf ("\n");
	printf ("----------");
	printf ("----------");
	printf ("----------");
	printf ("----------");
	printf ("----------");
	printf ("\n");
	
	//display total cost and change given
	printf ("\t Total \t\t\t\t %.2f\n", 
			fTotal);
	printf ("\t Change \t\t\t %.2f\n", 
			fChange);
	
	//update transaction number after successful order
	*pTransactionNumber += 1;
}

/* This function computes and prints the cost of the
	individual cheese toppings according to the size
	of the crust
	
	@param cCrustSize is the size of the crust

*/
void 
cheeseBreakdown (char cCrustSize)
{
	switch (cCrustSize) {
		
		//for small
		case 's':
		case 'S':
			printf ("%.2f\n", 
					CHEESE_PRICE);
			break;
			
		//for medium
		case 'm':
		case 'M':
			printf ("%.2f\n", 
					CHEESE_PRICE * 1.5);
			break;
			
			//for large
		case 'l':
		case 'L':
			printf ("%.2f\n", 
					CHEESE_PRICE * 1.75);
			break;
	}
}

/* This function computes for the total time
	needed to bake the pizza and displays the
	countdown until it reaches 0

	@param nHamCnt is the amount of ham toppings
	@param nPineappleCnt is the amount of pineapple toppings
	@param nSausageCnt is the amount of sausage toppings
	@param nCheeseCnt is the amount of cheese toppings
	@param nOlivesCnt is the amount of olives toppings
	@param cStuffing is the type of additional stuffing
*/

void 
countdown (int  nHamCnt, 
		   int  nPineappleCnt, 
		   int  nSausageCnt,
		   int  nCheeseCnt, 
		   int  nOlivesCnt, 
		   char cStuffing)
{
	//variable declaration
	int nSeconds = 180; //3 minutes to bake pizza
	int nMinutes;
	int i, 
		j;
	
	//add 5 seconds for each additional stuffing
	switch (cStuffing) {
		case 'c':
		case 'C':
		case 's':
		case 'S':
			nSeconds += 5;
		//add 10 if cheese and spam stuffing were added
		case 'b':
		case 'B':
			nSeconds += 10;
	}
	
	//compute for total seconds needed to bake pizza
	nSeconds += nHamCnt * 2 + 
				nPineappleCnt * 2 + 
				nSausageCnt * 2 +
				nCheeseCnt * 2 + 
				nOlivesCnt * 2;
	
	nMinutes = nSeconds / 60;
	nSeconds %= 60;
	
	printf ("Pizza will be ready in\n");
	
	//display countdown
	for (i = nMinutes; i >= 0; i--) {
		for (j = nSeconds; j >= 0; j--)
		printf ("%02d:%02d\n", i, j);
		
		nSeconds = 59; 
	}
	
	printf ("\n");
	printf ("Done!\n");
	
	printf ("\n**********\n");
}		  
