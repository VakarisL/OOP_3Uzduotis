#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "../Main/Headers/MathFunctions.h"

double darbuVidurkis(const std::vector<int>& ivertinimai){
	if (ivertinimai.size() == 0) return 0;
	return ((double) std::accumulate(ivertinimai.begin(), ivertinimai.end(), 0.0) / ivertinimai.size());
}

double darbuMediana(const std::vector<int> ivertinimai) {
	std::vector<int> *tempVector = new std::vector<int>;
	*tempVector = ivertinimai;
	if (tempVector->size() == 0) return 0;
	std::sort(tempVector->begin(), tempVector->end());
	if (tempVector->size() % 2 == 1) {
		return tempVector->operator[]((tempVector->size() - 1) / 2);
	} else {
		return ((double)tempVector->operator[]((tempVector->size() - 1) / 2) / 2 +
		        (double)tempVector->operator[]((tempVector->size() - 1) / 2 + 1) / 2);
	}
}
