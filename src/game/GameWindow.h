//
// Created by adam on 22.04.18.
//

#ifndef GKOM_ANIMATION_GAME_H
#define GKOM_ANIMATION_GAME_H


#include <Ogre.h>
#include <Bites/OgreInput.h>
#include <Bites/OgreApplicationContext.h>

namespace Game {

	class GameWindow : public OgreBites::ApplicationContext, public OgreBites::InputListener {
	protected:
	public:

		GameWindow();

		bool keyPressed(const OgreBites::KeyboardEvent &evt);

		void setup();

		void open();
	};

}


#endif //GKOM_ANIMATION_GAME_H
