#include "GameObject.h"
#include <cmath>

void GameObject::Start(){
	
}

void GameObject::Update() {

}

void GameObject::SetPosition(XYZ _position) {
	Position = _position;
}

void GameObject::SetRotation(XYZ _rotation) {
    _rotation.X = fmod(_rotation.X, 360.0f);
    _rotation.Y = fmod(_rotation.Y, 360.0f);
    _rotation.Z = fmod(_rotation.Z, 360.0f);

    Rotation = _rotation;
}

void GameObject::SetScale(XYZ _scale) {
	Scale = _scale;
}

XYZ GameObject::GetPosition() {
	return Position;
}

XYZ GameObject::GetRotation() {
	return Rotation;
}

XYZ GameObject::GetScale() {
	return Scale;
}

void GameObject::setVals() {

}


GameObject::GameObject()
{
    struct XYZ object1;
    struct XYZ object2;
    struct XYZ object3;
    object1.X = 2.0f;
    object1.Y = 2.0f;
    object1.Z = 2.0f;
    object2.X = 0.0f;
    object2.Y = 0.0f;
    object2.Z = 0.0f;
    object3.X = 0.0f;
    object3.Y = 0.0f;
    object3.Z = 0.0f;
    SetScale(object1);
    SetPosition(object2);
    SetRotation(object3);
}

GameObject::~GameObject()
{
}