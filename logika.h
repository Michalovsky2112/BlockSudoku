#ifndef LOGIKA_H_INCLUDED
#define LOGIKA_H_INCLUDED

#define rozmiar_pionka 4

void logika_mat_dodaj_offset(int pionek[4][4], int plansza [12][12], int offset_x, int offset_y){
    for (int i = 0; i < rozmiar_pionka ; i++)
        for (int j = 0; j < rozmiar_pionka; j++)
            plansza[i+offset_y][j+offset_x] += pionek[i][j];
}

bool logika_czyfit(int plansza [12][12], int pionek [4][4], int x, int y){
    bool returner = false;
    int temp [12][12];
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            temp[i][j] = plansza[i][j];
    logika_mat_dodaj_offset(pionek, temp, x-1, y-1);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            if ((temp [i][j] == 0) || (temp [i][j] == 1) || (temp [i][j] == 4))
                returner =  true;
            else
                return false;
    return returner;
}

bool logika_czyanyfit(int plansza[12][12], int pionek[25][4][4], short int & id_pierw, short int & id_drugi, short int & id_trzec){
    const int rozmiar_planszy = 9;
    int id_pier = id_pierw, id_drug = id_drugi, id_trze = id_trzec;
    id_drugi = -1; id_pierw = -1; id_trzec = -1;

    if (id_pier > -1) {
        for (int x = 1; x < rozmiar_planszy+1; x++) {  
            for (int y = 1; y < rozmiar_planszy+1; y++) {   
                if (logika_czyfit(plansza, pionek[id_pier], x, y)) {
                    id_pierw = id_pier;
                }
            }
        }
    }
    
    if (id_drug > -1) {
        for (int x = 1; x < rozmiar_planszy+1; x++) {  
            for (int y = 1; y < rozmiar_planszy+1; y++) {   
                if (logika_czyfit(plansza, pionek[id_drug], x, y)) {
                    id_drugi = id_drug;
                }
            }
        }
    }
    
    if (id_trze > -1) {
        for (int x = 1; x < rozmiar_planszy+1; x++) {  
            for (int y = 1; y < rozmiar_planszy+1; y++) {   
                if (logika_czyfit(plansza, pionek[id_trze], x, y)) {
                    id_trzec = id_trze;
                }
            }
        }
    }

    if (id_pierw == -1 && id_drugi == -1 && id_trzec == -1) {
        return false;
    } else {
        return true;
    }
}

int logika_usuwaniepunkty (int plansza[12][12]){
    const int mnoznik = 3;
    int columns[9] = {0,0,0,0,0,0,0,0,0};
    int rows[9] = {0,0,0,0,0,0,0,0,0};
    int squares[9] = {0,0,0,0,0,0,0,0,0};
    
    // koluny od lewej do prawej
    // wiersze od góry do dołu
    // kwadraty od góra-maks-lewo w prawo, na końcu w dół-maks-lewo i w prawo
    // 1 2 3
    // 4 5 6
    // 7 8 9

    for (int i = 0; i < 9; i++)         //wiersze
        for (int j = 0; j < 9; j++)
            rows[i] += plansza[i][j];
    
    for (int i = 0; i < 9; i++)         //kolumny
        for (int j = 0; j < 9; j++)
            columns[i] += plansza[j][i];

    int i = 0, j = 0;                   //kwadraty
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            squares[0] += plansza[i][j];
    for (i = 3; i < 6; i++)
        for (j = 0; j < 3; j++)
            squares[1] += plansza[i][j];
    for (i = 6; i < 9; i++)
        for (j = 0; j < 3; j++)
            squares[2] += plansza[i][j];
    
    for (i = 0; i < 3; i++)
        for (j = 3; j < 6; j++)
            squares[3] += plansza[i][j];
    for (i = 3; i < 6; i++)
        for (j = 3; j < 6; j++)
            squares[4] += plansza[i][j];
    for (i = 6; i < 9; i++)
        for (j = 3; j < 6; j++)
            squares[5] += plansza[i][j];

    for (i = 0; i < 3; i++)
        for (j = 6; j < 9; j++)
            squares[6] += plansza[i][j];
    for (i = 3; i < 6; i++)
        for (j = 6; j < 9; j++)
            squares[7] += plansza[i][j];
    for (i = 6; i < 9; i++)
        for (j = 6; j < 9; j++)
            squares[8] += plansza[i][j];

    int liczba_punktow = 0;

    for (int g = 0; g < 9; g++){
        if (columns[g] == 9)
            liczba_punktow += mnoznik*9;
        if (rows[g] == 9)
            liczba_punktow += mnoznik*9;
        if (squares[g] == 9)
            liczba_punktow += mnoznik*9;
    }

    for (int g = 0; g < 9; g++){
        if (columns[g] == 9)
            for (int h = 0; h < 9; h++)
                plansza[h][g] = 0;
        if (rows[g] == 9)
            for (int h = 0; h < 9; h++)
                plansza[g][h] = 0;
    }
    i = 0; j = 0;
    if (squares[0] == 9)
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                plansza[i][j] = 0;
    if (squares[1] == 9)
        for (i = 3; i < 6; i++)
            for (j = 0; j < 3; j++)
                plansza[i][j] = 0;
    if (squares[2] == 9)
        for (i = 6; i < 9; i++)
            for (j = 0; j < 3; j++)
                plansza[i][j] = 0;

    if (squares[3] == 9)
        for (i = 0; i < 3; i++)
            for (j = 3; j < 6; j++)
                plansza[i][j] = 0;
    if (squares[4] == 9)
        for (i = 3; i < 6; i++)
            for (j = 3; j < 6; j++)
                plansza[i][j] = 0;
    if (squares[5] == 9)
        for (i = 6; i < 9; i++)
            for (j = 3; j < 6; j++)
                plansza[i][j] = 0;

    if (squares[6] == 9)
        for (i = 0; i < 3; i++)
            for (j = 6; j < 9; j++)
                plansza[i][j] = 0;
    if (squares[7] == 9)
        for (i = 3; i < 6; i++)
            for (j = 6; j < 9; j++)
                plansza[i][j] = 0;
    if (squares[8] == 9)
        for (i = 6; i < 9; i++)
            for (j = 6; j < 9; j++)
                plansza[i][j] = 0;
                
    
    for (int i = 0; i < 9; i++){
        if (columns[i] == 9)
            columns[i] = 0;
        if (rows[i] == 9)
            rows[i] = 0;
        if (squares[i] == 9)
            squares[i] = 0;
    }
    return liczba_punktow;
}

#endif // LOGIKA_H_INCLUDED