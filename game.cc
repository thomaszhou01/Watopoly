#include "game.h"
#include "ownableProperty.h"
#include "unownableProperty.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Game::Game(): textDisplay{this}
{
    game.push_back(make_shared<UnownableProperty>("COLLECT OSAP", 0, 51, 81));
    game.push_back(make_shared<OwnableProperty>("AL", "Arts1", 40, 50, std::vector<int>{2, 10, 30, 90, 160, 250}, 1, false, false, 2, 51, 73));
    game.push_back(make_shared<UnownableProperty>("SLC", 2, 51, 65));
    game.push_back(make_shared<OwnableProperty>("ML", "Arts1", 60, 50, std::vector<int>{4, 20, 60, 180, 320, 450}, 3, false, false, 2, 51, 57));
    game.push_back(make_shared<UnownableProperty>("TUITION", 4, 51, 49));
    game.push_back(make_shared<OwnableProperty>("MKV", "Residence", 200, 0, std::vector<int>{}, 5, false, true, 4, 51, 41));
    game.push_back(make_shared<OwnableProperty>("ECH", "Arts2", 100, 50, std::vector<int>{6, 30, 90, 270, 400, 550}, 6, false, false, 3, 51, 33));
    game.push_back(make_shared<UnownableProperty>("NEEDLES HALL", 7, 51, 25));
    game.push_back(make_shared<OwnableProperty>("PAS", "Arts2", 100, 50, std::vector<int>{6, 30, 90, 270, 400, 550}, 8, false, false, 3, 51, 17));
    game.push_back(make_shared<OwnableProperty>("HH", "Arts2", 120, 50, std::vector<int>{8, 40, 100, 300, 450, 600}, 9, false, false, 3, 51, 9));
    game.push_back(make_shared<UnownableProperty>("DC Tims Line", 10, 51, 1));
    game.push_back(make_shared<OwnableProperty>("RCH", "Eng", 140, 100, std::vector<int>{10, 50, 150, 450, 625, 750}, 11, false, false, 3, 46, 1));
    game.push_back(make_shared<OwnableProperty>("PAC", "Gym", 150, 0, std::vector<int>{}, 12, true, false, 2, 41, 1));
    game.push_back(make_shared<OwnableProperty>("DWE", "Eng", 140, 100, std::vector<int>{10, 50, 150, 450, 625, 750}, 13, false, false, 3, 36, 1));
    game.push_back(make_shared<OwnableProperty>("CPH", "Eng", 160, 100, std::vector<int>{12, 60, 180, 500, 700, 900}, 14, false, false, 3, 31, 1));
    game.push_back(make_shared<OwnableProperty>("UWP", "Residence", 200, 0, std::vector<int>{}, 15, false, true, 4, 26, 1));
    game.push_back(make_shared<OwnableProperty>("LHI", "Health", 180, 100, std::vector<int>{14, 70, 200, 550, 750, 950}, 16, false, false, 3, 21, 1));
    game.push_back(make_shared<UnownableProperty>("SLC", 17, 16, 1));
    game.push_back(make_shared<OwnableProperty>("BMH", "Health", 180, 100, std::vector<int>{14, 70, 200, 550, 750, 950}, 18, false, false, 3, 11, 1));
    game.push_back(make_shared<OwnableProperty>("OPT", "Health", 200, 100, std::vector<int>{16, 80, 220, 600, 800, 1000}, 19, false, false, 3, 6, 1));
    game.push_back(make_shared<UnownableProperty>("Goose Nesting", 20, 1, 1));
    game.push_back(make_shared<OwnableProperty>("EV1", "Env", 220, 150, std::vector<int>{18, 90, 250, 700, 875, 1050}, 21, false, false, 3, 1, 9));
    game.push_back(make_shared<UnownableProperty>("NEEDLES HALL", 22, 1, 17));
    game.push_back(make_shared<OwnableProperty>("EV2", "Env", 220, 150, std::vector<int>{18, 90, 250, 700, 875, 1050}, 23, false, false, 3, 1, 25));
    game.push_back(make_shared<OwnableProperty>("EV3", "Env", 240, 150, std::vector<int>{20, 100, 300, 750, 925, 1100}, 24, false, false, 3, 1, 33));
    game.push_back(make_shared<OwnableProperty>("V1", "Residence", 200, 0, std::vector<int>{}, 25, false, true, 4, 1, 41));
    game.push_back(make_shared<OwnableProperty>("PHYS", "Sci1", 260, 150, std::vector<int>{22, 110, 330, 800, 975, 1150}, 26, false, false, 3, 1, 49));
    game.push_back(make_shared<OwnableProperty>("B1", "Sci1", 260, 150, std::vector<int>{22, 110, 330, 800, 975, 1150}, 27, false, false, 3, 1, 57));
    game.push_back(make_shared<OwnableProperty>("CIF", "Gym", 150, 0, std::vector<int>{}, 28, true, false, 2, 1, 65));
    game.push_back(make_shared<OwnableProperty>("B2", "Sci1", 280, 150, std::vector<int>{24, 120, 360, 850, 1025, 1200}, 29, false, false, 3, 1, 73));
    game.push_back(make_shared<UnownableProperty>("GO TO TIMS", 30, 1, 81));
    game.push_back(make_shared<OwnableProperty>("EIT", "Sci2", 300, 200, std::vector<int>{26, 130, 390, 900, 1100, 1275}, 31, false, false, 3, 6, 81));
    game.push_back(make_shared<OwnableProperty>("ESC", "Sci2", 300, 200, std::vector<int>{26, 130, 390, 900, 1100, 1275}, 32, false, false, 3, 11, 81));
    game.push_back(make_shared<UnownableProperty>("SLC", 33, 16, 81));
    game.push_back(make_shared<OwnableProperty>("C2", "Sci2", 320, 200, std::vector<int>{28, 150, 450, 1000, 1200, 1400}, 34, false, false, 3, 21, 81));
    game.push_back(make_shared<OwnableProperty>("REV", "Residence", 200, 0, std::vector<int>{}, 35, false, true, 4, 26, 81));
    game.push_back(make_shared<UnownableProperty>("NEEDLES HALL", 36, 31, 81));
    game.push_back(make_shared<OwnableProperty>("MC", "Math", 350, 200, std::vector<int>{35, 175, 500, 1100, 1300, 1500}, 37, false, false, 2, 36, 81));
    game.push_back(make_shared<UnownableProperty>("COOP FEE", 38, 41, 81));
    game.push_back(make_shared<OwnableProperty>("DC", "Math", 400, 200, std::vector<int>{50, 200, 600, 1400, 1700, 2000}, 39, false, false, 2, 46, 81));
}

