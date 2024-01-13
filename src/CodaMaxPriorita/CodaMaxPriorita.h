#ifndef CodaMaxPriorita_H
#define	CodaMaxPriorita_H
#include "RBT.h"

class CodaMaxPriorita {
private:
    RBT tree;
public:
    CodaMaxPriorita(); //Costruttore
    void insert(int k, string s); //Inserimento
    Nodo maximum(); //visualizza massimo
    Nodo extract_max(); //estrai elemento massimo
    void increase_key(int key, int new_priority); //incrementa priorità
    ~CodaMaxPriorita(); //Distruttore
};
#endif	/* CodaMaxPriorita_H */
