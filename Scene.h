#pragma once
#include <vector>
#include "GameObject.h"

class Scene
{
public:
	Scene(std::vector<GameObject*> _gameObjects);
	Scene();
	std::vector<GameObject*> GetGameObjects();
	void Add(GameObject* _gameObject);
	~Scene();

private:
	std::vector<GameObject*> GameObjects;
};
