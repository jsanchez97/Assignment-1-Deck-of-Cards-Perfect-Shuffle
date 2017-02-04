/******************************************************************************
* AUTHOR        : Jesus Sanchez
* STUDENT ID    : 1024834
* ASSIGNMENT #1 : Deck of Cards - Perfect Shuffle
* CLASS         : CS1C
* SECTION       : MW: 1:30pm
* DUE DATE      : 01/30/2017
* ****************************************************************************/

#ifndef PLAYINGCARD_H_
#define PLAYINGCARD_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/******************************************************************************
 * CONSTANTS
 * ----------------------------------------------------------------------------
 * MAX_CARDS - Total number of cards in the deck
 * MAX_SUITS - Number of suits
 * MAX_RANKS - Number of ranks per suit
 *****************************************************************************/
const int MAX_CARDS = 52;
const int MAX_SUITS = 4;
const int MAX_RANKS = 13;

enum Suits
{
	CLUBS, DIAMONDS, HEARTS, SPADES
};

enum LetterRank
{
	A, K, Q, J
};

class PlayingCard
{
	private:
		string suit; // Card Suit (Clubs, Diamonds, Hearts, or Spades)
		string rank; // Card Rank (A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2)

	public:
		/**********************************************************************
		 * PlayingCard
		 *    Default class constructor.
		 *********************************************************************/
		PlayingCard();

		/**********************************************************************
		 * PlayingCard
		 *    Class destructor.
		 *********************************************************************/
		~PlayingCard();

		/**********************************************************************
		 * LoadDeck
		 *    This function loads the standard deck and the shuffle deck to
		 *    their original state.
		 *********************************************************************/
		void LoadDeck(PlayingCard standardDeck[], PlayingCard shuffleDeck[]);

		/**********************************************************************
		 * PerfectShuffle
		 *    This function performs a perfect shuffle on the shuffle deck and
		 *    increments the shuffles variable to keep track of how many times
		 *    the deck is shuffled.
		 *********************************************************************/
		void PerfectShuffle(PlayingCard shuffleDeck[], int &shuffles);

		/**********************************************************************
		 * CompareDecks
		 *    This function compares the cards of the original deck and
		 *    shuffled deck to check to see if they are in the same order.
		 *********************************************************************/
		bool CompareDecks(PlayingCard originalDeck[], PlayingCard compDeck[]);

		/**********************************************************************
		 * PrintDeck
		 *    This function prints the current state of the deck.
		 *********************************************************************/
		void PrintDeck(PlayingCard outputDeck[]);
};

/*****************************************************************************
 * ConvertIntToString
 *    This function converts an integer to a string.
 ****************************************************************************/
string ConvertIntToString(int number);

#endif
