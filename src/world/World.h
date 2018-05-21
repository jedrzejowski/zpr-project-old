//
// Created by adam on 05.05.18.
//

#pragma once

#include <utility>
#include <map>

#include <Ogre.h>

#include "src/lib/PerlinNoise.h"
#include "Chunk.h"

namespace World {

	class World {
	protected:

		PerlinNoise perlinNoise;
		Ogre::SceneNode *sceneNode;
		std::map<ChunkCoord, Chunk*> chunkMap;

	public:
		World();
		~World();

		void appendTo(Ogre::SceneNode* sceneNode);
		void appendChunk(Chunk *chunk);

		Chunk* getChunk(int x, int z){
			return chunkMap[ChunkCoord(x,z)];
		}

		void loadChunk(int x, int z);

		void generateChunk(int x, int z);
	};
}



