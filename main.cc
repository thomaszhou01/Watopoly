#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "boardPiece.h"
#include "ownableProperty.h"
#include "unownableProperty.h"

using namespace std;

int main(int argc, char *argv[])
{
    bool testing = false;
    string loadFile = "";
    for(int i = 0; i < argc; i++){
        string cmd = argv[i];
        if(cmd == "-testing"){
            testing = true;
        }
        else if(cmd == "-load"){
            if(i+1 < argc){
                loadFile = argv[i+1];
            }
        }
    }
    Game g;
    if(testing){
        g.setTesting();
    }

    if(loadFile == ""){
        g.InitializeOrder();
    }
    else{
        g.load(loadFile);
    }
    
    g.start();

}
