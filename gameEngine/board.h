#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include "boarditerators.h"
#include "playermark.h"




class Board
{
    using ColumnIter = BoardIterColumn<Board>;
    using const_column_iter = const ColumnIter;
    using RowIter = BoardIterRow<Board>;
    using DiagonalIter = BoardIterDiag<Board, DiagIterBasis, 0, 0, BoardDimensions::Size(), BoardDimensions::Size()>;
    using const_diagonal_iter = const DiagonalIter;
    using AntiDiagonalIter = BoardIterDiag<Board, AntiDiagIterBasis, 0, BoardDimensions::Size(), BoardDimensions::Size(), 0>;
private:
    const std::shared_ptr<Mark>& operator()(std::size_t row, std::size_t col) const { return _spaces[3*row + col]; }

public:
    constexpr Board() noexcept : _spaces() {}
    std::shared_ptr<Mark>& Space(std::size_t row, std::size_t col) { return const_cast<std::shared_ptr<Mark>&>(operator()(row, col)); }
    const std::shared_ptr<Mark>& GetSpace(std::size_t row, std::size_t col) const { return operator()(row, col); }
    constexpr std::size_t SizeRow() const noexcept { return BoardDimensions::Rows(); }
    constexpr std::size_t SizeColumn() const noexcept { return BoardDimensions::Columns(); }
    DiagonalIter IterDiagonal() const { return const_diagonal_iter(this);}
    AntiDiagonalIter IterAntiDiagonal() { return AntiDiagonalIter(this); }
    ColumnIter IterColumn(std::size_t column) { return ColumnIter(this, column); }
    RowIter IterRow(std::size_t row) { return RowIter(this, row); }


private:
    std::array<std::shared_ptr<Mark>, BoardDimensions::Rows()*BoardDimensions::Columns()> _spaces;
};

#endif // BOARD_H
