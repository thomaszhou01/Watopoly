#include "game.h"
#include "textDisplay.h"
#include "ownableProperty.h"
#include "unownableProperty.h"

// OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, int row, int col);
// UnownableProperty(std::string name, int position, int row, int col);
Game::Game(){
    game[0] = new UnownableProperty{"COLLECT OSAP", 0, 51, 81};
    game[1] = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 1, false, false, 2, 51, 73};
    game[2] = new UnownableProperty{"SLC", 2, 51, 65};
    game[3] = new OwnableProperty{"ML", "Arts1", 60, 50, {4,20,60,180,320,450}, 3, false, false, 2, 51, 57};
    game[4] = new UnownableProperty{"TUITION", 4, 51, 49};
    //game[] = new UnownableProperty{"", , , };
    //game[] = new OwnableProperty{"", "", , , {,,,,,}, , false, false, , , };

    //game[] = new OwnableProperty{"", "", , , {,,,,,}, , false, false, , , };
    //game[] = new UnownableProperty{"", , , };
}

void Game::start(){
    TextDisplay display{this, order};
    display.display();
}

int Game::getNumPlayers(){
    return numPlayers;
}

int Game::getPieces(){
    return pieces;
}

std::vector<BoardPiece *> Game::getGame(){
    return game;
}



