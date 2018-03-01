#ifndef FILEINPUT_H_
#define	FILEINPUT_H_

struct studentaiInfo {
	std::string vardas;
	std::string pavarde;
	std::vector<int> nDarbai;
	int egzaminas;
	double average;
	double median;
};

void read_data(std::vector<studentaiInfo>& studentai); //reads the data from file into a vector of structures
void write_data(std::vector<studentaiInfo> studentai); // calculates and outputs the final result from a vector of 'studentaiInfo'
bool compareNames(const studentaiInfo& a, const studentaiInfo& b); // comparison function that allows us to sort vector of 'studentaiInfo' by 'vardas'

#endif