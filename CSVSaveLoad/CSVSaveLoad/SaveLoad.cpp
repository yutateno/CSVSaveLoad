#include "SaveLoad.hpp"


namespace SaveLoad
{
	/// �e�f�[�^�̓��e��ۑ�����ϐ�---------------

	// �N���X����ۑ�����
	std::vector<std::string> v_className;

	// X���W��ۑ�����
	std::vector<float> v_areaX;

	// Y���W��ۑ�����
	std::vector<float> v_areaY;

	// Z���W��ۑ�����
	std::vector<float> v_areaZ;

	// ������ۑ�����
	std::vector<float> v_direction;

	// �f�[�^�̌���ۑ�����
	int num;
	/// �e�f�[�^�̓��e��ۑ�����ϐ�---------------


	// �f�[�^��ǉ�����
	void InitAdd(const std::string className, float const areaX, float const areaY, float const areaZ, float const direction)
	{
		num++;
		v_className.push_back(className);
		v_areaX.push_back(areaX);
		v_areaY.push_back(areaY);
		v_areaZ.push_back(areaZ);
		v_direction.push_back(direction);
	}


	// CSV�ɏo�͂���
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


	// CSV����ǂݍ���
	void Load()
	{
		std::ifstream ifs;
		std::vector<std::vector<std::string>> mapdata;
		ifs.open("Save.csv");
		// �}�b�v�f�[�^�ǂݍ��ݎ��s
		if (ifs.fail())
		{
			std::cout << "LoadError" << std::endl;
		}

		// ���u��
		std::string str;
		int count = 0;

		while (getline(ifs, str)) 
		{
			// ���u��
			std::string token;
			std::istringstream stream(str);

			// �������m��
			mapdata.resize(count + 1);

			while (getline(stream, token, ',')) 
			{
				mapdata[count].push_back(token);
			}
			// �J�E���g�A�b�v
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
	} /// void Load()


	// �f�[�^�̉��
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


	// �f�[�^�̌���n��
	const int GetIDNum()
	{
		return num;
	}


	// �f�[�^�̃N���X����n��
	const std::string GetName(int i)
	{
		return v_className[i];
	}


	// �f�[�^��X���W��n��
	const float GetX(int i)
	{
		return v_areaX[i];
	}


	// �f�[�^��Y���W��n��
	const float GetY(int i)
	{
		return v_areaY[i];
	}


	// �f�[�^��Z���W��n��
	const float GetZ(int i)
	{
		return v_areaZ[i];
	}


	// �f�[�^�̌�����n��
	const float GetDirection(int i)
	{
		return v_direction[i];
	}
} /// namespace SaveLoad
