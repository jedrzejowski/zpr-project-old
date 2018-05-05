//
// Created by adam on 01.05.18.
//

#include <iostream>
#include "Stone.h"

using namespace Block;

Ogre::MovableObject *Stone::get3dObject() {
	if (cube != nullptr)
		return cube;

	return cube = SolidAbstract::createCubeMesh("BlockStone", "Stone");
}
