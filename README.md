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


### 1- Skaityti pazymius is failo; (v0.2/v0.3)
Nuskaito informaciją iš pateikto failo `Kursiokai.txt` ir pateikia surušiuotą lentelę su galutiniais pažymiais
- (formatas: Pavarde Vardas Pažymys Pažymys Pažymys Pažymys Pažymys Egzaminas)

### 2- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika; (v0.4/v0.5)
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector` konteinerį
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa surūšiuoja visą konteinerį pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6
- Sukuria failus TestOutputV.txt kuriuose pateikiami galutiniai įrašai

### 3- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius; (v1.0)
Generuoja test.txt failą su n įrašų ir matuoja programos veikimo laiką naudojant `vector` konteinerį
Veikimo principas:
- Nuskaitomas failas į operatyviąją atmintį
- Programa suskirsto nuskaitytą konteinerį į du naujus pagal surinktus galutinius pažymius
- Programa surūšiuoja abu naujus konteinerius pagal surinktus galutinius pažymius
- Programa į naują failą surašo įrašus pažymių mažėjimo eile
- prie kiekvieno įrašo prirašoma pass/fail, priklausomai nuo to ar pažymiai mažesni už 6
- Sukuria failus TestOutputV.txt kuriuose pateikiami galutiniai įrašai

### 4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri; v(1.0)
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