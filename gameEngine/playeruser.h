#ifndef PLAYERUSER_H
#define PLAYERUSER_H

#include "player.h"

class PlayerUser : public Player
{
public:
    PlayerUser();
    bool MakeAPlay(Board& board) override;
};

#endif // PLAYERUSER_H
