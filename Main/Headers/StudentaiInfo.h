#ifndef STUDENTAIINFO_H_
#define	STUDENTAIINFO_H_

#include <string>
#include <vector>

struct studentaiInfo {
	std::string vardas;
	std::string pavarde;
	std::vector<int> nDarbai;
	int egzaminas;
	double average;
	double median;
};

#endif