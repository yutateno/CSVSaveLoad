#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace SaveLoad
{	
	// データを追加する
	void InitAdd(const std::string className, float const areaX, float const areaY, float const areaZ, float const direction);


	// CSVに出力する
	void Save();


	// CSVから読み込む
	void Load();


	// データ追加時及び読み込み時に追加されたデータを削除する
	void Reset();


	// 各データのゲッター
	const int GetIDNum();
	const std::string GetName(int i);
	const float GetX(int i);
	const float GetY(int i);
	const float GetZ(int i);
	const float GetDirection(int i);
}