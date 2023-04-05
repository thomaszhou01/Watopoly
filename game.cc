#include "game.h"
#include "textDisplay.h"
#include "ownableProperty.h"
#include "unownableProperty.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, int row, int col);
// UnownableProperty(std::string name, int position, int row, int col);
Game::Game(){
    game.push_back(new UnownableProperty{"COLLECT OSAP", 0, 51, 81});
    game.push_back(new OwnableProperty{"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, 1, false, false, 2, 51, 73});
    game.push_back(new UnownableProperty{"SLC", 2, 51, 65});
    game.push_back(new OwnableProperty{"ML", "Arts1", 60, 50, {4,20,60,180,320,450}, 3, false, false, 2, 51, 57});
    game.push_back(new UnownableProperty{"TUITION", 4, 51, 49});
    game.push_back(new OwnableProperty{"MKV", "Residence", 200, 0, {}, 5, false, true, 4, 51, 41});
    game.push_back(new OwnableProperty{"ECH", "Arts2", 100, 50, {6,30,90,270,400,550}, 6, false, false, 3, 51, 33});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 7, 51, 25});
    game.push_back(new OwnableProperty{"PAS", "Arts2", 100, 50, {6,30,90,270,400,550}, 8, false, false, 3, 51, 17});
    game.push_back(new OwnableProperty{"HH", "Arts2", 120, 50, {8,40,100,300,450,600}, 9, false, false, 3, 51, 9});
    game.push_back(new UnownableProperty{"DC Tims Line", 10, 51, 1});
    game.push_back(new OwnableProperty{"RCH", "Eng", 140, 100, {10,50,150,450,625,750}, 11, false, false, 3, 46, 1});
    game.push_back(new OwnableProperty{"PAC", "Gym", 150, 0, {}, 12, true, false, 2, 41, 1});
    game.push_back(new OwnableProperty{"DWE", "Eng", 140, 100, {10,50,150,450,625,750}, 13, false, false, 3, 36, 1});
    game.push_back(new OwnableProperty{"CPH", "Eng", 160, 100, {12,60,180,500,700,900}, 14, false, false, 3, 31, 1});
    game.push_back(new OwnableProperty{"UWP", "Residence", 200, 0, {}, 15, false, true, 4, 26, 1});
    game.push_back(new OwnableProperty{"LHI", "Health", 180, 100, {14,70,200,550,750,950}, 16, false, false, 3, 21, 1});
    game.push_back(new UnownableProperty{"SLC", 17, 16, 1});
    game.push_back(new OwnableProperty{"BMH", "Health", 180, 100, {14,70,200,550,750,950}, 18, false, false, 3, 11, 1});
    game.push_back(new OwnableProperty{"OPT", "Health", 200, 100, {16,80,220,600,800,1000}, 19, false, false, 3, 6, 1});
    game.push_back(new UnownableProperty{"Goose Nesting", 20, 1, 1});
    game.push_back(new OwnableProperty{"EV1", "Env", 220, 150, {18,90,250,700,875,1050}, 21, false, false, 3, 1, 10});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 22, 1, 17});
    game.push_back(new OwnableProperty{"EV2", "Env", 220, 150, {18,90,250,700,875,1050}, 23, false, false, 3, 1, 25});
    game.push_back(new OwnableProperty{"EV3", "Env", 240, 150, {20,100,300,750,925,1100}, 24, false, false, 3, 1, 33});
    game.push_back(new OwnableProperty{"V1", "Residence", 200, 0, {}, 15, false, true, 4, 1, 41});
    game.push_back(new OwnableProperty{"PHYS", "Sci1", 260, 150, {22,110,330,800,975,1150}, 26, false, false, 3, 1, 49});
    game.push_back(new OwnableProperty{"B1", "Sci1", 260, 150, {22,110,330,800,975,1150}, 27, false, false, 3, 1, 57});
    game.push_back(new OwnableProperty{"PAC", "Gym", 150, 0, {}, 28, true, false, 2, 1, 65});
    game.push_back(new OwnableProperty{"B2", "Sci1", 280, 150, {24,120,360,850,1025,1200}, 29, false, false, 3, 1, 73});
    game.push_back(new UnownableProperty{"GO TO TIMS", 30, 1, 81});
    game.push_back(new OwnableProperty{"EIT", "Sci2", 300, 200, {26,130,390,900,1100,1275}, 31, false, false, 3, 6, 81});
    game.push_back(new OwnableProperty{"ESC", "Sci2", 300, 200, {26,130,390,900,1100,1275}, 32, false, false, 3, 11, 81});
    game.push_back(new UnownableProperty{"SLC", 33, 16, 81});
    game.push_back(new OwnableProperty{"C2", "Sci2", 320, 200, {28,150,450,1000,1200,1400}, 34, false, false, 3, 21, 81});
    game.push_back(new OwnableProperty{"REV", "Residence", 200, 0, {}, 35, false, true, 4, 26, 81});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 36, 31, 81});
    game.push_back(new OwnableProperty{"MC", "Math", 350, 200, {35,175,500,1100,1300,1500}, 37, false, false, 2, 36, 81});
    game.push_back(new UnownableProperty{"COOP FEE", 38, 41, 81});
    game.push_back(new OwnableProperty{"DC", "Math", 400, 200, {50,200,600,1400,1700,2000}, 39, false, false, 2, 46, 81});

    cout << "How many players are playing?" << endl;
    cin >> numPlayers;
    while (true) {
        if (numPlayers > 8 || numPlayers < 2) {
            cout << "Invalid number of players." << endl;
            cout << "Number of players must be between 2 and 8 (inclusive)" << endl;
            cin >> numPlayers;
        } else {
            break;
        }
    }
    string name;
    char character;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Player " << i + 1 << ": ";
        cout << "Please enter your name: " << endl;
        while (true) {
            if (cin >> name) break;
            else {
                if (cin.eof()) break;
                else {
                    cin.clear();
                    cin.ignore();
                }
                cout << "Incorrect type" << endl;
            }
            cout << "Please enter your name: " << endl;
        }

        cout << "The playable Characters are: G: Goose, B: GRT Bus, D: Tim Hortons Doughnut, P: Professor, S: Student, $: Money, L: Laptop, T: Pink tie" << endl;
        bool success = false;
        while (true) {
            cout << "Please choose from the options:";
            for (int j = 0; j < 8; ++j) {
                if (playerCharTaken[j] == false) {
                    cout << " " << playerChar[j];
                }
            }
            cout << endl;
            if (cin >> character) {
                for (int j = 0; j < 8; ++j) {
                    if (playerChar[j] == character && playerCharTaken[j] == false) {
                        playerCharTaken[j] = true;
                        success = true;
                        break;
                    }
                }
            } else {
                if (cin.eof()) break;
                else {
                    cin.clear();
                    cin.ignore();
                }
                cout << "Incorrect type" << endl;
            }
            if(success) break;
        }
        order.push_back(new Player{name, character});
    }

    textDisplay = new TextDisplay{this, order};
    for (int i = 0; i < pieces; ++i) {
        game[i]->attach(textDisplay);
        game[i]->notifyObservers();
    }
}

