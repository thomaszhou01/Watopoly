#include <iostream>
#include <vector>
#include <string>
#include "boardPiece.h"
#include "ownableProperty.h"
#include "unownableProperty.h"

using namespace std;

int main(int argc, char *argv[])
{
    BoardPiece *p1 = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 2};
    BoardPiece *p2 = new OwnableProperty{"ML", "Arts1", 60, 50, {2,10,30,90,160,250}, 0, false, false, 2};
    BoardPiece *p3 = new OwnableProperty{"ECH", "Arts2", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3};
    BoardPiece *q = new UnownableProperty{"TimsLine", 2};
    Player *player = new Player{"Goose", 'G'};
    Player *player2 = new Player{"GRT", 'B'};
    player->addMoney(1500);
    player2->addMoney(0);

    cout << p3->isTuitionPaid() << endl;

    p1->landedOn(player);
    p2->landedOn(player);
    p3->landedOn(player);
    p3->landedOn(player2);
    cout << p3->isTuitionPaid() << endl;
    player2->addMoney(1000);
    p3->landedOn(player2);
    cout << p3->isTuitionPaid() << endl << endl;
    
    cout << p1->improve(player) << endl;
    cout << p1->getImprovementLevel() << endl;
    


    std::vector<BoardPiece*> otherProperties = player->getProperties();
    for(auto & i : otherProperties){
        cout << i->getName() << endl;
    }

    cout << player->getMoney() << endl;
    cout << player2->getMoney() << endl;


}

// int main()
// {
//     BoardPiece *p = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3};
//     BoardPiece *q = new UnownableProperty{"TimsLine", 2};

//     cout << p->getName() << " " << p->isOwnable() << endl;
//     cout << q->getName() << " " << q->isOwnable() << endl;
// }
