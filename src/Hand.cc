#include "Hand.hh"

Hand::Hand(){
  hand.resize(0);
  sevenCardHand.resize(0);  
  bestHand.resize(0);
}

Hand::Hand(Deck * d){

  hand.resize(0);
  sevenCardHand.resize(0);  
  bestHand.resize(0);

  card1 = d->TakeCard();  
  card2 = d->TakeCard();  

  hand.push_back(card1);
  hand.push_back(card2);

}

Hand::~Hand(){
//  hand.resize(0);
}

void Hand::GetFirstCard(Deck * d){

  if(hand.size() == 0){
	card1 = d->TakeCard();
  	hand.push_back(card1);
  }
  else{
	card1 = hand.at(0);
  }
}

void Hand::GetSecondCard(Deck * d){

  if(hand.size() == 0)GetFirstCard(d);
  if(hand.size() == 1){
	card2 = d->TakeCard();
	hand.push_back(card2);
  }
  else{
	card2 = hand.at(1);
  }

}

Cards Hand::FullHand(Cards communityCards){

  sevenCardHand.resize(0);

  sevenCardHand.push_back(card1);
  sevenCardHand.push_back(card2);
  for(int i=0;i<communityCards.size();i++){
	sevenCardHand.push_back(communityCards.at(i));
  }

  return sevenCardHand;

}

//always will have this as a minimum
bool Hand::IsHighCard(){

  //clear best hand vector first
  bestHand.resize(0);

  //sort the sevenCardHand in order of card rank
  Utils::SortCardsByRankAscending(sevenCardHand);

  for(int i=sevenCardHand.size()-5;i<sevenCardHand.size();i++){
	//add the last five cards to best hand vector
	bestHand.push_back(sevenCardHand.at(i));
  }

  return true;
}

bool Hand::IsOnePair(){

  //clear best hand vector first
  bestHand.resize(0);

  bool found = false;

  Cards tempHand;
  Cards otherCards;

  //sort the sevenCardHand in order of card rank
  Utils::SortCardsByRankAscending(sevenCardHand);

  int pos = -1;
  int size = sevenCardHand.size();
  for(int i=0;i<size;i++){
	if(i<size-1){
	  if(sevenCardHand.at(i).GetRank() == sevenCardHand.at(i+1).GetRank()){
		found = true;
		tempHand.push_back(sevenCardHand.at(i));
		tempHand.push_back(sevenCardHand.at(i+1));
		if(pos==-1)pos =i;
		break;
	  }
	}
  }
  for(int i=0;i<size;i++){
	//add the 5 remaining cards
	if( (i==pos || i==(pos+1)) && found)continue;
	else{
	  //add the last five cards to best hand vector
	  otherCards.push_back(sevenCardHand.at(i));
	}
  }

  if(found){
	Utils::SortCardsByRankAscending(otherCards);

	for(int i=2;i<otherCards.size();i++){
	  tempHand.push_back(otherCards.at(i));
	}
	tempHand.swap(bestHand);
	return true;
  }
  else return false;
}

