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
			m_player.ChooseRandomTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 1);
		}

		TEST_METHOD(CanChooseAMultipleTargets)
		{
			m_player.ChooseRandomTarget();
			m_player.ChooseRandomTarget();

			list<Coordinate> previousTargets = m_player.GetPreviousTargets();

			Assert::IsTrue(previousTargets.size() == 2);
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
			Player player = Player(board);

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

		TEST_METHOD(CanValidateTargets_Valid)
		{
			Coordinate target = Coordinate(3, 2);
			bool isTargetValid = m_player.IsTargetValid(target);

			Assert::IsTrue(isTargetValid);
		}

		TEST_METHOD(CanValidateTargets_Invalid_BelowRange)
		{
			Coordinate target = Coordinate(-1, -2);
			bool isTargetValid = m_player.IsTargetValid(target);

			Assert::IsFalse(isTargetValid);
		}

		TEST_METHOD(CanValidateTargets_Invalid_AboveRange)
		{
			Coordinate target = Coordinate(30, 26);			

			bool isTargetValid = m_player.IsTargetValid(target);
			
			Assert::IsFalse(isTargetValid);			
		}

		TEST_METHOD(CanValidateTargets_Invalid_PartialAboveRange)
		{
			Coordinate target = Coordinate(30, 5);
			Coordinate target2 = Coordinate(5, 30);
			bool isTargetValid = m_player.IsTargetValid(target);
			bool isTargetValid2 = m_player.IsTargetValid(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}

		TEST_METHOD(CanValidateTargets_Invalid_PartialBelowRange)
		{
			Coordinate target = Coordinate(1, -2);
			Coordinate target2 = Coordinate(-1, 2);
			bool isTargetValid = m_player.IsTargetValid(target);
			bool isTargetValid2 = m_player.IsTargetValid(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}

		TEST_METHOD(CanValidateTargets_Invalid_AboveAndBelowRange)
		{
			Coordinate target = Coordinate(-1, 22);
			Coordinate target2 = Coordinate(11, -2);

			bool isTargetValid = m_player.IsTargetValid(target);
			bool isTargetValid2 = m_player.IsTargetValid(target2);

			Assert::IsFalse(isTargetValid);
			Assert::IsFalse(isTargetValid2);
		}
	};
}
