//
// Created by adam on 01.05.18.
//

#pragma once

#include <string>
#include <Ogre.h>

namespace Block {

	class Abstract {
	public:
		virtual std::string getName() = 0;

		virtual Ogre::MovableObject *get3dObject() = 0;

		virtual bool isSolid() {
			return false;
		};
	};

}
