#include "Reader.h"
#include "TapeMatrix.h"

TapeMatrix::TapeMatrix(const std::string InputMatrix, const std::string InputDiag)
{
	FileReader ReadStream;

	ReadStream.ReadMatrix(Matrix, InputMatrix);
	ReadStream.ReadVector(Diag, InputDiag);
}
void TapeMatrix::ReadLAMatrix(const std::string& Path) {
	FileReader reader;
	reader.ReadMatrix(Matrix, Path);
}
void TapeMatrix::ReadLADiagonal(const std::string& Path) {
	FileReader reader;
	reader.ReadVector(Diag, Path);
}
