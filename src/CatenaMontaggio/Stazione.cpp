#include "Stazione.h"

Stazione::Stazione() {
    id_line = -1;
    work_time = 0;
}


Stazione::Stazione(int n_catene,int n_stazioni,int id_catena, int id_stazione) {
    cout<<"                    STAZIONE " << id_stazione << endl;
    id_line = id_catena;
    set_work_time(id_stazione);
    if (id_stazione < n_stazioni)
        set_transition_time(n_catene,id_stazione);
}

void Stazione::set_work_time(int id_stazione){
    int lavoro=0;

    while(lavoro <= 0){
        cout << "Inserire Tempo di Lavoro Catena " << id_line<<",Stazione " << id_stazione <<": ";
        cin >> lavoro;
        if(lavoro <= 0)
            cout<<"ERRORE: tempo di Lavoro non valido"<<endl;
        else{
            work_time=lavoro;
            cout << "Tempo Lavoro correttamente inserito => TL["<<id_stazione <<"]: " << work_time;
        } 
    }
    cout<<endl;
}
void Stazione::set_transition_time(int n_catene,int id_stazione) {
    int tempo_trasferimento;
    for (int i = 1; i <= n_catene; i++) {
       tempo_trasferimento=-1;
        while(tempo_trasferimento <= 0){
            cout<<"Inserire Tempo Trasferimento Stazione "<<id_stazione << " verso Catena " << i<<": ";
            cin>>tempo_trasferimento;
            if(tempo_trasferimento <= 0)
                cout<<"ERRORE: tempo di Trasferimento non valido"<<endl;
            else{
                transition_time[i]=tempo_trasferimento;
                cout << "Tempo Trasferimento correttamente inserito => TT["<< i <<"]: " << transition_time[i]<<endl;
            }
        }
    }
    cout<<endl;
}


int Stazione::get_transition_time(int n) {
    return transition_time[n];
}

int Stazione::get_work_time() {
    return work_time;
}


int Stazione::get_next_time() {
    return transition_time[id_line];
}


void Stazione::print_station() {
    map<int, int>::iterator it;
    cout << "TL: " << get_work_time() << endl;
    for (it = transition_time.begin(); it != transition_time.end(); it++) {
        cout << "TT[" <<  it->first << "]" << ": " << it->second << endl;
    }
    cout << "------------" << endl;
}

Stazione::~Stazione() {

}