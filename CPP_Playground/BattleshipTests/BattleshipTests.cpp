#include "pch.h"
#include "CppUnitTest.h"
#include "..\CPP_Playground\Battleship.cpp"
#include "..\CPP_Playground\Coordinate.cpp"
#include <list>

using namespace BattleshipGame;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BattleshipTests
{
	TEST_CLASS(BattleshipTests)
	{
	public:
		
		TEST_METHOD(NorthDirectionValid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(4, shipPosition, Direction::North);
			int expectedPosition[2] = { 5,6 };

			Coordinate nextCell= ship.NextCellInDirection(shipPosition);

			Assert::AreEqual(expectedPosition[0], nextCell.x);
			Assert::AreEqual(expectedPosition[1], nextCell.y);
		}

		TEST_METHOD(EastDirectionValid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(4, shipPosition, Direction::East);
			int expectedPosition[2] = { 6,5 };

			Coordinate nextCell = ship.NextCellInDirection(shipPosition);

			Assert::AreEqual(expectedPosition[0], nextCell.x);
			Assert::AreEqual(expectedPosition[1], nextCell.y);
		}


		TEST_METHOD(SouthDirectionValid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(4, shipPosition, Direction::South);
			int expectedPosition[2] = { 5,4 };

			Coordinate nextCell = ship.NextCellInDirection(shipPosition);

			Assert::AreEqual(expectedPosition[0], nextCell.x);
			Assert::AreEqual(expectedPosition[1], nextCell.y);
		}

		TEST_METHOD(WestDirectionValid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(4, shipPosition, Direction::West);
			int expectedPosition[2] = { 4,5 };

			Coordinate nextCell = ship.NextCellInDirection(shipPosition);

			Assert::AreEqual(expectedPosition[0], nextCell.x);
			Assert::AreEqual(expectedPosition[1], nextCell.y);
		}

		TEST_METHOD(CanGetTilesOccupiedByShip)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			int expectedOccupiedTiles[][2] = {{5,5},{4,5}, {3,5}};
			
			vector<Coordinate> actualOccupiedTiles = ship.GetCellsOccupiedByShip();

			Assert::AreEqual(expectedOccupiedTiles[0][1], actualOccupiedTiles[0].x);
			Assert::AreEqual(expectedOccupiedTiles[0][1], actualOccupiedTiles[0].y);
			Assert::AreEqual(expectedOccupiedTiles[1][0], actualOccupiedTiles[1].x);
			Assert::AreEqual(expectedOccupiedTiles[1][1], actualOccupiedTiles[1].y);
			Assert::AreEqual(expectedOccupiedTiles[2][0], actualOccupiedTiles[2].x);
			Assert::AreEqual(expectedOccupiedTiles[2][1], actualOccupiedTiles[2].y);
		}
	};
}
