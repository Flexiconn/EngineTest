#include "GameLoop.h"
#include <iostream>
#include "Render.h"
#include "TestObject.h"

int GameLoop::Loop(std::vector<GameObject*> Objects) {
	Render render;
	Objects.push_back(new TestObject());
	Objects.push_back(new TestObject());
	Objects[0]->setVals();
	Objects[1]->setVals();
	render.SetUp();
	while (true) {
		
		//render objects

		//struct XYZ newRot, newRot2;
		//newRot.X = Objects[0]->GetRotation().X + 0.0f;
		//newRot.Y = Objects[0]->GetRotation().Y + 0.1f;
		//newRot.Z = Objects[0]->GetRotation().Z + 0.0f;
		//Objects[0]->SetRotation(newRot);
		//newRot2.X = Objects[1]->GetRotation().X + 0.1f;
		//newRot2.Y = Objects[1]->GetRotation().Y + 0.0f;
		//newRot2.Z = Objects[1]->GetRotation().Z + 0.0f;
		//std::cout << newRot2.X << std::endl;
		//Objects[1]->SetRotation(newRot2);
		Objects[0]->Update();
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