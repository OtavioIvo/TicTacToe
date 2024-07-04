#include "winningstates.h"
#include "player.h"

const WinningStates::Moves WinningStates::_allStates {&CheckMainDiagonal, &CheckAntiDiagonal, &CheckAllColumns, &CheckAllRows};

bool WinningStates::CheckMainDiagonal(const Board& board, const Player& player) noexcept
{
    std::size_t i = 0;
    std::size_t j = 0;
    while ((i<board.SizeRow()) && (j< board.SizeColumn()))
    {
        if (board.GetSpace(i++,j++) != player.GetMarker())
        {
            return false;
        }
    }
    return true;
}

bool WinningStates::CheckAntiDiagonal(const Board& board, const Player& player) noexcept
{
    std::size_t i = 0;
    std::size_t j = board.SizeColumn();
    while ((i<board.SizeRow()) && (j>0))
    {
        if (board.GetSpace(i++, j-- -1) != player.GetMarker())
        {
            return false;
        }
    }
    return true;
}

bool WinningStates::CheckColumn(const Board& board, const Player& player, const std::size_t column) noexcept
{
    for (std::size_t row = 0; row<board.SizeRow(); ++row)
    {
        if (board.GetSpace(row, column) != player.GetMarker())
        {
            return false;
        }
    }
    return true;
}

bool WinningStates::CheckRow(const Board& board, const Player& player, const std::size_t row) noexcept
{
    for (std::size_t column = 0; column < board.SizeColumn(); ++column)
    {
        if (board.GetSpace(row, column) != player.GetMarker())
        {
            return false;
        }
    }
    return true;
}

bool WinningStates::CheckAllColumns(const Board& board, const Player& player) noexcept
{
    for (std::size_t column=0; column< board.SizeColumn(); ++column)
    {
        if(WinningStates::CheckColumn(board, player, column))
        {
            return true;
        }
    }
    return false;
}

bool WinningStates::CheckAllRows(const Board& board, const Player& player) noexcept
{
    for (std::size_t row=0; row< board.SizeRow(); ++row)
    {
        if(WinningStates::CheckRow(board, player, row))
        {
            return true;
        }
    }
    return false;
}

bool WinningStates::AnyWinner(const Board& board, const Player& player) noexcept
{
    return std::find_if(_allStates.cbegin(), _allStates.cend(), [&board, &player] (auto fun) { return fun(board, player) == true;});
}
