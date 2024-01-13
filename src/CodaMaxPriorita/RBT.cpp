#include "RBT.h"

RBT::RBT() {
    NIL = new Nodo;
    NIL->set_color("NERO");
    NIL->set_left(NULL);
    NIL->set_right(NULL);
    NIL->set_parent(NULL);
    NIL->set_key(-1);
    NIL->set_data("");
    root = NIL;

};


bool RBT::tree_empty() {
    return root == NIL ? true : false;
}

void RBT::inorder(Nodo * punt) {
    if (punt != NIL) {
        RBT::inorder(punt->get_left());
        punt->stampa_nodo();
        RBT::inorder(punt->get_right());
    }
}

void RBT::inorder() {
    inorder(root);
}

void RBT::tree_info(Nodo * punt) {
    if (punt != NIL) {
        punt->print_info();
        RBT::tree_info(punt->get_left());
        RBT::tree_info(punt->get_right());
    }
}

void RBT::tree_info() {
    tree_info(root);
}

Nodo * RBT::search(Nodo * punt, int k) {
    while (punt != NIL && k != punt->get_key()) {
        if (k < punt->get_key())
            punt = punt->get_left();
        else
            punt = punt->get_right();
    }

    if (punt == NIL)
        return NULL;
    return punt;
}

bool RBT::search_node(int k) {
    if (search(root, k) == NULL)
        return false;
    return true;
}

Nodo * RBT::get_max(Nodo * punt) {
    while (punt->get_right() != NIL) {
        punt = punt->get_right();
    }
    return punt;
}

Nodo * RBT::get_min(Nodo * punt) {
    while (punt->get_left() != NIL) {
        punt = punt->get_left();
    }
    return punt;
}
//Overloading del metodo private omonimo

Nodo RBT::get_max() {
    return *(get_max(root));
}
//Overloading del metodo private omonimo

Nodo RBT::get_min() {
    return *(get_min(root));
}

//Funzione di individuazione del successore di un nodo presente nell'albero
//che tiene conto delle tre casistiche possibili quando si effettua tale
//interrogazione.

Nodo * RBT::successore(int k) {
    Nodo * z, * y;
    z = root;
    y = NIL;
    while (z != NIL && z->get_key() != k) {
        if (z->get_key() < k) //Caso 3:k non ha figlio destro ed è
            z = z->get_right(); //figlio destro del padre.

        else if (z->get_key() > k) //Caso 2: k non ha figlio destro ed è
            //        figlio sx.
        {
            y = z;
            z = z->get_left();
        }
    }
    if (z != NIL && z->get_right() != NIL) //Caso 1: il nodo k ha un figlio dx.
        return RBT::get_min(z->get_right());
    else
        return y;
}

//Operazione di inserimento che sfrutta dapprima l'insert in un semplice albero 
//binario per poi ripristinare eventualmente le proprietà del RBT attraverso 
//la insert fix-up.Si noti come viene mantenuta la proprietà tale che una data
//priorità k appartenga ad uno ed un solo nodo all'interno dell'Albero.Viene 
//infatti effettuato un controllo di tale condizione che se non rispettata fa si
//che la funzione restutisca come valore di ritorno 'false',ovvero inserimento non 
//riuscito,altrimenti esegue le successive istruzioni per portare a termine tale 
//operazione.

bool RBT::inserimento(int k, string s) {

    if (search_node(k)) {
        return false;
    }
    Nodo *punt = new Nodo(k, s);
    Nodo * x, * y;
    y = NIL;
    x = root;

    while (x != NIL) {
        y = x;
        if (punt->get_key() < x->get_key())
            x = x->get_left();
        else
            x = x->get_right();
    }

    punt->set_parent(y);
    if (y == NIL)
        root = punt;
    else {
        if (punt->get_key() < y->get_key())
            y->set_left(punt);
        else
            y->set_right(punt);
    }
    punt->set_left(NIL);
    punt->set_right(NIL);
    punt->set_color("ROSSO");
    RBT::insert_fixup(punt);

    return true;
}


//Può essere invocata soltanto dopo una operazione di insert se,eventualemente
//sono state violate alcune proprietà consone ai RBT.In particolar modo essa 
//tiene conto del caso in cui rientra l'eventuale problematico inserito ed opera
//di conseguenza.

