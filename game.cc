#include "game.h"
#include "textDisplay.h"

Game::Game(){

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
