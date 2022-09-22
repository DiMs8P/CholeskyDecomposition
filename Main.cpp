#include "Reader.h"
#include "Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"
#include "HilbertMatrix.h"

int main() {
	Decompositor Solution;
	SolverOfSLAE Solver;

	std::vector<std::vector<real>> Matrix;
	std::vector<real> Vector;
	std::vector<real> Diag;

	HilbertMatrix HMatrix;
	std::vector<std::vector<real>> HilbertMatrix = HMatrix.GenerateALMatrix(HilbertSize);
	std::vector<real> HilbertVector = HMatrix.GenerateDiag(HilbertSize);

	FileWriter FileWriter;
	FileWriter.WriteMatrix(HilbertMatrix, "HilbertMatrixOutput.txt");
	FileWriter.WriteVector(HilbertVector, "HilbertDiagOutput.txt");

	FileReader FilerReader;
	FilerReader.ReadMatrix(Matrix, "Matrix.txt");
	FilerReader.ReadVector(Vector, "Vector.txt");
	FilerReader.ReadVector(Diag, "Diag.txt");

	Solution.DecomposeByCholesky(Matrix, Diag);
	const std::vector<real> Vec1 = Solver.SolveWithLowerTriangle(Matrix, Diag, Vector);
	std::vector<real> Vec2 = Solver.SolveWithHigherTriangle(Matrix, Diag, Vec1);

	FileWriter.WriteMatrix(Matrix, "MatrixOutput.txt");
	FileWriter.WriteVector(Diag, "DiagOutput.txt");
	FileWriter.WriteVector(Vec2, "Output.txt");

	return 0;
}