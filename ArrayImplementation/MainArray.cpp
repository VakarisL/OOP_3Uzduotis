#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>


//declarations
//#######################################################################
void check_size(int *ivertinimai, int *masDydis, int elementas); // checks the size of array and doubles it, if necessary
double darbuVidurkis(int *ivertinimai, int elementuSk); // calculates and returns the arithmetic mean of the array elements
double darbuMediana(int *ivertinimai, int elementuSk); // creates placeholder array, sorts it, finds and returns the median of sorted values
int input_by_hand(int *ivertinimai, int *masDydis, int *egzaminas, int counter);  // function that lets you enter 'any' amount of values by hand;
                                                                                  // returns the number of values entered
int generate_values(int *ivertinimai, int *masDydis, int *egzaminas); // function that generates a selected number of values pseudorandomly;
                                                                      // returns the number of values generated

//main
//#######################################################################
int main(){
std::string vardas, pavarde;
  std::cout << "Iveskite studento varda: " << std::endl;
  std::cin >> vardas;
  std::cout << "Iveskite studento pavarde: " << std::endl;
  std::cin >> pavarde;

  int choice=0;
  do{
    std::cout << "Ar norite:"<< std::endl;
    std::cout << "1- Irasyti pazymius ranka"<< std::endl;
    std::cout << "2- Generuoti atsitiktinius pazymius"<< std::endl;
    std::cin >> choice;
  }while(choice!=1 && choice!=2);


  int counter=0;
  int *ivertinimai = new int[1];
  int *masDydis = new int;
  int *egzaminas = new int;
  double galBalasVid, galBalasMed;
  *masDydis = 1;


  switch(choice){
    case 1:{
      counter = input_by_hand(ivertinimai, masDydis, egzaminas, counter);
      break;
    }
    case 2:{
      counter = generate_values(ivertinimai, masDydis, egzaminas);
      break;
    }
  }


  galBalasVid=0.4*darbuVidurkis(ivertinimai, counter)+*egzaminas*0.6;
  galBalasMed=0.4*darbuMediana(ivertinimai, counter)+*egzaminas*0.6;

  std::cout << "Studento info:" <<std::endl;
  std::cout << vardas << " " << pavarde << std::endl;
  for(int i=0; i<counter; i++){
    std::cout << "Namu darbu "<< i+1 << " pazymys: "<<ivertinimai[i] <<std::endl;
  }
  std::cout << "Egzamino pazymys: " << *egzaminas << std::endl;
  std::cout << "Galutinis balas (naudojant vidurki): " << galBalasVid << std::endl;
  std::cout << "Galutinis balas (naudojant mediana): " << galBalasMed << std::endl;

  delete[] ivertinimai;
}

//functions
//#######################################################################

void check_size(int *ivertinimai, int *masDydis, int elementas){
  if(elementas==*masDydis){
    //std::cout << "boom" <<std::endl;
    int *naujasMasyvas = new int[*masDydis*2];
    memcpy(naujasMasyvas, ivertinimai, *masDydis);

    delete[] ivertinimai;
    ivertinimai=naujasMasyvas;

    *masDydis=*masDydis*2;
  }
}

double darbuVidurkis(int *ivertinimai, int elementuSk){
  double vidurkis=0;
  for(int i=0; i<elementuSk;i++){
    vidurkis+=ivertinimai[i];
  }
  return(vidurkis/elementuSk);
}

double darbuMediana(int *ivertinimai, int elementuSk){
    int *tempMasyvas = new int[elementuSk];
    for(int i=0;i<elementuSk;i++){
        tempMasyvas[i]=ivertinimai[i];
    }
  std::sort(tempMasyvas, tempMasyvas+elementuSk);

  if(elementuSk % 2 == 1){
    return (tempMasyvas[(elementuSk-1)/2]);
  }
  else{
    double median = (double)tempMasyvas[(elementuSk-1)/2]/2+(double)tempMasyvas[(elementuSk-1)/2+1]/2;
    return(median);
  }
}

int input_by_hand(int *ivertinimai, int *masDydis, int *egzaminas, int counter){
  std::cout << "Iveskite namu darbu pazymius (-1 norint uzbaigti)"<<std::endl;

  int pazymys=0;
  do{
    std::cout << "iveskite " << counter+1 << " pazymi: ";
    std::cin >> pazymys;
    if (pazymys <= 10 &&  pazymys >= 0){
      check_size(ivertinimai, masDydis, counter);
      ivertinimai[counter]=pazymys;
      counter++;
    }
    else{
        if (pazymys!=(-1)){
            std::cout << "Ivestas ivertinimas nepriklauso desimtbalei sistemai" << std::endl;
            pazymys = 0;
        }
    }
  }while(pazymys != (-1));

  std::cout << "iveskite egzamino pazymi: ";
  std::cin >> *egzaminas;

  return counter;
}

int generate_values(int *ivertinimai, int *masDydis, int *egzaminas){
  std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1,10);

  int kiekis=0;
  std::cout << "Kiek pazymiu noretumete sugeneruoti?" << std::endl;
  std::cin >> kiekis;

  int pazymys=0;
  for(int i=0; i<kiekis; i++){
    check_size(ivertinimai, masDydis, i);
    ivertinimai[i]=dist(mt);
  }
  *egzaminas=dist(mt);
  return kiekis;
}
