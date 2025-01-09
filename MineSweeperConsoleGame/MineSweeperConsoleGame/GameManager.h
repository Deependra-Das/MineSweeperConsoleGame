#pragma once
#include "Board.h"
#include <iostream>

namespace GameManager
{
	class GameManager
	{
	private:
		Board::Board* board;
		int moves = 0;
		bool isGameOver = false;
		int isInitialized = false;
		int firstRow = -1;
		int firstCol = -1;

		void resetBoard();

	public:

		GameManager(int r, int c, int m);
		~GameManager();

		void play();
		void printBoxedSentence(std::string sentence);

	};
}