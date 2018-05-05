//
// Created by adam on 01.05.18.
//
#pragma once

#include <Ogre.h>
#include "Abstract.h"

namespace Block {

	class SolidAbstract : public Abstract {
	protected:
		Ogre::MovableObject *cube = nullptr;

	public:
		static Ogre::ManualObject *createCubeMesh(Ogre::String name, Ogre::String matName);

		bool isSolid() {
			return true;
		}
	};

}

