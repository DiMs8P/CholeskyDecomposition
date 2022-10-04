#pragma once

#include "../Config.h"
#include <vector>
#include <string>

class FileWriter
{
public:
	FileWriter(const string& outputPath);
	void WriteVector(const vector<real>& vector) const;
	void WriteMatrix(const vector<vector<real>>& matrix) const;

private:
	const string& _outputPath;
};

