#include "game.h"
#include "textDisplay.h"
#include "ownableProperty.h"
#include "unownableProperty.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Game::Game()
{
    game.push_back(new UnownableProperty{"COLLECT OSAP", 0, 51, 81});
    game.push_back(new OwnableProperty{"AL", "Arts1", 40, 50, {2, 10, 30, 90, 160, 250}, 1, false, false, 2, 51, 73});
    game.push_back(new UnownableProperty{"SLC", 2, 51, 65});
    game.push_back(new OwnableProperty{"ML", "Arts1", 60, 50, {4, 20, 60, 180, 320, 450}, 3, false, false, 2, 51, 57});
    game.push_back(new UnownableProperty{"TUITION", 4, 51, 49});
    game.push_back(new OwnableProperty{"MKV", "Residence", 200, 0, {}, 5, false, true, 4, 51, 41});
    game.push_back(new OwnableProperty{"ECH", "Arts2", 100, 50, {6, 30, 90, 270, 400, 550}, 6, false, false, 3, 51, 33});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 7, 51, 25});
    game.push_back(new OwnableProperty{"PAS", "Arts2", 100, 50, {6, 30, 90, 270, 400, 550}, 8, false, false, 3, 51, 17});
    game.push_back(new OwnableProperty{"HH", "Arts2", 120, 50, {8, 40, 100, 300, 450, 600}, 9, false, false, 3, 51, 9});
    game.push_back(new UnownableProperty{"DC Tims Line", 10, 51, 1});
    game.push_back(new OwnableProperty{"RCH", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}, 11, false, false, 3, 46, 1});
    game.push_back(new OwnableProperty{"PAC", "Gym", 150, 0, {}, 12, true, false, 2, 41, 1});
    game.push_back(new OwnableProperty{"DWE", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}, 13, false, false, 3, 36, 1});
    game.push_back(new OwnableProperty{"CPH", "Eng", 160, 100, {12, 60, 180, 500, 700, 900}, 14, false, false, 3, 31, 1});
    game.push_back(new OwnableProperty{"UWP", "Residence", 200, 0, {}, 15, false, true, 4, 26, 1});
    game.push_back(new OwnableProperty{"LHI", "Health", 180, 100, {14, 70, 200, 550, 750, 950}, 16, false, false, 3, 21, 1});
    game.push_back(new UnownableProperty{"SLC", 17, 16, 1});
    game.push_back(new OwnableProperty{"BMH", "Health", 180, 100, {14, 70, 200, 550, 750, 950}, 18, false, false, 3, 11, 1});
    game.push_back(new OwnableProperty{"OPT", "Health", 200, 100, {16, 80, 220, 600, 800, 1000}, 19, false, false, 3, 6, 1});
    game.push_back(new UnownableProperty{"Goose Nesting", 20, 1, 1});
    game.push_back(new OwnableProperty{"EV1", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}, 21, false, false, 3, 1, 9});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 22, 1, 17});
    game.push_back(new OwnableProperty{"EV2", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}, 23, false, false, 3, 1, 25});
    game.push_back(new OwnableProperty{"EV3", "Env", 240, 150, {20, 100, 300, 750, 925, 1100}, 24, false, false, 3, 1, 33});
    game.push_back(new OwnableProperty{"V1", "Residence", 200, 0, {}, 15, false, true, 4, 1, 41});
    game.push_back(new OwnableProperty{"PHYS", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150}, 26, false, false, 3, 1, 49});
    game.push_back(new OwnableProperty{"B1", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150}, 27, false, false, 3, 1, 57});
    game.push_back(new OwnableProperty{"PAC", "Gym", 150, 0, {}, 28, true, false, 2, 1, 65});
    game.push_back(new OwnableProperty{"B2", "Sci1", 280, 150, {24, 120, 360, 850, 1025, 1200}, 29, false, false, 3, 1, 73});
    game.push_back(new UnownableProperty{"GO TO TIMS", 30, 1, 81});
    game.push_back(new OwnableProperty{"EIT", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}, 31, false, false, 3, 6, 81});
    game.push_back(new OwnableProperty{"ESC", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}, 32, false, false, 3, 11, 81});
    game.push_back(new UnownableProperty{"SLC", 33, 16, 81});
    game.push_back(new OwnableProperty{"C2", "Sci2", 320, 200, {28, 150, 450, 1000, 1200, 1400}, 34, false, false, 3, 21, 81});
    game.push_back(new OwnableProperty{"REV", "Residence", 200, 0, {}, 35, false, true, 4, 26, 81});
    game.push_back(new UnownableProperty{"NEEDLES HALL", 36, 31, 81});
    game.push_back(new OwnableProperty{"MC", "Math", 350, 200, {35, 175, 500, 1100, 1300, 1500}, 37, false, false, 2, 36, 81});
    game.push_back(new UnownableProperty{"COOP FEE", 38, 41, 81});
    game.push_back(new OwnableProperty{"DC", "Math", 400, 200, {50, 200, 600, 1400, 1700, 2000}, 39, false, false, 2, 46, 81});
}

