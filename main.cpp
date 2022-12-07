#include "GameLoop.h"
#include "TestObject.h"
#include "Scene.h"

int main(){
	Scene scene;
	scene.Add(new TestObject());
	GameLoop gameLoop;
	gameLoop.Loop(scene);
}