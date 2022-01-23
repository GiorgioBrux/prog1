/*
Questo esercizio ha l'obbiettivo di approfondire l'uso delle strutture, dei tipi definiti
dall'utente.
Il programma gestisce un sistema di prenotazione per un club Tennis.
Le prenotazioni di ogni singolo giorno sono memorizzate in file binario (uno per ogni giorno).
_	Ogni file contiene SOLO le prenotazioni di un solo giorno ed il nome e'
        la data nel formato GGMMAAAA.dat (senza spazi intermedi)
_	Ogni prenotazione contiene l'orario di inizio (per semplificare la ricerca sono permesse
        (prenotazioni solo all'inizio di ogni ora e per la durata di un ora, quindi è possibile
        prenotare dalle 8:00 alle 9:00 non dalle 8:30 alle 9:30)
_	La prenotazione è definita tramite una struttura che contiene gli attributi necessario e l'elenco
        è definito da un vettore la cui dimensioni permettono le prenotazione dalle 8:00 alle 21:00 (chiusura 22:00).
_	per semplicità suppongo di gestire un solo campo
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORA_APERTURA 8
#define ORA_CHIUSURA 22
#define NUMERO_TURNI \
    (ORA_CHIUSURA - ORA_APERTURA)  // Numero di turni prenotabili uguale al numero di ore dalle 22:00 alle 8:00
#define COSTO_ORARIO 4             // costo in euro
#define DIMENSIONE_MASSIMA_STRINGA 128
class prenotazione_t {
   public:
    char nome[DIMENSIONE_MASSIMA_STRINGA];
    unsigned short int numero_persone;  // questo valore contiene un valore compreso in [8,12] quindi positivo
                                        // (unsigned) e molto piccolo (short)
};


// In questo programma utilizzo lla lettura dei dati con gets (fgets) e non utilizzo scanf, per
// evitare problemi è meglio non mischiare due meccanismi diversi quindi definisco la lettura di stringa
// ed intero usando le funzioni (poichè non sono state ancora studiate le dovete usare come qualsiasi
// funzione di libreria)
void leggi_stringa(char* s, size_t dimensione) {
    fgets(s, dimensione, stdin);
    // elimino, se esiste il \n
    int len = strlen(s);
    if (s[len - 1] == '\n') s[len - 1] = '\0';
}
unsigned short int leggi_unsigned(void) {
    char buffer[DIMENSIONE_MASSIMA_STRINGA] = "";
    char* ptr;
    fgets(buffer, DIMENSIONE_MASSIMA_STRINGA, stdin);
    return (unsigned short)strtoul(buffer, &ptr, 10);
    // ptr rappresenta la sottostringa che inizia dopo il valore intero e 10 è la base (decimale appunto)
    // ad esempio se buffer = "12 pippo" dopo la funzione ptr = " pippo"
}
int main(void) {
    prenotazione_t agenda[NUMERO_TURNI] = {{"", 0}};
    // Massimo numero di prenotazioni possibili, il vettore e' inizializzato con nome = "", ora e campo = 0
    // a cui do il significato turno libero
    unsigned short scelta;
    char buffer[DIMENSIONE_MASSIMA_STRINGA];
    FILE* fp = NULL;
    do {
        // Completare il programma aggiungendo le seguenti funzioni
        // 2. stampa le prenotazioni del giorno richiesto
        // 3. cancella una prenotazione (e' sufficiente porre a 0 il numero_persone)
        // 4. cancellare tutte le prenotazioni di un giorno
        // 5. contare le prenotazioni presenti in un giorno dato
        // 6. dato il giorno e l'ora calcolare il costo totale (costo orario * numero di persone * numero di ore)
        // Modificare il codice per permettere la prenotazione di piu' ore consecutive (dalle .. alle ..)
        // Modificare il codice per gestire piu' campi (suggerimento creare un file per ogni campo
        // Modificare la struttura per inserire un campo che indica l'avveuto pagamento (da utilizzare nel punto 6)
        // concatenando la stringa che rappresenta la data con il codice del campo letto come stringa (per esempio
        // campo A, campo B, ecc.). Per concatenare due stringhe usare la funzione strcat
        printf("1. inserisci prenotazione\n");
        printf("0. esci\n");
        scelta = leggi_unsigned();
        switch (scelta) {
            case 1:
                // chiedere la data (nel formato GGMMAAAA)
                printf("Inserire la data: ");
                leggi_stringa(buffer, DIMENSIONE_MASSIMA_STRINGA);
                // apro il file se esiste altrimenti inizializzo il vettore ai valori liberi
                // nota che sto aprendo il file in modo binario
                fp = fopen(buffer, "rb");
                if (fp == NULL) {  // non esistono prenotazioni per questa data, quindi creo lo schema vuoto
                    for (int i = 0; i < NUMERO_TURNI; ++i)
                        agenda[i].numero_persone = 0;  // Inizializzo solo il campo relativo al numero di persone
                                                       // che mi e' sufficiente
                                                       // a capire se il turno e' disponibile
                } else {                               // il file esiste e, quindi, carico il vettore
                    if (fread(agenda, sizeof(prenotazione_t), NUMERO_TURNI, fp) != NUMERO_TURNI)
                        printf("Errore caricando i dati da %s\n", buffer);
                    fclose(fp);  //
                }
                // A questo punto chiedo i dati per la nuova prenotazione
                prenotazione_t p;  // variabile di appoggio utile nelle prossime istruzionit
                unsigned short int ora;
                printf("Inserisci l'ora (solo il valore intero): ");
                ora = leggi_unsigned();
                // verifico se il turno e' libero, ricordando che i valori dell'indice appartegono all'intervallo
                // [0, NUMERO_TURNI[ (intervallo aperto) mentre il valore dell'ora appartiene all'intervallo [8,22[
                // (anche questo inervallo aperto) il valore dell'indice si calcola come indice = ora - 8 infatti
                // e' una semplice traslazione dell'asse
                // ATTENZIONE: aggiungere una verifica della correttezza dell'orario
                if (agenda[ora - ORA_APERTURA].numero_persone != 0) {
                    printf("Turno non disponibile\n");
                    break;
                }
                printf("Inserisci il nome: ");
                leggi_stringa(p.nome, DIMENSIONE_MASSIMA_STRINGA);
                printf("Inserisci il numero di persone: ");
                p.numero_persone = leggi_unsigned();
                agenda[ora - ORA_APERTURA] = p;
                // Salvo subito i dati sul file sostituendo la vecchia agenda
                fp = fopen(buffer, "wb");
                if (fp == NULL) {
                    printf("Impossibile salvare la prenotazione\n");
                    break;
                }
                fwrite(agenda, sizeof(prenotazione_t), NUMERO_TURNI, fp);
                fclose(fp);
                break;
            case 0:
                // ATTENZIONE: chiedere di salvare prima di uscire
                break;
            default:
                printf("Scelta non valida\n");
                break;
        }
    } while (scelta != 0);
}