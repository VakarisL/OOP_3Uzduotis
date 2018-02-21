#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <iomanip>


//declarations
//#######################################################################
void input_by_hand(std::vector<int> *ivertinimai, int *egzaminas);  // function that lets you enter 'any' amount of values by hand;
void generate_values(std::vector<int> *ivertinimai, int *egzaminas);  // function that generates a selected number of values pseudorandomly;
double darbuVidurkis(std::vector<int> *ivertinimai);  // calculates and returns the arithmetic mean of the vector elements;
double darbuMediana(std::vector<int> ivertinimai);  // creates placeholder vector, sorts it, finds and returns the median of sorted values;

//main
//#######################################################################
int main(){
  std::vector<int> *ivertinimai = new std::vector<int>;
  int *egzaminas = new int;
  double galBalasVid, galBalasMed;

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

  switch(choice){
    case 1:{
      input_by_hand(ivertinimai, egzaminas);
      break;
    }
    case 2:{
      generate_values(ivertinimai, egzaminas);
      break;
    }
  }

  galBalasVid=0.4*darbuVidurkis(ivertinimai)+*egzaminas*0.6;
  galBalasMed=0.4*darbuMediana(*ivertinimai)+*egzaminas*0.6;

  std::cout << "Studento info:" <<std::endl;
  std::cout << vardas << " " << pavarde << std::endl;
  int counter = 0;
  for(auto i:*ivertinimai){
    std::cout << "Namu darbu "<< ++counter << " pazymys: "<< i <<std::endl;
  }
  std::cout << "Egzamino pazymys: " << *egzaminas << std::endl;
  std::cout << "Galutinis balas (naudojant vidurki): " << std::setprecision(2) << std::fixed << galBalasVid << std::endl;
  std::cout << "Galutinis balas (naudojant mediana): " << std::setprecision(2) << std::fixed <<galBalasMed << std::endl;
}

//functions
//#######################################################################
void input_by_hand(std::vector<int> *ivertinimai, int *egzaminas){
  std::cout << "Iveskite namu darbu pazymius (-1 norint uzbaigti)"<<std::endl;

  int pazymys=0, counter=1;
  do{
    std::cout << "iveskite " << counter << " pazymi: ";
    std::cin >> pazymys;
    if (pazymys <= 10 &&  pazymys >= 0){
      ivertinimai->push_back(pazymys);
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

}

void generate_values(std::vector<int> *ivertinimai, int *egzaminas){
  std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1,10);

  int kiekis=0;
  std::cout << "Kiek pazymiu noretumete sugeneruoti?" << std::endl;
  std::cin >> kiekis;

  for(int i=0; i<kiekis; i++){
    ivertinimai->push_back(dist(mt));
  }

  *egzaminas=dist(mt);
}

double darbuVidurkis(std::vector<int> *ivertinimai){
  return ((double) std::accumulate(ivertinimai->begin(),ivertinimai->end(), 0.0)/ivertinimai->size());
}

double darbuMediana(std::vector<int> ivertinimai){
  std::vector<int> *tempVector = new std::vector<int>;
  *tempVector=ivertinimai;
  std::sort(tempVector->begin(), tempVector->end());
  if(tempVector->size() % 2 == 1){
    return tempVector->operator[]((tempVector->size()-1)/2);
  }
  else{
    return ((double)tempVector->operator[]((tempVector->size()-1)/2)/2+
            (double)tempVector->operator[]((tempVector->size()-1)/2+1)/2);
  }
}
