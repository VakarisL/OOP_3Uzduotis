#ifndef STUDENTAIINFO_H_
#define	STUDENTAIINFO_H_

#include <string>
#include <vector>
#include <fstream>

/**
 * @brief Class to store the data about a student and his grades
 * @details 
 * 
 */

class studentaiInfo {
  private:
	std::string Vardas;
	std::string Pavarde;
	std::vector<int> nDarbai;
	int Egzaminas;
	double Vidurkis;
	double Mediana;
	double Galutinis_Balas;
	void readStudent(std:: istream&);
	void setVidurkis();
	void setMediana();
	void setGalutinisBalas();
  public:
  	/**
  	 * @brief basic constructor
  	 * @details sets values to 0
  	 * 
  	 */
	studentaiInfo() : Egzaminas(0), Vidurkis(0), Mediana(0), Galutinis_Balas(0) { }
	/**
	 * @brief istream constructor
	 * @details gets passed a file stream, and calls a function readStudent() which passes the to the class object
	 * 
	 * @param input [a single line frrom the file in format: ([name] [surname] [grade] [grade] [grade] [grade] [grade] [exam grade])]
	 */
	studentaiInfo(std::istream& input) { readStudent(input); setVidurkis(); setGalutinisBalas();}
	
	/**
	 * @brief Vardas getter
	 * 
	 */
	inline std::string vardas() const {return Vardas;}

	/**
	 * @brief Pavarde getter
	 * 
	 */
	inline std::string pavarde() const {return Pavarde;}

	/**
	 * @brief nDarbai getter
	 * 
	 */
	inline std::vector<int> pazymiai() const {return nDarbai;}
	/**
	 * @brief Egzaminas getter
	 * 
	 */
	inline int egzaminas() const {return Egzaminas;}
	/**
	 * @brief Vidurkis getter
	 * 
	 */
	inline double average() const {return Vidurkis;}
	/**
	 * @brief Mediana getter
	 * @details usually has value of 0 as setMediana() function isn't used 
	 */
	inline double median() const {return Mediana;}
	/**
	 * @brief Galutinis_Balas getter
	 * 
	 */
	inline double galBalas() const {return Galutinis_Balas;}
	/**
	 * @brief output stream operator
	 * @details returns nicely formatted info about the class object (the contents/values of it's variables)
	 * 
	 */
	friend std::ostream& operator<<(std::ostream&, const studentaiInfo&);
	/**
	 * @brief comparison operator (less than)
	 * @details compares two same class objects by Galutinis_Balas
	 * 
	 */
	inline bool operator<(const studentaiInfo& a) const {return (galBalas() < a.galBalas());}
	/**
	 * @brief comparison operator (equals)
	 * @details compares whether two class objects have the same Galutinis_Balas
	 * 
	 */
	inline bool operator==(const studentaiInfo& a) const {return (galBalas() == a.galBalas());}
};

inline bool operator!=(const studentaiInfo& a, const studentaiInfo& b) {return !(a == b);}
inline bool operator<=(const studentaiInfo& a, const studentaiInfo& b) {return (a < b) || (a == b);}
inline bool operator>(const studentaiInfo& a, const studentaiInfo& b) {return !(a <= b);}
inline bool operator>=(const studentaiInfo& a, const studentaiInfo& b) {return !(a < b);}

#endif