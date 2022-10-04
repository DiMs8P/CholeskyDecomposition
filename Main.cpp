#include "VectorFileReader.h"
#include "MatrixFileReader.h"
#include "Solution/Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SLAESolver.h"
#include "HilbertTapeMatrix.h"

void GaussTest()
{
	SLAESolver Solver;
	FileWriter vectorWriter("Gauss.txt");

	vector<vector<real>> matrix
	{
		{1, 1, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 1, 1},
		{-1, -2, -3, -21}
	};
	auto answer = Solver.SolveByGaussMethod(matrix, vector<real> {1, 2, 3, 4});
	vectorWriter.WriteVector(answer);
}

void HilbertExample()
{
	HilbertTapeMatrix hilbertMatrix(
		HilbertSize,
		FileWriter("HilbertMatrixOutput.txt"),
		FileWriter("HilbertDiagOutput.txt")
	);

	hilbertMatrix.Write();

	const auto hilbertProductByDefaultVector = hilbertMatrix.GetProductByZeroToSizeVector(HilbertSize);

	FileWriter hilbertProduct("hilbertProduct.txt");
	hilbertProduct.WriteVector(hilbertProductByDefaultVector);
}

int main() {
	GaussTest();
	Decompositor decompositor;
	SLAESolver SLAESolver;
	MatrixFileReader matrixReader("HilbertMatrixOutput.txt");
	VectorFileReader vectorReader("Vector.txt");
	VectorFileReader diagReader("HilbertDiagOutput.txt");

	vector<vector<real>> matrix;
	vector<real> v;
	vector<real> diag;

	matrixReader.Read(matrix);
	vectorReader.Read(v);
	diagReader.Read(diag);

	decompositor.DecomposeByCholesky(matrix, diag);
	const vector<real> vec1 = SLAESolver.SolveWithTapeMatrixAsLowerTriangle(matrix, diag, v);
	vector<real> vec2 = SLAESolver.SolveWithTapeMatrixAsHigherTriangle(matrix, diag, vec1);

	/*FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");*/

	return 0;
}
