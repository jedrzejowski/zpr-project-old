//
// Created by adam on 22.04.18.
//

#ifndef GKOM_ANIMATION_GAME_H
#define GKOM_ANIMATION_GAME_H


#include <Ogre.h>
#include <Bites/OgreInput.h>
#include <Bites/OgreApplicationContext.h>
#include "Camera.h"

namespace Game {

	class GameManager : public OgreBites::ApplicationContext, public OgreBites::InputListener {

		//region Singleton

	public:
		static GameManager &getInstance() {
			static GameManager instance; // Guaranteed to be destroyed.
			// Instantiated on first use.
			return instance;
		}

	public:
		GameManager(GameManager const &) = delete;

		void operator=(GameManager const &)  = delete;

	protected:
		GameManager();

		//endregion

	protected:
		Ogre::SceneManager *sceneManager;
		Camera *mainCamera;

		//region Getters
	public:
		Ogre::SceneManager *getSceneManager() const;
		//endregion

	public:

		bool keyPressed(const OgreBites::KeyboardEvent &evt);

		void setup();

		void open();
	};

}


#endif //GKOM_ANIMATION_GAME_H
