#pragma once

#include "Config.h"

//class string;
//class vector;

class FileWriter
{
public:
	void WriteVector(std::vector<real>& Vector, const std::string& Path);
	void WriteMatrix(const std::vector<std::vector<real>>& Matrix, const std::string& Path);
};

