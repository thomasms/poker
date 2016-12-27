#ifndef DECK_HH
#define DECK_HH 1

#include "vector"
#include <stdlib.h>

#include "Card.hh"

using namespace std;

class Deck{

  public:
	Deck();
	~Deck();

	Card TakeCard();	
	void AddToDeck(Card card)	{deck->push_back(card);};

	void Initialise();
	void NewDeck();
	void Shuffle();
	void Print();

  private:
	Cards * deck;

};
#endif
