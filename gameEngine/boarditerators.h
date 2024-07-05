#ifndef BOARDITERATORS_H
#define BOARDITERATORS_H

#include <memory>
#include "playermark.h"

class BoardDimensions
{
public:
    static constexpr std::size_t Size() {return 3;}
    static constexpr std::size_t Columns() {return Size();}
    static constexpr std::size_t Rows() {return Size();}
};

class BoardRanges
{
private:
    BoardRanges() = delete;
public:
    constexpr BoardRanges(std::size_t row, std::size_t column) noexcept : _row(row), _column(column) {}
    std::size_t GetRow() {return _row; }
    std::size_t GetColumn() {return _column; }
private:
    std::size_t _row;
    std::size_t _column;
};

template<int _STEP, int _OFFSET>
class IterBasis
{
private:
    std::shared_ptr<Mark>* _ptr;
public:
    IterBasis(std::shared_ptr<Mark>* ptr) : _ptr(ptr) {}
    IterBasis& operator++()
    {
        _ptr += _STEP + _OFFSET;
        return *this;
    }
    std::shared_ptr<Mark>& operator*() { return *_ptr; }
};

struct DiagIterBasis : IterBasis<BoardDimensions::Size(), 1>
{
    DiagIterBasis(std::shared_ptr<Mark>* ptr) : IterBasis(ptr) {}
};

struct AntiDiagIterBasis : IterBasis<BoardDimensions::Size(), -1>
{
    AntiDiagIterBasis(std::shared_ptr<Mark>* ptr) : IterBasis(ptr) {}
};

struct ColumnIterBasis : IterBasis<BoardDimensions::Size(), 0>
{
    ColumnIterBasis(std::shared_ptr<Mark>* ptr) : IterBasis(ptr) {}
};

struct RowIterBasis : IterBasis<1, 0>
{
    RowIterBasis(std::shared_ptr<Mark>* ptr) : IterBasis(ptr) {}
};

template<class _BD>
struct BoardRef
{
    using value = _BD;
    using reference = const value*;
    using const_pointer_const_value = const value* const;
public:
    BoardRef(const_pointer_const_value board) : _board(board) {}
    reference Ref() const { return _board;}
private:
    const_pointer_const_value _board;
};

template<class _BD, class _IT, std::size_t _SROW, std::size_t _SCOL, std::size_t _EROW, std::size_t _ECOL>
struct BoardIterDiag : public BoardRef<_BD>
{
    using iterator = _IT;
    using const_iterator = const _IT;
    using BoardRef<_BD>::BoardRef;
    using BoardRef<_BD>::Ref;

    iterator begin()
    {
        return iterator(&Ref()->Space(_SROW, _SCOL));
    }
    iterator end()
    {
        return iterator(&Ref()->Space(_EROW, _ECOL));
    }
    const_iterator cbegin() const
    {
        return const_iterator(&Ref()->Space(_SROW, _SCOL));
    }
    const_iterator cend() const
    {
        return const_iterator(&Ref()->Space(_EROW, _ECOL));
    }

};

template<class _BD>
struct BoardIterRow : public BoardRef<_BD>
{
    using BoardRef<_BD>::BoardRef;
    using BoardRef<_BD>::Ref;

    BoardIterRow(_BD* board, std::size_t row)
        : BoardRef<_BD>(board), _row(row) {}
    RowIterBasis begin()
    {
        return RowIterBasis(&Ref()->Space(_row, 0));
    }
    RowIterBasis end()
    {
        return RowIterBasis(&Ref()->Space(_row, BoardDimensions::Columns()));
    }
private:
    std::size_t _row;
};

template<class _BD>
struct BoardIterColumn : BoardRef<_BD>
{
    using BoardRef<_BD>::BoardRef;
    using BoardRef<_BD>::Ref;

    BoardIterColumn(_BD* board, std::size_t column)
        : BoardRef<_BD>(board),_column(column) {}
    ColumnIterBasis begin()
    {
        return ColumnIterBasis(&Ref()->Space(0, _column));
    }
    ColumnIterBasis end()
    {
        return ColumnIterBasis(&Ref()->Space(BoardDimensions::Rows(), _column));
    }
private:
    std::size_t _column;
};
#endif // BOARDITERATORS_H
