#include "Reader.h"
#include "TapeMatrix.h"

TapeMatrix::TapeMatrix(const string InputMatrix, const string InputDiag)
{
	FileReader ReadStream;

	ReadStream.ReadMatrix(Matrix, InputMatrix);
	ReadStream.ReadVector(Diag, InputDiag);
}
void TapeMatrix::ReadLAMatrix(const string& Path) {
	FileReader reader;
	reader.ReadMatrix(Matrix, Path);
}
void TapeMatrix::ReadLADiagonal(const string& Path) {
	FileReader reader;
	reader.ReadVector(Diag, Path);
}
