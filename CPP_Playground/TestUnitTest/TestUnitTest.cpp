#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_Playground/Battleship.h"
#include "../CPP_Playground/Direction.h"
#include "../CPP_Playground/Battleship.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitTest
{
	TEST_CLASS(TestUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int shipPosition[2] = { 5,5 };
			BattleshipGame::Battleship ship = BattleshipGame::Battleship::Battleship(4, shipPosition, Direction::North);
			int expectedPosition[2] = { 5,6 };

			int* nextCell;
			nextCell = ship.NextCellInDirection(shipPosition);

			Assert::AreEqual(expectedPosition[0], nextCell[0]);
			Assert::AreEqual(expectedPosition[1], nextCell[1]);
		}
	};
}
