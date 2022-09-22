#pragma once

#include "Config.h"
#include <vector>
#include <string>

class FileWriter
{
public:
	void WriteVector(std::vector<real>& Vector, const std::string& Path);
	void WriteMatrix(const std::vector<std::vector<real>>& Matrix, const std::string& Path);
};

