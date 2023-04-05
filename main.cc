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
    g.start();

}

/*
BoardPiece *p1 = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 1, false, false, 2, 51, 73};
    BoardPiece *p2 = new OwnableProperty{"ML", "Arts1", 60, 50, {4,20,60,180,320,450}, 3, false, false, 2, 51, 57};
    BoardPiece *p3 = new OwnableProperty{"ECH", "Arts2", 100, 50, {6,30,90,270,400,550}, 6, false, false, 3, 51, 33};
    BoardPiece *p4 = new OwnableProperty{"PAS", "Arts2", 100, 50, {6,30,90,270,400,550}, 8, false, false, 3, 51, 17};
    BoardPiece *p5 = new OwnableProperty{"HH", "Arts2", 120, 50, {8,40,100,300,450,600}, 9, false, false, 3, 51, 9};
    BoardPiece *p6 = new OwnableProperty{"RCH", "Eng", 140, 100, {10,50,150,450,625,750}, 11, false, false, 3, 46, 1};
    BoardPiece *q = new UnownableProperty{"DC Tims Line", 10, 51, 1};
    Player *player = new Player{"Goose", 'G'};
    Player *player2 = new Player{"GRT", 'B'};
    cout << p3->isTuitionPaid() << endl;

    p1->landedOn(player);
    p2->landedOn(player);
    p3->landedOn(player);
    p3->landedOn(player2);
    p4->landedOn(player2);
    p5->landedOn(player2);
    p6->landedOn(player2);

    cout << p3->isTuitionPaid() << endl;
    p3->landedOn(player2);
    cout << p3->isTuitionPaid() << endl << endl;

    cout << p1->improve(player) << endl;
    cout << p1->getImprovementLevel() << endl;
    


    player->showAssets();

    player2->showAssets();

    player->trade(player2, "AL","1500");
    cout << endl;
    player->showAssets();

    player2->showAssets();
*/
