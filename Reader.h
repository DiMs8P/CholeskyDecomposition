#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Config.h"

static class Reader
{
public:
	static void MatrixReader(std::vector<std::vector<real>>& Matrix, const std::string& Path);
	static void VectorReader(std::vector<real>& Vector, const std::string& Path);
};
