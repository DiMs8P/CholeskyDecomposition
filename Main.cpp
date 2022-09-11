#include "Reader.h"
#include "Decompositor.h"
#include <vector>
#include "Config.h"
#include "SolverOfSLAE.h"

int main() {
	Reader reader;
	Decompositor Solution;
	Solver

	std::vector<std::vector<real>> Matrix;
	std::vector<real> Vector;
	std::vector<real> Diag;

	reader.MatrixReader(Matrix, "Matrix.txt");
	reader.VectorReader(Vector, "Vector.txt");
	reader.VectorReader(Diag, "Diag.txt");

	//Solution.DecomposeByCholesky(Matrix, Diag);

	

	return 0;
}