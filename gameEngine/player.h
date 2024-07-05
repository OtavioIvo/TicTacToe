#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "playermark.h"
#include "board.h"

class Player
{
protected:
    Player(std::shared_ptr<Mark> mark);
public:
    Player() = delete;
    Player(Player&& in) = default;
    Player(const Player& in) = default;

    Player& operator=(const Player& in) = delete;
    Player& operator=(Player&& in) = delete;

    virtual ~Player() {}

    virtual bool MakeAPlay(Board& board) = 0;

    const std::shared_ptr<Mark>& GetMarker() const;
private:
    std::shared_ptr<Mark> _marker;
};


class PlayerManager
{
    std::array<std::unique_ptr<Player>, 2> _players;
public:
    PlayerManager();
    const std::unique_ptr<Player>& PickNextPlayer() noexcept;
    const Player& GetCurrentPlayer() const noexcept;
};

#endif // PLAYER_H