void RBT::insert_fixup(Nodo * punt) {
    Nodo * y;

    while (punt->get_parent()->get_color() == "ROSSO") {
        if (punt->get_parent() == punt->get_parent()->get_parent()->get_left()) {

            y = punt->get_parent()->get_parent()->get_right();
            if (y->get_color() == "ROSSO") //Caso 1:Lo zio del nodo inserito è rosso
            {
                punt->get_parent()->set_color("NERO");
                y->set_color("NERO");
                punt->get_parent()->get_parent()->set_color("ROSSO");
                punt = punt->get_parent()->get_parent();
            } else {
                if (punt == punt->get_parent()->get_right()) { //Caso 2:Lo zio del nodo inserito è nero ed esso è figlio dx
                    punt = punt->get_parent();
                    RBT::rotazione_sx(punt);
                }
                //Caso 3:Lo zio del nodo inserito è nero ed esso è figlio sx
                punt->get_parent()->set_color("NERO");
                punt->get_parent()->get_parent()->set_color("ROSSO");
                RBT::rotazione_dx(punt->get_parent()->get_parent());
            }

        }            //Stesse considerazioni,ma in maniera simmetrica
        else {
            y = punt->get_parent()->get_parent()->get_left();
            if (y->get_color() == "ROSSO") {
                punt->get_parent()->set_color("NERO");
                y->set_color("NERO");
                punt->get_parent()->get_parent()->set_color("ROSSO");
                punt = punt->get_parent()->get_parent();
            } else {
                if (punt == punt->get_parent()->get_left()) {
                    punt = punt->get_parent();
                    RBT::rotazione_dx(punt);
                }

                punt->get_parent()->set_color("NERO");
                punt->get_parent()->get_parent()->set_color("ROSSO");
                RBT::rotazione_sx(punt->get_parent()->get_parent());
            }
        }
    }

    root->set_color("NERO");

}

//Operazione di cancellazione che anche in questo caso sfrutta il delete da un 
//binario per poi invocare la delete-fixup per ripristinare le proprietà RBT.
//In particolar modo prima di procedere con l'operazione di cancellazione viene
//controllato che esista nell'albero un nodo con la priorità k in input.Se ciò 
//è vero viene portata a termine la cancellazione,altrimenti viene restituito un 
//valore 'false' relativo al fallimento dell'operazione di rimozione del nodo con 
//tale priorità.

bool RBT::cancellazione(int k) {

    Nodo *punt = search(root, k);
    if (punt == NULL) {
        cout << "ERRORE: nodo con priorità " << k << " non presente" << endl;
        return false;
    }

    Nodo * x, * y;
    if (punt->get_left() == NIL || punt->get_right() == NIL)
        y = punt;
    else
        y = RBT::successore(punt->get_key());

    if (y->get_left() != NIL)
        x = y->get_left();
    else
        x = y->get_right();

    x->set_parent(y->get_parent());

    if (y->get_parent() == NIL)
        root = x;
    else {
        if (y == y->get_parent()->get_left())
            y->get_parent()->set_left(x);
        else
            y->get_parent()->set_right(x);
    }

    if (y != punt) {
        punt->set_key(y->get_key());
        punt->set_data(y->get_data());
    }
    if (y->get_color() == "NERO") {
        RBT::delete_fixup(x);
    }

    if (y->get_key() == punt->get_key() && y->get_data() == punt->get_data()) {
        delete y;
    }
    else {
        delete punt;
    }

    return true;
}


//Invocata dopo una operazione di cancellazzione di assume di ripristinare
//le proprietà di Red-Black analizzando i casi in cui esse potrebbero essere
//state violate.Anche la cancellazione tiene conto dei casi in cui rientra il
//nodo problematico per riottenere le condizioni di RBT che sono state violate.

