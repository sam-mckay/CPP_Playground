#include "pch.h"
#include "gmock\gmock.h"
//#include "gtest/gtest.h"

#include "../CPP_Playground/Battleship.h"
#include "../CPP_Playground/Direction.h"
#include "../CPP_Playground/Battleship.cpp"
#include <iostream>


using ::testing::AllOf;
using ::testing::Gt;
using ::testing::Lt;
using ::testing::StartsWith;
using ::testing::ElementsAre;

namespace BattleshipGame
{
	//class BattleshipTest : public ::testing::Test
	//{
	//protected:
	//	void SetUp() override {
	//		
	//	}
	//
	//	int position[2] = { 5,5 };
	//	Battleship ship = Battleship(4, position, Direction::North);
	//};


	TEST(BattleshipTest, NorthDirectionValid)
	{
		int shipPosition[2] = { 5,5 };
		Battleship ship = Battleship(4, shipPosition, Direction::North);
		int expectedPosition[2] = { 5,6 };

		int *nextCell;
		nextCell = ship.NextCellInDirection(shipPosition);

		EXPECT_EQ(expectedPosition[0], nextCell[0]);
		EXPECT_EQ(expectedPosition[1], nextCell[1]);
	}

	TEST(BattleshipTest, EastDirectionValid)
	{
		int shipPosition[2] = { 5,5 };
		Battleship ship = Battleship(4, shipPosition, Direction::East);
		int expectedPosition[2] = { 6,5 };

		int *nextCell = ship.NextCellInDirection(shipPosition);

		EXPECT_EQ(expectedPosition[0], nextCell[0]);
		EXPECT_EQ(expectedPosition[1], nextCell[1]);
	}


	TEST(BattleshipTest, SouthDirectionValid)
	{
		int shipPosition[2] = { 5,5 };
		Battleship ship = Battleship(4, shipPosition, Direction::South);
		int expectedPosition[2] = { 5,4 };

		int *nextCell = ship.NextCellInDirection(shipPosition);

		EXPECT_EQ(expectedPosition[0], nextCell[0]);
		EXPECT_EQ(expectedPosition[1], nextCell[1]);
	}

	TEST(BattleshipTest, WestDirectionValid)
	{
		int shipPosition[2] = { 5,5 };
		Battleship ship = Battleship(4, shipPosition, Direction::West);
		int expectedPosition[2] = { 4,5 };

		int *nextCell = ship.NextCellInDirection(shipPosition);

		EXPECT_EQ(expectedPosition[0], nextCell[0]);
		EXPECT_EQ(expectedPosition[1], nextCell[1]);
	}

	TEST(BattleshipTest, CanGetTilesOccupiedByShip)
	{
		int shipPosition[2] = { 5,5 };
		Battleship ship = Battleship(3, shipPosition, Direction::West);

		vector<int*> expectedOccupiedTiles;// = { {5,5},{4,5 }, {3,5} };
		//expectedOccupiedTiles.push_back({ 5,5 });
		vector<int*> actualOccupiedTiles = ship.GetCellsOccupiedByShip();

		EXPECT_THAT(actualOccupiedTiles[0], ElementsAre(5, 5));
		EXPECT_THAT(actualOccupiedTiles[0], ElementsAre(4, 5));
		EXPECT_THAT(actualOccupiedTiles[0], ElementsAre(3, 5));
		
	}
}