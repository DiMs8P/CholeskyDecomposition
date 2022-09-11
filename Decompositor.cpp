#include "Decompositor.h"

void Decompositor::DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real> Vector) {

    if (Matrix.empty())
        return;

	const int HalfWidth = Matrix[0].size();
	DecomposeTheFirstHalfWidth(Matrix, Vector, HalfWidth);

}

void Decompositor::DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real> Vector, const int HalfWidth) {

    real Accumulator = 0;

    Vector[0] = sqrt(Vector[0]);

    for (int i = 1; i < HalfWidth; ++i)
    {
        // вычислили самый левый
        Matrix[i][HalfWidth - i] /= Vector[0];
        Vector[i] -= pow(Matrix[i][HalfWidth - i], 2);

        for (int j = HalfWidth - i + 1; j < HalfWidth; ++j)
        {

            for (int k = 0; k < j - HalfWidth - i; k++)
            {
                Accumulator += Matrix[i][HalfWidth - i + k] * Matrix[j - (HalfWidth - i)][2 * HalfWidth - j - i + (k)];
            }

            Matrix[i][j] -= Accumulator / Vector[j - (HalfWidth - i)];
            Accumulator = 0;
        }

        for (int j = HalfWidth - i; j < HalfWidth; ++j)
        {
            Accumulator += Matrix[i][j] * Matrix[i][j];
        }
        Vector[i] = sqrt(Vector[i] - Accumulator);
        Accumulator = 0;
    }
}
