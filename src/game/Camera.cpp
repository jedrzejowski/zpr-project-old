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
	cameraNode->attachObject(camera);

	front = Ogre::Vector3(0, 0, -1);
	up = Ogre::Vector3(0, 1, 0);
	position = Ogre::Vector3(0, 0, 15);
	moveScale = 0.1;

	update();

	initViewports();
}


void Camera::initViewports() {
	Ogre::Viewport *vp = GameManager::getInstance().getRenderWindow()->addViewport(camera);
	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	camera->setAspectRatio(
			Ogre::Real(vp->getActualWidth()) /
			Ogre::Real(vp->getActualHeight()));
}

void Camera::moveFromEvent(const OgreBites::KeyboardEvent &evt) {

	if (evt.keysym.sym == SDLK_w) keyW = evt.state == SDL_PRESSED;
	else keyW = false;

	if (evt.keysym.sym == SDLK_d) keyD = evt.state == SDL_PRESSED;
	else keyD = false;

	if (evt.keysym.sym == SDLK_s) keyS = evt.state == SDL_PRESSED;
	else keyS = false;

	if (evt.keysym.sym == SDLK_a) keyA = evt.state == SDL_PRESSED;
	else keyA = false;

	update();
}

void Camera::update() {
	if (keyW) position += front * moveScale;
	if (keyS) position -= front * moveScale;
	if (keyA) position -= up.crossProduct(front).normalisedCopy() * moveScale;
	if (keyD) position += up.crossProduct(front).normalisedCopy() * moveScale;

	cameraNode->setPosition(position);
	cameraNode->lookAt(position, Ogre::Node::TS_WORLD, up);
}


