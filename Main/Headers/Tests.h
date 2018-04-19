#ifndef TESTS_H_
#define TESTS_H_

#include <vector>
#include "../Headers/StudentaiInfo.h"

void SpeedTest(int, void (*)(std::vector<studentaiInfo>&, int));
void test(std::vector <studentaiInfo>&, int);
bool Compare_By_Result(const studentaiInfo&, const studentaiInfo&);
void testTwoContainers(std::vector <studentaiInfo>&, int);
void testSingleContainer(std::vector <studentaiInfo>&, int);
bool Check_if_Pass(studentaiInfo&);
bool Check_if_Fail(studentaiInfo&);

#endif