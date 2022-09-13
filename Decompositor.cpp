#include "Decompositor.h"

void Decompositor::DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag) {

    if (Matrix.empty())
        return;

	const int HalfWidth = Matrix[0].size();
    const int MatrixSize = Diag.size();
	DecomposeTheFirstHalfWidth(Matrix, Diag, HalfWidth);
    DecomposeTheLast(Matrix, Diag, MatrixSize);

}

void Decompositor::DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag, const int HalfWidth) {

    real Accumulator = 0;

    Diag[0] = sqrt(Diag[0]);

    for (int i = 1; i <= HalfWidth; ++i)
    {
        // вычислили самый левый
        Matrix[i][HalfWidth - i] /= Diag[0];

        for (int j = HalfWidth - i + 1; j < HalfWidth; ++j)
        {

            for (int k = 0; k < j - (HalfWidth - i); k++)
            {
                Accumulator += Matrix[i][HalfWidth - i + k] * Matrix[j - (HalfWidth - i)][(2 * HalfWidth) - j + k - i];
            }

            Matrix[i][j] -= Accumulator;
            Matrix[i][j] /= Diag[j - (HalfWidth - i)];
            Accumulator = 0;
        }

        for (int j = HalfWidth - i; j < HalfWidth; ++j)
        {
            Accumulator += Matrix[i][j] * Matrix[i][j];
        }
        Diag[i] = sqrt(Diag[i] - Accumulator);
        Accumulator = 0;
    }
}

void Decompositor::DecomposeTheLast(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag, const int MatrixSize) {
    real Accumulator = 0;
    int HalfWidth = Matrix[0].size();

    for (int i = HalfWidth + 1; i < MatrixSize; ++i)
    {
        // вычислили самый левый
        Matrix[i][0] /= Diag[i - HalfWidth];

        for (int j = 1; j < HalfWidth; ++j)
        {

            for (int k = 0; k < j; k++)
            {
                Accumulator += Matrix[i][k] * Matrix[j - (HalfWidth - i)][HalfWidth - j + k];
            }

            Matrix[i][j] -= Accumulator; 
            Matrix[i][j] /= Diag[j - (HalfWidth - i)];
            Accumulator = 0;
        }

        for (int j = 0; j < HalfWidth; ++j)
        {
            Accumulator += Matrix[i][j] * Matrix[i][j];
        }
        Diag[i] = sqrt(Diag[i] - Accumulator);
        Accumulator = 0;
    }

    Accumulator = 0;
}