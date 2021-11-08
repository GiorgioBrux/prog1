/*
 * Author: giorgiobrux
 * Created Date: Sunday November 7th 2021
 * -----
 * Last Modified: Sun Nov 07 2021
 */
#include <cmath>
#include <iostream>

using namespace std;

// WIP. Mancano le mosse dell'avversario, le condizioni di vittoria e il salvare/caricare da file.

int main() {
    string nome;
    int dimTab, dimNaviMax, dimNaviMin;
    srand(time(0));
    cout << "Ciao, benvenuto a battaglia navale." << endl;
    cout << "Per iniziare, inserisci il tuo nome >> ";
    cin >> nome;
    cout << "Bellissimo nome, " << nome << ". Ora inserisci la dimensione del campo/tabella di gara (0<N<=10) >> ";
    cin >> dimTab;
    cout << "Perfetto. Infine inserici la dimensione minima e massima delle navi, separando i due valori con uno "
            "spazio >> ";
    cin >> dimNaviMin >> dimNaviMax;

    if (dimTab <= 0 || dimNaviMin <= 0 || dimNaviMax <= 0 || dimNaviMin > dimNaviMax || dimNaviMax > dimTab ||
        dimTab > 10) {
        cout << "Almeno uno dei valori che hai inserito non è valido :( Esco...";
        return -1;
    }

    cout << "Tutto regolare. Genero il campo di gioco..." << endl;
    char tab[2][dimTab][dimTab];
    char tab_colpiti[dimTab][dimTab];

    // Riempiamo le tabelle di acqua
    for (int i = 0; i < dimTab; i++) {
        for (int j = 0; j < dimTab; j++) {
            tab[0][i][j] = '.';
            tab[1][i][j] = '.';
            tab_colpiti[i][j] = '?';
        }
    }

    // Calcoliamo il numero di navi appropriate
    int N_navi = sqrt(dimTab + dimTab);
    cout << "Numero navi: " << N_navi << endl;
    bool success = false;

    int dim[N_navi];
    for (int i = 0; i < N_navi; i++) {
        dim[i] = rand() % (dimNaviMax - dimNaviMin + 1) + dimNaviMin;
    }

    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < N_navi; i++) {
            bool verticale = rand() % 2;
            int x = rand() % (dimTab - 1) + 1;
            int y = rand() % (dimTab - 1) + 1;
            cout << "Nave n." << i << ", x: " << x << ", y: " << y << endl;
            // Controlliamo se lo possiamo inserire senza problemi
            i--;
            bool exit = false;
            if (verticale) {
                if (x + dim[i] >= (dimTab - 1)) continue;
                for (int j = 0; j <= dim[i]; j++) {
                    if (tab[f][x + j][y] == 'N') exit = true;
                    if (tab[f][x + j + 1][y] == 'N') exit = true;
                    if (tab[f][x + j - 1][y] == 'N') exit = true;
                    if (tab[f][x + j][y - 1] == 'N') exit = true;
                    if (tab[f][x + j][y + 1] == 'N') exit = true;
                }
            } else {
                if (y + dim[i] >= (dimTab - 1)) continue;
                for (int j = 0; j <= dim[i]; j++) {
                    if (tab[f][x][y + j] == 'N') exit = true;
                    if (tab[f][x][y + j + 1] == 'N') exit = true;
                    if (tab[f][x][y + j - 1] == 'N') exit = true;
                    if (tab[f][x + 1][y + j] == 'N') exit = true;
                    if (tab[f][x - 1][y + j] == 'N') exit = true;
                }
            }

            if (exit) continue;

            i++;

            for (int k = 0; k < dim[i]; k++) {
                if (verticale)
                    tab[f][x + k][y] = 'N';
                else
                    tab[f][x][y + k] = 'N';
            }
        }
    }

    for (int i = 0; i < dimTab; i++) {
        for (int j = 0; j < dimTab; j++) {
            cout << tab[0][i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < dimTab; i++) {
        for (int j = 0; j < dimTab; j++) {
            cout << tab[1][i][j] << " ";
        }
        cout << endl;
    }

    cout << "Campi generati con successo!" << endl;

    bool stampa = false, affondato = false, colpito = false;
    while (true) {
        system("clear");
        cout << "     LA TUA TABELLA          DOVE HAI COLPITO l'AVVERSARIO" << endl << endl;
        cout << "  ";
        for (int i = 0; i < dimTab; i++) {
            cout << i << " ";
        }
        cout << "            ";
        for (int i = 0; i < dimTab; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < dimTab; i++) {
            cout << (char)('a' + i) << " ";
            for (int j = 0; j < dimTab; j++) {
                cout << tab[0][i][j] << " ";
            }
            cout << "          ";
            cout << (char)('a' + i) << " ";
            for (int j = 0; j < dimTab; j++) {
                cout << tab_colpiti[i][j] << " ";
            }
            cout << endl;
        }

        if (stampa) {
            if (colpito)
                cout << "Hai colpito una nave!" << endl;
            else
                cout << "Non hai colpito niente." << endl;
            if (affondato) cout << "Hai affondato una nave!" << endl;
            affondato = false;
            colpito = false;
        }
        stampa = true;

        string pos;
        cout << nome << ", tocca a te. Inserisci la posizione che vuoi colpire (e.g. a5) >> ";

        while (true) {
            cin >> pos;

            if (pos.length() != 2 || pos[0] < 'a' || pos[0] > 'z' || pos[0] >= (char)(dimTab + 'a') || pos[1] < '0' ||
                pos[1] > '9' || pos[1] >= (char)(dimTab + '0')) {
                cout << "Non hai inserito una posizione valida. Riprova." << endl << " >> ";
                continue;
            }
            if (tab_colpiti[pos[0] - 'a'][pos[1] - '0'] == '.' || tab_colpiti[pos[0] - 'a'][pos[1] - '0'] == 'X') {
                cout << "Hai gia' provato a sparare qui. Riprova." << endl << " >> ";
                continue;
            }
            break;
        }
        int x = pos[0] - 'a';
        int y = pos[1] - '0';
        if (tab[1][x][y] == 'N') {
            tab_colpiti[x][y] = 'X';
            tab[1][x][y] = 'X';
            colpito = true;
            bool imposta_affondato = true, do_x_p = true, do_y_p = true, do_x_n = true, do_y_n = true;
            for (int i = 0; i < dimNaviMax; i++) {
                if (do_x_p && tab[1][x + i][y] == '.') do_x_p = false;
                if (do_x_n && tab[1][x - i][y] == '.') do_x_n = false;
                if (do_y_p && tab[1][x][y + i] == '.') do_y_p = false;
                if (do_y_n && tab[1][x][y - i] == '.') do_y_n = false;

                if (do_x_p && tab[1][x + i][y] == 'N') {
                    imposta_affondato = false;
                    break;
                } else if (do_x_n && tab[1][x - i][y] == 'N') {
                    imposta_affondato = false;
                    break;
                }

                if (do_y_p && tab[1][x][y + i] == 'N') {
                    imposta_affondato = false;
                    break;
                } else if (do_y_n && tab[1][x][y - i] == 'N') {
                    imposta_affondato = false;
                    break;
                }
            }
            if (imposta_affondato) affondato = true;
        } else
            tab_colpiti[x][y] = '.';
    }
}