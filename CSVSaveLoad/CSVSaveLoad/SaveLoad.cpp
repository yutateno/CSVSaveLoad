#include "SaveLoad.hpp"


namespace SaveLoad
{
	std::vector<std::string> v_className;
	std::vector<float> v_areaX;
	std::vector<float> v_areaY;
	std::vector<float> v_areaZ;
	std::vector<float> v_direction;
	int num;


	void InitAdd(const std::string className, float const areaX, float const areaY, float const areaZ, float const direction)
	{
		num++;
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

		// ファイル読み込み失敗
		if (saveFile.fail())
		{
			std::cout << "SaveError" << std::endl;
		}
		else
		{
			// 読み込み成功
			for (int i = 0, n = static_cast<int>(v_className.size()); i < n; i++)
			{
				saveFile << v_className[i] << "," << v_areaX[i] << "," << v_areaY[i] << "," << v_areaZ[i] << "," << v_direction[i];
				saveFile << std::endl;
			}
		}

		// ファイルを閉じる
		saveFile.close();
	}


	void Load()
	{
		std::ifstream ifs;
		std::vector<std::vector<std::string>> mapdata;
		ifs.open("Save.csv");
		// マップデータ読み込み失敗
		if (ifs.fail())
		{
			std::cout << "LoadError" << std::endl;
		}

		// 仮置き
		std::string str;
		int count = 0;

		while (getline(ifs, str)) 
		{
			// 仮置き
			std::string token;
			std::istringstream stream(str);

			// メモリ確保
			mapdata.resize(count + 1);

			while (getline(stream, token, ',')) 
			{
				mapdata[count].push_back(token);
			}
			// カウントアップ
			count++;
		}

		for (int i = 0, n = mapdata.size(); i != n; ++i)
		{
			num++;
			v_className.push_back(const_cast<char*>(mapdata[i][0].c_str()));
			v_areaX.push_back(std::stof(mapdata[i][1].c_str()));
			v_areaY.push_back(std::stof(mapdata[i][2].c_str()));
			v_areaZ.push_back(std::stof(mapdata[i][3].c_str()));
			v_direction.push_back(std::stof(mapdata[i][4].c_str()));
		}
	}


	void Reset()
	{
		num = 0;
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


	const int GetIDNum()
	{
		return num;
	}


	const std::string GetName(int i)
	{
		return v_className[i];
	}


	const float GetX(int i)
	{
		return v_areaX[i];
	}


	const float GetY(int i)
	{
		return v_areaY[i];
	}


	const float GetZ(int i)
	{
		return v_areaZ[i];
	}


	const float GetDirection(int i)
	{
		return v_direction[i];
	}
}
