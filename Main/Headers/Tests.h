#ifndef TESTS_H_
#define TESTS_H_

#include <vector>
#include <list>
#include <deque>
#include "../Headers/StudentaiInfo.h"

void SpeedTest(int, int);
void test(std::vector <studentaiInfo>&);
void test(std::list <studentaiInfo>&);
void test(std::deque <studentaiInfo>&);
bool Compare_By_Result(const studentaiInfo&, const studentaiInfo&);
void testTwoContainers(std::vector <studentaiInfo>&);
void testTwoContainers(std::list <studentaiInfo>&);
void testTwoContainers(std::deque <studentaiInfo>&);
void testSingleContainer(std::vector <studentaiInfo>&);
void testSingleContainer(std::list <studentaiInfo>&);
void testSingleContainer(std::deque <studentaiInfo>&);
bool Check_if_Pass(studentaiInfo&);
bool Check_if_Fail(studentaiInfo&);

#endif