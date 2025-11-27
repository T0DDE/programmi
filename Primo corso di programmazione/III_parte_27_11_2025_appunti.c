#include <stdio.h>
#define N 10

void carica_array(int, int *);
void stampa_array(int, int *);

int main(void) {
    int v[N], n;

    do{
        printf("Quanti numeri vuoi inserire (max %d)? ", N);
        scanf("%d", &n);
    }while(n < 1 || n > N); // Controllo che il numero di elementi da inserire sia compreso tra 1 e N. In C il simbolo "||" indica l'operatore logico "OR".
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

// Note:
// I limiti che abbiamo presentato per gli array sono risolvibili adottando le liste concatenate: tra un elemento e l'altro non c'è necessariamente contiguità in memoria, ma ogni elemento contiene un puntatore all'elemento successivo. In questo modo, possiamo facilmente inserire o rimuovere elementi senza dover spostare gli altri elementi in memoria. Tuttavia, le liste concatenate hanno i loro svantaggi, come l'overhead di memoria per i puntatori e l'accesso sequenziale agli elementi, che può essere più lento rispetto agli array. Non posso sommare all'indirizzo di un elemento un numero arbitrario per accedere a un altro elemento, ma devo seguire i puntatori da un elemento all'altro. Ogni elemento avrà un puntatore al successivo.
// Se voglio eliminare un elemento dalla mia lista concatenata, dico al puntatore del precedente di saltare l'elemento da eliminare e puntare direttamente al successivo. In questo modo, l'elemento eliminato non è più accessibile dalla lista, e posso liberare la memoria occupata da quell'elemento se necessario.
// Per inserire un nuovo elemento in una posizione specifica, creo un nuovo elemento e dico al puntatore del precedente di puntare al nuovo elemento, e al puntatore del nuovo elemento di puntare al successivo. In questo modo, il nuovo elemento è inserito nella lista senza dover spostare gli altri elementi.
// L'ultimo elemento della lista punta a NULL, indicando la fine della lista. L'unica cosa che mi serve è un puntatore di lista, che punta al primo elemento della lista. Da lì, posso attraversare la lista seguendo i puntatori da un elemento all'altro.
// L'elemento "eliminato" rimane in memoria fino a quando non viene liberata esplicitamente, ma non è più accessibile dalla lista. 
// Di fatto è spazzatura, e quello che dovrei fare è liberare la memoria occupata da quell'elemento usando la funzione free() se l'elemento era stato allocato dinamicamente con malloc() o simili.
// Come fa l'elemento i-esimo, una volta eliminato il suo successivo, a sapere dove si trova quello che dovrà essere il "nuovo" successivo? Non lo sa. È compito del programmatore gestire correttamente i puntatori per mantenere l'integrità della lista.
// "Eliminare" un elemento della lista, di fatto significa solo sovrascrivere il puntatore del precedente, in modo che punti al successivo di quello che voglio eliminare.
// memory leak: se non libero (cioé dealloco) la memoria occupata dagli elementi eliminati (che avevo allocato dinamicamente), questa rimane occupata fino alla terminazione del programma, causando un consumo di memoria inutile.
// Nota: nella allocazione statica, la deallocazione è automatica. Pensa alla funzione scambia definita nell'altro file: le variabili formali a e b vengono allocate nello stack quando la funzione viene chiamata, e deallocate automaticamente quando la funzione termina. Non devo fare nulla per liberare quella memoria.
// Statica è l'allocazione che avviene in fase di compilazione. So già quanta memoria mi serve, e la riservo tutta in una volta. La memoria viene liberata automaticamente quando la variabile esce dal suo scope (ad esempio, quando una funzione termina).
// Dinamica è l'allocazione che avviene in fase di esecuzione (run time). Non so a priori quanta memoria mi servirà, quindi la chiedo al sistema operativo durante l'esecuzione del programma, usando funzioni come malloc(), calloc(), realloc(). In questo caso, sono io a dover liberare esplicitamente la memoria quando non mi serve più, usando la funzione free(): anche se alloco dinamicamente all'interno di una funzione, la memoria rimane allocata fino a quando non la libero esplicitamente, anche se la funzione termina.
// L'allocazione dinamica avviene nell'heap, una zona di memoria diversa dallo stack. Lo stack è usato per le variabili locali e le chiamate di funzione, mentre l'heap è usato per la memoria allocata dinamicamente. 
// Nella allocazione dinamica ho uno spazio praticamente illimitato (fino alla memoria disponibile del sistema), ma la gestione della memoria è più complessa, perché devo tenere traccia di quanta memoria ho allocato e liberarla quando non mi serve più, per evitare memory leak. Il meccanismo automatico di deallocazione nell'allocazione dinamica non avviene, ad esempio, perché potrebbe essere troppo costoso in termini di prestazioni fare un controllo automatico continuo. 
// In C, l'allocazione dinamica è esplicita: il programmatore deve richiedere e liberare la memoria manualmente. In altri linguaggi, come Java o Python, esistono meccanismi di garbage collection che si occupano automaticamente della gestione della memoria, liberando la memoria non più utilizzata senza intervento esplicito del programmatore.

// Array dinamico: malloc()

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i,n;
    int *ptr, *ctr;
    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    ptr = malloc(n * sizeof(int)); // Alloco dinamicamente un array di n interi
    // malloc, memory allocation, chiede: quanta memoria ti serve? In questo caso, n * sizeof(int) byte.
    // Restituisce un puntatore al primo byte della memoria allocata.
    printf("Valori non inizializzati con malloc (possono essere spazzatura):\n");
    for(i = 0; i < n; i++) {
        printf("Inserisci l'elemento %d: ", i + 1);
        scanf("%d", ptr + i); // equivalente a &ptr[i]
    }
    // Qui stampo gli elementi dell'array
    for(i = 0; i < n; i++) {
        printf("Ora li ho inizializzati uno ad uno: elemento %d: %d\n", i + 1, *(ptr + i)); // equivalente a ptr[i]
    }
    // Rispetto al caso statico, qui ho definito un array di dimensione n, che posso scegliere a runtime, mentre prima dovevo definire un array di dimensione fissa N, e poi usare solo i primi n elementi.
    // Sono sempre elementi contigui in memoria, quindi posso usare la stessa sintassi per accedere agli elementi, ma la dimensione dell'array è decisa a runtime, anziché a compile time. Prima avevo necessità di dichiarare la dimansione mentre ora, chiedendola all'utente, posso allocare esattamente la quantità di memoria necessaria.
    // Lo stesso risultato si può ottenere con calloc(), che inizializza la memoria allocata a zero:
    // ptr = calloc(n, sizeof(int)); Alloca e inizializza un array di n zeri (interi)
    for(i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i + 1, *(ptr + i)); // equivalente a ptr[i]
    }
    ctr = calloc(n, sizeof(int)); // Alloca e inizializza un array di n zeri (interi)
    printf("Valori inizializzati con calloc (tutti zero):\n");
    // Nelle slide fa vedere come può essere definita una funzione allocate_array usando calloc, sia usando return che usando il puntatore a puntatore (vedi da lì per la sintassi).

    free(ptr); // Libero la memoria allocata dinamicamente
    free(ctr); // Libero la memoria allocata dinamicamente 
    return 0; 

}













