#include "Play.hh"

Play::Play() : players(0){
  this->Init();
}

Play::~Play(){
  delete deck;
}

void Play::Init(){
  deck = new Deck();
  deck->NewDeck();
  deck->Shuffle();
  hands.resize(0);
  communityCards.resize(0);
}

void Play::ShowDeck(){
  deck->Print();
}

void Play::SetNumberOfPlayers(int p){
	players = p;
}

void Play::Deal(){

  hands.resize(0);
  communityCards.resize(0);

  //first card
  for(int i=0;i<players;i++){
	Hand currentHand;
	currentHand.GetFirstCard(deck);
	hands.push_back(currentHand);
  }
  //second card
  for(int i=0;i<players;i++){
	hands.at(i).GetSecondCard(deck);
	hands.at(i).Print();
  }


}

void Play::FoldAll(){
  
  //all fold
  for(int i=0;i<players;i++){
	hands.at(i).Fold(deck);
  }

  deck->AddToDeck(flop1);
  deck->AddToDeck(flop2);
  deck->AddToDeck(flop3);
  deck->AddToDeck(turn);
  deck->AddToDeck(river);

  //shuffle deck again
  ShuffleDeck();

}

void Play::ShuffleDeck(){

  for(int i=0;i<100000;i++){
	deck->Shuffle();
  }
}

void Play::Flop(){

  flop1 = deck->TakeCard();
  flop2 = deck->TakeCard();
  flop3 = deck->TakeCard();

  communityCards.push_back(flop1);
  communityCards.push_back(flop2);
  communityCards.push_back(flop3);

  std::cout << "\n====== FLOP =========";
  flop1.Print();
  flop2.Print();
  flop3.Print();
  std::cout << "\n=====================" << std::endl;

}

void Play::Turn(){

  turn = deck->TakeCard();

  communityCards.push_back(turn);

  std::cout << "\n====== TURN =========";
  turn.Print();
  std::cout << "\n=====================" << std::endl;

}

void Play::River(){

  river = deck->TakeCard();

  communityCards.push_back(river);

  std::cout << "\n====== RIVER ========";
  river.Print();
  std::cout << "\n=====================" << std::endl;

}

void Play::Showdown(){

  // loop over players
  for(int player=0;player<players;player++){

	//add the community cards to the hand to give the full hand - seven cards
	Cards fullHand = hands.at(player).FullHand(communityCards);

	//find the best hand 5 out of 7 possible cards
	if(hands.at(player).IsStraightFlush()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Straight Flush!!! " <<std::endl;
	}
	else if(hands.at(player).IsFourOfAKind()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Four of a Kind!! " <<std::endl;
	}
	else if(hands.at(player).IsFullHouse()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Full House! " <<std::endl;
	}
	else if(hands.at(player).IsFlush()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Flush. " <<std::endl;
	}
	else if(hands.at(player).IsStraight()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Straight. " <<std::endl;
	}
	else if(hands.at(player).IsThreeOfAKind()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Three of a Kind. " <<std::endl;
	}
	else if(hands.at(player).IsTwoPair()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Two Pair. " <<std::endl;
	}
	else if(hands.at(player).IsOnePair()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> Pair. " <<std::endl;
	}
	else if(hands.at(player).IsHighCard()){
		hands.at(player).PrintBestHand();
		std::cout << " ===> High Card. " <<std::endl;
	}

  }  


}
