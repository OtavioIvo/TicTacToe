#ifndef PLAYERMACHINE_H
#define PLAYERMACHINE_H

#include "player.h"

class PlayerMachine : public Player
{
private:
    struct Win {
        std::size_t _winCol {0};
        std::size_t _winRow {0};
        bool canWin {false};
    };


private:
    Win FindWinnablePlay(const Board&);

public:
    PlayerMachine();
    bool MakeAPlay(Board& board) override;

private:

};

#endif // PLAYERMACHINE_H
