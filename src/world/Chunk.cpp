//
// Created by adam on 05.05.18.
//

#include <src/block/terrain/Stone.h>
#include "Chunk.h"


World::Chunk::Chunk() {

}

World::Chunk *World::Chunk::Generate(const ChunkCoord &chunkCoord, const PerlinNoise &perlinNoise) {
	Chunk *chunk = new Chunk;

	for (int x = 0; x < SizeX; x++)
		for (int z = 0; z < SizeZ; z++) {
			int Y = (int) perlinNoise.GetHeight(chunkCoord.getXOffest() + x, chunkCoord.getZOffest() + z);

			for (int y = 0; y < Y && y < SizeY; y++) {

				auto stone = new Block::Stone();
				chunk->appendBlock(x, y, z, stone);

			}
		}

	return chunk;
}

void World::Chunk::appendTo(Ogre::SceneNode *sceneNode) {
	this->sceneNode = sceneNode;

	for (const auto &item : blockMap) {
		auto blockNode = sceneNode->createChildSceneNode();

		blockNode->setPosition(std::get<0>(item.first), std::get<1>(item.first), std::get<2>(item.first));

		item.second->appendTo(blockNode);
	}
}

void World::Chunk::appendBlock(Block::BlockCoord coord, Block::Abstract *block) {

	blockMap[coord] = block;
}

void World::Chunk::appendBlock(int x, int y, int z, Block::Abstract *block) {
	appendBlock(Block::BlockCoord(x, y, z), block);
}


