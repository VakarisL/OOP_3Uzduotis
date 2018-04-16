#include <iostream>
#include <vector>

#include "../Main/Headers/StudentaiInfo.h"
#include "../Main/Headers/MathFunctions.h"


double studentaiInfo::average() const{
	return ::darbuVidurkis(nDarbai);
}

double studentaiInfo::median() const{
	return ::darbuMediana(nDarbai);
}

double studentaiInfo::galBalas(double (*mathFunc)(const std::vector<int>&)) const{
	return (0.4 * mathFunc(nDarbai) + Egzaminas * 0.6);
}
