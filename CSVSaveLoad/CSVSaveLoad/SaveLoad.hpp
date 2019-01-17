#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace SaveLoad
{	
	void InitAdd(const std::string className, float const areaX, float const areaY, float const areaZ, float const direction);

	void Save();

	void Load();

	void Reset();

	const int GetIDNum();
	const std::string GetName(int i);
	const float GetX(int i);
	const float GetY(int i);
	const float GetZ(int i);
	const float GetDirection(int i);
}