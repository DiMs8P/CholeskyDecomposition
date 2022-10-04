#include "VectorFileReader.h"

VectorFileReader::VectorFileReader(const string& path)
	: FileReader(path)
	{ }

void VectorFileReader::Read(vector<real>& vec)
{
	ifstream stream = getStream();

	stream >> _height;
	vec.resize(_height);

	for (int i = 0; i < _height; ++i)
		stream >> vec[i];

	stream.close();
}