#pragma once

#include "../Config.h"
#include <vector>
#include <string>

class FileReader
{
public:
	void ReadMatrix(vector<vector<real>>& Matrix, const string& Path);
	void ReadVector(vector<real>& Vector, const string& Path);
};
