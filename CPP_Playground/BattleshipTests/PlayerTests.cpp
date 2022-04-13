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
			m_player = Player(board);
		}

		TEST_METHOD(CanChooseASingleTarget)
		{
			m_player.ChooseTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 1);
		}

		TEST_METHOD(CanChooseAMultipleTargets)
		{
			m_player.ChooseTarget();
			m_player.ChooseTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 2);
			Assert::IsFalse(previousTargets.front() == previousTargets.back());			
		}

		TEST_METHOD(CanFindDuplicateTargets)
		{
			Coordinate target = Coordinate(5, 5);

			bool targetFound = m_player.HasTargetBeenSelectedPreviously(target);

			Assert::IsFalse(targetFound);

			m_player.ChooseTarget();
			list<Coordinate> previousTargets = m_player.GetPreviousTargets();			
			bool wasSelected = m_player.HasTargetBeenSelectedPreviously(previousTargets.front());

			Assert::IsTrue(wasSelected);
		}

		TEST_METHOD(HandlesMoreTargetsThanBoardCells)
		{
			BattleshipBoard board = BattleshipBoard(2, 2);
			Player player = Player(board);

			player.ChooseTarget();
			player.ChooseTarget();
			player.ChooseTarget();
			player.ChooseTarget();
			player.ChooseTarget();

			list<Coordinate> previousTargets = player.GetPreviousTargets();

			//Assert::IsTrue(previousTargets.size() == 4);
			Assert::AreEqual(4, (int)previousTargets.size());
		}
	};
}
