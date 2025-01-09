#pragma once
#include "Cell.h"
#include <iostream>
#include <string>
#include <ctime>
#include <string>

namespace Board
{
    class Board
    {
    private:
        Cell** arrBoard;
        int rows, cols, minesCount;
        bool isInitialized;

        void countAdjacentCells();

    public:
        Board(int r, int c, int m);
        ~Board();

        void initializeBoard(int firstRow, int firstCol);
        void printBoard(bool revealMines = false);
        bool revealCell(int r, int c);
        bool checkWin();

        int getRows() const { return rows; }
        int getCols() const { return cols; }
        int getMinesCount() const { return minesCount; }
    };
}