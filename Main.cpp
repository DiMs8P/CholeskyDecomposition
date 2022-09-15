#include "Reader.h"
#include "Decompositor.h"
#include <vector>
#include "Writer.h"
#include "Config.h"
#include "SolverOfSLAE.h"
#include "Utils.h"
#include <iostream>

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
	const std::vector<real> Vec1 = Solver.SolveWithLowerTriangle(Matrix, Diag, Vector);
	std::vector<real> Vec2 = Solver.SolveWithHigherTriangle(Matrix, Diag, Vec1);

	Writer::WriteMatrixToFile(Matrix, "MatrixOutput.txt");
	Writer::WriteVectorToFile(Diag, "DiagOutput.txt");
	Writer::WriteVectorToFile(Vec2, "Output.txt");

	std::cout << Utils::CalcScalarProduct(Vec2, Vec2) << '\n';
	std::cout << std::fixed << Utils::CalcScalarProduct(Vector, Vector);

	return 0;
}