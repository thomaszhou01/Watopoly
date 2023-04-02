#ifndef UNOWNABLEPROPERTY_H
#define UNOWNABLEPROPERTY_H
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include "boardPiece.h"

class UnownableProperty: public BoardPiece{
    int generateRandom(int begin, int end, int range);
    void OSAP(Player* p);
    void DCTimsLine(Player* p);
    void GoToTims(Player* p);
    void GooseNesting(Player* p);
    void Tuition(Player* p);
    void CoopFee(Player* p);
    void SLC(Player* p);
    void NeedlesHall(Player* p);

    public:
        UnownableProperty(std::string name, int position);
        void landedOn(Player* p) override;
        ~UnownableProperty() override;
};

#endif
