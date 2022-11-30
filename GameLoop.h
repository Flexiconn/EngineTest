#pragma once
#include "GameObject.h"
#include <vector>

class GameLoop
{
public:
	GameLoop();
	int Loop(std::vector<GameObject*> Objects);
	~GameLoop();

private:

};

