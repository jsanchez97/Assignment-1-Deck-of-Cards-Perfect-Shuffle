/******************************************************************************
* AUTHOR        : Jesus Sanchez
* STUDENT ID    : 1024834
* ASSIGNMENT #1 : Deck of Cards - Perfect Shuffle
* CLASS         : CS1C
* SECTION       : MW: 1:30pm
* DUE DATE      : 01/30/2017
* ****************************************************************************/

#include "PlayingCard.h"

/******************************************************************************
 * DECK OF CARDS - PERFECT SHUFFLE
 *-----------------------------------------------------------------------------
 * This program will use a PlayingCard class in order to create a standardDeck
 * array. This class will include methods to initialize the deck with the
 * appropriate card suit and rank. After the deck is initialized, the program
 * will perform a perfect shuffle on the deck and continue to do this until the
 * deck is shuffled into its original state. The program will also output the
 * original deck, the deck after the first perfect shuffle, and the final deck,
 * as well as how many perfect shuffles it takes to get the deck back to its
 * original state.
 *-----------------------------------------------------------------------------
 * INPUTS:
 *    There are no inputs.
 *
 * OUTPUTS:
 *    standardDeck - Array of PlayingCard objects representing a standard deck.
 *    shuffleDeck  - Array of PlayingCard objects representing the deck after
 *    				 each shuffle.
 *****************************************************************************/

/******************************************************************************
 * PrintHeader
 *    This function outputs the project print header.
 *****************************************************************************/
void PrintHeader (string labName, char labType, int labNum);

int main()
{
	PlayingCard card;

	PlayingCard standardDeck[MAX_CARDS]; // Initial state of the deck
	PlayingCard shuffleDeck[MAX_CARDS];  // Deck to be shuffled

	int numShuffles = 0; // CALC - Perfect shuffles necessary to reset deck

	PrintHeader ("Deck of Cards - Perfect Shuffle", 'A', 1);

	// Loads the standard deck and the shuffle deck to the initial state.
	card.LoadDeck(standardDeck, shuffleDeck);

	// Outputs the original state of the deck.
	cout << "Here is the deck in its original state:\n";
	card.PrintDeck(standardDeck);

	// Performs the first perfect shuffle on the shuffle deck and prints the
	// new order of the cards.
	cout << "\nHere is the deck after the first perfect shuffle:\n";
	card.PerfectShuffle(shuffleDeck, numShuffles);
	card.PrintDeck(shuffleDeck);

	// Performs a perfect shuffle on the shuffle deck until it is the same as
	// the initial deck.
	while(!card.CompareDecks(standardDeck, shuffleDeck))
	{
		card.PerfectShuffle(shuffleDeck, numShuffles);
	}

	// Outputs the shuffle deck again once it has been perfect shuffled back to
	// the initial state.
	cout << "\nHere is the final deck:\n";
	card.PrintDeck(shuffleDeck);

	// Outputs the number of perfect shuffles it takes to revert the deck to
	// its original state.
	cout << "\nIt took " << numShuffles << " perfect shuffles to reset the "
		 << "deck to its original state.";

	return 0;
}

/******************************************************************************
 * PrintHeader
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      labName: Lab Name has to be preciously defined
 *      labType: Lab Type has to be preciously defined
 *      labNum: Lab Number has to be preciously defined
 *
 * POST-CONDITIONS
 *       This function will output the class heading.
 *****************************************************************************/
void PrintHeader (string labName, char labType, int labNum)
{
	cout << left;
	cout << "***************************************************\n";
	cout << "* PROGRAMMED BY  : Jesus Sanchez";
	cout << "\n* " << setw(15) << "STUDENT ID" << ": 1024834" ;
	cout << "\n* " << setw(15) << "CLASS" << ": MW: 1:30pm - 2:50pm";
	cout << "\n* ";

	if(toupper(labType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}

	cout << labNum << " : " << labName;
	cout << "\n***************************************************\n\n";
	cout << right;
}
