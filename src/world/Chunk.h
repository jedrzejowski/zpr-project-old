//
// Created by adam on 05.05.18.
//

#pragma once

#include <utility>
#include <map>

#include "src/lib/PerlinNoise.h"
#include "src/block/Abstract.h"

namespace World {

	struct ChunkCoord {
		int x, z;

		ChunkCoord(){};

		ChunkCoord(int x, int z) : x(x), z(z) {}

		bool const operator==(const ChunkCoord &o) const {
			return x == o.x && z == o.z;
		}

		bool const operator<(const ChunkCoord &o) const {
			return x < o.x || (x == o.x && z < o.z);
		}

		inline int getXOffest() const {
			return x * 16;
		}

		inline int getZOffest() const {
			return z * 16;
		}

		inline Ogre::Vector3 getOffest() const {
			return Ogre::Vector3(getXOffest(), 0 , getZOffest());
		}
	};

	class Chunk {
	protected:
		ChunkCoord chunkCoord;
		Ogre::SceneNode *sceneNode;
		std::map<Block::BlockCoord, Block::Abstract *> blockMap;

		Chunk();

	public:
		static Chunk *Generate(const ChunkCoord &chunkCoord, const PerlinNoise &perlinNoise);

		void appendTo(Ogre::SceneNode *sceneNode);

		void appendBlock(Block::BlockCoord coord, Block::Abstract *block);

		void appendBlock(int x, int y, int z, Block::Abstract *block);

		static Chunk *LoadFromJSON();

		static const int SizeX = 16;
		static const int SizeY = 16;
		static const int SizeZ = 16;
	};


}



