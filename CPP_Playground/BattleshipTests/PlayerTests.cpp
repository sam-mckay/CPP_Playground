#include "pch.h"
#include "CppUnitTest.h"
#include "..\CPP_Playground\Player.cpp"
#include <list>

using namespace BattleshipGame;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerTests
{
	TEST_CLASS(PlayerTests)
	{
		Player m_player;

		TEST_METHOD_INITIALIZE(Setup)
		{
			BattleshipBoard board = BattleshipBoard(10, 10);
			vector<Battleship*> ships = board.GenerateShips(3, 3);
			m_player = Player(board, ships);
		}

		TEST_METHOD(CanChooseASingleTarget)
		{
			m_player.ChooseRandomTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 1);
		}

		TEST_METHOD(CanChooseMultipleTargets)
		{
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 2);
			Assert::IsFalse(previousTargets.front() == previousTargets.back());			
		}

		TEST_METHOD(CanChooseMultipleTargets_10)
		{
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 10);
			Assert::IsFalse(previousTargets.front() == previousTargets.back());
		}

		TEST_METHOD(CanFindDuplicateTargets)
		{
			Coordinate target = Coordinate(5, 5);

			bool targetFound = m_player.HasTargetBeenSelectedPreviously(target);

			Assert::IsFalse(targetFound);

			m_player.ChooseRandomTarget();
			list<Coordinate> previousTargets = m_player.GetPreviousTargets();			
			bool wasSelected = m_player.HasTargetBeenSelectedPreviously(previousTargets.front());

			Assert::IsTrue(wasSelected);
		}

		TEST_METHOD(HandlesMoreTargetsThanBoardCells)
		{
			BattleshipBoard board = BattleshipBoard(2, 2);
			vector<Battleship*> ships = board.GenerateShips(1, 1);
			Player player = Player(board, ships);

			player.ChooseRandomTarget();
			player.ChooseRandomTarget();
			player.ChooseRandomTarget();
			player.ChooseRandomTarget();
			player.ChooseRandomTarget();

			list<Coordinate> previousTargets = player.GetPreviousTargets();

			Assert::AreEqual(4, (int)previousTargets.size());
		}

		TEST_METHOD(CanChoosePreciseTarget_Valid)
		{
			Coordinate target = Coordinate(3, 2);

			bool isTargetSelected = m_player.ChoosePreciseTarget(target);

		 	list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(isTargetSelected);
			Assert::IsTrue(target == previousTargets.front());
		}

		TEST_METHOD(CanChoosePreciseTarget_Invalid)
		{
			Coordinate target = Coordinate(-3, 2);

			bool isTargetSelected = m_player.ChoosePreciseTarget(target);

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsFalse(isTargetSelected);
		}

		
	};
}
