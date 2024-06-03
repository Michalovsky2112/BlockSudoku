#ifndef EKRANY_H_INCLUDED
#define EKRANY_H_INCLUDED
#include <iostream>

using namespace std;

void clearscreen (){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void ekran_rysuj_pl(int plansza[][12]){
    cout<<"    BLOCK SUDOKU "<<'\n'
        <<"    |123456789|  "<<endl
        <<"   -+---------+ "<<endl;
    for(int i = 0; i < 9; i++){
        cout<<"   "<<i + 1<<'|';
        for (int j = 0; j < 9; j++){
            if (plansza[i][j] == 1)
                cout<<'#';
            else
                cout<<'.';
       }
        cout<<'|'<<endl;
    }
    cout<<"   -+---------+ "<<endl;
}

int ekran_mainmenu(){
    cout<<"Gra terminalowa \t \t ver.0.01"<<endl<<endl;
    cout<<
" ____  _            _     ____            _       _          "<<endl<<
"| __ )| | ___   ___| | __/ ___| _   _  __| | ___ | | ___   _ "<<endl<<
"|  _ \\| |/ _ \\ / __| |/ /\\___ \\| | | |/ _` |/ _ \\| |/ / | | |"<<endl<<
"| |_) | | (_) | (__|   <  ___) | |_| | (_| | (_) |   <| |_| |"<<endl<<
"|____/|_|\\___/ \\___|_|\\_\\|____/ \\__,_|\\__,_|\\___/|_|\\_|\\__,_|"<<endl<<endl;
    cout<<"Napisna przez: Michal Czapiga"<<endl;
    cout<<"Instrukcja:"<<"\n"<<"Wcisnij \' 1 \' aby grac."<<endl<<
    "Wcisnij \' 2 \' any wyswietlic jak grac"<<endl<<
    "Wcisnij \' 3 \' aby wyjsc z programu"<<endl;
    int wybor = 0;
    cout<<"Prosze podac wybor: "; cin>>wybor;
    switch (wybor){
        case 1:
            return 1;
            break;
        case 2:
            
            system("cls");
            cout<<"Gra polega na uzupelnianiu kwadratu 9x9 klockami o roznych ksztaltach. \nKazdy klocek daje punkty rowne liczbie kwadratow 1x1, z ktorych sie sklada. N.p. klocek linia 3x1 daje 3 punkty, ponieważ sklada sie z 3 kwadratow 1x1: ###. ---- sa tylko 3 hashe, wiec 3 punkty. \nKlocki musza sie calkowicie miescic wewnatrz planszy I nie zzachodzic na inne klocki. \nJesli zaden z 3 dostepnych klockow nie miesci sie, gra sie konczy, a uzytkownik jest proszony o zapamietanie wyniku, poniewaz nie zaprogramowalem jesze zapisow. soon(TM) \nToretycznie gra trwa do wyniku 18 446 744 073 709 551 615, bo wtedy konczy sie miejsce na nowe wyniki. \nJesli tak sie stalo, to gratuluje. *CLAP CLAP CLAP* \nNacisnij ENTER aby kontynouwac."<<endl;
            system("pause");
            system("cls");
            return 0;
            break;
        case 3:
            exit(0);
        default:
            return 0;
            break;
    }
    return 0;
}

void ekran_wyswietl_pionki(int pionki[25][4][4], int id_pierwszy,  int id_drugi , int id_trzeci){
    bool used_pier = false ,used_drug = false, used_trze = false;
    if (id_pierwszy == -1) used_pier = true;
    if (id_drugi == -1) used_drug = true;
    if (id_trzeci == -1) used_trze = true;
    cout<<"+-----KLOCKI-----+"<<endl;
    cout<<"|  1     2     3 |"<<endl;
    cout<<'|';
    if(!used_pier) {for (int i = 0; i < 4; i++) if (pionki[id_pierwszy][0][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_drug) {for (int i = 0; i < 4; i++) if (pionki[id_drugi][0][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_trze) {for (int i = 0; i < 4; i++) if (pionki[id_trzeci][0][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<'|'<<endl;
    cout<<'|';
    if(!used_pier) {for (int i = 0; i < 4; i++) if (pionki[id_pierwszy][1][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_drug) {for (int i = 0; i < 4; i++) if (pionki[id_drugi][1][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_trze) {for (int i = 0; i < 4; i++) if (pionki[id_trzeci][1][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<'|'<<endl;
    cout<<'|';
    if(!used_pier) {for (int i = 0; i < 4; i++) if (pionki[id_pierwszy][2][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_drug) {for (int i = 0; i < 4; i++) if (pionki[id_drugi][2][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_trze) {for (int i = 0; i < 4; i++) if (pionki[id_trzeci][2][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<'|'<<endl;
    cout<<'|';
    if(!used_pier) {for (int i = 0; i < 4; i++) if (pionki[id_pierwszy][3][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_drug) {for (int i = 0; i < 4; i++) if (pionki[id_drugi][3][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<"  ";
    if(!used_trze) {for (int i = 0; i < 4; i++) if (pionki[id_trzeci][3][i] == 1) cout<<'#'; else cout<<'.';} else cout<<"    ";
    cout<<'|'<<endl;
    cout<<"+----------------+"<<endl;
    
    cout<<"Ktory klocek wybierasz, lub wpisz zero dla wyjscia z gry: ";
}
#endif // EKRANY_H_INCLUDED
