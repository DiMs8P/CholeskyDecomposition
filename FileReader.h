#pragma once
#include <string>
#include <fstream>
using namespace std;

class FileReader
{
protected:
	FileReader(const string& path);
	ifstream getStream() const;

private:
	static void ThrowIfNotOpen(const ifstream& stream);

	string _path;
};

