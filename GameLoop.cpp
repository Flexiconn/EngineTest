#include "GameLoop.h"
#include <iostream>
#include "Render.h"
#include "TestObject.h"

int GameLoop::Loop(std::vector<GameObject*> Objects) {
	Render render;
	Objects.push_back(new TestObject());
	Objects[0]->setVals();
	render.SetUp();
	while (true) {
		
		//render objects

		struct XYZ newRot;
		newRot.X = Objects[0]->GetRotation().X + 0.0f;
		newRot.Y = Objects[0]->GetRotation().Y + 0.5f;
		newRot.Z = Objects[0]->GetRotation().Z + 0.0f;
		std::cout << newRot.X << std::endl;
		Objects[0]->SetRotation(newRot);
		render.RenderFrame(Objects);
		
		//execute logic
		
	}
	render.Clean();
}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}