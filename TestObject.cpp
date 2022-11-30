#include "TestObject.h"
#include <iostream>

void TestObject::Update() {
	struct XYZ newRot;
	newRot.X = GetRotation().X + 0.0f;
	newRot.Y = GetRotation().Y + 0.1f;
	newRot.Z = GetRotation().Z + 0.0f;
	SetRotation(newRot);
}
TestObject::TestObject()
{
}

TestObject::~TestObject()
{

}