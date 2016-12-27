#ifndef PLAY_HH 
#define PLAY_HH 1

#include "Deck.hh"
#include "Hand.hh"

class Play{

 public:
   Play();
   ~Play();

   void Init();
   void Deal();
   void FoldAll();

   void Flop();
   void Turn();
   void River();
   void Showdown();

   void ShowDeck();
   void ShuffleDeck();

   void SetNumberOfPlayers(int players);

 private:

   Deck * deck;
   std::vector<Hand> hands;
   Cards communityCards;

   Card flop1,flop2,flop3;
   Card turn,river;

   int players; 
};

#endif
