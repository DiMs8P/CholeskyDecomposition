#pragma once

#include "Config.h"

class string;
class vector;

class FileReader
{
public:
	void ReadMatrix(std::vector<std::vector<real>>& Matrix, const std::string& Path);
	void ReadVector(std::vector<real>& Vector, const std::string& Path);
};
