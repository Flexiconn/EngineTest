#pragma once
#include <vector>
#include "GameObject.h"

class Render
{



public:
	//struct XYZ {
	//	float X, Y, Z;
	//};

	//struct Object {
	//	struct XYZ scale;
	//	struct XYZ position;
	//	struct XYZ rotation;
	//};
	void SetUp();
	void RenderFrame(std::vector<GameObject*> objects);
	void Clean();
	Render();
	~Render();

private:

};

