//
// Created by adam on 05.05.18.
//

#include <iostream>
#include "Camera.h"
#include "GameManager.h"

using namespace Game;

Camera::Camera(const Ogre::String &name) {
	camera = GameManager::getInstance().getSceneManager()->createCamera(name);
	camera->setNearClipDistance(.1);
	camera->setAutoAspectRatio(true);

	cameraNode = GameManager::getInstance().getSceneManager()->getRootSceneNode()->createChildSceneNode();
	yawXNode = cameraNode->createChildSceneNode();
	yawYNode = yawXNode->createChildSceneNode();
	yawZNode = yawYNode->createChildSceneNode();
	yawZNode->attachObject(camera);


	front = Ogre::Vector3(0, 0, -1);
	up = Ogre::Vector3(0, 1, 0);
	position = Ogre::Vector3(0, 0, 15);
	moveScale = 0.1;

	yawYNode->rotate(Ogre::Vector3(0, 0, 1), Ogre::Degree(90), Ogre::Node::TS_LOCAL);
	yawZNode->rotate(Ogre::Vector3(0, 0, -1), Ogre::Degree(90), Ogre::Node::TS_LOCAL);

	initViewports();
}


void Camera::initViewports() {
	Ogre::Viewport *vp = GameManager::getInstance().getRenderWindow()->addViewport(camera);
	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	camera->setAspectRatio(
			Ogre::Real(vp->getActualWidth()) /
			Ogre::Real(vp->getActualHeight()));
}


bool Camera::keyPressed(const OgreBites::KeyboardEvent &evt) {

	if (evt.keysym.sym == SDLK_w) keyW = true;
	if (evt.keysym.sym == SDLK_d) keyD = true;
	if (evt.keysym.sym == SDLK_s) keyS = true;
	if (evt.keysym.sym == SDLK_a) keyA = true;

	return true;
}

bool Camera::keyReleased(const OgreBites::KeyboardEvent &evt) {
	if (evt.keysym.sym == SDLK_w) keyW = false;
	if (evt.keysym.sym == SDLK_d) keyD = false;
	if (evt.keysym.sym == SDLK_s) keyS = false;
	if (evt.keysym.sym == SDLK_a) keyA = false;

	return true;
}

void Camera::frameRendered(const Ogre::FrameEvent &evt) {

	if (keyW) position += front * moveScale;
	if (keyS) position -= front * moveScale;
	if (keyA) position += up.crossProduct(front).normalisedCopy() * moveScale;
	if (keyD) position -= up.crossProduct(front).normalisedCopy() * moveScale;

	cameraNode->setPosition(position);
	cameraNode->lookAt(position, Ogre::Node::TS_WORLD);
}

bool Camera::mouseMoved(const OgreBites::MouseMotionEvent &evt) {

	//std::cout << evt.x << ":" << evt.xrel << std::endl << std::flush;

	Ogre::Degree rotateScale(0.1);
	Ogre::Vector3 right = up.crossProduct(front).normalisedCopy();

	//cameraNode->rotate(up, rotateScale * evt.xrel, Ogre::Node::TS_PARENT);
	//cameraNode->rotate(right, rotateScale * evt.yrel, Ogre::Node::TS_PARENT);

	yawXNode->yaw(rotateScale * evt.xrel);
	yawYNode->yaw(rotateScale * evt.yrel);



	return true;
}
