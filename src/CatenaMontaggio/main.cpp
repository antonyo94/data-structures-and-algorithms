/* 
 * File:   main.cpp
 * Author: Antonio Abate 0124/874
 */

#include "Stabilimento.h"

int main() {
	int n = 0, m = 0;
    cout << "***************************************************" << endl;
    cout << "*            ABATE ANTONIO 0124/874               *" << endl;
    cout << "*             Catena di Montaggio                 *" << endl;
    cout << "***************************************************" << endl;
    cout << endl;
    while (n < 2) {
        cout << "[1]Inserire il numero di catene della fabbrica: ";
        cin>>n;
        if (n < 2)
            cout << "ERRORE: Il numero di catene deve essere >=2" << endl;
    }
    while (m < 1) {
        cout << "[2]Inserire il numero di stazioni della fabbrica: ";
        cin>>m;
        if (m < 1)
            cout << "ERRORE: Il numero di catene deve essere >=1" << endl;
    }
    cout << endl;
    Stabilimento a(n, m);
    a.fastest_way();
    a.print_plant();
    a.print_stations();
    return 0;

}
