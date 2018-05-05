//
// Created by adam on 05.05.18.
//

#pragma once

#include <utility>
#include <map>

#include "Ogre.h"
#include "Chunk.h"

namespace World {

	class World {
	protected:

		std::map<std::pair<int,int>, Chunk> worldMap;

	public:
		World();
	};
}



