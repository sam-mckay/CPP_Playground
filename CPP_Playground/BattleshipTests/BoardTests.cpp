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
			m_board = BattleshipBoard(10, 10);
		}

		TEST_METHOD(CalculateBoardSize) 
		{
			BattleshipBoard board = BattleshipBoard(2, 2);
			
			Assert::AreEqual(4, board.MaxCellsInBoard());
		}

		TEST_METHOD(CanValidateTargets_Valid)
		{
			Coordinate target = Coordinate(3, 2);
			bool isTargetValid = m_board.IsCoordinateOnBoard(target);

			Assert::IsTrue(isTargetValid);
		}

		TEST_METHOD(CanValidateTargets_Invalid_BelowRange)
		{
			Coordinate target = Coordinate(-1, -2);
			bool isTargetValid = m_board.IsCoordinateOnBoard(target);

			Assert::IsFalse(isTargetValid);
		}

		TEST_METHOD(CanValidateTargets_Invalid_AboveRange)
		{
			Coordinate target = Coordinate(30, 26);

			bool isTargetValid = m_board.IsCoordinateOnBoard(target);

			Assert::IsFalse(isTargetValid);
		}

		TEST_METHOD(CanValidateTargets_Invalid_PartialAboveRange)
		{
			Coordinate target = Coordinate(30, 5);
			Coordinate target2 = Coordinate(5, 30);
			bool isTargetValid = m_board.IsCoordinateOnBoard(target);
			bool isTargetValid2 = m_board.IsCoordinateOnBoard(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}

		TEST_METHOD(CanValidateTargets_Invalid_PartialBelowRange)
		{
			Coordinate target = Coordinate(1, -2);
			Coordinate target2 = Coordinate(-1, 2);
			bool isTargetValid = m_board.IsCoordinateOnBoard(target);
			bool isTargetValid2 = m_board.IsCoordinateOnBoard(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}

		TEST_METHOD(CanValidateTargets_Invalid_AboveAndBelowRange)
		{
			Coordinate target = Coordinate(-1, 22);
			Coordinate target2 = Coordinate(11, -2);

			bool isTargetValid = m_board.IsCoordinateOnBoard(target);
			bool isTargetValid2 = m_board.IsCoordinateOnBoard(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}

		TEST_METHOD(CanGenerateSingleShipOnBoard)
		{
			vector<Battleship*> ships = m_board.GenerateShips(1, 5);

			Assert::AreEqual(1, (int)ships.size());
		}

		TEST_METHOD(CanGenerateMultipleShipsOnBoard)
		{
			vector<Battleship*> ships = m_board.GenerateShips(2, 5);

			Assert::AreEqual(2, (int)ships.size());
		}

		TEST_METHOD(CanValidateShipPostion_Valid)
		{
			Coordinate location = Coordinate(1, 1);
			Battleship ship = Battleship(5, location, Direction::North);
			bool isValid = m_board.IsValidShipLocation(ship);

			Assert::IsTrue(isValid);
		}

		TEST_METHOD(CanValidateShipPostion_Invalid_StartsOffBoard)
		{
			Coordinate location = Coordinate(-1, 1);
			Battleship ship = Battleship(5, location, Direction::North);
			bool isValid = m_board.IsValidShipLocation(ship);

			Assert::IsFalse(isValid);
		}

		TEST_METHOD(CanValidateShipPostion_Invalid_EndsOffBoard)
		{
			Coordinate location = Coordinate(1, 1);
			Battleship ship = Battleship(5, location, Direction::South);
			bool isValid = m_board.IsValidShipLocation(ship);

			Assert::IsFalse(isValid);
		}

		TEST_METHOD(CanValidateShipPostion_Invalid_OccupiesSameCellsAsAnotherShip)
		{
			vector<Battleship*> ships = m_board.GenerateShips(1, 5);

			Battleship* existingShip = ships.front();

			Coordinate location = Coordinate(existingShip->location.x, existingShip->location.y);
			Battleship ship = Battleship(5, location, existingShip->direction);

			bool isValid = m_board.IsValidShipLocation(ship);

			Assert::IsFalse(isValid);
		}
	};
}