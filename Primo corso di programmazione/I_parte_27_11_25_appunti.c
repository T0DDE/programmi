// Su teams trovi le slide della lezione scorsa, e anche il file di codice che abbiamo visto a lezione.
// Si può usare struct per raggruppare variabili di tipi diversi sotto un unico nome.
// In pratica mi permette di creare un nuovo tipo di vatiabile che contiene più campi di tipi diversi.
// Posso anche creare una struttura che contiene a sua volta strutture.
// Ad esempio:
//
//      struct studente {
//          char nome[20];
//          int matricola;
//          float media;
//      };
//
// nota che la struct non occupa spazio di memoria finché non dichiaro una variabile di quel tipo.

// Quanta memoria occupa una struct?
// Dipende dai campi che contiene, e anche dall'eventuale padding che il compilatore inserisce per allineare i campi in memoria. Non è sempre solo la somma delle dimensioni dei campi.
// A differenza degli oggetti in linguaggi come Java o Python, in C le struct non hanno metodi associati. Sono semplicemente contenitori di dati. Si tratta solo di una definizione di tipo.

// Per accedere ai campi di una struct si usa l'operatore punto (.) se si ha una variabile della struct, oppure la freccia (->) se si ha un puntatore alla struct. 
// Ad esempio:
//    struct studente s1; // inizializzo variabile di tipo struct studente
//    s1.matricola = 12345; // accesso al campo matricola

// Ci sono fondamentalmente due strutture dati principali in C: gli array e le struct.

// Gli array sono collezioni di elementi dello stesso tipo, accessibili tramite un indice numerico.
// Di questi conosco l'indirizzo, e posso calcolare l'indirizzo di ogni elemento tramite l'indice.
// Questi elementi come abbiamio visto sono tutti adiacenti in memoria.
// nota: v+i == &v[i], così come *(v+i) == v[i].
// nota: se definisto un array come 
//
//      int v[3];
//
// allora scrivere 
//
//      v[3]=5;
//
// è un errore, perché l'indice massimo è 2 (si parte da 0). Significherebbe prendere l'indirizzo del primo byte, aggiungere 3*sizeof(int) byte, dereferenziarlo, e scrivere lì il valore 5.
// Ma quell'area di memoria non mi appartiene, quindi è un errore di scrittura fuori dai limiti dell'array (out of bounds).
// Però il compilatore C non controlla questi errori, quindi il codice compila lo stesso. Però a runtime potrei avere comportamenti strani, come crash del programma o corruzione di dati.
// Se è vero che tutti i puntatori occupano la stessa quantità di memoria (di solito 4 o 8 byte a seconda dell'architettura), perché allora devo indicare il tipo del puntatore?
// Perché il tipo del puntatore serve al compilatore per sapere di quanto devo spostarmi in memoria quando faccio operazioni di aritmetica sui puntatori.
// Inoltre, quando dereferenzio un puntatore, il tipo indica al compilatore quanti byte deve leggere da quell'indirizzo per ottenere il valore.

#include <stdio.h>

int main() {
    int v[3] = {1025, 1027, 1024};
    printf("\n%d %d", v[0], v[1]); // Stampa i valori degli elementi dell'array"
    int *ip;
    char *cp;
    printf("\n%ld %ld", sizeof(ip), sizeof(cp)); // Stampa la dimensione dei puntatori (di solito 8 byte su sistemi a 64 bit)

    ip = &v[0];                     // Assega l'indirizzo di v[0], il primo elemento dell'array, a un puntatore int
    printf("\n%p %d",ip,*ip);       // Stampa l'indirizzo di v[0] e il suo valore (1025)
    printf("\n%p %d",ip+1,*(ip+1)); // Stampa l'indirizzo di v[1] e il suo valore (1027)
    printf("\n%p %d",ip+2,*(ip+2)); // Stampa l'indirizzo di v[2] e il suo valore (1024)

    cp = (char *)ip;                // Assega l'indirizzo di v[0] a un puntatore char
// cp resta un puntatore a char, quindi ogni incremento di cp sposta di 1 byte! 
    printf("\n%p %d",cp,*cp);       // Stampa l'indirizzo di v[0] e il primo byte del valore (1)
    printf("\n%p %d",cp+1,*(cp+1)); // Stampa l'indirizzo di v[0] + 1 e il secondo byte del valore (4)
    printf("\n%p %d",cp+2,*(cp+2)); // Stampa l'indirizzo di v[0] + 2 e il terzo byte del valore (0)
    printf("\n%p %d",cp+3,*(cp+3)); // Stampa l'indirizzo di v[0] + 3 e il quarto byte del valore (0)
    printf("\n%p %d",cp+4,*(cp+4)); // Stampa l'indirizzo di v[1] e il primo byte del valore (3)
    printf("\n%p %d",cp+5,*(cp+5)); // Stampa l'indirizzo di v[1] + 1 e il secondo byte del valore (10)

    // 00000000 00000000 00000100 00000001 = 1025 Questo numero occupa i primi 4 byte. Il primo byte è 00000001 = 1, il secondo byte è 00000100 = 4, il terzo e quarto byte sono 0. Il puntatore char legge un byte alla volta, quindi:
    // byte 0: 00000001 = 1
    // byte 1: 00000100 = 4
    // byte 2: 00000000 = 0
    // byte 3: 00000000 = 0
    // al 1027 non ci era ancora arrivato! Questo mostra come l'array altro non è che un insieme di byte successivi in memoria.
    //
    // 00000000 00000000 00000100 00000011 = 1027
    // 
    return 0;
}