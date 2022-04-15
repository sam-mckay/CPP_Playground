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

		TEST_METHOD(CanCheckHits_Valid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(5, 5);

			bool isHit = ship.CheckIfHit(target);

			Assert::IsTrue(isHit);
		}

		TEST_METHOD(CanCheckHits_Invalid)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(6, 6);

			bool isHit = ship.CheckIfHit(target);

			Assert::IsFalse(isHit);
		}

		TEST_METHOD(CanCheckHits_Multiple)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(5, 5);
			Coordinate target2 = Coordinate(4, 5);

			bool isHit = ship.CheckIfHit(target);
			bool isHit2 = ship.CheckIfHit(target2);
			

			Assert::IsTrue(isHit);
			Assert::IsTrue(isHit2);
			Assert::AreEqual(2, ship.CheckHitCount());
		}

		TEST_METHOD(ShipDestroyedWhenAllCellsHit)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(5, 5);
			Coordinate target2 = Coordinate(4, 5);
			Coordinate target3 = Coordinate(3, 5);

			ship.CheckIfHit(target);
			ship.CheckIfHit(target2);
			ship.CheckIfHit(target3);

			Assert::IsTrue(ship.CheckIfDestroyed());
		}

		TEST_METHOD(ShipDestroyedWhenAllCellsHit_NonSequential)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(4, 5);
			Coordinate target2 = Coordinate(3, 5);
			Coordinate target3 = Coordinate(5, 5);

			ship.CheckIfHit(target);
			ship.CheckIfHit(target2);
			ship.CheckIfHit(target3);

			Assert::IsTrue(ship.CheckIfDestroyed());
		}

		TEST_METHOD(ShipOnlyDestroyedWhenAllCellsHit)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(5, 5);
			Coordinate target2 = Coordinate(4, 5);
			
			ship.CheckIfHit(target);
			ship.CheckIfHit(target2);
			
			Assert::IsFalse(ship.CheckIfDestroyed());
		}

		TEST_METHOD(ShipOnlyDestroyedWhenAllCellsHit_NonSequential)
		{
			Coordinate shipPosition = Coordinate(5, 5);
			Battleship ship = Battleship(3, shipPosition, Direction::West);

			Coordinate target = Coordinate(5, 5);
			Coordinate target2 = Coordinate(3, 5);

			ship.CheckIfHit(target);
			ship.CheckIfHit(target2);

			Assert::IsFalse(ship.CheckIfDestroyed());
		}

		
	};
}
