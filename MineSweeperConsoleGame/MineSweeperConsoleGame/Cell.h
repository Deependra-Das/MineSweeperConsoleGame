#pragma once


class Cell
{
public:
    bool isMine, isRevealed;
    char value;
    int adjacentMines;

    Cell() : isMine(false), isRevealed(false), value('-'), adjacentMines(0) {}
};

