#include "match.h"


void Match::Execute()
{
    Beginning();
    while (GameLoop(_allPlayers.GetCurrentPlayer()))
    {
        _referee.CheckIfPlayerWins(_board, _allPlayers.GetCurrentPlayer());
        _allPlayers.PickNextPlayer();

    }
    EndMatch();
};

bool Match::GameLoop(const Player& player)
{
    return true;
}

void Match::Beginning()
{
    //_player.Randomize();
    _turnCount = 0;
}


void Match::EndMatch()
{

}
