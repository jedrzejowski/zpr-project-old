//
// Created by adam on 05.05.18.
//

#include <iostream>
#include "World.h"

using namespace World;

World::World::World() {

	perlinNoise = PerlinNoise(1, 0.03, Chunk::SizeY, 3, 26849);

	//region Geeracja Chunkow

	for (int x = 0; x < 2; x++)
		for (int z = 0; z < 2; z++)
			generateChunk(x, z);

	//endregion
}

World::World::~World() {
	for (const auto &item : chunkMap) {
		delete item.second;
	}
}

void World::World::loadChunk(int x, int z) {

}

void World::World::generateChunk(int x, int z) {
	auto cord = ChunkCoord(x, z);
	Chunk *chunk = Chunk::Generate(cord, perlinNoise);
	chunkMap[cord] = chunk;
}

void World::World::appendTo(Ogre::SceneNode *sceneNode) {
	this->sceneNode = sceneNode;


	for (const auto &item : chunkMap) {
		auto chunkNode = sceneNode->createChildSceneNode();

		chunkNode->setPosition(item.first.getOffest());

		item.second->appendTo(chunkNode);
	}

}
