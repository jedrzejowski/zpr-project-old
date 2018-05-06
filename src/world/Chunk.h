//
// Created by adam on 05.05.18.
//

#pragma once

#include <utility>
#include <map>

#include "src/lib/PerlinNoise.h"
#include "src/block/Abstract.h"

namespace World {

	typedef std::pair<int, int> ChunkCoord;

	class Chunk {
	protected:
		Ogre::SceneNode *sceneNode;
		std::map<Block::BlockCoord, Block::Abstract*> blockMap;

		Chunk();

	public:
		static Chunk *Generate(const PerlinNoise &perlinNoise);

		void appendTo(Ogre::SceneNode* sceneNode);
		void appendBlock(Block::BlockCoord coord, Block::Abstract* block);
		void appendBlock(int x, int y, int z, Block::Abstract* block);

		static Chunk *LoadFromJSON();

		static const int SizeX = 16;
		static const int SizeY = 128;
		static const int SizeZ = 16;
	};
}



