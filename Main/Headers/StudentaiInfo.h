#ifndef STUDENTAIINFO_H_
#define	STUDENTAIINFO_H_

#include <string>
#include <vector>
#include <fstream>

/**
 * @brief class to store the data about a student and his grades
 * @details [long description]
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
	studentaiInfo() : Egzaminas(0), Vidurkis(0), Mediana(0), Galutinis_Balas(0) { }
	studentaiInfo(std::istream& input) { readStudent(input); setVidurkis(); setGalutinisBalas();}
	inline std::string vardas() const {return Vardas;}
	inline std::string pavarde() const {return Pavarde;}
	inline std::vector<int> pazymiai() const {return nDarbai;}
	inline int egzaminas() const {return Egzaminas;}
	inline double average() const {return Vidurkis;}
	inline double median() const {return Mediana;}
	inline double galBalas() const {return Galutinis_Balas;}
	friend std::ostream& operator<<(std::ostream&, const studentaiInfo&);
	inline bool operator<(const studentaiInfo& a) const {return (galBalas() < a.galBalas());}
	inline bool operator==(const studentaiInfo& a) const {return (galBalas() == a.galBalas());}
};

inline bool operator!=(const studentaiInfo& a, const studentaiInfo& b) {return !(a == b);}
inline bool operator<=(const studentaiInfo& a, const studentaiInfo& b) {return (a < b) || (a == b);}
inline bool operator>(const studentaiInfo& a, const studentaiInfo& b) {return !(a <= b);}
inline bool operator>=(const studentaiInfo& a, const studentaiInfo& b) {return !(a < b);}

#endif