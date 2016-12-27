#ifndef HAND_HH
#define HAND_HH

#include "Deck.hh"
#include "Utils.hh"

class Hand{

  public:
	Hand();
	Hand(Deck *d);
	~Hand();

	void Print();
	void PrintBestHand();
	void GetFirstCard(Deck * d);
	void GetSecondCard(Deck * d);
	void Fold(Deck *d);

	bool IsHighCard();
	bool IsOnePair();
	bool IsTwoPair();
	bool IsThreeOfAKind();
	bool IsStraight();
	bool IsFlush();
	bool IsFullHouse();
	bool IsFourOfAKind();
	bool IsStraightFlush();

	void SortByRank(Cards);

	Card * FirstCard()	{return &card1;};
	Card * SecondCard()	{return &card2;};

	std::vector<Card> FullHand(Cards communityCards);
	std::vector<Card> BestHand();

  private:
	Card card1;
	Card card2;

	Cards hand;
	Cards sevenCardHand;
	Cards bestHand;
	

};
#endif
