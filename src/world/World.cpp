//
// Created by adam on 05.05.18.
//

#include "World.h"

using namespace World;

World::World::World() {

	perlinNoise = PerlinNoise(1, 0.03, Chunk::SizeY, 3, 26849);

	//region Geeracja Chunkow

	for (int x = 0; x < 8; x++)
		for (int z = 0; z < 8; z++) {
			Chunk *chunk = Chunk::Generate(perlinNoise);
			chunkMap[ChunkCoord(x, z)] = chunk;
		}

	//endregion
}

World::World::~World() {
	for (const auto &item : chunkMap) {
		delete item.second;
	}
}

void World::World::loadChunk(int x, int z, void (*callback)()) {

}

void World::World::generateChunk(int x, int z, void (*callback)()) {

}

void World::World::appendTo(Ogre::SceneNode *sceneNode) {
	this->sceneNode = sceneNode;


	for (const auto &item : chunkMap) {
		auto chunkNode = sceneNode->createChildSceneNode();

		chunkNode->setPosition(std::get<0>(item.first), 0, std::get<1>(item.first));

		item.second->appendTo(chunkNode);
	}

}
