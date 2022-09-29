#include "VectorFileReader.h"
#include "MatrixFileReader.h"
#include "Solution/Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SLAESolver.h"
#include "HilbertMatrix.h"

void GaussTest()
{
	/*SLAESolver Solver;
	FileWriter FileWriter;

	vector<vector<real>> matrix
	{
		{1, 1, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 1, 1},
		{-1, -2, -3, -21}
	};
	Solver.ToUpperTriangle(matrix);

	FileWriter.WriteMatrix(matrix, "Gauss.txt");*/
}

int main() {
	GaussTest();
	Decompositor decompositor;
	SLAESolver SLAESolver;

	vector<vector<real>> matrix;
	vector<real> v;
	vector<real> diag;

	ALHilbertMatrix hilbertMatrix(
		HilbertSize,
		FileWriter("HilbertMatrixOutput.txt"),
		FileWriter("HilbertDiagOutput.txt")
	);

	hilbertMatrix.Write();

	// добавить в Hilbert matrix умножение на вектор
	//Vector = HMatrix.GetProductByVector(HilbertSize);

	//FileWriter FileWriter;
	//FileWriter.WriteVector(Vector, "Vector.txt");

	MatrixFileReader matrixReader("HilbertMatrixOutput.txt");
	VectorFileReader vectorReader("Vector.txt");
	VectorFileReader diagReader("HilbertDiagOutput.txt");

	matrixReader.Read(matrix);
	vectorReader.Read(v);
	diagReader.Read(diag);

	decompositor.DecomposeByCholesky(matrix, diag);
	const vector<real> vec1 = SLAESolver.SolveWithLALowerTriangle(matrix, diag, v);
	vector<real> vec2 = SLAESolver.SolveWithLAHigherTriangle(matrix, diag, vec1);

	/*FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");*/

	return 0;
}