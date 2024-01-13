
#include "Stabilimento.h"

Stabilimento::Stabilimento() {
    n_catene = 0;
    n_stazioni = 0;
}

Stabilimento::Stabilimento(int n_lines, int n_stations) {
    //Controlla se puoi inserire un cerror nel costruttore
    if (n_lines < 0 || n_stations < 0) {
        cerr << "ERRORE: il numero di catene o stazioni deve essere positivo" << endl;
        exit(1);
    }
    n_catene = n_lines;
    n_stazioni = n_stations;
    Catene.resize(n_catene);
    f_way.resize(n_catene);
    soluzioni.resize(n_catene);

    for (int i = 0; i < n_catene; i++) {
        f_way[i].resize(n_stazioni + 1);
        soluzioni[i].resize(n_stazioni + 1);
    }

    for (int i = 0; i < n_catene; i++) {
        CatenaMontaggio a( n_catene,n_stazioni, i+1);
        Catene[i] = a;
    }

    cout<<"\nCostruzione Stabilimento correttamente eseguita!\n"<<endl;

}

//Algoritmo principale del problema,si assume di calcolare i tempi di percorrenza
//migliori attraverso la programmazione dinamica.Conserva infatti in f_way i tempi di
//percorrenza migliori già trovati ed in soluzioni i relativi indici di catena
//da cui essi provengono.Si noti che viene rispettata l'equazione di ricorrenza definita
//per il nostro problema nel caso in cui in cui ci ritroviamo nella prima stazione delle 
//catene,per quanto riguarda le stazioni successive invece tale soluzione è ripresa nella
//function di supporto all'algoritmo,ovvero la "int min(int i,int j)".

void Stabilimento::fastest_way() {
    //i=catena,j=stazione
    for (int i = 0; i < n_catene; i++) {
        f_way[i][0] = Catene[i].get_work_time_station(0) + Catene[i].get_entry_time();
        soluzioni[i][0] = i+1;
    }

    for (int j = 1; j < n_stazioni; j++)
        for (int i = 0; i < n_catene; i++)
            f_way[i][j] = min(i, j);

    for (int i = 0; i < n_catene; i++) {
        f_way[i][n_stazioni] = f_way[i][n_stazioni - 1] + Catene[i].get_exit_time();
    }


    int min = f_way[0][n_stazioni];
    indice = 1;
    for (int i = 1; i < n_catene; i++) {
        if (f_way[i][n_stazioni] < min) {
            min = f_way[i][n_stazioni];
            indice = i+1;
        }
        soluzioni[indice-1][n_stazioni] = indice;
    }
    tempo_minimo = f_way[indice-1][n_stazioni];

}


//Funzione di supporto all'algoritmo fastest-way.Calola effettivamente il tempo 
//di percorrena migliore per la stazione corrente j,appartenente alla catena i,
//individuando quale sia il tempo minimo che una auto impiega a trasferirsi da 
//una stazione immediatamente precedente sino a quella corrente.Si noti anche in 
//questo caso come venga rispettata l'equazione di ricorrenza definita per il problema 
//corrente;ci ritroviamo infatti in una stazione che non sia la prima delle catene,
//di conseguenza bisogna valutare i tempi di attraversamento dell'automobile sino alle 
//stazioni immediatamente precedenti,il tempo di trasferimento dalla stazione immediatamente 
//precedente  della stessa catena "get_next_time_station()" ed il tempo di trasferimento da 
//dalla stazione precedente appartenente ad una catena diversa da quella corrente 
//ovvero "get_trans_time_station()",oltre ovviamente  al tempo di lavoro.
int Stabilimento::min(int i, int j) {
    //i=catena,j=stazione
    int mini;
    mini = f_way[i][j - 1] + Catene[i].get_next_time_station(j - 1) + Catene[i].get_work_time_station(j);
    soluzioni[i][j] = i+1;
    for (int k = 0; k < n_catene; k++) {
        if (f_way[k][j - 1] + Catene[k].get_trans_time_station(j - 1, i+1) + Catene[i].get_work_time_station(j) < mini) {
            mini = f_way[k][j - 1] + Catene[k].get_trans_time_station(j - 1, i+1) + Catene[i].get_work_time_station(j);
            soluzioni[i][j] = k+1;
        }
    }

    return mini;
}


//Stampa il comportamento dell'automobile rispetto ai suoi tempi di percorrenza 
//all'interno dello stabilimento.Invoca poi la print_solution per mandare a video 
//quale sia il percorso migliore da essa compiuto.
void Stabilimento::print_stations() {
    if (tempo_minimo > 0) {
         
        cout << "Stazione : ";
        for (int k = 0; k < n_stazioni; k++) {
            cout << "[" << k+1 << "]\t ";
        }
        cout << "[exit]\t " << endl;
        cout << endl;
        for (int i = 0; i < n_catene; i++) {
            cout << "Catena\t" << i+1 << ": ";
            for (int j = 0; j <= n_stazioni; j++)
                cout << f_way[i][j] << "\t ";
                cout << endl;
        }
        print_solution();
    } else
        cout << "La soluzione migliore non è stata ancora calcolata!" << endl;

}



//Stampa delle soluzioni trovate con fastest-way,se esse sono già state calcolate
void Stabilimento::print_solution() {
    cout << endl << "Tempo Migliore: " << tempo_minimo << endl << "Catena di Provenienza: " << indice << "\n\n";
    cout << "MIGLIORE SOLUZIONE TROVATA" << endl;
    int i = indice-1;
    for (int j = n_stazioni; j > 0; j--) {
        i = soluzioni[i][j]-1;
        cout << "Stazione " << j << ": Catena " << i+1 << endl;

    }
}


//Funzione utile a stampare le informazioni legate ai tempi di lavoro e di
//trasferimento di tutte le stazioni che compongono le varie catene di 
//assemblaggio del nostro stabilimento
void Stabilimento::print_plant() {
    vector<CatenaMontaggio>::iterator it;
    for (it = Catene.begin(); it != Catene.end(); it++) {
        it->print_line();
        cout << endl;
    }
}
Stabilimento::~Stabilimento() {
}
