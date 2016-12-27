#include "Game.hh"

Game::Game(){
}

Game::Game(int players){
  play.SetNumberOfPlayers(players);
  //play.ShowDeck();

  play.ShuffleDeck();

}

Game::~Game(){
}

void Game::Go(int rounds){

  for(int i=0;i<rounds;i++){
	std::cout << "\n********************************"
		  << "\n	   ROUND " << i
                  << "\n********************************" <<std::endl; 

	Round();
  }

}

void Game::Round(){
  //play.ShowDeck();
  play.Deal();

  //add the flop
  play.Flop();

  //add the turn
  play.Turn();

  //add the River
  play.River();

  play.Showdown();

  play.FoldAll();
}

