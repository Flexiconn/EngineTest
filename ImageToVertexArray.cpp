#include "ImageToVertexArray.h"
#include "ImageHandler.h"

struct Vertex {
    float x;
    float y;
    float z;
};

struct Point {
    int x, y;
    int r, g, b;
    bool North = false, East = false, South = false, West = false;
};


int GetPointIndex(int x, int y, std::vector<Point> points) {
    for (size_t i = 0; i < points.size(); i++)
    {
        if (points[i].x == x && points[i].y == y) {
            return i;
        }
    }
    return -1;
}

float* ImageToVertexArray::ToArray(std::string path) {
    Image image = load_image(path.c_str());


    // create a 2D array to store the pixels
    unsigned char** pixels = new unsigned char* [image.height];
    for (int i = 0; i < image.height; i++) {
        pixels[i] = new unsigned char[image.width * image.channels];
    }
    // copy the pixels from the image buffer into the 2D array
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            pixels[y][x * image.channels + 0] = image.data[y * image.width * image.channels + x * image.channels + 0];
            pixels[y][x * image.channels + 1] = image.data[y * image.width * image.channels + x * image.channels + 1];
            pixels[y][x * image.channels + 2] = image.data[y * image.width * image.channels + x * image.channels + 2];
            pixels[y][x * image.channels + 3] = image.data[y * image.width * image.channels + x * image.channels + 3];
        }
    }

    Free(image.data);
    std::vector<float> vertex;
    std::vector<Point> points;
    int amount = 0;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            if (pixels[y][x * image.channels + 3] == 0) {
                continue;
            }
            else {
                Point point;
                if ((int)pixels[y - 1][x * image.channels + 3] != 0) {
                    point.North = true;
                }
                if ((int)pixels[y + 1][x * image.channels + 3] != 0) {
                    point.South = true;
                }
                if ((int)pixels[y][x * image.channels + 3 + image.channels] != 0) {
                    point.East = true;
                }
                if ((int)pixels[y][x * image.channels + 3 - image.channels] != 0) {
                    point.West = true;
                }


                if (point.North == true && point.East == true && point.South == true && point.West == true) {
                    
                }
                else {
                    point.x = x;
                    point.y = y;
                    point.r = pixels[y][x * image.channels];
                    point.g = pixels[y][x * image.channels + 1];
                    point.b = pixels[y][x * image.channels + 2];
                    std::cout << "X " << point.x << std::endl;
                    std::cout << "Y " << point.y << std::endl;
                    std::cout << "North " << point.North << std::endl;
                    std::cout << "East " << point.East << std::endl;
                    std::cout << "South " << point.South << std::endl;
                    std::cout << "West " << point.West << std::endl;
                    std::cout << "============" << std::endl;

                    points.push_back(point);
                }
            }
        }
    }



    float* verts = new float [points.size() * 30];
    int middleWidth = image.width / 2;
    int middleHeight = image.height / 2;
    float Wperpixel = (float)(1.0f / (float)middleWidth);
    float Hperpixel = (float)(1.0f / (float)middleHeight);

    for (size_t i = 0; i < points.size(); i++)
    {
        Point currentPoint = points[i];
        if (currentPoint.East || currentPoint.West) {
            if (currentPoint.x <= middleWidth) {

                verts[(i * 30) +0] = ((currentPoint.x - middleWidth)* Wperpixel);
                verts[(i * 30) + 1] =((currentPoint.y - middleHeight) * Hperpixel);
                verts[(i * 30) + 2] = (0.0f);
                verts[(i * 30) + 3] = (0.0f);
                verts[(i * 30) + 4] = (0.0f);


                verts[(i * 30) + 5] = ((((currentPoint.x - middleWidth) + 1) * Wperpixel));
                verts[(i * 30) + 6] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 7] = (0.0f);
                verts[(i * 30) + 8] = (0.0f);
                verts[(i * 30) + 9] = (0.0f);

                verts[(i * 30) + 10] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 11] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 12] = (1.0f);
                verts[(i * 30) + 13] = (0.0f);
                verts[(i * 30) + 14] = (0.0f);


                verts[(i * 30) + 15] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 16] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 17] = (1.0f);
                verts[(i * 30) + 18] = (0.0f);
                verts[(i * 30) + 19] = (0.0f);

                verts[(i * 30) + 20] = ((((currentPoint.x - middleWidth) + 1) * Wperpixel));
                verts[(i * 30) + 21] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 22] = (1.0f);
                verts[(i * 30) + 23] = (0.0f);
                verts[(i * 30) + 24] = (0.0f);

                verts[(i * 30) + 25] = ((((currentPoint.x - middleWidth) + 1) * Wperpixel));
                verts[(i * 30) + 26] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 27] = (0.0f);
                verts[(i * 30) + 28] = (0.0f);
                verts[(i * 30) + 29] = (0.0f);
            }
            else {
                verts[(i * 30) + 0] = ((currentPoint.x - middleWidth) * Wperpixel);
                verts[(i * 30) + 1] = ((currentPoint.y - middleHeight) * Hperpixel);
                verts[(i * 30) + 2] = (0.0f);
                verts[(i * 30) + 3] = (0.0f);
                verts[(i * 30) + 4] = (0.0f);


                verts[(i * 30) + 5] = ((((currentPoint.x - middleWidth) - 1) * Wperpixel));
                verts[(i * 30) + 6] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 7] = (0.0f);
                verts[(i * 30) + 8] = (0.0f);
                verts[(i * 30) + 9] = (0.0f);

                verts[(i * 30) + 10] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 11] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 12] = (1.0f);
                verts[(i * 30) + 13] = (0.0f);
                verts[(i * 30) + 14] = (0.0f);


                verts[(i * 30) + 15] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 16] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 17] = (1.0f);
                verts[(i * 30) + 18] = (0.0f);
                verts[(i * 30) + 19] = (0.0f);

                verts[(i * 30) + 20] = ((((currentPoint.x - middleWidth) - 1) * Wperpixel));
                verts[(i * 30) + 21] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 22] = (1.0f);
                verts[(i * 30) + 23] = (0.0f);
                verts[(i * 30) + 24] = (0.0f);

                verts[(i * 30) + 25] = ((((currentPoint.x - middleWidth) - 1) * Wperpixel));
                verts[(i * 30) + 26] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 27] = (0.0f);
                verts[(i * 30) + 28] = (0.0f);
                verts[(i * 30) + 29] = (0.0f);
            }
        }

        if (currentPoint.North || currentPoint.South) {
            if (currentPoint.y <= middleHeight) {

                verts[(i * 30) + 0] = ((currentPoint.y - middleHeight) * Hperpixel);
                verts[(i * 30) + 1] = ((currentPoint.x - middleWidth) * Wperpixel);
                verts[(i * 30) + 2] = (0.0f);
                verts[(i * 30) + 3] = (0.0f);
                verts[(i * 30) + 4] = (0.0f);


                verts[(i * 30) + 5] = ((((currentPoint.y - middleHeight) + 1) * Hperpixel));
                verts[(i * 30) + 6] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 7] = (0.0f);
                verts[(i * 30) + 8] = (0.0f);
                verts[(i * 30) + 9] = (0.0f);

                verts[(i * 30) + 10] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 11] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 12] = (1.0f);
                verts[(i * 30) + 13] = (0.0f);
                verts[(i * 30) + 14] = (0.0f);


                verts[(i * 30) + 15] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 16] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 17] = (1.0f);
                verts[(i * 30) + 18] = (0.0f);
                verts[(i * 30) + 19] = (0.0f);

                verts[(i * 30) + 20] = ((((currentPoint.y - middleHeight) + 1) * Hperpixel));
                verts[(i * 30) + 21] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 22] = (1.0f);
                verts[(i * 30) + 23] = (0.0f);
                verts[(i * 30) + 24] = (0.0f);

                verts[(i * 30) + 25] = ((((currentPoint.y - middleHeight) + 1) * Hperpixel));
                verts[(i * 30) + 26] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 27] = (0.0f);
                verts[(i * 30) + 28] = (0.0f);
                verts[(i * 30) + 29] = (0.0f);
            }
            else {
                verts[(i * 30) + 0] = ((currentPoint.y - middleHeight) * Hperpixel);
                verts[(i * 30) + 1] = ((currentPoint.x - middleWidth) * Wperpixel);
                verts[(i * 30) + 2] = (0.0f);
                verts[(i * 30) + 3] = (0.0f);
                verts[(i * 30) + 4] = (0.0f);


                verts[(i * 30) + 5] = ((((currentPoint.y - middleHeight) - 1) * Hperpixel));
                verts[(i * 30) + 6] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 7] = (0.0f);
                verts[(i * 30) + 8] = (0.0f);
                verts[(i * 30) + 9] = (0.0f);

                verts[(i * 30) + 10] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 11] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 12] = (1.0f);
                verts[(i * 30) + 13] = (0.0f);
                verts[(i * 30) + 14] = (0.0f);


                verts[(i * 30) + 15] = (((currentPoint.y - middleHeight) * Hperpixel));
                verts[(i * 30) + 16] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 17] = (1.0f);
                verts[(i * 30) + 18] = (0.0f);
                verts[(i * 30) + 19] = (0.0f);

                verts[(i * 30) + 20] = ((((currentPoint.y - middleHeight) - 1) * Hperpixel));
                verts[(i * 30) + 21] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 22] = (1.0f);
                verts[(i * 30) + 23] = (0.0f);
                verts[(i * 30) + 24] = (0.0f);

                verts[(i * 30) + 25] = ((((currentPoint.y - middleHeight) - 1) * Hperpixel));
                verts[(i * 30) + 26] = (((currentPoint.x - middleWidth) * Wperpixel));
                verts[(i * 30) + 27] = (0.0f);
                verts[(i * 30) + 28] = (0.0f);
                verts[(i * 30) + 29] = (0.0f);
            }
        }
    }
    for (size_t i = 0; i < (vertex.size()/3); i++)
    {
        std::cout << "=======" << std::endl;
        std::cout << vertex[(i * 3)] << " ";
        std::cout << vertex[(i * 3) + 1] << " ";
        std::cout << vertex[(i * 3) + 2] << " " << std::endl;
    }
    //std::cout << vertex.size();

	return verts;
}

ImageToVertexArray::ImageToVertexArray()
{
}

ImageToVertexArray::~ImageToVertexArray()
{
}
