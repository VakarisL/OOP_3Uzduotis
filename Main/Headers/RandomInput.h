#ifndef RANDOMINPUT_H_
#define	RANDOMINPUT_H_

struct studentaiInfoTest {
	std::string vardas;
	std::string pavarde;
	std::vector<int> nDarbai;
	int egzaminas;
	bool pass; // True - average of nDarbai >= 6, False otherwise
};

void generate_values(std::vector<int> *ivertinimai, int *egzaminas);  // function that generates a selected number of values pseudorandomly;
void generate_speed_test(std::vector <studentaiInfoTest>& speedTest, int amount);
bool comparePass(const studentaiInfoTest& a, const studentaiInfoTest& b);

#endif