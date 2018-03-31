#ifndef CONSOLEOUTPUT_H_
#define	CONSOLEOUTPUT_H_

#include "../Headers/FileInput.h"

void SpeedTest(int);
//void FileWrite(std::vector <studentaiInfo>&, std::vector <studentaiInfo>&);
void FileWrite(std::vector <studentaiInfo>&);
void FileWrite(std::list <studentaiInfo>&);
void FileWrite(std::deque <studentaiInfo>&);
void test(std::vector <studentaiInfo>&);
void test(std::list <studentaiInfo>&);
void test(std::deque <studentaiInfo>&);
bool Compare_By_Average(const studentaiInfo &a, const studentaiInfo &b);
//void SortingFailures(std::vector <studentaiInfo>& , std::vector <studentaiInfo>&);

#endif