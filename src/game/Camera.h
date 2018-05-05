//
// Created by adam on 05.05.18.
//

#pragma once
#include <Ogre.h>
#include <Bites/OgreInput.h>


namespace Game {
	class Camera {
	public:
		Camera(const Ogre::String &name);

		void update(float dt);

		Ogre::SceneNode *getNode() { return cameraNode; }

		Ogre::Camera *getOgreCamera() { return camera; }

		void moveFromEvent(const OgreBites::KeyboardEvent &evt);
		void update();

	private:
		void initViewports();


		Ogre::Camera *camera;
		Ogre::SceneNode *cameraNode;
		Ogre::Vector3 front, position, up;
		Ogre::Real moveScale;

		bool keyW, keyS, keyD, keyA;

	};
}



