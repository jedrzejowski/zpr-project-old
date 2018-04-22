//
// Created by adam on 22.04.18.
//


#include <iostream>
#include <src/game/GameWindow.h>


using namespace std;

int main(int argc, char *argv[]) {

	try {

		auto game = game::GameWindow();
		game.initApp();
		game.open();
		game.closeApp();

	} catch (exception &error) {
		cout << error.what();
	}

	return 0;
}
