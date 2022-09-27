#include "Reader.h"
#include "Solution/Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"
#include "HilbertMatrix.h"

std::vector<real> GetHilbertMatrixXVectorProduct(const int HilbertMatrixSize)
{
	std::vector<real> Output(HilbertMatrixSize);
	for (int i = 0; i < HilbertMatrixSize; i++)
	{
		accVarType Sum = 0;
		for (int j = 1; j <= HilbertMatrixSize; j++)
		{
			Sum += (accVarType)j / (j + i);
		}
		Output[i] = Sum;
	}
	return Output;
}

int main() {
	Decompositor Solution;
	SolverOfSLAE Solver;

	std::vector<std::vector<real>> Matrix;
	std::vector<real> Vector;
	std::vector<real> XVector(HilbertSize);
	std::vector<real> Diag;

	for (int i = 0; i < HilbertSize; i++)
	{
		XVector[i] = i + 1;
	}

	HilbertMatrix HMatrix;
	std::vector<std::vector<real>> HilbertMatrix = HMatrix.GenerateALMatrix(HilbertSize);
	std::vector<real> HilbertVector = HMatrix.GenerateDiag(HilbertSize);
	Vector = GetHilbertMatrixXVectorProduct(HilbertSize);

	FileWriter FileWriter;
	FileWriter.WriteMatrix(HilbertMatrix, "HilbertMatrixOutput.txt");
	FileWriter.WriteVector(HilbertVector, "HilbertDiagOutput.txt");
	FileWriter.WriteVector(Vector, "Vector.txt");

	FileReader FilerReader;
	FilerReader.ReadMatrix(Matrix, "HilbertMatrixOutput.txt");
	FilerReader.ReadVector(Vector, "Vector.txt");
	FilerReader.ReadVector(Diag, "HilbertDiagOutput.txt");

	Solution.DecomposeByCholesky(Matrix, Diag);
	const std::vector<real> Vec1 = Solver.SolveWithLowerTriangle(Matrix, Diag, Vector);
	std::vector<real> Vec2 = Solver.SolveWithHigherTriangle(Matrix, Diag, Vec1);

	FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");

	return 0;
}