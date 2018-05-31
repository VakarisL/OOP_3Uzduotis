#include "catch.hpp"
#include "../Headers/StudentaiInfo.h"
#include "../Headers/InfoFromFile.h"
#include "../Headers/Menu.h"


TEST_CASE("File read/average", "[one]"){
	std::vector<studentaiInfo> studentai;
	read_data(studentai);
	std::sort(studentai.begin(), studentai.end(), compareNames);
	REQUIRE(studentai[2].vardas()=="Vakaris");
	REQUIRE(studentai[2].pavarde()=="Likas");
	REQUIRE(studentai[2].average()==7.00);
}