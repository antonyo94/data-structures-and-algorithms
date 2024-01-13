#ifndef NODO_H
#define	NODO_H
#include "Header.h"

class Nodo {
private:
    Nodo *parent;
    Nodo *left;
    Nodo *right;
    int key;
    string data;
    string color;
public:
    Nodo(); //Costruttore di default
    Nodo(int priority, string elem); //Costruttore con argomenti
    Nodo(const Nodo &orig); //Costruttore copia
    void set_parent(Nodo *punt);
    void set_left(Nodo *punt);
    void set_right(Nodo *punt);
    void set_key(int priority);
    void set_data(string elem);
    void set_color(string colore);
    Nodo *get_parent();
    Nodo *get_left();
    Nodo *get_right();
    int get_key();
    string get_data();
    string get_color();
    void stampa_nodo();
    void print_info();
    ~Nodo(); //Distruttore
};



#endif	/* NODO_H */

