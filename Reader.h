#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Config.h"

class Reader
{
public:
	void MatrixReader(std::vector<std::vector<real>>& Matrix, const std::string& Path);
	void VectorReader(std::vector<real>& Vector, const std::string& Path);
};
