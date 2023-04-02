#include <iostream>
#include <vector>
#include <string>
#include "boardPiece.h"
#include "ownableProperty.h"

using namespace std;

int main()
{
    BoardPiece *p = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3};

    cout << p->getId() << " " << p->getOwner() << endl;
}
