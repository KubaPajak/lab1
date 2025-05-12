#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <cmath>


void przydzielPamiec1D(int * &tab, int n){
    tab = new int[n];
    if (tab == nullptr) {
        std::cerr << "Nie można przydzielić pamięci!" << std::endl;
        exit(1);
    }
}

void przydzielPamiec2D(int ** &tab, int w, int k){
    tab = new int*[w];
    for (int i = 0; i < w; ++i) {
        tab[i] = new int[k];
    }
    if (tab == nullptr) {
        std::cerr << "Nie można przydzielić pamięci!" << std::endl;
        exit(1);
    }



}

// optymalna funkcja sprawdzająca czy liczba jest pierwsza
bool czyPierwsza(int a){
    if(a <= 1) return false;
    if(a==2 || a==3) return true;
    if(a%2==0 || a%3==0) return false;

    int granica = static_cast<int>(sqrt (a));   //polecenie nazwa_zmiennej =static_cast<nazwa_typu> pozwala na rzutowanie jednego typu zmiennej na drugi
    for(int i=5; i<=granica; i+=6){
        if(a%i==0 || a%(i+2)==0) return false;
    }
    return true;

}

void wypelnijTablice1D(int * tab, int n, int a, int b){
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void wypelnijTablice2D(int ** tab, int w, int k, int a, int b){
    std::srand(std::time(0));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }

}

void usunTablice1D(int * &tab){
    delete[] tab;
    tab = nullptr;
    std::cout << "Tablica 1D została usunięta." << std::endl;
}

void usunTablice2D(int ** &tab, int w){
    for (int i = 0; i < w; ++i) {
        delete[] tab[i];
    }
    delete[] tab;
    tab = nullptr;
    std::cout << "Tablica 2D została usunięta." << std::endl;
}

