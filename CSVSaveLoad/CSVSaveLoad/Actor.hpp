#pragma once

class Actor
{
private:
	float areaX;
	float areaY;
	float areaZ;

	float direction;
	

public:
	Actor();
	Actor(float areaX, float areaY, float areaZ, float direction);
	~Actor();

	void Update();

	const float GetX() const { return areaX; }
	const float GetY() const { return areaY; }
	const float GetZ() const { return areaZ; }
	const float GetDirection() const { return direction; }
};

