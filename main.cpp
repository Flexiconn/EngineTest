#include "GameLoop.h"
#include "TestObject.h"
#include "Scene.h"
#include "ImageToVertexArray.h"

int main(){
	ImageToVertexArray sett;
	sett.ToArray("test2.png");
	Scene scene;
	scene.Add(new TestObject());
	GameLoop gameLoop;
	gameLoop.Loop(scene);
}