#include "CodaMaxPriorita.h"

CodaMaxPriorita::CodaMaxPriorita() {
};

CodaMaxPriorita::~CodaMaxPriorita() {
};


//Operazione di inserimento nella CodaMaxPriorita che sfrutta la funzione di inserimento 
//del RBT,rispettandone dunque le sue proprietà

void CodaMaxPriorita::insert(int k, string s) {

    if (tree.inserimento(k, s))
        cout << "Nodo corretamente inserito" << endl;
    else
        cout << "ERRORE: nodo con priorità " << k << " già presente nella Coda" << endl;
}

Nodo CodaMaxPriorita::maximum() {

    if (tree.tree_empty()) {
        cerr << "ERRORE: la Coda è vuota" << endl;
        exit(1);
    } else {
        return (tree.get_max());
    }

}


//Estrazione e dunque cancellazione dalla CodaMaxPriorita del nodo con priorità massima.
//Viene individuato dapprima il nodo massimo nell'albero,per poi procedere
//alla sua eliminazione dallo stesso e quindi dalla CodaMaxPriorita.

Nodo CodaMaxPriorita::extract_max() {

    if (tree.tree_empty()) {
        cerr << "ERRORE: la Coda è vuota" << endl;
        exit(1);
    } else {
        Nodo max;
        max = tree.get_max();
        tree.cancellazione(max.get_key());
        return max;
    }

}


//Incremento della priorità di un nodo se e solo se esso è presente nella coda.
//Dopo aver accertato la sua presenza e che la nuova prorità sia effettivamente 
//maggiore di quella corrente richiama la function 'aggiornamento' definita in RBT
//per incrementare il valore chiave se questa va a buon fine,stampando al termine
//un messaggio che ci indica o la corretta esecuzione o,in caso contrario,di errore.

void CodaMaxPriorita::increase_key(int key, int new_priority) {

    if (tree.search_node(key) == false || new_priority < key)
        cout << "Errore nell'aggiornare la priorità" << endl;
    else {
        if (tree.aggiornamento(key, new_priority))
            cout << "Priorità correttamente aggiornata" << endl;
        else
            cout << "ERRORE: nodo di priorita " << new_priority << " gia presente nella Coda" << endl;
    }


}