//
// Created by adam on 22.04.18.
//

#include <iostream>
#include <src/block/terrain/Stone.h>
#include "GameWindow.h"

using namespace std;
using namespace Game;
using namespace Ogre;

ManualObject* createCubeMesh(Ogre::String name, Ogre::String matName) {

	ManualObject* cube = new ManualObject(name);
	cube->begin(matName);

	cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(1,0);
	cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(0,1);
	cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(1,1);
	cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(0,0);
	cube->position(0.5,0.5,1.0);cube->normal(0.666667,0.333333,0.666667);cube->textureCoord(1,0);
	cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(0,1);
	cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(1,1);
	cube->position(-0.5,0.5,1.0);cube->normal(-0.408248,0.816497,0.408248);cube->textureCoord(0,0);
	cube->position(-0.5,0.5,0.0);cube->normal(-0.666667,0.333333,-0.666667);cube->textureCoord(0,1);
	cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(1,1);
	cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(1,0);
	cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(0,1);
	cube->position(0.5,0.5,0.0);cube->normal(0.408248,0.816497,-0.408248);cube->textureCoord(1,1);
	cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(0,0);
	cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(1,0);
	cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(0,0);
	cube->position(-0.5,0.5,1.0);cube->normal(-0.408248,0.816497,0.408248);cube->textureCoord(1,0);
	cube->position(0.5,0.5,0.0);cube->normal(0.408248,0.816497,-0.408248);cube->textureCoord(0,1);
	cube->position(-0.5,0.5,0.0);cube->normal(-0.666667,0.333333,-0.666667);cube->textureCoord(1,1);
	cube->position(0.5,0.5,1.0);cube->normal(0.666667,0.333333,0.666667);cube->textureCoord(0,0);

	cube->triangle(0,1,2);		cube->triangle(3,1,0);
	cube->triangle(4,5,6);		cube->triangle(4,7,5);
	cube->triangle(8,9,10);		cube->triangle(10,7,8);
	cube->triangle(4,11,12);	cube->triangle(4,13,11);
	cube->triangle(14,8,12);	cube->triangle(14,15,8);
	cube->triangle(16,17,18);	cube->triangle(16,19,17);
	cube->end();

	return cube;

}

GameWindow::GameWindow() : OgreBites::ApplicationContext("CraftMine") {

}

void GameWindow::setup() {
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// register for input events
	addInputListener(this);

	// get a pointer to the already created root
	Ogre::Root *root = getRoot();
	Ogre::SceneManager *scnMgr = root->createSceneManager();

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator *shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);

	// without light we would just get a black screen
	Ogre::Light *light = scnMgr->createLight("MainLight");
	Ogre::SceneNode *lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 10, 15);
	lightNode->attachObject(light);

	// also need to tell where we are
	Ogre::SceneNode *camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 5, 15);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	Ogre::Camera *cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);

	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);

	// finally something to render
//	Ogre::Entity *ent = scnMgr->createEntity("Sinbad.mesh");
//	Ogre::SceneNode *node = scnMgr->getRootSceneNode()->createChildSceneNode();
//	node->attachObject(ent);

	//
	auto stone = Block::Stone();

	SceneNode* mNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	mNode->setPosition(0,0.5,0);
	mNode->attachObject(stone.get3dObject());

}

void GameWindow::open() {
	getRoot()->startRendering();
}

bool GameWindow::keyPressed(const OgreBites::KeyboardEvent &evt) {
	if (evt.keysym.sym == SDLK_ESCAPE) {
	}

	return true;
}
