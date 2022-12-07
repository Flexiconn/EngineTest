#include "TestObject.h"
#include <iostream>
#include "KeyLogging.h"

void TestObject::Update() {
	KeyLogging* keylogging = KeyLogging::getInstance();
	if (keylogging->IsKeyPressed(KEY_SPACE)) {
		struct XYZ newRot;
		newRot.X = GetRotation().X + 0.0f;
		newRot.Y = GetRotation().Y + 1.0f;
		newRot.Z = GetRotation().Z + 0.0f;
		SetRotation(newRot);
	}
}
TestObject::TestObject()
{
}

TestObject::~TestObject()
{

}