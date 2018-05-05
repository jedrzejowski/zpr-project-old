
#include <iostream>
#include <src/game/GameManager.h>


using namespace std;

int main(int argc, char *argv[]) {

	try {

		Game::GameManager::getInstance();
		Game::GameManager::getInstance().initApp();
		Game::GameManager::getInstance().open();
		Game::GameManager::getInstance().closeApp();

	} catch (exception &error) {
		cout << error.what();
	}

	return 0;
}
