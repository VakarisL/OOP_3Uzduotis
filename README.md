# OOP_3Uzduotis - Vakario Liko trecia objektinio programavimo pratybų užduotis

## Naudojimo instrukcija:
### - Windows (naudojant git bash; tik jeigu instaliuoti Cmake įrankiai ir GCC kompiliatorius):
- `git clone https://github.com/VakarisL/OOP_3Uzduotis.git`
- `cd OOP_3Uzduotis`
- `cmake . -G "MinGW Makefiles"`
- `mingw32-make`
- `.\main`

### - Unix (untested)
- `git clone https://github.com/VakarisL/OOP_3Uzduotis.git`
- `cd OOP_3Uzduotis`
- `cmake .`
- `make`
- `./main`


## Programos valdymo meniu:
```
Ar norite:
1- Skaityti pazymius is failo;
2- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika;
3- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius;
4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri;
5- Iseiti...
```


### 1- Skaityti pazymius is failo;
Nuskaito informaciją iš pateikto failo `Kursiokai.txt` ir pateikia surušiuotą lentelę su galutiniais pažymiais
- (formatas: Pavarde Vardas Pažymys Pažymys Pažymys Pažymys Pažymys Egzaminas)

### 2- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika;
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector` konteinerį
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa surūšiuoja visą konteinerį pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6
- Sukuria failus TestOutputV.txt kuriuose pateikiami galutiniai įrašai

### 3- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius;
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector` konteinerį
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa suskirsto nuskaitytą konteinerį į du naujus pagal surinktus galutinius pažymius
- Programa surūšiuoja abu naujus konteinerius pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6
- Sukuria failus TestOutputV.txt kuriuose pateikiami galutiniai įrašai

### 4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri;
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector`konteinerį
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa sukuria naują konteinerį į kurį įkelia įrašus su mažais pažymiais
- Programa nuskaitytame konteineryje ištrina įrašus su mažais pažymiais
- Programa surūšiuoja abu naujus konteinerius pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6
- Sukuria failus TestOutputV.txt kuriuose pateikiami galutiniai įrašai

### 5- Iseiti...
Programa užsidaro

## Spartos palyginimų lentelės (tarp struct ir class, naudojant vector konteinerį):
### 2 metodu
| Generuotų įrašų kiekis | Struct (-O3) | Class (-O3) | Class(-O2) | Class(-O1)
| :-------------: |:-------------:| :-----:|  :-----:|  :-----:
| 10      | 0.06498s | 0.006118s |  0.016001s|  0.0s
| 100      | 0.00702s | 0.005014s | 0.004027s|  0.01563s
| 1000 | 0.02306s | 0.015628s | 0.015627s|  0.031269s
| 10000 | 0.154425s | 0.141073s | 0.156437s|  0.226344s
| 100000 | 1.56439s  | 1.69389s | 1.81119s|  1.69688s


### 3 metodu, naudojant/išskirstant į du papildomus konteinerius
| Generuotų įrašų kiekis | Struct (-O3) | Class (-O3) | Class(-O2) | Class(-O1)
| :-------------: |:-------------:| :-----:|  :-----:|  :-----:
| 10      | 0.005514s | 0.0015595s |  0.015566s|  0.0s
| 100      | 0.008021s | 0.031279s | 0.0s|  0.0s
| 1000 | 0.030104s | 0.031279s | 0.046922s|  0.015628s
| 10000 | 0.151402s | 0.171868s | 0.187525s|  0.156266s
| 100000 | 1.59442s  | 1.59019s | 2.04596s|  1.74326s


### 4 metodu, naudojant vieną papildomą konteinerį, trinant įrašus iš orginalaus konteinerio
| Generuotų įrašų kiekis | Struct (-O3) | Class (-O3) | Class(-O2) | Class(-O1)
| :-------------: |:-------------:| :-----:|  :-----:|  :-----:
| 10      | 0.005504s |0.0115685s |  0.015563s|  0.015566s|  0.0s
| 100      | 0.0059915s | 0.004029s | 0.0s|  0.015589s
| 1000 | 0.027073s | 0.019705s | 0.031253s|  0.031281s
| 10000 | 0.153408s | 0.137174s | 0.171922s|  0.175059s
| 100000 | 1.58353s  | 1.64346s | 1.56424s|  1.56335s


## Not so Notable Stuff
### Switch statement
```C++
switch (choice) {
	case 1: {
		std::vector<studentaiInfo> studentai;
		read_data(studentai);
		output(studentai);
		break;
	}
	case 2: {
		SpeedTest(10, test);
		// [...]
		break;
	}
	case 3: {
		SpeedTest(10, testTwoContainers);
		//[...]
		break;
	}
	case 4: {
		SpeedTest(10, testSingleContainer);
		//[...]
		break;
	}
	case 5: {
		std::cout << "Bye bye!" << std::endl;
		break;
	}
	default: {
		std::cerr << "Ivyko switch klaida" << std::endl;
	}
	}
```


### studentaiInfo class
```C++
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
```