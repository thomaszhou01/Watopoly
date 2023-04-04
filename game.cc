#include "game.h"

Game::Game(){
    
}

void Game::start(){
    game[0] = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3, 0, 0};
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
