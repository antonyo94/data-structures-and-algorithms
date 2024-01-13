#include "CatenaMontaggio.h"

CatenaMontaggio::CatenaMontaggio() {
    id_line=-1;
    entry_time = 0;
    exit_time = 0;
}

CatenaMontaggio::CatenaMontaggio(int n_catene,int n_stazioni,  int id_catena) {
    cout<<"\n---------------COSTRUZIONE CATENA "<<id_catena << "----------------" << endl;
    id_line = id_catena;
    set_entry_time();
    catena.resize(n_stazioni);
    for (int i = 0; i < n_stazioni; i++){
        Stazione a(n_catene,n_stazioni,id_catena,i+1);
        catena[i] = a;
    }
    set_exit_time();
}

void CatenaMontaggio::set_entry_time(){
    int entrata=0;

    while(entrata<=0){
        cout<<"Inserire Tempo di Entrata catena "<< id_line<<": ";
        cin>>entrata;
        if(entrata <= 0)
            cout<<"ERRORE: tempo di Entrata non valido"<<endl;
        else{
            entry_time=entrata;
            cout<<"Tempo Entrata correttamente inserito => TE["<<id_line<<"]: "<<entry_time<<endl;
        }
    }
    cout<<endl;
}

void CatenaMontaggio::set_exit_time(){
    int uscita=0;

     while(uscita<=0){
        cout<<"\nInserire Tempo di Uscita catena "<< id_line <<": ";
        cin>>uscita;
        if(uscita <= 0)
            cout<<"ERRORE: tempo di Uscita non valido"<<endl;
        else{
            exit_time=uscita;
            cout<<"Tempo Uscita correttamente inserito  => TX["<< id_line <<"]: "<<exit_time<<endl;
        }
    }
    cout<<endl;
}

   

int CatenaMontaggio::get_entry_time() {
    return entry_time;
}

int CatenaMontaggio::get_exit_time() {
    return exit_time;
}

//Funzione che ci permette di ottenere il tempo di lavoro della stazione
//i-sima appartenente alla catena

int CatenaMontaggio::get_work_time_station(int i) {
    return catena[i].get_work_time();
}

//Funzione che ci restituisce il tempo di trasferimento verso la n-sima
//catena dello stabilimento da parte dell'i-sima stazione della catena

int CatenaMontaggio::get_trans_time_station(int i, int n) {
    return catena[i].get_transition_time(n);
}

//La funzione che segue restituisce il tempo di trasferimento dell'i-sima
//stazione verso la stazione immediatamente successiva della medesima catena

int CatenaMontaggio::get_next_time_station(int i) {
    return catena[i].get_next_time();
}

//La seguente funzione molto semplice nella impletentazione stampo a video le
//informazioni riguardanti le stazioni che appartengono ad una singola catena.

void CatenaMontaggio::print_line() {
    vector <Stazione>::iterator it;
    int i = 1;
    cout << "----------------------CATENA " << id_line << "---------------------" << endl;
    cout << "TE[" << id_line << "]: " << entry_time << endl << endl;
    for (it = catena.begin(); it != catena.end(); it++) {
        cout << "STAZIONE [" << i << "]" << endl;
        it->print_station();
        i++;
    }
    cout << endl;
    cout << "TX[" << id_line <<"]: " << exit_time << endl;
}

CatenaMontaggio::~CatenaMontaggio() {

}
