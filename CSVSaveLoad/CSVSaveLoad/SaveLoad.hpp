#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace SaveLoad
{	
	void InitAdd(char* const className, float const areaX, float const areaY, float const areaZ, float const direction);

	void Save();

	void Reset();
}