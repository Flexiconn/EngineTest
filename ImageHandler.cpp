#include "ImageHandler.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <stdexcept>

Image load_image(const char* filepath) {
    Image image;
    unsigned char* data = stbi_load(filepath, &image.width, &image.height, &image.channels, 0);
    if (data == nullptr) {
        throw std::runtime_error("Failed to load image: " + std::string(filepath));
    }
    image.data = data;
    return image;
}

void Free(void * data) {
    stbi_image_free(data);
}

