#include "TRandom3.h"

#include "Deck.hh"

Deck::Deck(){

  deck = new Cards;

}

Deck::~Deck(){
  delete deck;

}

//set all the cards into the deck
void Deck::Initialise(){

  //clear the deck
  deck->resize(0);

  rank_t rank;
  suit_t suit;

  //add the 52 cards
  for(int i= Clubs;i!=suit_end;i++){
  	for(int j =Two;j!=rank_end;j++){
		Card card(j,i);
		deck->push_back(card);
		//std::cout << "\ncard.rank: " << card.GetRank() << ", card.suit: " << card.GetSuit();
	}
  }

  //std::cout << "\nNew deck contains " << deck->size() << " cards." <<std::endl;

}

void Deck::NewDeck(){
  Initialise();
}

void Deck::Shuffle(){

   TRandom3 rand;
   rand.SetSeed(0); 

   Cards newDeck;
   Card::ResetCount();

   int counter = 1;
   while(deck->size()>0){

	int position = (int)(rand.Rndm()*deck->size());
	Card card(deck->at(position));
	card.SetID(counter++);
	newDeck.push_back(card);
	deck->erase(deck->begin()+position);
   }

   deck->swap(newDeck);

}

Card Deck::TakeCard(){

  Card c = deck->at(deck->size()-1);
  deck->pop_back();

  return c;

}

void Deck::Print(){
  for(int i=0;i<deck->size();i++){
        deck->at(i).Print();
  }
  std::cout << std::endl;
}
