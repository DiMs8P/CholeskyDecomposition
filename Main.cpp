#include "Reader.h"
#include "Solution/Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"
#include "HilbertMatrix.h"

void GaussTest()
{
	/*SolverOfSLAE Solver;
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
	Decompositor Solution;
	SolverOfSLAE Solver;

	vector<vector<real>> Matrix;
	vector<real> Vector;
	vector<real> Diag;

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

	FileReader FilerReader;
	FilerReader.ReadMatrix(Matrix, "HilbertMatrixOutput.txt");
	FilerReader.ReadVector(Vector, "Vector.txt");
	FilerReader.ReadVector(Diag, "HilbertDiagOutput.txt");

	Solution.DecomposeByCholesky(Matrix, Diag);
	const vector<real> Vec1 = Solver.SolveWithLALowerTriangle(Matrix, Diag, Vector);
	vector<real> Vec2 = Solver.SolveWithLAHigherTriangle(Matrix, Diag, Vec1);

	/*FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");*/

	return 0;
}