Game::~Game() {
    for (int i = 0; i < pieces; ++i) {
        delete game[i];
    }
    for (int i = 0; i < numPlayers; ++i) {
        delete order[i];
    }
}

int Game::getPieces(){
    return pieces;
}

bool Game::getTesting() {
    return testing;
}

void Game::setTesting() {
    testing = true;
}

std::vector<BoardPiece *> Game::getGame(){
    return game;
}

std::vector<Player *> Game::getOrder() {
    return order;
}

void Game::start(){
    textDisplay->display();
    bool ended = false;

}

int Game::getNumPlayers(){
    return numPlayers;
}

void Game::save(string file, int playerOrderIndex) {
    ofstream f;
    f.open(file);
    f << numPlayers <<endl; //outputs number of players
    // outputs player info
     
    for (int i = 0; i < numPlayers; ++i) {
        Player * p = order[(i + playerOrderIndex) / numPlayers];
        f << p->getName() << " ";
        f << p->getCharacter() << " ";
        f << p->getRollUpTheRimCards() << " ";
        f << p->getMoney() << " ";
        f << p->getPosition() << endl;
        if (p->getPosition() == 10) {
            f << 0;
        } else if (p->isInTims()) {
            f << 1 << " ";
            f << p->getTurnsInTims();
        }
        f << endl;
    }
    // outputs ownable property info
    for (int i = 0; i < ownable; ++i) {
        f << game[i]->getName() << " ";
        if (game[i]->isOwned()) {
            f << game[i]->getOwner() << " ";
        } else {
            f << "BANK" << " ";
        }
        if (game[i]->isResidence() || game[i]->isGym()) {
            f << 0;
        } else if (game[i]->isMortgaged()) {
            f << -1;
        } else {
            f << game[i]->getImprovementLevel();
        }
    }
    f.close();
    cout << "The game has been saved to " << file << endl;
}

void Game::load(string file) {
    ifstream f(file);
    string s;
    f >> s;
    numPlayers = stoi(s);

    for (int i = 0; i < numPlayers; ++i) {
        getline(f,s);
        stringstream ss(s);
        string s1;
        vector<string> s2;
        while (ss >> s1) {
            s2.push_back(s1);
        }
        string name = s2[0];
        char character = s2[1][0];
        order[i] = new Player{name, character};
        order[i]->setRollUpTheRimCards(stoi(s2[2]));
        order[i]->setMoney(stoi(s2[3]));
        int position = stoi(s2[4]);
        order[i]->setPosition(position);
        if (position == 10) {
            int inTims = stoi(s2[5]);
            if (inTims != 0) {
                order[i]->sendToTims();
                order[i]->setTurnsInTims(stoi(s2[6]));
            }
        }
    }

    for (int i = 0; i < ownable; ++i) {
        getline(f,s);
        stringstream ss(s);
        string s1;
        vector<string> s2;
        while (ss >> s1) {
            s2.push_back(s1);
        }
        string name = s2[0];
        string owner = s2[1];
        int improvements = stoi(s2[2]);
        for (int j = 0; j < pieces; ++j) {
            if (game[j]->getName() == name) {
                if (owner != "BANK") {
                    for (int k = 0; k < numPlayers; ++k) {
                        if (order[k]->getName() == owner) {
                            game[j]->setOwner(order[k]);
                            if (improvements == -1) {
                                game[j]->mortgage(order[k]);
                            } else {
                                game[j]->setImprovementLevel(improvements);
                            }
                        } 
                    }
                } else {
                    game[j]->setOwned(false);
                }
            }
        }
    }

    for (int i=0; i < pieces; i++){
		game[i]->notifyObservers();
	}

    cout << "The game has been loaded" << endl;
}
