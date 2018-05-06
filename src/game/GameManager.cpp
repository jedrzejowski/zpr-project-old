//
// Created by adam on 22.04.18.
//

#include <iostream>
#include <src/block/terrain/Stone.h>
#include <src/world/World.h>
#include "GameManager.h"

using namespace std;
using namespace Game;
using namespace Ogre;

GameManager::GameManager() : OgreBites::ApplicationContext("CraftMine") {

}

void GameManager::setup() {
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// register for input events
	addInputListener(this);

	// get a pointer to the already created root
	sceneManager = getRoot()->createSceneManager();

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator *shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	// without light we would just get a black screen
	Ogre::Light *light = sceneManager->createLight("MainLight");
	Ogre::SceneNode *lightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 10, 15);
	lightNode->attachObject(light);

	mainCamera = new Camera("MainCamera");
	addInputListener(mainCamera);


	auto world = World::World();
	world.appendTo(sceneManager->getRootSceneNode()->createChildSceneNode());

}

void GameManager::open() {
	getRoot()->startRendering();

	//while (true) {

	//	getRoot()->renderOneFrame();

	//}
}

bool GameManager::keyPressed(const OgreBites::KeyboardEvent &evt) {

	return true;
}

SceneManager *GameManager::getSceneManager() const {
	return sceneManager;
}
