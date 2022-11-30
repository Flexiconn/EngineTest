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
		newRot.X = Objects[0]->GetPosition().X + 0.001f;
		newRot.Y = Objects[0]->GetPosition().Y + 0.001f;
		newRot.Z = Objects[0]->GetPosition().Z + 0.001f;
		std::cout << newRot.X << std::endl;
		Objects[0]->SetPosition(newRot);
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