#ifndef RBT_H
#define	RBT_H
#include "Nodo.h"

class RBT {
private:

    Nodo * root; //radice
    Nodo * NIL; //Nodo sentinella
    void inorder(Nodo * punt); //visita inorder dell'albero
    void rotazione_sx(Nodo * punt); //operazioni di rotazione quando si lavora con 
    void rotazione_dx(Nodo * punt); //gli alberi binari RED_BLACK per ripistinarne le modifice
    void insert_fixup(Nodo * punt); //ripristino delle proprietà dopo l'inserimento
    void delete_fixup(Nodo * punt); //ripristino delle proprietà dopo la cancellazione
    void delete_tree(Nodo * punt); //cancellazione esplicita
    Nodo * search(Nodo * punt, int k); //ricerca di un nodo nell'albero
    void tree_info(Nodo * punt); //visita preorder dell'albero
    Nodo * get_max(Nodo * punt); //ottieni il massimo elemento dell'albero
    Nodo * get_min(Nodo * punt); //ottieni il minimo elemento dell'albero
    Nodo * successore(int k); //Ottieni il successore del nodo con chiave k nell'albero

public:
    RBT();
    void inorder(); //Overload dell'omonimo metodo dell'interfaccia privata
    bool tree_empty(); //funzione predicativa
    bool search_node(int k);
    void tree_info(); //Overload della visita in preorder
    Nodo get_max(); //Overload dell'omonimo metodo nell'interfaccia privata
    Nodo get_min(); //Overload dell'omonimo metodo nell'interfaccia privata
    bool inserimento(int k, string s); //omonima funzione di inserimento di un nodo nell' albero
    bool cancellazione(int k); //funzione di cancellazione di un nodo nell'albero
    bool aggiornamento(int key, int new_priority);
    ~RBT();
};


#endif	/* RBT_H */

