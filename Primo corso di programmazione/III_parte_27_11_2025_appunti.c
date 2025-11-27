#include <stdio.h>
#define N 10

void carica_array(int, int *);
void stampa_array(int, int *);

int main(void) {
    int v[N], n;

    do{
        printf("Quanti numeri vuoi inserire (max %d)? ", N);
        scanf("%d", &n);
    }while(n < 1 || n > N); // Controllo che il numero di elementi da inserire sia compreso tra 1 e N.
    // Aver previsto un N più grande, mi permette di creare un array di dimensione fissa N, e poi usare solo la parte che mi serve, cioè i primi n elementi. Lo "spreco" di memoria è minimo e accettabile in questo caso, considerato che consentirà all'utente successivamente di scegliere quanti numeri inserire, senza dover ricompilare il programma.
    // Il più grande problema degli array, che è anche il suo più grande vantaggio, è che sono costituiti da elementi contigui in memoria. Questo consente di accedere rapidamente agli elementi tramite l'indice, ma richiede di conoscere la dimensione dell'array al momento della compilazione.
    // Se voglio eliminare un elemento del mio array, non posso semplicemente "rimuoverlo" e lasciare un buco, perché gli array in C hanno una dimensione fissa. Devo invece spostare tutti gli elementi successivi di una posizione verso sinistra per coprire il buco, e poi tenere traccia della nuova dimensione effettiva dell'array.
    // Lo stesso vale se voglio inserire un nuovo elemento in una posizione specifica: devo spostare tutti gli elementi successivi di una posizione verso destra per fare spazio al nuovo elemento.
    // Queste operazioni di scorrimento sono molto costose in termini di tempo di esecuzione, specialmente per array grandi, perché richiedono di copiare molti elementi, tant'è vero che esistono alternative, che vedremo (?).
    // Che sia statico o dinamico, il problema descritto sopra rimane. Gli array in C non supportano operazioni di inserimento o cancellazione efficienti.
    printf("\nIndirizzo di v[0]: %p\n", &v[0]);
    carica_array(n, v); 
    stampa_array(n, v);
    return 0;
}

void carica_array(int n, int *x){
    int i;
    printf("\n x è inizializzata con l'indirizzo di v[0]: %p\n", x);
    printf("\nLa variabile x è locale, e si trova in: %p\n", &n);

    for(i = 0; i < n; i++){
        printf("Inserisci il %d° numero: ", i + 1);
        scanf("%d", &x[i]); // equivalente a scanf("%d", x + i);
    }
}

void stampa_array(int n, int *x){
    int i;
    float media;
    printf("\nI numeri inseriti sono:\n");
    media = 0;
    for(i = 0; i < n; i++){
        printf("%d ", *(x+i)); // equivalente a printf("%d ", x[i]);
        media += *(x+i);
    }
    printf("\nLa media è: %.2f\n", media / n);
}