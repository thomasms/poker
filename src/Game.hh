#ifndef GAME_HH_
#define GAME_HH_

#include "Play.hh"

class Game{

  public:
    Game();
    Game(int players);
    ~Game();

   void Go(int rounds);
   void Round();
 

  private:
    Play play;

};

#endif