Game::~Game()
{
    for (int i = 0; i < pieces; ++i)
    {
        delete game[i];
    }
    for (int i = 0; i < numPlayers; ++i)
    {
        delete order[i];
    }
}

void Game::InitializeOrder()
{
    cout << "How many players are playing?" << endl;
    // add guard
    cin >> numPlayers;
    while (true)
    {
        if (numPlayers > 8 || numPlayers < 2)
        {
            cout << "Invalid number of players." << endl;
            cout << "Number of players must be between 2 and 8 (inclusive)" << endl;
            //add guard
            cin >> numPlayers;
        }
        else
        {
            break;
        }
    }
    string name;
    char character;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Player " << i + 1 << ": ";
        cout << "Please enter your name: " << endl;
        while (true)
        {
            if (cin >> name)
                break;
            else
            {
                if (cin.eof())
                    break;
                else
                {
                    cin.clear();
                    cin.ignore();
                }
                cout << "Incorrect type" << endl;
            }
            cout << "Please enter your name: " << endl;
        }

        cout << "The playable Characters are: G: Goose, B: GRT Bus, D: Tim Hortons Doughnut, P: Professor, S: Student, $: Money, L: Laptop, T: Pink tie" << endl;
        bool success = false;
        while (true)
        {
            cout << "Please choose from the options:";
            for (int j = 0; j < 8; ++j)
            {
                if (playerCharTaken[j] == false)
                {
                    cout << " " << playerChar[j];
                }
            }
            cout << endl;
            if (cin >> character)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (playerChar[j] == character && playerCharTaken[j] == false)
                    {
                        playerCharTaken[j] = true;
                        success = true;
                        break;
                    }
                }
            }
            else
            {
                if (cin.eof())
                    break;
                else
                {
                    cin.clear();
                    cin.ignore();
                }
                cout << "Incorrect type" << endl;
            }
            if (success)
                break;
        }
        order.push_back(new Player{name, character});
        orderIndex.push_back(i);
    }

    textDisplay = new TextDisplay{this, order};
    for (int i = 0; i < pieces; ++i)
    {
        game[i]->attach(textDisplay);
        game[i]->notifyObservers();
    }
}

int Game::getPieces()
{
    return pieces;
}

bool Game::getTesting()
{
    return testing;
}

void Game::setTesting()
{
    testing = true;
}

vector<int> Game::testRoll(int die1, int die2)
{
    return vector<int>{die1, die2};
}

vector<int> Game::rollDie()
{
    std::vector<int> v = {1,2,3,4,5,6};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
    return vector<int>{v[0], v[1]};
}

std::vector<BoardPiece *> Game::getGame()
{
    return game;
}

std::vector<Player *> Game::getOrder()
{
    return order;
}

