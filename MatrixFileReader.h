#pragma once
#include "Config.h"
#include "FileReader.h"
#include <vector>

class MatrixFileReader : public FileReader
{
public:
	MatrixFileReader(const string& path);
	void Read(vector<vector<real>>& matrix);

private:
	int _height;
	int _width;
};

