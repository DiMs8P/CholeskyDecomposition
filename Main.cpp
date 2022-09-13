#include "Reader.h"
#include "Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"

int main() {
	Decompositor Solution;
	SolverOfSLAE Solver;

	std::vector<std::vector<real>> Matrix;
	std::vector<real> Vector;
	std::vector<real> Diag;

	Reader::MatrixReader(Matrix, "Matrix.txt");
	Reader::VectorReader(Vector, "Vector.txt");
	Reader::VectorReader(Diag, "Diag.txt");

	Solution.DecomposeByCholesky(Matrix, Diag);
	Writer::WriteMatrixToFile(Matrix, "MatrixOutput.txt");
	Writer::WriteVectorToFile(Diag, "DiagOutput.txt");
	std::vector<real> Vec1 = Solver.SolveWithLowerTriangle(Matrix, Diag, Vector);
	std::vector<real> Vec2 = Solver.SolveWithHigherTriangle(Matrix, Diag, Vec1);

	Writer::WriteVectorToFile(Vec2, "Output.txt");

	return 0;
}