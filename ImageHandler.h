#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <vector>

struct Image {
	int width;
	int height;
	int channels;
	unsigned char* data;
};

Image load_image(const char* filepath);
void Free(void* data);
#endif