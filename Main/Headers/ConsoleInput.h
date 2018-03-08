#ifndef CONSOLEINPUT_H_
#define	CONSOLEINPUT_H_

void input_by_hand(std::vector<int> *ivertinimai, int *egzaminas);  // function that lets you enter 'any' amount of values by hand;
void InitialInfo(std::string& vardas, std::string& pavarde);	// function that lets you enter name, surname values for
																// 'input by hand or generate values options'
void MainMenu(int& choice); //displays main menu and saves the user choice

#endif