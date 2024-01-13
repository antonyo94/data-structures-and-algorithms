#include "Nodo.h"

Nodo::Nodo() {
    parent = NULL;
    left = NULL;
    right = NULL;
    key = -1;
    data = "";
    color = "ROSSO";
}

Nodo::Nodo(int priority, string elem) {
    parent = NULL;
    left = NULL;
    right = NULL;
    key = priority;
    data = elem;
}

Nodo::Nodo(const Nodo &orig) {
    parent = NULL;
    left = NULL;
    right = NULL;
    key = orig.key;
    data = orig.data;
    color = orig.color;

}

Nodo::~Nodo() {

};

void Nodo::set_right(Nodo* punt) {
    right = punt;
}

void Nodo::set_parent(Nodo* punt) {
    parent = punt;
}

void Nodo::set_left(Nodo* punt) {
    left = punt;
}

void Nodo::set_key(int priority) {
    key = priority;
}

void Nodo::set_data(string elem) {
    data = elem;
}

void Nodo::set_color(string colore) {
    color = colore;
}
string Nodo::get_color() {
    return color;
}

string Nodo::get_data() {
    return data;
}

int Nodo::get_key() {
    return key;
}

Nodo * Nodo::get_left() {
    return left;
}

Nodo *Nodo::get_parent() {
    return parent;
}

Nodo *Nodo::get_right() {
    return right;
}

void Nodo::stampa_nodo() {
    cout << "Priorità: " << key << "\nDati: " << data << "\n" << "Colore: " << color << endl;
}

void Nodo::print_info() {
    cout << "--------------------------------------------------" << endl;
    cout << "ELEMENTO: ";
    stampa_nodo();


    if (parent->get_key() != -1) {
        cout << "PADRE: ";
        parent->stampa_nodo();
    } else
        cout << "PADRE: NIL" << endl;


    if (left->get_key() != -1) {
        cout << "FIGLIO SX: ";
        left->stampa_nodo();
    } else
        cout << "FIGLIO SX: NIL" << endl;



    if (right->get_key() != -1) {
        cout << "FIGLIO DX: ";
        right->stampa_nodo();
    } else
        cout << "FIGLIO DX: NIL" << endl;
    cout << "--------------------------------------------------" << endl;
}

