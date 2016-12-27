#ifndef CARD_HH
#define CARD_HH 1

#include <iostream>
#include <iomanip> 
#include "vector"

using namespace std;

enum rank_t{ Two , Three , Four , Five , Six , Seven , Eight , Nine, Ten , Jack , Queen , King , Ace, rank_end, NoRank };
enum suit_t{ Clubs, Diamonds , Hearts , Spades , suit_end, NoSuit };

class Card{

  public:
	Card();
	Card(int r,int s);
	Card(string r,string s);
	~Card();

	int GetSuit() const		{return suit;};
	void SetSuit(int s)		{suit = s;};
	int GetRank() const		{return rank;};
	void SetRank(int r)		{rank = r;};

	int GetID() const		{return thisID;};
	void SetID(int id)		{thisID =id;};

	static void ResetCount()	{int count = 0;};

	void Blank();
	void Print();

  private: 
	int suit;
	int rank;

	string suitAsString;
	string rankAsString;

	static int count;
	int thisID;
};

typedef vector<Card> Cards;

#endif
