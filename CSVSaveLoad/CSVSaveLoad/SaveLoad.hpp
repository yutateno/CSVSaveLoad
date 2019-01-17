#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace SaveLoad
{	
	// �f�[�^��ǉ�����
	void InitAdd(const std::string className, float const areaX, float const areaY, float const areaZ, float const direction);


	// CSV�ɏo�͂���
	void Save();


	// CSV����ǂݍ���
	void Load();


	// �f�[�^�ǉ����y�ѓǂݍ��ݎ��ɒǉ����ꂽ�f�[�^���폜����
	void Reset();


	// �e�f�[�^�̃Q�b�^�[
	const int GetIDNum();
	const std::string GetName(int i);
	const float GetX(int i);
	const float GetY(int i);
	const float GetZ(int i);
	const float GetDirection(int i);
}