//
// Created by adam on 01.05.18.
//

#include "ResourceLoader.h"

bool ResourceLoader::loadImage(const Ogre::String &texture_name, const Ogre::String &texture_path) {
	bool image_loaded = false;
	std::ifstream ifs(texture_path.c_str(), std::ios::binary | std::ios::in);
	if (ifs.is_open()) {
		Ogre::String tex_ext;
		Ogre::String::size_type index_of_extension = texture_path.find_last_of('.');
		if (index_of_extension != Ogre::String::npos) {
			tex_ext = texture_path.substr(index_of_extension + 1);
			Ogre::DataStreamPtr data_stream(new Ogre::FileStreamDataStream(texture_path, &ifs, false));
			Ogre::Image img;
			img.load(data_stream, tex_ext);
			Ogre::TextureManager::getSingleton().loadImage(texture_name,
														   Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, img,
														   Ogre::TEX_TYPE_2D, 0, 1.0f);
			image_loaded = true;
		}
		ifs.close();
	}
	return image_loaded;
}
