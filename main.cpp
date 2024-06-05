#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "ekrany.h"
#include "logika.h"
using namespace std;
bool kontynuuj = true, gra = true;
//string wejscie;1


int pionki[25][4][4] = {
    {{1,1,1,1},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0}},

    {{1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,1,0,0},
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},
    {{1,0,0,0},

    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,1,0,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{0,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{0,1,0,0},
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,1,1,0},
    {1,0,0,0},
    {1,0,0,0},
    {0,0,0,0}},

    {{1,1,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {1,0,0,0},
    {1,1,1,0},
    {0,0,0,0}},

    {{0,0,1,0},
    {0,0,1,0},
    {1,1,1,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0}},

    {{0,1,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{0,1,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,0,0,0}},

    {{1,1,1,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

    {{1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}},

    {{0,0,0,1},
    {0,0,1,0},
    {0,1,0,0},
    {1,0,0,0}},

    {{0,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {0,0,0,0}}};



int plansza[12][12] = {
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {0,0,0,0,0,0,0,0,0,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4}
};

unsigned long long int punkty = 0, naj_wynik = 0;
short int klocek_j, klocek_d, klocek_t, klocek, x, y;
bool pier = false, drug = false, trze = false;

int main(){
    srand(time(NULL));
    //ekran_rysuj_pl(plansza);
    while(kontynuuj){
    system("cls");
    while (ekran_mainmenu() == 0);
    //logika gry tu
    system("cls");
    punkty = 0;
    int i = 0;
    while (true){
        system("cls");
        klocek_j = rand()%25;
        klocek_d = rand()%25;
        klocek_t = rand()%25;
        klocek == 1;
        pier = false; drug = false; trze = false;
        
        //cout<<klocek_j<<' '<<klocek_d<<' '<<klocek_t<<endl;
        
        //cout<<klocek_j<<' '<<klocek_d<<' '<<klocek_t<<endl;
        proba_ponowna:{
        if(!logika_czyanyfit(plansza, pionki, klocek_j, klocek_d, klocek_t, pier, drug, trze))
            {
                system("cls");
                cout<<endl<<endl<<"\t Przegrales. Twoj wynik wyniosl: "<<punkty<<"\n";
                cout<<"Twoj najwyzszy wynik wyniosl: "<<naj_wynik<<'.';
                    cout<<"\nNacisnij ENTER aby kontynuowac.";
                system("pause");
                break;
            }
        cout<<"Punkty: "<<punkty<<'\t'<<"Najwyzszy wynik: "<<naj_wynik<<'\n';
        ekran_rysuj_pl (plansza);
        cout<<endl;
        ekran_wyswietl_pionki(pionki, klocek_j, klocek_d, klocek_t, pier, drug, trze);
        cin>>klocek;
        if (klocek == 0) break;
        if (klocek == 1) klocek = klocek_j; else if (klocek == 2) klocek = klocek_d; else klocek = klocek_t;
        if (klocek == -1) {cout<<"Wybrany klocek nie miesci sie lub zostal juz uzyty. "<<endl; Sleep(2000); system("cls"); goto proba_ponowna;} 
        cout<<"Wybrano klocek nr "<<klocek<<". Gdzie go chcesz umiescic? (x y)"<<endl;
        cin>>x>>y;
        if (!logika_czyfit(plansza, pionki[klocek], x, y))
            {cout<<"Wybrany klocek nie miesci sie w podanym miejscu."<<endl; Sleep(2000); system("cls"); goto proba_ponowna;}
        else {logika_mat_dodaj_offset(pionki[klocek], plansza, x-1, y-1);punkty += 3; if (klocek == klocek_j) pier = true; else if (klocek == klocek_d) drug = true; else trze = false;}
        punkty += logika_usuwaniepunkty(plansza);
        if (punkty >= naj_wynik)
            naj_wynik = punkty;
        i++; 
        system("cls");}
        if (i < 3) goto proba_ponowna;
        else i = 0;
    }
    }
    return 0;
}
