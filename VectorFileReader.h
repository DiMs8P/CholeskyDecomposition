#pragma once
#include "FileReader.h"
#include "Config.h"
#include <vector>

class VectorFileReader : public FileReader
{
public:
	VectorFileReader(const string& path);
	void Read(vector<real> vec);

private:
	int _height;
};

