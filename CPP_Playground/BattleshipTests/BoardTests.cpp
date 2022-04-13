#include "pch.h"
#include "CppUnitTest.h"
#include "..\CPP_Playground\BattleshipBoard.cpp"
#include <list>

using namespace BattleshipGame;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BoardTests
{
	TEST_CLASS(BoardTests)
	{
		BattleshipBoard m_board;

		TEST_METHOD_INITIALIZE(Setup)
		{
			
		}

		TEST_METHOD(CalculateBoardSize) 
		{
			BattleshipBoard board = BattleshipBoard(2, 2);
			
			Assert::AreEqual(4, board.MaxCellsInBoard());
		}
	};
}