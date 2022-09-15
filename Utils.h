#pragma once

#include "Config.h"
#include <vector>

namespace Utils {
	inline real CalcScalarProduct(const std::vector<real>& Vec1, const std::vector<real>& Vec2)
	{
		if (Vec1.size() != Vec2.size())
			return -1;

		real Accumulator = 0;

		for (int i = 0; i < Vec1.size(); i++)
		{
			Accumulator += Vec1[i] * Vec2[i];
		}

		return Accumulator;
	}
}