void Game::InitializeOrder()
{
    cout << "How many players are playing?" << endl;
    // add guard
    while (true)
    {
        string temp="";
        getline(cin, temp);
        try{
            numPlayers = stoi(temp);
            if (numPlayers > 8 || numPlayers < 2)
            {
                cout << "Invalid number of players." << endl;
                cout << "Number of players must be between 2 and 8 (inclusive)" << endl;
            }
            else
            {
                break;
            }
        }
        catch(...){
            cout << "Please enter an integer" << endl;
        }
        
    }
    
    for (int i = 0; i < numPlayers; ++i)
    {
        string name = "";
        char character;
        while(true){
            cout << "Player " << i + 1 << ": ";
            cout << "Please enter your name: " << endl;
            getline(cin, name);
            if(name.find(" ") != string::npos){
                cout << "Your name cannot contain spaces" << endl;
            }
            else{
                break;
            }
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
            string temp = "";
            if (getline(cin, temp))
            {
                try{
                    if(temp.length() == 1){
                        character = temp[0];
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
                    else{
                        cout << "Please enter one of the options" << endl;
                    }
                }
                catch(...){
                    cout << "Please enter one of the options" << endl;
                }
            }
            else
            {
                cout << "Please enter one of the options" << endl;
            }
            if (success)
                break;
        }
        order.push_back(make_shared<Player>(name, character));
        orderIndex.push_back(i);
    }

    for (int i = 0; i < pieces; ++i)
    {
        game[i]->attach(&textDisplay);
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

std::vector<std::shared_ptr<BoardPiece>> Game::getGame()
{
    return game;
}

std::vector<shared_ptr<Player>> Game::getOrder()
{
    return order;
}

void Game::rollLogic(vector<int>& roll, bool& hasRolled, bool& rolledDouble, int& playerIndex, bool& over){
    int totalRoll = roll[0] + roll[1];
    int pos = order[playerIndex]->getPosition();
    int newPos;
    hasRolled = true;
    rolledDouble = false;
    cout << "You rolled: " << roll[0] << " & " << roll[1] << endl;
    if (roll[0] == roll[1])
    {
        consecutiveDoubles[orderIndex[playerIndex]]++;
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

            string input;
            bool canPass = true;
            if(order[playerIndex]->getTurnsInTims() >= 3){
                cout << "Its your third turn in the Tims line. You must pay $50 or use a RollUpTheRimCard (you have " << order[playerIndex]->getRollUpTheRimCards() << " cards) Options:"<< endl;
                cout << "-pay" << endl << "-card" << endl;
                canPass = false;
            }
            else{
                cout << "Would you like to pay $50 or use a RollUpTheRimCard (you have " << order[playerIndex]->getRollUpTheRimCards() << " cards)"<< endl;
                cout << "-pay" << endl << "-card" << endl << "-pass" << endl;
            }
            bool passed = false;
            while(!passed){
                getline(cin, input);
                if(canPass && input == "pass"){
                    cout << "You have passed" << endl;
                    passed = true;
                }
                else if(input == "pay"){
                    if(order[playerIndex]->getMoney() >= 50){
                        passed = true;
                        order[playerIndex]->subtractMoney(50);
                        cout << "You have paid $50" << endl;
                        order[playerIndex]->setInTims(false);
                        newPos = pos + totalRoll;
                        if(newPos >= 40){
                            order[playerIndex]->addMoney(200);
                            cout << "You passed the DC Tims Line. You gained $200" << endl;
                            newPos = newPos % 40;
                        }
                    }
                    else{
                        cout << "You don't have $50. ";
                        if(canPass){
                            //continue here
                            while(!passed){
                                cout << "Would you like to pass, or make the money? (pass, pay)" << endl;
                                getline(cin, input);
                                if(input == "pass"){
                                    cout << "You have passed" << endl;
                                    passed = true;
                                    break;
                                }
                                else if(input == "pay"){
                                    int initialPlayers = numPlayers;
                                    cout << "You do not have enough money to pay." << endl;
                                    cout << "Here are your following options:" << endl;
                                    cout << "-bankrupt" << endl;
                                    cout << "-trade <name> <money> <property>" << endl;
                                    cout << "-trade <name> <property> <property>" << endl;
                                    cout << "-trade <name> <property> <money>" << endl;
                                    cout << "-mortgage <property>" << endl;
                                    cout << "-improve <property> sell" << endl;
                                    makeMoney(playerIndex, newPos, over, hasRolled);
                                    if(initialPlayers == numPlayers){
                                        if(order[playerIndex]->getMoney() >= 50){
                                            passed = true;
                                            order[playerIndex]->subtractMoney(50);
                                            cout << "You have paid $50" << endl;
                                            order[playerIndex]->setInTims(false);
                                            newPos = pos + totalRoll;
                                            if(newPos >= 40){
                                                order[playerIndex]->addMoney(200);
                                                cout << "You passed the DC Tims Line. You gained $200" << endl;
                                                newPos = newPos % 40;
                                            }
                                        }
                                        else{
                                            cout << "You did not make enough, you have $" << order[playerIndex]->getMoney() << endl;
                                        }
                                    }
                                    else{
                                        passed = true;
                                    }
                                }
                                else{
                                    cout << "Invalid Option" << endl;
                                }
                            }
                        }
                        else{
                            cout << "Since it is your third turn in the DC Tims line, you must pay 50$" << endl;
                            cout << "You do not have enough money to pay." << endl;
                            cout << "Here are your following options:" << endl;
                            cout << "-bankrupt" << endl;
                            cout << "-trade <name> <money> <property>" << endl;
                            cout << "-trade <name> <property> <property>" << endl;
                            cout << "-trade <name> <property> <money>" << endl;
                            cout << "-mortgage <property>" << endl;
                            cout << "-improve <property> sell" << endl;
                            while(!passed){
                                int initialPlayers = numPlayers;
                                makeMoney(playerIndex, newPos, over, hasRolled);
                                if(initialPlayers == numPlayers){
                                    if(order[playerIndex]->getMoney() >= 50){
                                        passed = true;
                                        order[playerIndex]->subtractMoney(50);
                                        cout << "You have paid $50" << endl;
                                        order[playerIndex]->setInTims(false);
                                        newPos = pos + totalRoll;
                                        if(newPos >= 40){
                                            order[playerIndex]->addMoney(200);
                                            cout << "You passed the DC Tims Line. You gained $200" << endl;
                                            newPos = newPos % 40;
                                        }
                                    }
                                    else{
                                        cout << "You did not make enough, you have $" << order[playerIndex]->getMoney() << endl;
                                    }
                                }
                                else{
                                    passed = true;
                                }
                            }
                        }
                    }
                }
                else if(input == "card"){
                    if(order[playerIndex]->getRollUpTheRimCards() > 0){
                        order[playerIndex]->setRollUpTheRimCards(order[playerIndex]->getRollUpTheRimCards() - 1);
                        cout << "You used a RollUpTheRim card and left the DC Tims Line" << endl;

                        order[playerIndex]->setInTims(false);
                        newPos = pos + totalRoll;
                        if(newPos >= 40){
                            order[playerIndex]->addMoney(200);
                            cout << "You passed the DC Tims Line. You gained $200" << endl;
                            newPos = newPos % 40;
                        }
                        passed = true;
                    }
                    else{
                        cout << "You dont have a RollUpTheRim card" << endl;
                    }
                }
                else{
                    cout << "Invalid Option" << endl;
                }
            }
        }
    }
    else if (order[playerIndex]->isInTims() == false && consecutiveDoubles[orderIndex[playerIndex]] == 3)
    {
        cout << "Unfortunately this is your third time rolling doubles, so you are send to Tims DC Line" << endl;
        order[playerIndex]->sendToTims();
        newPos = 10;
        consecutiveDoubles[orderIndex[playerIndex]] = 0;
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
    if(!over){
        textDisplay.display();
        cout << "You are currently on: " << game[newPos]->getName() << endl;
    }
    game[newPos]->landedOn(order[playerIndex].get());
    game[newPos]->notifyObservers();
    
    while (newPos != order[playerIndex]->getPosition())
    {
        newPos = order[playerIndex]->getPosition();
        game[newPos]->landedOn(order[playerIndex].get());
        game[newPos]->notifyObservers();
        game[pos]->notifyObservers();
        textDisplay.display();
        cout << "You are currently on: " << game[newPos]->getName() << endl;
    }

    // buy/auction
    if (game[newPos]->isOwnable() == true && game[newPos]->isOwned() == false)
    {
        cout << "You are given the option to BUY the property for: $" << game[newPos]->getPrice() << " else the property will be AUCTIONED" << endl;

        while (true)
        {
            cout << "Would you like to buy the property? (Y/N)" << endl;
            string c = "";
            getline(cin, c);
            if (c == "Y")
            {
                game[newPos]->setOwned(true);
                game[newPos]->setOwner(order[playerIndex].get());
                order[playerIndex]->addProperty(game[newPos].get());
                game[newPos]->notifyObservers();
                cout << "You have succesfully purchased property: " << game[newPos]->getName() << endl;
                break;
            }
            else if (c == "N")
            {
                auction(game[newPos].get(), playerIndex);
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
        cout << "Here are your following options:" << endl;
        cout << "-bankrupt" << endl;
        cout << "-trade <name> <money> <property>" << endl;
        cout << "-trade <name> <property> <property>" << endl;
        cout << "-trade <name> <property> <money>" << endl;
        cout << "-mortgage <property>" << endl;
        cout << "-improve <property> sell" << endl;
    }
    while (game[newPos]->isTuitionPaid() == false && !over)
    {
        int initialPlayers = numPlayers;
        makeMoney(playerIndex, newPos, over, hasRolled);
        if(initialPlayers == numPlayers) game[newPos]->landedOn(order[playerIndex].get());
        else{
            break;
        }
    }
}

void Game::makeMoney(int& playerIndex, int& newPos, bool& over, bool& hasRolled){
    cout << "Please enter an option to get enough money:" << endl;
    string s;
    string s1 = "";
    getline(cin, s);
    stringstream ss(s);
    vector<string> cmd;
    cmd.clear();
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
            bool bankruptToPlayer = order[playerIndex]->setBankrupt(game[newPos]->getOwner());
            std::vector<BoardPiece*> propertiesOwnedByBankruptPlayer = order[playerIndex]->getProperties();
            if(bankruptToPlayer == false){
                for (auto i : propertiesOwnedByBankruptPlayer) {
                    auction(i, playerIndex);
                    i->notifyObservers();
                }
            }
            else{
                for (auto i : propertiesOwnedByBankruptPlayer) {
                    i->notifyObservers();
                }
            }
            game[oldPos]->notifyObservers();
            order.erase(order.begin() + playerIndex);
            orderIndex.erase(orderIndex.begin() + playerIndex);
            --numPlayers;

            if (numPlayers == 1)
            {
                cout << "The game is over. The winner of WATOPOLY is: " << order[0]->getName() << "!!!" << endl;
                over = true;
            }
            else
            {
                cout << "You gave control to the next player" << endl;
                consecutiveDoubles[orderIndex[playerIndex]] = 0;
                if(playerIndex >= numPlayers){
                    playerIndex = 0;
                }
                hasRolled = false;
                textDisplay.display();
                cout << "It is "<< order[playerIndex]->getName() << "'s turn. Please enter a command:" << endl;
                commands(order[playerIndex].get());
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
                    if (!game[i]->mortgage(order[playerIndex].get()))
                    {
                        cout << "This property does not belong to you" << endl;
                    }
                    else
                    {
                        cout << "You have sucessfully mortgaged " << cmd[1] << endl;
                        game[i]->notifyObservers();
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
                    if (game[i]->sellImprovement(order[playerIndex].get()))
                    {
                        cout << "You have sucessfully sold " << cmd[1] << endl;
                        game[i]->notifyObservers();
                    }
                    else{
                        cout << "You cannot sell " << cmd[1] << endl;
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
                    p = order[i].get();
                    flag = true;
                }
            }
            if (flag == true)
            {
                cout << cmd[1] << " do you accept this trade? (y or n)" << endl;
                string temp;
                bool acceptedTrade = false;
                getline(cin, temp);
                while(true){
                    if(temp == "y"){
                        acceptedTrade = true;
                        break;
                    }
                    else if(temp == "n"){
                        acceptedTrade = false;
                        break;
                    }
                    else{
                        cout << "Invalid input" << endl;
                    }
                }
                
                if (acceptedTrade && order[playerIndex]->trade(p, cmd[2], cmd[3]))
                {
                    cout << "You have sucessfulled traded with " << cmd[1] << endl;
                    for (int i = 0; i < pieces; ++i){
                        if (game[i]->getName() == cmd[2] || game[i]->getName() == cmd[3]){
                            game[i]->notifyObservers();
                        }
                    }
                }
                else{
                    cout << "Trade failed" << endl;
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

void Game::auction(BoardPiece *b, int playerThatStartedAuction)
{
    bool inAuction[8] = {true, true, true, true, true, true, true, true};
    inAuction[playerThatStartedAuction] = false;
    int numInAuction = numPlayers-1;

    string s = "";
    string s1 = "";
    vector<string> cmd;
    int bid = 0;

    cout << "The AUCTION will commence for " << b->getName() << endl;
    cout << "We will go in turns to raise the current bid or withdraw: raise <amount> / withdraw" << endl;
    cout << "The is bid is 0. " << endl;
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
                    
                    if (cmd.size() == 1 && cmd[0] == "withdraw")
                    {
                        inAuction[i] = false;
                        --numInAuction;
                        break;
                    }
                    else if (cmd.size() == 2 && cmd[0] == "raise")
                    {
                        try{
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
                        catch(...){
                            cout << "Invalid <amount>" << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid option" << endl;
                    }
                }
                else{
                    break;
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
            b->setOwner(order[i].get());
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
    while (over == false)
    {
        string s= "";
        string s1 = "";
        vector<string> cmd;
        cmd.clear();
        textDisplay.display();
        cout << "It is "<< order[playerIndex]->getName() << "'s turn. Please enter a command:" << endl;
        commands(order[playerIndex].get());
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
                vector<int> roll = rollDie();
                rollLogic(roll, hasRolled, rolledDouble, playerIndex, over);
            }
            else if (cmd[0] == "next")
            {
                if (hasRolled == true)
                {
                    cout << "You gave control to the next player" << endl;
                    consecutiveDoubles[orderIndex[playerIndex]] = 0;
                    playerIndex++;
                    if(playerIndex >= numPlayers){
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
                    if(order[playerIndex]->getMoney() >= 50){
                        order[playerIndex]->subtractMoney(50);
                        cout << "You have paid $50" << endl;
                        order[playerIndex]->setInTims(false);
                    }
                    else{
                        cout << "You do not have $50" << endl;
                    }
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
                        if (!game[i]->mortgage(order[playerIndex].get()))
                        {
                            cout << "This property does not belong to you" << endl;
                        }
                        else
                        {
                            cout << "You have sucessfully mortgaged " << cmd[1] << endl;
                            game[i]->notifyObservers();
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
                        if (!game[i]->unmortgage(order[playerIndex].get()))
                        {
                            cout << "This property does not belong to you" << endl;
                        }
                        else
                        {
                            cout << "You have sucessfully unmortgaged " << cmd[1] << endl;
                            game[i]->notifyObservers();
                            break;
                        }
                    }
                }
            }
            else if (cmd[0] == "save")
            {
                save(cmd[1]);
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
                            if (game[i]->sellImprovement(order[playerIndex].get()))
                            {
                                cout << "You have sucessfully sold " << cmd[1] << endl;
                                game[i]->notifyObservers();
                            }
                            else{
                                cout << "You cannot sell " << cmd[1] << endl;
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
                            if (game[i]->improve(order[playerIndex].get()))
                            {
                                cout << "You have sucessfully improved " << cmd[1] << endl;
                                game[i]->notifyObservers();
                            }
                            else{
                                cout << "You cannot improve " << cmd[1] << endl;
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
                    try{
                        int roll1 = stoi(cmd[1]);
                        int roll2 = stoi(cmd[2]);
                        if(roll1 >= 0 && roll2 >= 0){
                            vector<int> roll = testRoll(roll1, roll2);
                            rollLogic(roll, hasRolled, rolledDouble, playerIndex, over);
                        }
                        else{
                            cout << "Invalid roll <die1> <die2>" << endl;
                        }
                    }
                    catch(...){
                        cout << "Invalid roll <die1> <die2>" << endl;
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
                        p = order[i].get();
                        flag = true;
                    }
                }
                if (flag == true)
                {
                    cout << cmd[1] << " do you accept this trade? (y or n)" << endl;
                    string temp;
                    bool acceptedTrade = false;
                    getline(cin, temp);
                    while(true){
                        if(temp == "y"){
                            acceptedTrade = true;
                            break;
                        }
                        else if(temp == "n"){
                            acceptedTrade = false;
                            break;
                        }
                        else{
                            cout << "Invalid input" << endl;
                        }
                    }
                    
                    if (acceptedTrade && order[playerIndex]->trade(p, cmd[2], cmd[3]))
                    {
                        cout << "You have sucessfulled traded with " << cmd[1] << endl;
                        for (int i = 0; i < pieces; ++i){
                            if (game[i]->getName() == cmd[2] || game[i]->getName() == cmd[3]){
                                game[i]->notifyObservers();
                            }
                        }
                    }
                    else{
                        cout << "Trade failed" << endl;
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

        if(hasRolled && !over && (!rolledDouble || order[playerIndex]->isInTims())){
            cout << "Your turn has ended" << endl;
            cout << "_____________________________________________________" << endl;
            consecutiveDoubles[orderIndex[playerIndex]] = 0;
            playerIndex++;
            if(playerIndex >= numPlayers){
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

void Game::save(string file)
{
    ofstream f;
    f.open(file);
    f << numPlayers << endl; // outputs number of players
    // outputs player info

    for (int i = 0; i < numPlayers; ++i)
    {
        Player *p = order[i].get();
        f << p->getName() << " ";
        f << p->getCharacter() << " ";
        f << p->getRollUpTheRimCards() << " ";
        f << p->getMoney() << " ";
        f << p->getPosition() << " ";
        if (!p->isInTims() && p->getPosition() == 10)
        {
            f << 0;
        }
        else if (p->isInTims() && p->getPosition() == 10)
        {
            f << 1 << " ";
            f << p->getTurnsInTims();
        }
        f << endl;
    }
    // outputs ownable property info
    for (int i = 0; i < pieces; ++i)
    {
        if(game[i]->isOwnable()){
            f << game[i]->getName() << " ";
            if (game[i]->isOwned())
            {
                f << game[i]->getOwner()->getName() << " ";
            }
            else
            {
                f << "BANK" << " ";
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
            f << endl;
        }
    }
    f.close();
    cout << "The game has been saved to " << file << endl;
}

void Game::load(string file)
{
    ifstream f(file);
    string s;
    getline(f, s);
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
        order.push_back(make_shared<Player>(name, character));
        orderIndex.push_back(i);
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
    while(getline(f, s)){
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
                            game[j]->setOwner(order[k].get());
                            order[k]->addProperty(game[j].get());
                            if (improvements == -1)
                            {
                                game[j]->mortgage(order[k].get());
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
    for (int i = 0; i < pieces; ++i)
    {
        game[i]->attach(&textDisplay);
        game[i]->notifyObservers();
    }

    cout << "The game has been loaded" << endl;
}
