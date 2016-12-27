#ifndef UTILS_HH
#define UTILS_HH

#include "Card.hh"

namespace Utils{


  //functions to pass vector by reference, so sorts original
  void SortCardsByRankAscending(Cards& cardsUnsorted);
  void SortCardsByRankDescending(Cards& cardsUnsorted);
  void SortCardsBySuitAscending(Cards& cardsUnsorted);
  void SortCardsBySuitDescending(Cards& cardsUnsorted);

  //functions to return a new vector leaving the old one unsorted
  //Cards SortCardsByRankAscending(Cards cardsUnsorted);
  //Cards SortCardsByRankDescending(Cards cardsUnsorted);


}

#endif 
