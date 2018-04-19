#ifndef MENU_H_
#define	MENU_H_

#include "../Headers/studentaiInfo.h"

void MainMenu(int&);
void output(std::vector<studentaiInfo>&);
bool compareNames(const studentaiInfo&, const studentaiInfo&);

#endif