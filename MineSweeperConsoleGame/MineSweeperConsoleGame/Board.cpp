#include "Board.h"
#include <vector>
#include <cstdlib> 
#include <ctime>    
#include <iostream>

namespace Board
{
    using namespace std;  
    
        void Board::countAdjacentCells()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (arrBoard[i][j].isMine)
                    {
                        continue;
                    }
                    for (int x = -1; x <= 1; x++)
                    {
                        for (int y = -1; y <= 1; y++)
                        {
                            int ni = i + x;
                            int nj = j + y;
                            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && arrBoard[ni][nj].isMine)
                            {
                                arrBoard[i][j].adjacentMines++;
                            }
                        }
                    }

                    if (arrBoard[i][j].adjacentMines > 0)
                    {
                        arrBoard[i][j].value = '0' + arrBoard[i][j].adjacentMines;
                    }
                }
            }
            isInitialized = true;
        }

        Board::Board(int r, int c, int m) : rows(r), cols(c), minesCount(m), arrBoard(nullptr), isInitialized(false)
        {
            srand(time(0));
            arrBoard = new Cell * [rows];
            for (int i = 0; i < rows; i++)
            {
                arrBoard[i] = new Cell[cols];
            }
        }

        Board::~Board()
        {
            if (arrBoard != nullptr)
            {
                for (int i = 0; i < rows; i++)
                {
                    delete[] arrBoard[i];
                }
                delete[] arrBoard;
                arrBoard = nullptr;
            }
        }

        void Board::initializeBoard(int firstRow, int firstCol)
        {
            int count = 0;
            while (count < minesCount)
            {
                int r = rand() % rows;
                int c = rand() % cols;

                if (!arrBoard[r][c].isMine && !(r == firstRow && c == firstCol) && (r<firstRow - 1 || r> firstRow + 1 || c< firstCol - 1 || c> firstCol + 1))
                {
                    arrBoard[r][c].isMine = true;
                    count++;
                }
            }

            countAdjacentCells();
        }

        void Board::printBoard(bool revealMines)
        {
            cout << endl;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (arrBoard[i][j].isRevealed)
                    {
                        cout << arrBoard[i][j].value << " ";
                    }
                    else
                    {
                        if (revealMines && arrBoard[i][j].isMine)
                        {
                            cout << "* ";
                        }
                        else
                        {
                            cout << "- ";
                        }
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        bool Board::revealCell(int r, int c)
        {
            if (r < 0 || r >= rows || c < 0 || c >= cols || arrBoard[r][c].isRevealed)
            {
                return true;
            }

            arrBoard[r][c].isRevealed = true;

            if (arrBoard[r][c].isMine)
            {
                arrBoard[r][c].value = '*';
                return false;
            }

            if (arrBoard[r][c].adjacentMines == 0)
            {
                arrBoard[r][c].value = '0';

                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        revealCell(r + x, c + y);
                    }
                }
            }
            return true;
        }

        bool Board::checkWin()
        {
            int revealedCells = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (arrBoard[i][j].isRevealed)
                    {
                        revealedCells++;
                    }
                }
            }
            return revealedCells == (rows * cols - minesCount);
        }

 
}