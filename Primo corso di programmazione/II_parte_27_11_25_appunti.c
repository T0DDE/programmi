// La visibilità 

#include <stdio.h>

void scambia(int, int); // dichiarazione della funzione scambia. Serve per dire al compilatore che esiste una funzione con questo prototipo, anche se la definizione (il corpo) viene dopo la funzione main. In alternativa potrei mettere la definizione della funzione scambia prima della funzione main, ma in questo modo il codice risulta più ordinato.
// nota che qui non ho dovuto specificare i nomi dei parametri, solo i tipi. Questo perché in questa fase mi interessa solo dire al compilatore che esiste una funzione con questi tipi di parametri e di ritorno.
void scambia_con_indirizzi(int *, int *); // dichiarazione della funzione scambia_con_indirizzi che prende due puntatori a int come parametri

int main(void) {
    int x, y, tmp;

    x = 0;
    y = 1;

    printf("Prima dello scambio: x = %d, y = %d\n", x, y);
    // Se io volessi scambiare i valori di x e y, potrei fare così:
    x = y;
    y = x;
    // Ma questo non funziona, perché dopo la prima istruzione x e y valgono entrambi 1:
    printf("Dopo lo scambio errato: x = %d, y = %d\n", x, y);
    // Dopo aver sovrascritto x con y, il valore originale di x (0) è andato perso.
    // Per scambiare correttamente i valori, ho bisogno di una variabile temporanea:
    x = 0; // resetto x a 0
    y = 1; // resetto y a 1
    tmp = x; // salvo il valore di x in tmp
    x = y;   // assegno a x il valore di y
    y = tmp; // assegno a y il valore originale di x salvato in tmp
    printf("Dopo lo scambio corretto: x = %d, y = %d\n", x, y);
    // stampo i valori e gli indirizzi dei parametri attuali x e y:
    printf("Nel main, i parametri attuali sono: x = %d, che sta in %p, y = %d, che sta in %p\n ", x, &x, y, &y);
    // Se ho definito prima la funzione scambia, posso usarla qui:
    x = 0; // resetto x a 0
    y = 1; // resetto y a 1
    scambia(x, y); // qui prendono il nome di parametri attuali.
    // se stampo i valori di x e y dopo la chiamata a scambia
    printf("Nel main, dopo la chiamata a scambia: x = %d, y = %d\n", x, y);
    // Io voglio che la mia funzione faccia lo scambio di x e y, ma non succede nulla. Questo perché in C i parametri delle funzioni sono passati per valore.
    // Ciò significa che quando chiamo una funzione, i valori dei parametri attuali (x e y nel main) vengono copiati nei parametri formali (x e y nella funzione scambia).
    // Quindi, all'interno della funzione scambia, sto lavorando con copie dei valori di x e y, non con le variabili originali del main, e lì dentro lo scambio sulle copie sta avvenendo correttamente, ma non ha effetto sulle variabili originali del main.
    // Se  invece alla mia funzione passo gli indirizzi di x e y, allora posso fare lo scambio usando i puntatori. 

    // Ora uso la funzione che usa i puntatori per fare lo scambio:
    x = 0; // resetto x a 0
    y = 1; // resetto y a 1
    scambia_con_indirizzi(&x, &y); // passo gli indirizzi di x e y usando l'operatore &
    // Dopo la chiamata a scambia_con_indirizzi, i valori di x e y dovrebbero essere scambiati:
    printf("Nel main, dopo la chiamata a scambia_con_indirizzi: x = %d, y = %d\n", x, y);
    return 0;
}

// Ora definisco la funzione scambia:
void scambia(int x, int y) { // nota che qui invece devo specificare i nomi dei parametri, perché qui li uso nel corpo della funzione. In questa fase prendono il nome di parametri formali, che sono copie dei valori passati dalla chiamata.
    // I parametri formali sono variabili vere e proprie, allocate nello stack quando la funzione viene chiamata, quindi occupano spazio di memoria, ma sono copie dei valori passati come parametri attuali, che a loro volta sono variabili che occupano (un'altra parte della) memoria nello stack del main.
    int tmp;
    // Stampo i valori e gli indirizzi dei parametri formali x e y:
    printf("Dentro scambia, i parametri formali sono: x = %d, che sta in %p, y = %d, che sta in %p\n ", x, &x, y, &y);
    // Mi aspetto stesso valore di x e y del main, ma indirizzi diversi, perché sono copie, cioè variabili diverse.
    tmp = x;
    x = y;
    y = tmp;
    // Se stampo ora i valori e gli indirizzi dei parametri formali x e y dopo lo scambio, mi aspetto che i valori siano scambiati, ma gli indirizzi restino gli stessi:
    printf("Dentro scambia dopo lo scambio, i parametri formali sono: x = %d, che sta in %p, y = %d, che sta in %p\n ", x, &x, y, &y);
    // Tuttavia, questi cambiamenti non influenzano i parametri attuali nel main, perché qui sto lavorando solo con copie dei loro valori.
}

// Ora definisco la funzione scambia_con_indirizzi che prende due puntatori a int come parametri:
void scambia_con_indirizzi(int *x, int *y) { // La funzione deve sapere dove si trovano i parametri attuali!
    int tmp;
    // Stampo i valori e gli indirizzi dei parametri formali x e y (che sono puntatori):
    printf("Dentro scambia_con_indirizzi, i parametri formali sono: *x = %d, che sta in %p, *y = %d, che sta in %p\n ", *x, x, *y, y);
    // Qui mi aspetto che i valori puntati da x e y siano quelli di x e y del main, e che gli indirizzi contenuti in x e y siano gli indirizzi di x e y del main.
    tmp = *x; // dereferenzio x per ottenere il valore di x nel main
    *x = *y;  // dereferenzio y per ottenere il valore di y nel main e lo assegno a dove punta x
    *y = tmp; // assegno a dove punta y il valore originale di x salvato in tmp
    // Se stampo ora i valori e gli indirizzi dei parametri formali x e y dopo lo scambio, mi aspetto che i valori puntati siano scambiati, ma gli indirizzi restino gli stessi:
    printf("Dentro scambia_con_indirizzi dopo lo scambio, i parametri formali sono: *x = %d, che sta in %p, *y = %d, che sta in %p\n ", *x, x, *y, y);
    // Questi cambiamenti influenzano i parametri attuali nel main, perché qui sto lavorando con i loro indirizzi.
}
// Quanto abbiamo visto riguarda il concetto di visibilità delle variabili e dei parametri in C.
// Le variabili dichiarate all'interno di una funzione sono visibili solo all'interno di quella funzione (scope locale).
// Le variabili dichiarate all'esterno di tutte le funzioni sono visibili in tutto il file (scope globale).