bool Hand::IsTwoPair(){

  //clear best hand vector first
  bestHand.resize(0);

  Cards tempHand;

  //sort the sevenCardHand in order of card rank
  Utils::SortCardsByRankAscending(sevenCardHand);

  bool foundOnePair = false;
  bool foundTwoPair = false;
  bool foundThreePair = false;

  int firstPos = -1;
  int secondPos = -1;
  int thirdPos = -1;
  
  int numberOfPairs = 0;

  //first loop over to count number of pairs
  int size = sevenCardHand.size();
  for(int i=0;i<size;i++){
	if(i<=size-3){
          if( (sevenCardHand.at(i).GetRank() == sevenCardHand.at(i+1).GetRank()) && (sevenCardHand.at(i).GetRank() != sevenCardHand.at(i+2).GetRank()) ){
		numberOfPairs++;
		if(numberOfPairs==1){
		  firstPos = i;
		  foundOnePair = true;
		}
		else if(numberOfPairs==2){
		  secondPos = i;
		  foundTwoPair = true;
		}
		else if(numberOfPairs==3){
		  thirdPos = i;
		  foundThreePair = true;
		}
          }
	  else if( i==size-2 && (sevenCardHand.at(i).GetRank() == sevenCardHand.at(i+1).GetRank()) ){
		numberOfPairs++;
		if(numberOfPairs==1){
		  firstPos = i;
		  foundOnePair = true;
		}
		else if(numberOfPairs==2){
		  secondPos = i;
		  foundTwoPair = true;
		}
		else if(numberOfPairs==3){
		  thirdPos = i;
		  foundThreePair = true;
		}
	  }
	}
  }

  if(numberOfPairs<2)return false;
  else{
	if(foundThreePair){
	  tempHand.push_back(sevenCardHand.at(thirdPos));
	  tempHand.push_back(sevenCardHand.at(thirdPos+1));
	  tempHand.push_back(sevenCardHand.at(secondPos));
	  tempHand.push_back(sevenCardHand.at(secondPos+1));
	}
	else{
	  tempHand.push_back(sevenCardHand.at(secondPos));
	  tempHand.push_back(sevenCardHand.at(secondPos+1));
	  tempHand.push_back(sevenCardHand.at(firstPos));
	  tempHand.push_back(sevenCardHand.at(firstPos+1));
	}

	Cards otherCards;
	for(int i=0;i<sevenCardHand.size();i++){
	  if(foundThreePair && (i!=secondPos || i!=secondPos+1 || i!=thirdPos || i!=thirdPos+1) )otherCards.push_back(sevenCardHand.at(i));
	  else if( (i!=firstPos || i!=firstPos+1 || i!=secondPos || i!=secondPos+1) && foundThreePair==false)otherCards.push_back(sevenCardHand.at(i));
	}
	
	//sort these to get the highest card
	Utils::SortCardsByRankAscending(otherCards);

	if(otherCards.size()>1)tempHand.push_back(otherCards.at(otherCards.size()-1));

        tempHand.swap(bestHand);
  	return true;
  }
}

bool Hand::IsThreeOfAKind(){
  return false;
}

bool Hand::IsStraight(){
  return false;
}

bool Hand::IsFlush(){
  return false;
}

bool Hand::IsFullHouse(){
  return false;
}

bool Hand::IsFourOfAKind(){
  return false;
}

bool Hand::IsStraightFlush(){
  return false;
}

void Hand::Fold(Deck * d){

  d->AddToDeck(card1);
  d->AddToDeck(card2);
  hand.resize(0);
  sevenCardHand.resize(0);  
}

void Hand::Print(){

  std::cout << "\n---Hand----";
  card1.Print();
  card2.Print();
  std::cout << "\n-----------" << std::endl;

}

void Hand::PrintBestHand(){

  std::cout << "\n--- TOP HAND ---";
  for(int i=0;i<bestHand.size();i++)bestHand.at(i).Print();
  std::cout << "\n----------------" << std::endl;
}

void Hand::SortByRank(Cards cardVector){

  Cards tempVector;

  for(int i=0;i<cardVector.size();i++){

	//add the first to the temp vector
	if(i==0){
	  tempVector.push_back(cardVector.at(0));
	  continue;
	}

	for(int j=0;j<tempVector.size();j++){

	  //is the card rank bigger than jth in vector
	  if(cardVector.at(i).GetRank() >= tempVector.at(j).GetRank()){
		//if the index is at the end then it must be the largest and so put at the end of vector
		if(j==tempVector.size()+1)tempVector.push_back(cardVector.at(i));
		continue;
	  }
	  //else it must be lower and because vector is in ascending order must be inserted at beginning of vector
	  else{
		tempVector.insert(tempVector.begin(), cardVector.at(i));
		j=tempVector.size();
	  }
	}
  }

  cardVector.swap(tempVector);

}
