//
// Created by adam on 22.04.18.
//

#include <iostream>
#include <src/block/terrain/Stone.h>
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



	SceneNode* world = sceneManager->getRootSceneNode()->createChildSceneNode();

	SceneNode* chunk1 = world->createChildSceneNode();
	SceneNode* chunk2 = world->createChildSceneNode();

	auto stone1 = Block::Stone();
	auto stone2 = Block::Stone();

	chunk1->setPosition(0,2,0);
	chunk1->attachObject(stone1.get3dObject());

	chunk2->setPosition(0,-2,0);
	chunk2->attachObject(stone2.get3dObject());


}

void GameManager::open() {
	getRoot()->startRendering();

}

bool GameManager::keyPressed(const OgreBites::KeyboardEvent &evt) {
	mainCamera->moveFromEvent(evt);

	return true;
}

SceneManager *GameManager::getSceneManager() const {
	return sceneManager;
}
