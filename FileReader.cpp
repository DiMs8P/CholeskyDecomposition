#include "FileReader.h"

FileReader::FileReader(const string& path):
	_path(path)
	{ }

ifstream FileReader::getStream() const
{
	ifstream stream(_path);
	ThrowIfNotOpen(stream);
	return stream;
}

void FileReader::ThrowIfNotOpen(const ifstream& stream)
{
	if (!stream.is_open())
		throw exception("Can't open file");
}
