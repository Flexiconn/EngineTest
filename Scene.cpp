#include "Scene.h"

std::vector<GameObject*> Scene::GetGameObjects() {
	return GameObjects;
}

Scene::Scene(std::vector<GameObject*> _gameObjects)
{
	GameObjects.insert(GameObjects.end(), _gameObjects.begin(), _gameObjects.end());
}

void Scene::Add(GameObject* _gameObject) {
	GameObjects.push_back(_gameObject);
}


Scene::Scene()
{

}

Scene::~Scene()
{
}