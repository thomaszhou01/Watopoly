#include <iostream>
#include <vector>
#include <string>
#include "boardPiece.h"
#include "ownableProperty.h"
#include "unownableProperty.h"

using namespace std;

int main(int argc, char *argv[])
{
    BoardPiece *p = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3};
    BoardPiece *q = new UnownableProperty{"TimsLine", 2};

    cout << p->getName() << " " << p->isOwnable() << endl;
    cout << q->getName() << " " << q->isOwnable() << endl;
}

// int main()
// {
//     BoardPiece *p = new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 0, false, false, 3};
//     BoardPiece *q = new UnownableProperty{"TimsLine", 2};

//     cout << p->getName() << " " << p->isOwnable() << endl;
//     cout << q->getName() << " " << q->isOwnable() << endl;
// }