void RBT::delete_fixup(Nodo * punt) {
    Nodo * y;

    while (punt != root && punt->get_color() == "NERO") {
        if (punt == punt->get_parent()->get_left()) {
            y = punt->get_parent()->get_right();
            if (y->get_color() == "ROSSO") //Caso 1: Il fratello del nodo inserito è rosso
            {
                y->set_color("NERO");
                y->get_parent()->set_color("ROSSO");
                RBT::rotazione_sx(punt->get_parent());
                y = punt->get_parent()->get_right();
            }
            if (y->get_left()->get_color() == "NERO" && y->get_right()->get_color() == "NERO") {
                y->set_color("ROSSO"); //Caso 2: Il fratello del nodo inserito è nero
                punt = punt->get_parent(); //ed entrambi i  figli del fratello sono neri
            } else {
                if (y->get_color() == "NERO") //Caso 3: Il fratello del nodo inserito è nero
                    //il figlio sx del fratello è rosso,
                    //il figlio dx del fratello è nero
                {
                    y->get_left()->set_color("NERO");
                    y->set_color("ROSSO");
                    RBT::rotazione_dx(y);
                    y = punt->get_parent()->get_right();
                }
                y->set_color(punt->get_parent()->get_color()); //Caso 4: Il fratello del nodo ins.
                punt->get_parent()->set_color("NERO"); //è nero ed il suo figlio dx è red.
                y->get_right()->set_color("NERO");
                RBT::rotazione_sx(punt->get_parent());
                punt = root;
            }
        }            //Stesse considerazioni in maniera simmetrica
        else {
            y = punt->get_parent()->get_left();
            if (y->get_color() == "ROSSO") {
                y->set_color("NERO");
                y->get_parent()->set_color("ROSSO");
                RBT::rotazione_dx(punt->get_parent());
                y = punt->get_parent()->get_left();
            }
            if (y->get_right()->get_color() == "NERO" && y->get_left()->get_color() == "NERO") {
                y->set_color("ROSSO");
                punt = punt->get_parent();
            } else {
                if (y->get_color() == "NERO") {
                    y->get_right()->set_color("NERO");
                    y->set_color("ROSSO");
                    RBT::rotazione_sx(y);
                    y = punt->get_parent()->get_left();
                }
                y->set_color(punt->get_parent()->get_color());
                punt->get_parent()->set_color("NERO");
                y->get_left()->set_color("NERO");
                RBT::rotazione_dx(punt->get_parent());
                punt = root;
            }
        }


    }

    punt->set_color("NERO");
}

//Le due operazioni di rotazione,tra loro simmetriche sono operazioni aggiuntive
//che riguardano l'uso dei RBT.Esse infatti sono strettamente necessarie al 
//seguito delle operazioni di inserimento e cancellazione e,nel nostro caso di
//supporto al ripristino delle proprietà effettuato da delete-fixup  e insert-fixup.

void RBT::rotazione_sx(Nodo * punt) {
    Nodo * y;
    y = punt->get_right();
    punt->set_right(y->get_left());

    if (y->get_left() != NIL)
        y->get_left()->set_parent(punt);

    y->set_parent(punt->get_parent());

    if (y->get_parent() == NIL)
        root = y;
    else {
        if (punt == y->get_parent()->get_left())
            punt->get_parent()->set_left(y);
        else
            punt->get_parent()->set_right(y);
    }


    y->set_left(punt);
    punt->set_parent(y);
}

void RBT::rotazione_dx(Nodo * punt) {
    Nodo * y;
    y = punt->get_left();
    punt->set_left(y->get_right());

    if (y->get_right() != NIL)
        y->get_right()->set_parent(punt);

    y->set_parent(punt->get_parent());

    if (y->get_parent() == NIL)
        root = y;
    else {
        if (punt == y->get_parent()->get_right())
            punt->get_parent()->set_right(y);
        else
            punt->get_parent()->set_left(y);
    }


    y->set_right(punt);
    punt->set_parent(y);
}




//Funzione di aggiornamento della priorità di un Nodo appartenente al RBT che
//sarà di supporto alla function increase-key della coda.In particolar modo
//si controlla se il nodo con la priorità da aggiornare sia effettivamente 
//presente,oltre a verificare che la nuova priorità da assegnare ad esso non 
//appartenga già ad un altro nodo dell'Albero.Si procede poi col rimuovere il
//vecchio nodo dall'albero e ad inserire un nuovo nodo con la priorità 
//incrementata ed i dati identici a quelli del precedetne.Il valore false in 
//output ci indica un fallimento,true per la corretta esecuzione dell'aggiornamento

bool RBT::aggiornamento(int key, int new_priority) {
    Nodo *punt;
    punt = search(root, key);
    if (punt == NULL || search_node(new_priority))
        return false;
    else {
        Nodo *temp = new Nodo(new_priority, punt->get_data());
        cancellazione(punt->get_key());
        inserimento(temp->get_key(), temp->get_data());
        delete(temp);
    }

    return true;
}

//Dato che si lavora con puntatori a oggetto istanziati mediante new si provvede
//a rimuovere gli stessi mediante una chiamata esplicita alla delete.

void RBT::delete_tree(Nodo * punt) {
    if (punt != NIL) {

        RBT::delete_tree(punt->get_left());
        RBT::delete_tree(punt->get_right());
        delete punt;
    }

}

RBT::~RBT() {
    RBT::delete_tree(root);
    delete NIL;

};