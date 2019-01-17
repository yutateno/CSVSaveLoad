#include "Actor.hpp"
#include <iostream>


Actor::Actor()
{
	std::cout << "コンストラクタ呼ばれた" << std::endl;
	areaX = 0.0f;
	areaY = 0.0f;
	areaZ = 0.0f;
	direction = 0.0f;

	std::cout << "X: " << areaX << ", Y: " << areaY << ", Z: " << areaZ << ", direction: " << direction << std::endl;
}


Actor::Actor(float areaX, float areaY, float areaZ, float direction) : areaX(areaX), areaY(areaY), areaZ(areaZ), direction(direction)
{
	std::cout << "コピーコンストラクタ呼ばれた" << std::endl;
	std::cout << "X: " << this->areaX << ", Y: " << this->areaY << ", Z: " << this->areaZ << ", direction: " << this->direction << std::endl;
}


Actor::~Actor()
{
	std::cout << "デストラクタ呼ばれた" << std::endl;
}

void Actor::Update()
{
	areaX += 10.5f;
	areaY += 10.5f;
	areaZ += 10.5f;
	direction += 3.14f / 90;
}
