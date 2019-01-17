#include "SaveLoad.hpp"


namespace SaveLoad
{
	std::vector<char*> v_className;
	std::vector<float> v_areaX;
	std::vector<float> v_areaY;
	std::vector<float> v_areaZ;
	std::vector<float> v_direction;


	void InitAdd(char * const className, float const areaX, float const areaY, float const areaZ, float const direction)
	{
		v_className.push_back(className);
		v_areaX.push_back(areaX);
		v_areaY.push_back(areaY);
		v_areaZ.push_back(areaZ);
		v_direction.push_back(direction);
	}


	void Save()
	{
		std::ofstream saveFile;

		saveFile.open("Save.csv");

		// �t�@�C���ǂݍ��ݎ��s
		if (saveFile.fail())
		{
			std::cout << "SaveError" << std::endl;
		}
		else
		{
			// �ǂݍ��ݐ���
			for (int i = 0, n = static_cast<int>(v_className.size()); i < n; i++)
			{
				saveFile << v_className[i] << "," << v_areaX[i] << "," << v_areaY[i] << "," << v_areaZ[i] << "," << v_direction[i];
				saveFile << std::endl;
			}
		}

		// �t�@�C�������
		saveFile.close();
	}


	void Reset()
	{
		v_className.clear();
		v_className.shrink_to_fit();
		v_areaX.clear();
		v_areaX.shrink_to_fit();
		v_areaY.clear();
		v_areaY.shrink_to_fit();
		v_areaZ.clear();
		v_areaZ.shrink_to_fit();
		v_direction.clear();
		v_direction.shrink_to_fit();
	}
}
