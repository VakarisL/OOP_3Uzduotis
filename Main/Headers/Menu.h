#ifndef MENU_H_
#define	MENU_H_

#include "../Headers/studentaiInfo.h"

void InitialInfo(std::string&, std::string&);
void MainMenu(int&);
void output(studentaiInfo&);
void output(std::vector<studentaiInfo>&);
bool compareNames(const studentaiInfo&, const studentaiInfo&);

#endif