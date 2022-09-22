#pragma once

#include <vector>
#include "Config.h"

class HilbertMatrix
{
public:
	std::vector<std::vector<real>> GenerateALMatrix(const int Size);
	std::vector<real> GenerateDiag(const int Size);
};
