# OOP_2DuomenuApdorojimas - Vakario Liko antra objektinio programavimo pratybų užduotis


## Naudojimo instrukcija:
### - Windows (naudojant cmd.exe; tik jeigu instaliuoti Cmake įrankiai ir GCC kompiliatorius):
- `git clone https://github.com/VakarisL/OOP_2DuomenuApdorojimas.git`
- `cd OOP_2DuomenuApdorojimas`
- `cmake . -G "MinGW Makefiles"`
- `mingw32-make`
- `.\main`

### - Unix (untested)
- `git clone https://github.com/VakarisL/OOP_2DuomenuApdorojimas.git`
- `cd OOP_2DuomenuApdorojimas`
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


## Spartos palyginimų lentelės:
### v0.4/v0.5 metodu
| Generuotų įrašų kiekis | Vector | List  | Deque
| :-------------: |:-------------:| :-----:|  :-----:
| 10      | 0.06498s | 0.004012s |  0.003009s
| 100      | 0.00702s | 0.009027s | 0.005014s
| 1000 | 0.02306s | 0.021056s | 0.026056s
| 10000 | 0.154425s | 0.143439s | 0.157458s
| 100000 | 1.56439s  | 1.65258s | 1.75514s


### v1.0 metodu, naudojant/išskirstant į du papildomus konteinerius
| Generuotų įrašų kiekis | Vector | List  | Deque
| :-------------: |:-------------:| :-----:|  :-----:
| 10      | 0.005514s | 0.002493s |  0.004998s
| 100      | 0.008021s | 0.00502s | 0.010026s
| 1000 | 0.030104s | 0.020053s | 0.025568s
| 10000 | 0.151402s | 0.155922s | 0.155737s
| 100000 | 1.59442s  | 1.4895s | 1.622s


### v1.0 metodu (be optimizacijos), naudojant vieną papildomą konteinerį, trinant įrašus iš orginalaus konteinerio
| Generuotų įrašų kiekis | Vector | List  | Deque
| :-------------: |:-------------:| :-----:|  :-----:
| 10      | 0.004512s | 0.002006s |  0.003008s
| 100      | 0.005515s | 0.006516s | 0.006532s
| 1000 | 0.055147s | 0.020592s | 0.0311s
| 10000 | 3.86827s | 0.149931s | 1.31118s
| 100000 | 370.434s  | 1.47288s | 122.726s

### v1.0 metodu (optimizacuota), naudojant vieną papildomą konteinerį, trinant įrašus iš orginalaus konteinerio
| Generuotų įrašų kiekis | Vector | List  | Deque
| :-------------: |:-------------:| :-----:|  :-----:
| 10      | 0.005504s |0.003008s |  0.006017s
| 100      | 0.0059915s | 0.010512s | 0.007025s
| 1000 | 0.027073s | 0.023061s | 0.029583s
| 10000 | 0.153408s | 0.152944s | 0.166948s
| 100000 | 1.58353s  | 1.48761s | 1.56484s

## Spartos lentelių apžvalga:
Matome, kad neoptimizavus trynimo metodo vector ir deque konteineriai labai stipriai sulėtėja, naudojant didelius duomenų failus. List konteineriui trynimo metodas nekenkia, nes jame nereikia aktyviai perskirstyti atminties vietos.

Tačiau optimizavus Vector ir Deque konteinerius naudojant remove_copy_if ir remove_if algoritmus, jų veiklos laikas stipriai nukrenta ir yra beveik palyginamas su List konteinerio veikimo laiku.

Visų trijų metodų darbo laikas (po optimizacijos) yra panašus, tačiau trynimo metodas (po optimizacijos) gali būti pranašesnis, jeigu norime naudoti mažiau kompiuterio operatyviosios atminties.
