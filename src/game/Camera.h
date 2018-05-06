//
// Created by adam on 05.05.18.
//

#pragma once

#include <Ogre.h>
#include <Bites/OgreInput.h>
#include <Bites/OgreApplicationContext.h>


namespace Game {
	class Camera : public OgreBites::InputListener {
	public:
		Camera(const Ogre::String &name);

		void update(float dt);

		Ogre::SceneNode *getNode() { return cameraNode; }

		Ogre::Camera *getOgreCamera() { return camera; }

		void updatePosition();

	private:
		void initViewports();

		void frameRendered(const Ogre::FrameEvent &evt);
		bool keyPressed(const OgreBites::KeyboardEvent &evt);
		bool keyReleased(const OgreBites::KeyboardEvent &evt);
		bool mouseMoved(const OgreBites::MouseMotionEvent& evt);


		Ogre::Camera *camera;
		Ogre::SceneNode *cameraNode, *yawXNode, *yawYNode, *yawZNode;
		Ogre::Vector3 front, position, up;
		Ogre::Real moveScale;

		bool keyW = false, keyS = false, keyD = false, keyA = false;

	};
}



