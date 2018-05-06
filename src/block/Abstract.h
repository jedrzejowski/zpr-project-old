//
// Created by adam on 01.05.18.
//

#pragma once

#include <string>
#include <Ogre.h>

namespace Block {

	typedef std::tuple<int, int, int> BlockCoord;

	class Abstract {
	protected:
		Ogre::SceneNode* sceneNode = nullptr;
	public:

		virtual void appendTo(Ogre::SceneNode* sceneNode) = 0;

		virtual std::string getName() = 0;

		virtual Ogre::MovableObject *get3dObject() = 0;

		virtual bool isSolid() {
			return false;
		};
	};

}
