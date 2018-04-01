#ifndef TESTS_H_
#define TESTS_H_

#include <vector>
#include <list>
#include <deque>
#include "../Headers/StudentaiInfo.h"

void SpeedTest(int);
void test(std::vector <studentaiInfo>&);
void test(std::list <studentaiInfo>&);
void test(std::deque <studentaiInfo>&);
bool Compare_By_Average(const studentaiInfo&, const studentaiInfo&);

#endif