void Game::commands(Player *p)
{
    cout << p->getName() << "'s turn. Here are your following options: " << endl;
    if (p->isInTims() == true)
    {
        cout << "You are currently in DC Tims Line. Your turns here are: " << p->getTurnsInTims() << endl;
        cout << "To leave you must pay $50, use a Roll Up the Rim cup, or roll doubles" << endl;
        cout << "pay $50" << endl;
        cout << "use RUTRC" << endl;
    }
    if (testing == true)
    {
        cout << "roll <die1> <die2>  where die1, die2 > 0" << endl;
    }
    cout << "roll" << endl;
    cout << "next" << endl;
    cout << "trade <name> <money> <property>" << endl;
    cout << "trade <name> <property> <property>" << endl;
    cout << "trade <name> <property> <money>" << endl;
    cout << "improve <property> buy" << endl;
    cout << "improve <property> sell" << endl;
    cout << "mortgage <property>" << endl;
    cout << "unmortgage <property>" << endl;
    cout << "assets" << endl;
    cout << "all" << endl;
    cout << "save <filename>" << endl;
    cout << "Please understand that if you enter \"next\" or \"roll\" you are not able to enter any other options" << endl;
}

void Game::auction(BoardPiece *b)
{
    bool inAuction[8] = {true, true, true, true, true, true, true, true};
    int numInAuction = numPlayers;

    string s;
    string s1;
    vector<string> cmd;
    int bid = 0;

    cout << "The AUCTION will commence" << endl;
    cout << "We will go in turns to raise the current bid or withdraw: raise <amount> / withdraw" << endl;
    cout << "The is bid is 0. ";
    while (numInAuction != 1)
    {
        for (int i = 0; i < numPlayers; ++i)
        {
            while (true)
            {
                if (inAuction[i] == true)
                {
                    cout << order[i]->getName() << ": ";
                    getline(cin, s);
                    stringstream ss(s);
                    cmd.clear();
                    while (ss >> s1)
                    {
                        cmd.push_back(s1);
                    }

                    for(auto i: cmd){
                        cout << i << endl;
                    }

                    if (cmd[0] == "withdraw")
                    {
                        inAuction[i] = "false";
                        --numInAuction;
                        break;
                    }
                    else if (cmd[0] == "raise")
                    {
                        if (stoi(cmd[1]) > 0)
                        {
                            int raise = stoi(cmd[1]);
                            if ((bid + raise) > order[i]->getMoney())
                            {
                                cout << "You do not have enough money to bid, Please raise less or withdraw" << endl;
                            }
                            else
                            {
                                bid += raise;
                                cout << "The bid is now $" << bid << endl;
                                break;
                            }
                        }
                        else
                        {
                            cout << "Invalid <amount>" << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid option" << endl;
                    }
                }
            }
            if (numInAuction == 1)
            {
                break;
            }
        }
    }
    for (int i = 0; i < numPlayers; ++i)
    {
        if (inAuction[i] == true)
        {
            cout << "Congratulations to " << order[i]->getName() << " for winning the property for $" << bid << endl;
            order[i]->subtractMoney(bid);
            order[i]->addProperty(b);
            b->setOwner(order[i]);
            b->setOwned(true);
            b->notifyObservers();
            break;
        }
    }
}

void Game::start()
{
    bool over = false;
    bool hasRolled = false;
    int playerIndex = 0;
    bool rolledDouble = false;

    cout << "Welcome to WATOPOLY" << endl;
    cout << "We have the following players: " << endl;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << order[i]->getName() << ": " << order[i]->getCharacter() << endl;
    }
    textDisplay->display();
    commands(order[playerIndex]);
    cin.ignore();
    while (over == false)
    {
        string s= "";
        string s1 = "";
        vector<string> cmd;
        cmd.clear();

        cout << "It is "<< order[playerIndex]->getName() << "'s turn. Please enter a command:" << endl;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s1)
        {
            cmd.push_back(s1);
        }
        if (cmd.size() == 1)
        {
            if (cmd[0] == "roll")
            {
                int pos = order[playerIndex]->getPosition();
                int newPos;
                vector<int> roll = rollDie();
                int totalRoll = roll[0] + roll[1];
                hasRolled = true;
                rolledDouble = false;
                cout << "You rolled: " << roll[0] << " & " << roll[1] << endl;
                if (roll[0] == roll[1])
                {
                    consecutiveDoubles[playerIndex]++;
                    rolledDouble = true;
                }
                else{
                    rolledDouble = false;
                }

                if (order[playerIndex]->isInTims() == true)
                {
                    if (roll[0] == roll[1])
                    {
                        newPos = pos + totalRoll;
                        if(newPos >= 40){
                            order[playerIndex]->addMoney(200);
                            cout << "You passed the DC Tims Line. You gained $200" << endl;
                            newPos = newPos % 40;
                        }
                        cout << "Congrats you made it out of DC Tims Line" << endl;
                        order[playerIndex]->setInTims(false);
                    }
                    else
                    {
                        newPos = pos;
                        cout << "Unfortunately you did not roll doubles. You are still stuck in DC Tims Line" << endl;
                        order[playerIndex]->reduceTimsTime();
                    }
                }
                else if (order[playerIndex]->isInTims() == false && consecutiveDoubles[orderIndex[playerIndex]] == 3)
                {
                    cout << "Unfortunately this is your third time rolling doubles, so you are send to Tims DC Line" << endl;
                    order[playerIndex]->sendToTims();
                    newPos = 10;
                    consecutiveDoubles[playerIndex] = 0;
                }
                else
                {
                    newPos = pos + totalRoll;
                    if(newPos >= 40){
                        order[playerIndex]->addMoney(200);
                        cout << "You passed the DC Tims Line. You gained $200" << endl;
                        newPos = newPos % 40;
                    }
                }
                order[playerIndex]->setPosition(newPos);
                game[pos]->notifyObservers();
                game[newPos]->notifyObservers();
                pos = newPos;
                textDisplay->display();
                cout << "You are currently on: " << game[newPos]->getName() << endl;
                game[newPos]->landedOn(order[playerIndex]);
                game[newPos]->notifyObservers();

                while (newPos != order[playerIndex]->getPosition())
                {
                    newPos = order[playerIndex]->getPosition();
                    game[newPos]->landedOn(order[playerIndex]);
                    game[newPos]->notifyObservers();
                    game[pos]->notifyObservers();
                    textDisplay->display();
                    cout << "You are currently on: " << game[newPos]->getName() << endl;
                }

                // buy/auction
                if (game[newPos]->isOwnable() == true && game[newPos]->isOwned() == false)
                {
                    char c;
                    cout << "You are given the option to BUY the property for: $" << game[newPos]->getPrice() << " else the property will be AUCTIONED" << endl;

                    while (true)
                    {
                        cout << "Would you like to buy the propert? (Y/N)" << endl;
                        cin >> c;
                        cin.ignore();
                        if (c == 'Y')
                        {
                            game[newPos]->setOwned(true);
                            game[newPos]->setOwner(order[playerIndex]);
                            order[playerIndex]->addProperty(game[newPos]);
                            game[newPos]->notifyObservers();
                            cout << "You have succesfully purchased propert: " << game[newPos]->getName() << endl;
                            break;
                        }
                        else if (c == 'N')
                        {
                            auction(game[newPos]);
                            break;
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                }

                if (game[newPos]->isTuitionPaid() == false)
                {
                    cout << "You do not have enough money to pay." << endl;
                    cout << "Here are your following options:";
                    cout << "bankrupt" << endl;
                    cout << "trade <name> <money> <property>" << endl;
                    cout << "trade <name> <property> <property>" << endl;
                    cout << "trade <name> <property> <money>" << endl;
                    cout << "mortgage <property>" << endl;
                    cout << "improve <property> sell" << endl;
                }
                while (game[newPos]->isTuitionPaid() == false)
                {
                    cout << "Please enter an option to get enough money:" << endl;
                    getline(cin, s);
                    while (ss >> s1)
                    {
                        cmd.push_back(s1);
                    }
                    if (cmd.size() == 1)
                    {
                        if (cmd[0] == "bankrupt")
                        {
                            int oldPos = order[playerIndex]->getPosition();
                            order[playerIndex]->setPosition(-1);
                            game[oldPos]->notifyObservers();
                            order.erase(order.begin() + playerIndex);
                            --numPlayers;

                            if (numPlayers == 1)
                            {
                                cout << "The game is over. The winner of WATOPOLY is: " << order[0]->getName() << "!!!" << endl;
                                over = true;
                            }
                            else
                            {
                                cout << "You gave control to the next player" << endl;
                                consecutiveDoubles[playerIndex] = 0;
                                playerIndex++;
                                if(playerIndex == numPlayers){
                                    playerIndex = 0;
                                }
                                hasRolled = false;
                            }
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                    else if (cmd.size() == 2)
                    {
                        if (cmd[0] == "mortgage")
                        {
                            for (int i = 0; i < pieces; ++i)
                            {
                                if (game[i]->getName() == cmd[1])
                                {
                                    if (!game[i]->mortgage(order[playerIndex]))
                                    {
                                        cout << "This property does not belong to you" << endl;
                                    }
                                    else
                                    {
                                        cout << "You have sucessfully mortgaged " << cmd[1] << endl;
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                    else if (cmd.size() == 3)
                    {
                        if (cmd[0] == "improve" && cmd[2] == "sell")
                        {
                            for (int i = 0; i < pieces; ++i)
                            {
                                if (game[i]->getName() == cmd[1])
                                {
                                    if (game[i]->sellImprovement(order[playerIndex]))
                                    {
                                        cout << "You have sucessfully sold " << cmd[1] << endl;
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                    else if (cmd.size() == 4)
                    {
                        bool trade(Player * p, std::string give, std::string recieve);
                        if (cmd[0] == "trade")
                        {
                            Player *p;
                            bool flag = false;
                            for (int i = 0; i < numPlayers; ++i)
                            {
                                if (order[i]->getName() == cmd[1])
                                {
                                    p = order[i];
                                    flag = true;
                                }
                            }
                            if (flag == true)
                            {
                                if (order[playerIndex]->trade(p, cmd[2], cmd[3]))
                                {
                                    cout << "You have sucessfulled traded with " << cmd[1] << endl;
                                }
                            }
                            else
                            {
                                cout << "Invalid <name>" << endl;
                            }
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid option" << endl;
                    }
                }
            }
            else if (cmd[0] == "next")
            {
                if (hasRolled == true)
                {
                    cout << "You gave control to the next player" << endl;
                    consecutiveDoubles[playerIndex] = 0;
                    playerIndex++;
                    if(playerIndex == numPlayers){
                        playerIndex = 0;
                    }
                    hasRolled = false;
                }
                else
                {
                    cout << "\"next\" denied: You can roll" << endl;
                }
            }
            else if (cmd[0] == "assets")
            {
                order[playerIndex]->showAssets();
            }
            else if (cmd[0] == "all")
            {
                for (int i = 0; i < numPlayers; ++i)
                {
                    order[i]->showAssets();
                    cout << endl;
                }
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
        else if (cmd.size() == 2)
        {
            if (order[playerIndex]->isInTims() == true)
            {
                if (s == "pay $50")
                {
                    cout << "You have paid $50. Congrats you made it out of DC Tims Line" << endl;
                    order[playerIndex]->setInTims(false);
                }
                else if (s == "use RUTRC")
                {
                    int amount_of_RUTRC = order[playerIndex]->getRollUpTheRimCards();
                    if (amount_of_RUTRC == 0)
                    {
                        cout << "You do not have any Roll Up The Rim Cards. You are still in DC Tims Line" << endl;
                    }
                    else
                    {
                        cout << "You have used 1 Roll Up The Rim Card. Congrats you made it out of DC Tims Line" << endl;
                        order[playerIndex]->setInTims(false);
                        order[playerIndex]->setRollUpTheRimCards(amount_of_RUTRC - 1);
                    }
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
            else if (cmd[0] == "mortgage")
            {
                for (int i = 0; i < pieces; ++i)
                {
                    if (game[i]->getName() == cmd[1])
                    {
                        if (!game[i]->mortgage(order[playerIndex]))
                        {
                            cout << "This property does not belong to you" << endl;
                        }
                        else
                        {
                            cout << "You have sucessfully mortgaged " << cmd[1] << endl;
                            break;
                        }
                    }
                }
            }
            else if (cmd[0] == "unmortgage")
            {
                for (int i = 0; i < pieces; ++i)
                {
                    if (game[i]->getName() == cmd[1])
                    {
                        if (!game[i]->unmortgage(order[playerIndex]))
                        {
                            cout << "This property does not belong to you" << endl;
                        }
                        else
                        {
                            cout << "You have sucessfully unmortgaged " << cmd[1] << endl;
                            break;
                        }
                    }
                }
            }
            else if (cmd[0] == "save")
            {
                save(cmd[1], playerIndex);
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
        else if (cmd.size() == 3)
        {
            if (cmd[0] == "improve")
            {
                if (cmd[2] == "sell")
                {
                    for (int i = 0; i < pieces; ++i)
                    {
                        if (game[i]->getName() == cmd[1])
                        {
                            if (game[i]->sellImprovement(order[playerIndex]))
                            {
                                cout << "You have sucessfully sold " << cmd[1] << endl;
                            }
                            break;
                        }
                    }
                }
                else if (cmd[2] == "buy")
                {
                    for (int i = 0; i < pieces; ++i)
                    {
                        if (game[i]->getName() == cmd[1])
                        {
                            if (game[i]->improve(order[playerIndex]))
                            {
                                cout << "You have sucessfully improved " << cmd[1] << endl;
                            }
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
            else if (cmd[0] == "roll")
            {
                if (testing == false)
                {
                    cout << "Invalid option" << endl;
                }
                else
                {
                    int pos = order[playerIndex]->getPosition();
                    int newPos;
                    vector<int> roll = testRoll(stoi(cmd[1]), stoi(cmd[2]));
                    int totalRoll = roll[0] + roll[1];
                    hasRolled = true;
                    rolledDouble = false;
                    cout << "You rolled: " << roll[0] << " & " << roll[1] << endl;
                    if (roll[0] == roll[1])
                    {
                        consecutiveDoubles[playerIndex]++;
                        rolledDouble = true;
                    }
                    else{
                        rolledDouble = false;
                    }
                    
                    if (order[playerIndex]->isInTims() == true)
                    {
                        if (roll[0] == roll[1])
                        {
                            newPos = pos + totalRoll;
                            if(newPos >= 40){
                                order[playerIndex]->addMoney(200);
                                cout << "You passed the DC Tims Line. You gained $200" << endl;
                                newPos = newPos % 40;
                            }
                            cout << "Congrats you made it out of DC Tims Line" << endl;
                            order[playerIndex]->setInTims(false);
                        }
                        else
                        {
                            newPos = pos;
                            cout << "Unfortunately you did not roll doubles. You are still stuck in DC Tims Line" << endl;
                            order[playerIndex]->reduceTimsTime();
                        }
                    }
                    else if (order[playerIndex]->isInTims() == false && consecutiveDoubles[orderIndex[playerIndex]] == 3)
                    {
                        cout << "Unfortunately this is your third time rolling doubles, so you are send to Tims DC Line" << endl;
                        order[playerIndex]->sendToTims();
                        newPos = 10;
                        consecutiveDoubles[playerIndex] = 0;
                    }
                    else
                    {
                        newPos = pos + totalRoll;
                        if(newPos >= 40){
                            order[playerIndex]->addMoney(200);
                            cout << "You passed the DC Tims Line. You gained $200" << endl;
                            newPos = newPos % 40;
                        }
                    }
                    order[playerIndex]->setPosition(newPos);
                    game[pos]->notifyObservers();
                    game[newPos]->notifyObservers();
                    pos = newPos;
                    textDisplay->display();
                    cout << "You are currently on: " << game[newPos]->getName() << endl;
                    game[newPos]->landedOn(order[playerIndex]);
                    game[newPos]->notifyObservers();
                    
                    while (newPos != order[playerIndex]->getPosition())
                    {
                        newPos = order[playerIndex]->getPosition();
                        game[newPos]->landedOn(order[playerIndex]);
                        game[newPos]->notifyObservers();
                        game[pos]->notifyObservers();
                        textDisplay->display();
                        cout << "You are currently on: " << game[newPos]->getName() << endl;
                    }

                    // buy/auction
                    if (game[newPos]->isOwnable() == true && game[newPos]->isOwned() == false)
                    {
                        char c;
                        cout << "You are given the option to BUY the property for: $" << game[newPos]->getPrice() << " else the property will be AUCTIONED" << endl;

                        while (true)
                        {
                            cout << "Would you like to buy the propert? (Y/N)" << endl;
                            cin >> c;
                            cin.ignore();
                            if (c == 'Y')
                            {
                                game[newPos]->setOwned(true);
                                game[newPos]->setOwner(order[playerIndex]);
                                order[playerIndex]->addProperty(game[newPos]);
                                game[newPos]->notifyObservers();
                                cout << "You have succesfully purchased propert: " << game[newPos]->getName() << endl;
                                break;
                            }
                            else if (c == 'N')
                            {
                                auction(game[newPos]);
                                break;
                            }
                            else
                            {
                                cout << "Invalid option" << endl;
                            }
                        }
                    }

                    if (game[newPos]->isTuitionPaid() == false)
                    {
                        cout << "You do not have enough money to pay." << endl;
                        cout << "Here are your following options:";
                        cout << "bankrupt" << endl;
                        cout << "trade <name> <money> <property>" << endl;
                        cout << "trade <name> <property> <property>" << endl;
                        cout << "trade <name> <property> <money>" << endl;
                        cout << "mortgage <property>" << endl;
                        cout << "improve <property> sell" << endl;
                    }
                    while (game[newPos]->isTuitionPaid() == false)
                    {
                        cout << "Please enter an option to get enough money:" << endl;
                        getline(cin, s);
                        while (ss >> s1)
                        {
                            cmd.push_back(s1);
                        }
                        if (cmd.size() == 1)
                        {
                            if (cmd[0] == "bankrupt")
                            {
                                int oldPos = order[playerIndex]->getPosition();
                                order[playerIndex]->setPosition(-1);
                                game[oldPos]->notifyObservers();
                                order.erase(order.begin() + playerIndex);
                                --numPlayers;

                                if (numPlayers == 1)
                                {
                                    cout << "The game is over. The winner of WATOPOLY is: " << order[0]->getName() << "!!!" << endl;
                                    over = true;
                                }
                                else
                                {
                                    cout << "You gave control to the next player" << endl;
                                    consecutiveDoubles[playerIndex] = 0;
                                    playerIndex++;
                                    if(playerIndex == numPlayers){
                                        playerIndex = 0;
                                    }
                                    hasRolled = false;
                                }
                            }
                            else
                            {
                                cout << "Invalid option" << endl;
                            }
                        }
                        else if (cmd.size() == 2)
                        {
                            if (cmd[0] == "mortgage")
                            {
                                for (int i = 0; i < pieces; ++i)
                                {
                                    if (game[i]->getName() == cmd[1])
                                    {
                                        if (!game[i]->mortgage(order[playerIndex]))
                                        {
                                            cout << "This property does not belong to you" << endl;
                                        }
                                        else
                                        {
                                            cout << "You have sucessfully mortgaged " << cmd[1] << endl;
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Invalid option" << endl;
                            }
                        }
                        else if (cmd.size() == 3)
                        {
                            if (cmd[0] == "improve" && cmd[2] == "sell")
                            {
                                for (int i = 0; i < pieces; ++i)
                                {
                                    if (game[i]->getName() == cmd[1])
                                    {
                                        if (game[i]->sellImprovement(order[playerIndex]))
                                        {
                                            cout << "You have sucessfully sold " << cmd[1] << endl;
                                        }
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Invalid option" << endl;
                            }
                        }
                        else if (cmd.size() == 4)
                        {
                            bool trade(Player * p, std::string give, std::string recieve);
                            if (cmd[0] == "trade")
                            {
                                Player *p;
                                bool flag = false;
                                for (int i = 0; i < numPlayers; ++i)
                                {
                                    if (order[i]->getName() == cmd[1])
                                    {
                                        p = order[i];
                                        flag = true;
                                    }
                                }
                                if (flag == true)
                                {
                                    if (order[playerIndex]->trade(p, cmd[2], cmd[3]))
                                    {
                                        cout << "You have sucessfulled traded with " << cmd[1] << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Invalid <name>" << endl;
                                }
                            }
                            else
                            {
                                cout << "Invalid option" << endl;
                            }
                        }
                        else
                        {
                            cout << "Invalid option" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
        else if (cmd.size() == 4)
        {
            if (cmd[0] == "trade")
            {
                Player *p;
                bool flag = false;
                for (int i = 0; i < numPlayers; ++i)
                {
                    if (order[i]->getName() == cmd[1])
                    {
                        p = order[i];
                        flag = true;
                    }
                }
                if (flag == true)
                {
                    if (order[playerIndex]->trade(p, cmd[2], cmd[3]))
                    {
                        cout << "You have sucessfulled traded with " << cmd[1] << endl;
                    }
                }
                else
                {
                    cout << "Invalid <name>" << endl;
                }
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
        else
        {
            cout << "Invalid option" << endl;
        }

        if(hasRolled && (!rolledDouble || order[playerIndex]->isInTims())){
            cout << "Your turn has ended" << endl;
            consecutiveDoubles[playerIndex] = 0;
            playerIndex++;
            if(playerIndex == numPlayers){
                playerIndex = 0;
            }
            hasRolled = false;
        }
    }
}

int Game::getNumPlayers()
{
    return numPlayers;
}

void Game::save(string file, int playerOrderIndex)
{
    ofstream f;
    f.open(file);
    f << numPlayers << endl; // outputs number of players
    // outputs player info

    for (int i = 0; i < numPlayers; ++i)
    {
        Player *p = order[(i + playerOrderIndex) / numPlayers];
        f << p->getName() << " ";
        f << p->getCharacter() << " ";
        f << p->getRollUpTheRimCards() << " ";
        f << p->getMoney() << " ";
        f << p->getPosition() << endl;
        if (p->getPosition() == 10)
        {
            f << 0;
        }
        else if (p->isInTims())
        {
            f << 1 << " ";
            f << p->getTurnsInTims();
        }
        f << endl;
    }
    // outputs ownable property info
    for (int i = 0; i < ownable; ++i)
    {
        f << game[i]->getName() << " ";
        if (game[i]->isOwned())
        {
            f << game[i]->getOwner() << " ";
        }
        else
        {
            f << "BANK"
              << " ";
        }
        if (game[i]->isResidence() || game[i]->isGym())
        {
            f << 0;
        }
        else if (game[i]->isMortgaged())
        {
            f << -1;
        }
        else
        {
            f << game[i]->getImprovementLevel();
        }
    }
    f.close();
    cout << "The game has been saved to " << file << endl;
}

void Game::load(string file)
{
    ifstream f(file);
    string s;
    f >> s;
    numPlayers = stoi(s);

    for (int i = 0; i < numPlayers; ++i)
    {
        getline(f, s);
        stringstream ss(s);
        string s1;
        vector<string> s2;
        while (ss >> s1)
        {
            s2.push_back(s1);
        }
        string name = s2[0];
        char character = s2[1][0];
        order[i] = new Player{name, character};
        order[i]->setRollUpTheRimCards(stoi(s2[2]));
        order[i]->setMoney(stoi(s2[3]));
        int position = stoi(s2[4]);
        order[i]->setPosition(position);
        if (position == 10)
        {
            int inTims = stoi(s2[5]);
            if (inTims != 0)
            {
                order[i]->sendToTims();
                order[i]->setTurnsInTims(stoi(s2[6]));
            }
        }
    }

    for (int i = 0; i < ownable; ++i)
    {
        getline(f, s);
        stringstream ss(s);
        string s1;
        vector<string> s2;
        while (ss >> s1)
        {
            s2.push_back(s1);
        }
        string name = s2[0];
        string owner = s2[1];
        int improvements = stoi(s2[2]);
        for (int j = 0; j < pieces; ++j)
        {
            if (game[j]->getName() == name)
            {
                if (owner != "BANK")
                {
                    for (int k = 0; k < numPlayers; ++k)
                    {
                        if (order[k]->getName() == owner)
                        {
                            game[j]->setOwner(order[k]);
                            order[k]->addProperty(game[j]);
                            if (improvements == -1)
                            {
                                game[j]->mortgage(order[k]);
                            }
                            else
                            {
                                game[j]->setImprovementLevel(improvements);
                            }
                        }
                    }
                }
                else
                {
                    game[j]->setOwned(false);
                }
            }
        }
    }

    for (int i = 0; i < pieces; i++)
    {
        game[i]->notifyObservers();
    }

    cout << "The game has been loaded" << endl;
}
