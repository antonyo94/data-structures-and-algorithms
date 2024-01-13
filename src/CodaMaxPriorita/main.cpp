#include "CodaMaxPriorita.h"

int main() {

    int j;
    char scelta = ' ';
    string s;
    CodaMaxPriorita queue;
    cout << "***************************************************" << endl;
    cout << "*            ABATE ANTONIO 0124/874               *" << endl;
    cout << "*              Coda Max Priorità                  *" << endl;
    cout << "***************************************************" << endl;
    cout << endl;

    while (scelta != '0') {


        cout << "--------SCEGLIERE L'OPERAZIONE DA COMPIERE--------" << endl;
        cout << "1)Inserimento " << endl;
        cout << "2)Visualizza Massima Priorità" << endl;
        cout << "3)Estrazione dell'elemento di Max Priorità" << endl;
        cout << "4)Incrementa Priorità" << endl;
        cout << "0)Uscita" << endl;
        cout << "SCELTA: ";
        cin>>scelta;
        switch (scelta) {
            case '1':
            {
                cout << "Inserire priorità: ";
                cin>>j;
                cout << "Inserire dati: ";
                cin>>s;
                queue.insert(j, s);
            }
                break;

            case '2':
            {
                Nodo punt = queue.maximum();
                if (1) {
                    cout << "---------------ELEMENTO MASSIMO-------------------" << endl;
                    punt.stampa_nodo();
                }
            }
                break;

            case '3':
            {
                Nodo punt = queue.extract_max();
                if (1) {
                    cout << "---------------ELEMENTO MASSIMO ESTRATTO----------" << endl;
                    punt.stampa_nodo();

                }
            }
                break;

            case '4':
            {
                cout << "Inserie priorità da modificare: ";
                cin>>j;
                int k;
                cout << "Inserire nuova priorità: ";
                cin>>k;
                queue.increase_key(j, k);
            }
                break;
            case '0':break;
            default: cout << "ERRORE: Scelta non presente" << endl;
        }

    }
    return 0;
}






















