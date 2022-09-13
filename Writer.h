#pragma once

#include <vector>
#include <string>
#include "Config.h"
#include <fstream>
#include <iomanip>

static class Writer
{
public:
	static void WriteVectorToFile(std::vector<real>& Vector, const std::string& Path);
	static void WriteMatrixToFile(const std::vector<std::vector<real>>& Matrix, const std::string& Path);
};

