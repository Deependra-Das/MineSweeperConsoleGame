#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"

using namespace std;

void printBoxedSentence(const string& sentence)
{
    int length = sentence.length();
    cout << "+" << string(length + 2, '-') << "+" << endl;
    cout << "| " << sentence << " |" << endl;
    cout << "+" << string(length + 2, '-') << "+" << endl;
}

int main() 
{
    printBoxedSentence("Welcome to Minesweeper");

    cout << "\n\nRULES: " << endl;
    cout << "1. The board is divided into cells, with mines randomly distributed." << endl;
    cout << "2. To win, you need to open all the cells in limited number of moves." << endl;
    cout << "3. The number on a cell reveals the number of mines adjacent to it." << endl;
    cout << "4. Use the revealed cells to determine whether the next cell is safe or contains mine." << endl;

    cout << "\n\nHow to Play: " << endl;
    cout << "1. Player will input x & y cooardinates where they want to click to open cell." << endl;
    cout << "2. On every step, win & lose conditions will be checked then board will be printed." << endl << endl << endl;

    int rows, cols, minesCount, minValue = 9, maxValue = 20;

    do {
        cout << "Enter number of rows ("<< minValue << " >= number of row <= "<< maxValue <<"):";
        cin >> rows;
        if (rows < minValue) 
        {
            cout << "Error: Number of rows must be more than " << minValue << "!" << endl << endl;
        }
        else if (rows > maxValue)
        {
            cout << "Error: Number of rows must be less than " << maxValue << "!" << endl << endl;
        }
    } while (rows < minValue || rows > maxValue);

    do {
        cout << "Enter number of columns (" << minValue << " >= number of columns <= " << maxValue << "):";
        cin >> cols;
        if (cols < minValue)
        {
            cout << "Error: Number of columns must be more than " << minValue << "!" << endl << endl;
        }
        else if (cols > maxValue)
        {
            cout << "Error: Number of columns must be less than " << maxValue << "!" << endl << endl;
        }
    } while (cols < minValue || cols > maxValue);

    do {
        cout << "Enter number of mines (1" << " >= number of mines <= " << (rows * cols) / 2 << "):";
        cin >> minesCount;
        if (minesCount < 1 || minesCount >(rows * cols) / 2) {
            cout << "Error: Mines count must be between 1 and " << (rows * cols) / 2 << "!" << endl;
        }
    } while (minesCount < 1 || minesCount >(rows * cols) / 2);

    GameManager::GameManager* newGame = new GameManager::GameManager(rows, cols, minesCount);
    newGame->play();

    return 0;


}