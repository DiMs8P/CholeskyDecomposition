#pragma once

#include "../Config.h"
#include <vector>
#include <string>

class FileReader
{
public:
	void ReadMatrix(vector<vector<real>>& matrix, const string& path);
	void ReadVector(vector<real>& Vector, const string& path);
};
