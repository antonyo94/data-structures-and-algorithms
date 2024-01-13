#ifndef STAZIONE_H
#define	STAZIONE_H

#include "Header.h"
class Stazione {
private:
    int id_line;
    int work_time;
    map<int, int> transition_time; //Contenitore dei tempi di trasferimento alle catene associate agli indici del map
    void set_work_time(int id_stazione); 
    void set_transition_time(int n_catene,int id_stazione);
public:
    Stazione(); //Cotruttore
    Stazione(int n_catene,int n_stazioni,int id_catena, int id_stazione); //Costruttore con argomenti
    int get_transition_time(int n);
    int get_work_time();
    int get_next_time();
    void print_station();
    ~Stazione(); //Distruttore
};
#endif	/* STATION_H */

