#pragma once
#include "XYZ.h"

class GameObject
{
public:
	GameObject();
	virtual void Start();
	virtual void Update();
	void SetPosition(XYZ _position);
	void SetRotation(XYZ _rotation);
	void SetScale(XYZ _scale);
	XYZ GetPosition();
	XYZ GetRotation();
	XYZ GetScale();
	void setVals();
	~GameObject();

private:
	XYZ Position, Rotation, Scale;
};
