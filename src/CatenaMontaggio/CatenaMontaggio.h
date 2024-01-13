#ifndef CATENAMONTAGGIO_H
#define	CATENAMONTAGGIO_H

#include "Stazione.h"

class CatenaMontaggio {
private:
    int id_line;
    int entry_time;
    int exit_time;
    vector <Stazione> catena;
    void set_entry_time();
    void set_exit_time();

public:
    CatenaMontaggio(); //Costruttore
    CatenaMontaggio(int n_catene,int n_stazioni,int id_catena); //Costruttore con argomenti
    int get_entry_time();
    int get_exit_time();
    int get_work_time_station(int i);
    int get_trans_time_station(int i, int n);
    int get_next_time_station(int i);
    void print_line();
    ~CatenaMontaggio(); //Distruttore
};

#endif	/* CATENAMONTAGGIO_H */
