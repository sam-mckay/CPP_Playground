#include "pch.h"
#include "CppUnitTest.h"
#include "..\CPP_Playground\GameManager.cpp"
#include "..\CPP_Playground\EnemyPlayer.cpp"
#include <list>

using namespace BattleshipGame;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameManagerTests
{
	TEST_CLASS(GameManagerTests)
	{
	public:

		TEST_METHOD(NewGameCreation)
		{
			GameManager gameManager = GameManager();
			gameManager.NewGame(3, 10, 10, 10);

			int playerShipsCount = gameManager.player.GetShips().size();
			int aiPlayerShipsCount = gameManager.aiPlayer.GetShips().size();

			Assert::AreEqual(3, playerShipsCount);
			Assert::AreEqual(3, aiPlayerShipsCount);
		}
	};
}
