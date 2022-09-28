#pragma once

#include "../Config.h"
#include <vector>

class Decompositor
{
public:
	// !TODO почему в декомпозитор нужен вектор
	void DecomposeByCholesky(vector<vector<real>>& matrix, vector<real>& Vector);

private:
	void DecomposeTheFirstHalfWidth(vector<vector<real>>& matrix, vector<real>& Vector);
	void FinishDecomposition(vector<vector<real>>& matrix, vector<real>& Vector);
};

