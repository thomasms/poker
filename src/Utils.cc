#include "Utils.hh"

namespace Utils{

 void SortCardsByRankAscending(Cards & cardsUnsorted){

  Cards cardsSorted;
  cardsSorted.resize(0);
  
  //sort them 
  for(int i=0;i<cardsUnsorted.size();i++){

        int rankToCompare = cardsUnsorted.at(i).GetRank();
        //add the first as its an empty vector to begin with
        if(i==0){
                cardsSorted.push_back(cardsUnsorted.at(i));
                continue;
        }

        for(int j=0;j<cardsSorted.size();j++){
                if(rankToCompare > cardsSorted.at(j).GetRank()){
                        if(j==cardsSorted.size()-1){
                                cardsSorted.push_back(cardsUnsorted.at(i));
                                break;
                        }
                        else continue;
                }
                else{
                        cardsSorted.insert(cardsSorted.begin() +j,cardsUnsorted.at(i));
                        break;
                }
        }

  }

  //swap cardsSorted vector contents with cardsUnsorted
  cardsSorted.swap(cardsUnsorted);
 

 }

 void SortCardsByRankDesending(Cards & cardsUnsorted){

  Cards cardsSorted;
  cardsSorted.resize(0);
  
  //sort them 
  for(int i=0;i<cardsUnsorted.size();i++){

        int rankToCompare = cardsUnsorted.at(i).GetRank();
        //add the first as its an empty vector to begin with
        if(i==0){
                cardsSorted.push_back(cardsUnsorted.at(i));
                continue;
        }

        for(int j=0;j<cardsSorted.size();j++){
                if(rankToCompare < cardsSorted.at(j).GetRank()){
                        if(j==cardsSorted.size()-1){
                                cardsSorted.push_back(cardsUnsorted.at(i));
                                break;
                        }
                        else continue;
                }
                else{
                        cardsSorted.insert(cardsSorted.begin() +j,cardsUnsorted.at(i));
                        break;
                }
        }

  }

  //swap cardsSorted vector contents with cardsUnsorted
  cardsSorted.swap(cardsUnsorted);
 

 }
 void SortCardsBySuitAscending(Cards & cardsUnsorted){

  Cards cardsSorted;
  cardsSorted.resize(0);
  
  //sort them 
  for(int i=0;i<cardsUnsorted.size();i++){

        int suitToCompare = cardsUnsorted.at(i).GetSuit();
        //add the first as its an empty vector to begin with
        if(i==0){
                cardsSorted.push_back(cardsUnsorted.at(i));
                continue;
        }

        for(int j=0;j<cardsSorted.size();j++){
                if(suitToCompare > cardsSorted.at(j).GetSuit()){
                        if(j==cardsSorted.size()-1){
                                cardsSorted.push_back(cardsUnsorted.at(i));
                                break;
                        }
                        else continue;
                }
                else{
                        cardsSorted.insert(cardsSorted.begin() +j,cardsUnsorted.at(i));
                        break;
                }
        }

  }

  //swap cardsSorted vector contents with cardsUnsorted
  cardsSorted.swap(cardsUnsorted);
 
 }

}
