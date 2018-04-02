# OOP_2DuomenuApdorojimas - Vakario Liko antra objektinio programavimo pratybų užduotis


## Naudojimo instrukcija:
### - Windows (naudojant cmd.exe; tik jeigu instaliuoti Cmake įrankiai ir GCC kompiliatorius):
- `git clone https://github.com/VakarisL/OOP_2DuomenuApdorojimas.git`
- `cmake . -G "MinGW Makefiles"`
- `mingw32-make`
- `.\main`

### - Unix (untested)
- `git clone https://github.com/VakarisL/OOP_2DuomenuApdorojimas.git`
- `cmake .`
- `make`
- `./main`


## Programos valdymo meniu:
```
Ar norite:
1- Irasyti pazymius ranka;
2- Generuoti atsitiktinius pazymius;
3- Skaityti pazymius is failo;
4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika;
5- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius;
6- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri;
7- Iseiti...
```

### 1- Irasyti pazymius ranka; (v0.1)
Leidžia įvesti norimo studento/mokinio vardą ir pavardę, bet kokį kiekį jo gautų pažymių (norint sustoti, reikia įvesti -1) ir egzamino pažymį. 
Suskaičiuoja ir pateikia įvestus pažymius bei galutinius pažymius naudojant vidurkį ir medianą

### 2- Generuoti atsitiktinius pazymius; (v0.1)
Leidžia įvesti norimo studento/mokinio vardą ir pavardę, ir pasirinkti kokį kiekį jo gautų pažymių norėtumėme sugeneruoti pseudo-atsitiktiniu generavimo būdu.
Suskaičiuoja ir pateikia sugeneruotus pažymius bei galutinius pažymius naudojant vidurkį ir medianą

### 3- Skaityti pazymius is failo; (v0.2/v0.3)
Nuskaito informaciją iš pateikto failo `Kursiokai.txt` ir pateikia surušiuotą lentelę su galutiniais pažymiais
- (formatas: Pavarde Vardas Pažymys Pažymys Pažymys Pažymys Pažymys Egzaminas)

### 4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika; (v0.4/v0.5)
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector`, `list` ir `deque` konteinerius
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa surūšiuoja visą konteinerį pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6

### 5- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius; (v1.0)
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector`, `list` ir `deque` konteinerius
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa suskirsto nuskaitytą konteinerį į du naujus pagal surinktus galutinius pažymius
- Programa surūšiuoja abu naujus konteinerius pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6

### 6- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri; v(1.0)
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector`, `list` ir `deque` konteinerius
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa sukuria naują konteinerį į kurį įkelia įrašus su mažais pažymiais
- Programa nuskaitytame konteineryje ištrina įrašus su mažais pažymiais
- Programa surūšiuoja abu naujus konteinerius pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6

### 7- Iseiti...
Programa užsidaro
