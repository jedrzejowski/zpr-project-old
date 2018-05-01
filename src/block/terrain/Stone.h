//
// Created by adam on 01.05.18.
//

#pragma once

#include <src/block/SolidAbstract.h>

namespace Block {
	class Stone : public SolidAbstract {
	public:

		std::string getName() {
			return "stone";
		}

		Ogre::MovableObject *get3dObject();
	};
}