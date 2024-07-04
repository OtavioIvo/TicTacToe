#ifndef MATCH_H
#define MATCH_H

#include "board.h"
#include "boardreferee.h"
#include "player.h"

class Match
{
private:
    Board _board;
    PlayerManager _allPlayers;
    BoardReferee _referee;
    std::size_t _turnCount;

public:
    Match();
    void Execute();
private:
    void Beginning();
    bool GameLoop(const Player& player);
    void EndMatch();
};

#endif // MATCH_H
