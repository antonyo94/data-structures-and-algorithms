#ifndef STABILIMENTO_H
#define	STABILIMENTO_H

#include "CatenaMontaggio.h"

class Stabilimento {
private:
    int n_catene;
    int n_stazioni;
    vector <CatenaMontaggio> Catene; //Catene di montaggio che compongono lo stabilimento
    vector <vector <int> > f_way; //Matrice dei tempi di percorrenza migliori
    vector <vector <int> > soluzioni; //Matrice delle soluzioni già calcolate con PD
    int indice; //Indice di uscita del tempo migliore
    int tempo_minimo; //Tempo migliore individuato
    int min(int i, int j);
    void print_solution();


public:
    Stabilimento(); //Costruttore
    Stabilimento(int n_lines, int n_stations); //Costruttore con argomenti    
    void fastest_way();
    void print_stations();
    void print_plant();
    ~Stabilimento(); //Distruttore
};


#endif	/* STABILIMENTO_H */

