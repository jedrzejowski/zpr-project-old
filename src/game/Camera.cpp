//
// Created by adam on 05.05.18.
//

#include <iostream>
#include "Camera.h"
#include "GameManager.h"
#include <SDL2/SDL.h>

using namespace Game;

Camera::Camera(const Ogre::String &name) {
	camera = GameManager::getInstance().getSceneManager()->createCamera(name);
	camera->setNearClipDistance(.1);
	camera->setAutoAspectRatio(true);

	cameraNode = GameManager::getInstance().getSceneManager()->getRootSceneNode()->createChildSceneNode();
	cameraNode->attachObject(camera);

	front = Ogre::Vector3(0, 0, -1);
	up = Ogre::Vector3(0, 1, 0);
	position = Ogre::Vector3(0, 0, 15);
	moveScale = 0.1;
	rotateScale = 0.75;

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

	switch (evt.keysym.sym) {
		case SDLK_w:
			keyW = true;
			break;
		case SDLK_d:
			keyD = true;
			break;
		case SDLK_s:
			keyS = true;
			break;
		case SDLK_a:
			keyA = true;
			break;

		case SDLK_UP:
			keyUp = true;
			break;
		case SDLK_DOWN:
			keyDown = true;
			break;
		case SDLK_LEFT:
			keyLeft = true;
			break;
		case SDLK_RIGHT:
			keyRight = true;
			break;
	}

	return true;
}

bool Camera::keyReleased(const OgreBites::KeyboardEvent &evt) {
	switch (evt.keysym.sym) {
		case SDLK_w:
			keyW = false;
			break;
		case SDLK_d:
			keyD = false;
			break;
		case SDLK_s:
			keyS = false;
			break;
		case SDLK_a:
			keyA = false;
			break;

		case SDLK_UP:
			keyUp = false;
			break;
		case SDLK_DOWN:
			keyDown = false;
			break;
		case SDLK_LEFT:
			keyLeft = false;
			break;
		case SDLK_RIGHT:
			keyRight = false;
			break;
	}

	return true;
}

void Camera::frameRendered(const Ogre::FrameEvent &evt) {

	if (keyW) position -= front * moveScale;
	if (keyS) position += front * moveScale;
	if (keyA) position += up.crossProduct(front).normalisedCopy() * moveScale;
	if (keyD) position -= up.crossProduct(front).normalisedCopy() * moveScale;

	cameraNode->setPosition(position);
	cameraNode->lookAt(position, Ogre::Node::TS_WORLD);

	Ogre::Vector3 right = up.crossProduct(front).normalisedCopy();

	if (keyRight) angleX -= Ogre::Degree(rotateScale);
	if (keyLeft) angleX -= Ogre::Degree(-rotateScale);

	if (keyUp) angleY -= Ogre::Degree(-rotateScale);
	if (keyDown) angleY -= Ogre::Degree(rotateScale);

	front = Ogre::Vector3(0, 0, 1);
	Ogre::Quaternion rotationH(angleY, Ogre::Vector3::UNIT_X);
	Ogre::Quaternion rotationV(angleX, Ogre::Vector3::UNIT_Y);
	front = rotationH * rotationV * front;
	front.normalise();

	cameraNode->resetOrientation();
	cameraNode->rotate(rotationH, Ogre::Node::TS_WORLD);
	cameraNode->rotate(rotationV, Ogre::Node::TS_WORLD);
}

bool Camera::mouseMoved(const OgreBites::MouseMotionEvent &evt) {

	//std::cout << evt.x << ":" << evt.xrel << std::endl << std::flush;

//	Ogre::Degree rotateScale(0.1);
//	Ogre::Vector3 right = up.crossProduct(front).normalisedCopy();
//
//	angleX -= Ogre::Degree(evt.xrel * 0.1f);
//	angleY += Ogre::Degree(evt.yrel * 0.1f);
//
//	front = Ogre::Vector3(0, 0, 1);
//	Ogre::Quaternion rotationH(angleY, Ogre::Vector3::UNIT_X);
//	Ogre::Quaternion rotationV(angleX, Ogre::Vector3::UNIT_Y);
//	front = rotationH * rotationV * front;
//	front.normalise();
//
//	cameraNode->resetOrientation();
//	cameraNode->rotate(rotationH, Ogre::Node::TS_WORLD);
//	cameraNode->rotate(rotationV, Ogre::Node::TS_WORLD);

	return true;
}
