#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>

#include "playermark.h"

class Board
{
public:
    constexpr Board() noexcept : _spaces() {}
    const std::shared_ptr<Mark>& GetSpace(std::size_t row, std::size_t col) const { return _spaces[3*row + col]; }
    constexpr std::size_t SizeRow() const noexcept { return _size; }
    constexpr std::size_t SizeColumn() const noexcept { return _size; }
private:
    constexpr static std::size_t _size {3};
    std::array<std::shared_ptr<Mark>,_size*_size> _spaces;
};

#endif // BOARD_H
