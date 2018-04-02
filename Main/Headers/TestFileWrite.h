#ifndef TESTFILEWRITE_H_
#define TESTFILEWRITE_H_

#include <vector>
#include <list>
#include <deque>
#include "../Headers/StudentaiInfo.h"

void FileWrite(std::vector <studentaiInfo>&);
void FileWrite(std::list <studentaiInfo>&);
void FileWrite(std::deque <studentaiInfo>&);
void FileWriteUC(std::vector <studentaiInfo>&, std::vector <studentaiInfo>&);
void FileWriteUC(std::list <studentaiInfo>&, std::list <studentaiInfo>&);
void FileWriteUC(std::deque <studentaiInfo>&, std::deque <studentaiInfo>&);

#endif