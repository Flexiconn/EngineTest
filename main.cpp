#include "GameLoop.h"
int main() {
	GameLoop gameLoop;
	std::vector<GameObject*> objs;

	gameLoop.Loop(objs);
}