#include "Reader.h"
#include "TapeMatrix.h"

TapeMatrix::TapeMatrix(const string inputMatrix, const string inputDiag)
{
	FileReader reader;

	reader.ReadMatrix(_matrix, inputMatrix);
	reader.ReadVector(_diag, inputDiag);
}
void TapeMatrix::ReadLAMatrix(const string& path) {
	FileReader reader;
	reader.ReadMatrix(_matrix, path);
}
void TapeMatrix::ReadLADiagonal(const string& path) {
	FileReader reader;
	reader.ReadVector(_diag, path);
}
