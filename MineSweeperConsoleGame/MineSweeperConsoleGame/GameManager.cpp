#include "GameManager.h"

namespace GameManager
{
    using namespace std;

    GameManager::GameManager(int rows, int cols, int minesCount)
    {
        board = new Board::Board(rows, cols, minesCount);
    }

    GameManager::~GameManager()
    {
        delete(board);
    }

    void GameManager::resetBoard()
    {
        int moves = 0;
        bool isGameOver = false;
        int isInitialized = false;
        int firstRow = -1;
        int firstCol = -1;
    }

    void GameManager::play()
    {
        resetBoard();

        int rows = board->getRows();
        int cols = board->getCols();
        int minesCount = board->getMinesCount();

        while (!isInitialized)
        {
            cout << "\n\nTo start playing, enter your first move: " << endl;
            cout << "Row (0-" << rows -1 << ") : ";
            cin >> firstRow;
            cout << "Column (0-" << cols - 1 << ") : ";
            cin >> firstCol;

            if (firstRow < 0 || firstRow >= rows || firstCol < 0 || firstCol >= cols)
            {
                cout << "Invalid Input. Try Again." << endl;
                isInitialized = false;
            }
            else
            {
                isInitialized = true;
                board->initializeBoard(firstRow, firstCol);
                isGameOver = !board->revealCell(firstRow, firstCol);
                moves++;
                if (board->checkWin())
                {
                    printBoxedSentence("Congratulations! You won the game!");
                    isGameOver = true;
                }
                //printBoard(true); // to check the mine positions
                board->printBoard();
            }
        }

        int totalMoves = rows * cols - minesCount;

        while (!isGameOver && moves < totalMoves)
        {
            int rValue, cValue;

            cout << "Moves Left : " << totalMoves - moves << endl;
            cout << "Enter your next move:" << endl;
            cout << "Row (0-" << rows - 1 << ") : ";
            cin >> rValue;
            cout << "Column (0-" << cols - 1 << ") : ";
            cin >> cValue;

            if (rValue < 0 || rValue >= rows || cValue < 0 || cValue >= cols)
            {
                cout << "Invalid Input. Try Again." << endl;
                continue;
            }

            isGameOver = !board->revealCell(rValue, cValue);
            moves++;
            board->printBoard();

            if (isGameOver)
            {
               
                printBoxedSentence("Game Over! You hit a mine!");
                board->printBoard(true);
            }
            else if (board->checkWin())
            {

                printBoxedSentence("Congratulations! You won the game!");
                board->printBoard();
                break;
            }
        }

        if (moves >= totalMoves)
        {

            printBoxedSentence("You are out of Moves!");
        }


        printBoxedSentence("Game has Ended | Thank you for Playing");

    }

    void GameManager::printBoxedSentence(std::string sentence)
    {
        int length = sentence.length();
        cout << "+" << std::string(length + 2, '-') << "+" << endl;
        cout << "| " << sentence << " |" << endl;
        cout << "+" << std::string(length + 2, '-') << "+" << endl;
    }
}