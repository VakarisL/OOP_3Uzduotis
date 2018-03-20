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

void read_data(std::vector<studentaiInfo>& );
void read_data_test(std::vector<studentaiInfo>& ); 
void read_data_test(std::list<studentaiInfo>& );
void read_data_test(std::deque<studentaiInfo>& );
void write_data(std::vector<studentaiInfo> ); 
bool compareNames(const studentaiInfo&, const studentaiInfo&); 

#endif