#include "Reader.h"
#include "Solution/Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"
#include "HilbertMatrix.h"

void GaussTest()
{
	SolverOfSLAE Solver;
	FileWriter FileWriter;

	std::vector<std::vector<real>> matrix
	{
		{1, 1, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 1, 1},
		{-1, -2, -3, -21}
	};
	Solver.ToUpperTriangle(matrix);

	FileWriter.WriteMatrix(matrix, "Gauss.txt");
}

int main() {
	GaussTest();
	/*Decompositor Solution;
	SolverOfSLAE Solver;

	std::vector<std::vector<real>> Matrix;
	std::vector<real> Vector;
	std::vector<real> Diag;

	HilbertMatrix HMatrix;
	std::vector<std::vector<real>> HilbertMatrix = HMatrix.GenerateALMatrix(HilbertSize);
	std::vector<real> HilbertVector = HMatrix.GenerateDiag(HilbertSize);
	Vector = HMatrix.GetHilbertMatrixXVectorProduct(HilbertSize);

	FileWriter FileWriter;
	FileWriter.WriteMatrix(HilbertMatrix, "HilbertMatrixOutput.txt");
	FileWriter.WriteVector(HilbertVector, "HilbertDiagOutput.txt");
	FileWriter.WriteVector(Vector, "Vector.txt");

	FileReader FilerReader;
	FilerReader.ReadMatrix(Matrix, "HilbertMatrixOutput.txt");
	FilerReader.ReadVector(Vector, "Vector.txt");
	FilerReader.ReadVector(Diag, "HilbertDiagOutput.txt");

	Solution.DecomposeByCholesky(Matrix, Diag);
	const std::vector<real> Vec1 = Solver.SolveWithLALowerTriangle(Matrix, Diag, Vector);
	std::vector<real> Vec2 = Solver.SolveWithLAHigherTriangle(Matrix, Diag, Vec1);

	FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");*/

	return 0;
}