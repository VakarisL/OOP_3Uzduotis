#ifndef TESTS_H_
#define TESTS_H_

#include <vector>
#include <list>
#include <deque>
#include "../Headers/StudentaiInfo.h"

void SpeedTest(int, void (*)(std::vector<studentaiInfo>&));
void test(std::vector <studentaiInfo>&);
bool Compare_By_Result(const studentaiInfo&, const studentaiInfo&);
void testTwoContainers(std::vector <studentaiInfo>&);
void testSingleContainer(std::vector <studentaiInfo>&);
bool Check_if_Pass(studentaiInfo&);
bool Check_if_Fail(studentaiInfo&);

#endif