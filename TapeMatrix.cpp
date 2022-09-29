#include "Reader.h"
#include "TapeMatrix.h"

TapeMatrix::TapeMatrix(const string inputMatrix, const string inputDiag)
{
	Reader reader;

	reader.ReadMatrix(_matrix, inputMatrix);
	reader.ReadVector(_diag, inputDiag);
}
void TapeMatrix::ReadLAMatrix(const string& path) {
	Reader reader;
	reader.ReadMatrix(_matrix, path);
}
void TapeMatrix::ReadLADiagonal(const string& path) {
	Reader reader;
	reader.ReadVector(_diag, path);
}
