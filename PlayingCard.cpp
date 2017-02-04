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
 * PlayingCard
 * ----------------------------------------------------------------------------
 * Class default constructor. Initializes private data members to empty strings.
 *****************************************************************************/
PlayingCard::PlayingCard()
{
	suit = "";
	rank = "";
} // end of PlayingCard

/******************************************************************************
 * ~PlayingCard
 * ----------------------------------------------------------------------------
 * Class destructor.
 *****************************************************************************/
PlayingCard::~PlayingCard()
{

} // end of ~PlayingCard

/******************************************************************************
 * LoadDeck
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *     standardDeck - The cards in the standard deck do not have to be
 *     				  previously defined.
 *     shuffleDeck  - The cards in the deck to be shuffled do not have to be
 *     				  previously defined.
 * POST-CONDITIONS:
 *      This function will load the original deck and the shuffle deck to their
 *      original state.
 *****************************************************************************/
void PlayingCard::LoadDeck(PlayingCard standardDeck[], PlayingCard shuffleDeck[])
{
	int suitIndex = 0;  // Current suit being accessed
	int rankIndex = 0;  // Current index of each card in the suit
	int numRank   = 10; // Number rank of each card in the suit starting after J

	for(int index = 0; index < MAX_CARDS; index++)
	{
		// Resets the suitIndex and numRank when the next suit is reached and
		// increments the suit.
		if(rankIndex == MAX_RANKS)
		{
			rankIndex = 0;
			numRank   = 10;
			suitIndex++;
		}

		// Assigns the appropriate suit to the cards in the deck.
		switch(suitIndex)
		{
			case CLUBS    : standardDeck[index].suit = "Clubs";
					        break;
			case DIAMONDS : standardDeck[index].suit = "Diamonds";
					        break;
			case HEARTS   : standardDeck[index].suit = "Hearts";
					        break;
			case SPADES   : standardDeck[index].suit = "Spades";
		}

		// Assigns the appropriate rank to each card in the suit.
		if(rankIndex <= J)
		{
			// Assigns the letter ranks to the first 4 cards in each of the suits
			switch(rankIndex)
			{
				case A : standardDeck[index].rank = "A";
						 break;
				case K : standardDeck[index].rank = "K";
						 break;
				case Q : standardDeck[index].rank = "Q";
						 break;
				case J : standardDeck[index].rank = "J";
			}
		}
		else
		{
			// Converts numRank to a string to represent the numerical rank of the card.
			standardDeck[index].rank = ConvertIntToString(numRank);

			numRank--;
		}

		rankIndex++;

		// Makes the shuffle deck and the original deck the same before the first shuffle
		shuffleDeck[index] = standardDeck[index];
	}
} // end of LoadDeck

/******************************************************************************
 * PerfectShuffle
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *     shuffleDeck - The cards in the shuffle deck must be previously defined.
 *     shuffles    - The number of perfect shuffles must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function performs a perfect shuffle on the shuffle deck and
 *      increments the shuffles variable.
 *****************************************************************************/
void PlayingCard::PerfectShuffle(PlayingCard shuffleDeck[], int &shuffles)
{
	PlayingCard temp; // Holds the card to be moved after the index while
					  // all cards are shifted forward

	int midIndex = (MAX_CARDS / 2); // Index of the middle card in the deck.
	int shiftIndex;                 // Index that moves backwards in order to
									// shift all cards forward

	for(int index = 0; index < MAX_CARDS; index += 2)
	{
		shiftIndex = midIndex;

		// Stores the value in the middle of the deck in a temporary location
		temp = shuffleDeck[midIndex];

		// Moves every class object to the next highest index to make room for
		// the temp variable to be placed one index after the current index.
		while(shiftIndex > index)
		{
			shuffleDeck[shiftIndex] = shuffleDeck[shiftIndex - 1];

			shiftIndex--;
		}

		// Stores the object in the middle of the deck in the index after the
		// current index.
		shuffleDeck[index + 1] = temp;

		midIndex++;
	}

	// Increments the shuffles accumulator to show that the deck has been shuffled.
	shuffles++;
} // end of PerfectShuffle

/******************************************************************************
 * CompareDecks
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *     originalDeck - The cards in the original deck must be previously defined.
 *     compDeck     - The cards in the comparison deck must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will return true if all of the cards in both decks are in
 *      the same order.
 *****************************************************************************/
bool PlayingCard::CompareDecks(PlayingCard originalDeck[], PlayingCard compDeck[])
{
	int  index = 0;       // Index of the cards being compared.
	bool sameDeck = true; // Determines whether or not the decks are the same.

	// This while loop compares each of the cards in both decks until two cards
	// do not possess the same suit and rank.
	while(index < MAX_CARDS && sameDeck)
	{
		// Increments the index of the decks if the cards are the same.
		if((originalDeck[index].suit == compDeck[index].suit) &&
		   (originalDeck[index].rank == compDeck[index].rank))
		{
			index++;
		}
		else
		{
			sameDeck = false;
		}
	}

	return sameDeck;
} // end of CompareDecks

/******************************************************************************
 * PrintDeck
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *     outputDeck - The cards in the deck must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will output the cards in the deck that is passed in.
 *****************************************************************************/
void PlayingCard::PrintDeck(PlayingCard outputDeck[])
{
	int index = 0;

	// This for loop outputs the deck in 4 columns.
	for(int column = 0; column < MAX_RANKS; column++)
	{
		for (int row = 0; row < MAX_SUITS; row++)
		{
			// Ensures that every 13th card is printed in each row.
			index = column + (row * MAX_RANKS);

			cout << left
				 << setw(2) << outputDeck[index].rank << " of "
				 << setw(8) << outputDeck[index].suit << "   ";
		}

		cout << endl;
	}
} // end of PrintDeck

/******************************************************************************
 * ConvertIntToString
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *     number - The integer to be converted must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will convert an integer to a string.
 *****************************************************************************/
string ConvertIntToString(int number)
{
	stringstream convert;   // Stream holding the integer to be converted.
	string       numString; // Integer represented as a string.

	// Reads the integer into the stringstream.
	convert << number;

	// Stores the number in the stream in a string variable.
	numString = convert.str();

	return numString;
}
