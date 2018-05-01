//
// Created by adam on 01.05.18.
//

#include <src/sys/ResourceLoader.h>
#include <iostream>
#include "Stone.h"

using namespace Block;

Ogre::MovableObject *cube = nullptr;

Ogre::MovableObject *Stone::get3dObject() {
	if (cube != nullptr)
		return cube;

	if (ResourceLoader::loadImage("stone", "../assets/textures/block/stone.png"))
		std::cout << "kurwa" << std::flush;
	std::cout << "huj" << std::flush;

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(
			"BlockStone", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	//material->getTechnique(0)->getPass(0)->setVertexColourTracking(Ogre::TVC_AMBIENT);
	material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTexture

	cube = SolidAbstract::createCubeMesh("BlockStone", "BlockStone");

	return cube;
}