void wyswietl1D(int * tab, int n){
    std::cout << "Tablica 1D: ";
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

void wyswietl2D(int ** tab, int w, int k){
    std::cout << "Tablica 2D: " << std::endl;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void wykonajZadanie1_2(){
    int n;
    std::cout<< "Podaj rozmiar tablicy 1D: "<<std::endl;
    std::cin>> n;
    int *tab = nullptr;
    przydzielPamiec1D(tab, n);
    int a,b;
    std::cout<<"Podaj zakres losowania: "<<std::endl;
    std::cin>>a>>b;
    wypelnijTablice1D(tab, n, a, b);
    wyswietl1D(tab, n);
        // polecenie z zadania 1.2 ze skryptu z laboratorium numer 1
        int najmniejszy = tab[0];
        if (n == 0){
            std::cout<< "Tablica jest pusta."<<std::endl;
            return;
        }
        if (n == 1){
            std::cout<< "Tablica ma tylko jeden element."<<std::endl;
            return;
        }
        else{
            for(int i=1; i<n; i++){
                if(tab[i] < najmniejszy){
                    najmniejszy = tab[i];
                };

            }
        }
    std::cout<< "Najmniejszy element tablicy to: "<< najmniejszy <<std::endl;
        bool czyPierwsza1 = czyPierwsza(najmniejszy);
        if(czyPierwsza1){
            std::cout<< "Najmniejszy element tablicy jest liczbą pierwszą."<<std::endl;
        }
        else{
            std::cout<< "Najmniejszy element tablicy nie jest liczbą pierwszą."<<std::endl;
        }
    usunTablice1D(tab);
    std::cout<< "Koniec zadania 1.2."<<std::endl;
    std::cout<< "------------------------"<<std::endl<< std::endl;
}

void wykonajZadanie1_3(){
    int n;
    std::cout<< "Podaj rozmiar tablicy 1D: "<<std::endl;
    std::cin>> n;
    int *tab = nullptr;
    przydzielPamiec1D(tab, n);
    int a=0,b=9;
    wypelnijTablice1D(tab, n, a, b);
    wyswietl1D(tab, n);
        // polecenie z zadania 1.3 ze skryptu z laboratorium numer 1
        int licznik=0;
        if (n == 0){
            std::cout<< "Tablica jest pusta."<<std::endl;
            return;
        }
        for(int i=a; i<=b; i++){
            int licznik =0;
            for(int j=0; j<n; j++){
                if(tab[j] == i){
                    licznik++;
                }
            }
            std::cout<< "Liczba "<< i << " występuje w tablicy "<< licznik << " razy."<<std::endl;


        }

    usunTablice1D(tab);
    std::cout<< "Koniec zadania 1.3."<<std::endl;
    std::cout<< "------------------------"<<std::endl<< std::endl;

}  

void wykonajZadanie1_4(){
    int w, k;
    std::cout<< "Podaj liczbę wierszy tablicy 2D: "<<std::endl;
    std::cin>> w;
    std::cout<< "Podaj liczbę kolumn tablicy 2D: "<<std::endl;
    std::cin>> k;
    int **tab = nullptr;
    przydzielPamiec2D(tab,w,k);
    int a,b;
    std::cout<< "Podaj zakres losowania: "<<std::endl;
    std::cin>> a >> b;
    wypelnijTablice2D(tab, w, k, a, b);
    wyswietl2D(tab, w, k);
        // polecenie z zadania 1.4 ze skryptu z laboratorium numer 1
        int najwiekszy = tab[0][0];
        if (w == 0 || k == 0){
            std::cout<< "Tablica jest pusta."<<std::endl;
            return;
        }
        if (w == 1 && k == 1){
            std::cout<< "Tablica ma tylko jeden element."<<std::endl;
            return;
        }
        else{
            for(int i=0; i<w; i++){
                for(int j=0; j<k; j++){
                    if(tab[i][j] > najwiekszy){
                        najwiekszy = tab[i][j];
                    };
                }
            }
        }
    std::cout<< "Największy element tablicy to: "<< najwiekszy <<std::endl;
    int suma_cyfr = 0;
    int liczba = najwiekszy;
    while (liczba > 0) {
        suma_cyfr += liczba % 10;
        liczba /= 10;
    }
    std::cout<< "Suma cyfr największego elementu tablicy to: "<< suma_cyfr <<std::endl;
    usunTablice2D(tab, w);
    std::cout<< "Koniec zadania 1.4."<<std::endl;
    std::cout<< "------------------------"<<std::endl<< std::endl;

}

void wykonajZadanie1_5(){
    int w, k;
    std::cout<< "Podaj liczbę wierszy i kolumn tablicy 2D: "<<std::endl;
    std::cin>> w;
    int **tab = nullptr;
    przydzielPamiec2D(tab,w,w);
    int a=7,b=122;

    wypelnijTablice2D(tab, w, w, a, b);
    wyswietl2D(tab, w, w);
        float srednia_arytmetyczna1_nad_glowna_przekatna = 0;
        float srednia_arytmetyczna2_pod_glowna_przekatna = 0;
        int licznik = w-1;
        if (w == 0){
            std::cout<< "Tablica jest pusta."<<std::endl;
            return;
        }
        for(int i=1; i<w; i++){
            srednia_arytmetyczna1_nad_glowna_przekatna += tab[i][i-1];
            srednia_arytmetyczna2_pod_glowna_przekatna += tab[i-1][i];
            srednia_arytmetyczna1_nad_glowna_przekatna /= licznik;
            srednia_arytmetyczna2_pod_glowna_przekatna /= licznik;
            }
            std::cout<< "Srednia arytmetyczna elementów nad główną przekątną to: "<< srednia_arytmetyczna1_nad_glowna_przekatna <<std::endl;
            std::cout<< "Srednia arytmetyczna elementów pod główną przekątną to: "<< srednia_arytmetyczna2_pod_glowna_przekatna <<std::endl;

        
        // polecenie z zadania 1.5 ze skryptu z laboratorium numer 1
    usunTablice2D(tab, w);
    std::cout<< "Koniec zadania 1.5."<<std::endl;
    std::cout<< "------------------------"<<std::endl<< std::endl;

}



int main(){
    setlocale(LC_ALL, "");
    int wybor;
  do{
    std::cout<<std::endl;
    std::cout<< "----------Menu----------"<<std::endl;
    std::cout<< "1. zadanie 1.2"<<std::endl;
    std::cout<< "2. zadanie 1.3"<<std::endl;
    std::cout<< "3. zadanie 1.4"<<std::endl;
    std::cout<< "4. zadanie 1.5"<<std::endl;
    std::cout<< "5. wyjście z programu"<<std::endl;
    std::cout<< "------------------------"<<std::endl;
    std::cout<< "Wybierz numer zadania do wykonania: "<< std::endl;
    std::cin>> wybor;
  
    switch (wybor){
        case 1: wykonajZadanie1_2();
        break;

        case 2: wykonajZadanie1_3();
        break;

        case 3: wykonajZadanie1_4();
        break;

        case 4: wykonajZadanie1_5();
        break;

        case 5:
        std::cout<< "Koniec programu."<<std::endl;
        break;

        default:
        std::cout<< "Nieprawidłowy wybór. Wybierz ponownie."<<std::endl;
        break;
    }

}while(wybor!=5);


return 0;
}