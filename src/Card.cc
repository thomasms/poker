#include "Card.hh"

using namespace std;

int Card::count = 0;

Card::Card(){
  thisID = count;
  count++;

  rank = Ace;
  suit = Spades;	

}

Card::Card(int r,int s){
  thisID = count;
  count++;

  rank = r;
  suit = s;

}

Card::~Card(){
}

void Card::Blank(){
  rank = NoRank;
  suit = NoSuit;

}

void Card::Print(){

  if(rank == Ace)rankAsString = "Ace";
  if(rank == Two)rankAsString = "2";
  if(rank == Three)rankAsString = "3";
  if(rank == Four)rankAsString = "4";
  if(rank == Five)rankAsString = "5";
  if(rank == Six)rankAsString = "6";
  if(rank == Seven)rankAsString = "7";
  if(rank == Eight)rankAsString = "8";
  if(rank == Nine)rankAsString = "9";
  if(rank == Ten)rankAsString = "10";
  if(rank == Jack)rankAsString = "Jack";
  if(rank == Queen)rankAsString = "Queen";
  if(rank == King)rankAsString = "King";

  if(rank == NoRank)rankAsString = "None";

  if(suit == Clubs)suitAsString = "Clubs";
  if(suit == Diamonds)suitAsString = "Diamonds";
  if(suit == Hearts)suitAsString = "Hearts";
  if(suit == Spades)suitAsString = "Spades";

  if(suit == NoSuit)suitAsString = "None";

  if(count==0)cout<< "\n="<<setfill('=') << setw(10) << "=" <<endl;
  cout << "\nCard " << thisID << ": " << rankAsString.substr(0,1) << suitAsString.substr(0,1);
  if(thisID+1==count)cout<< endl<<setfill('=') << setw(10) << "=" <<endl;

}
