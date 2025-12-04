"""
OGGETTI DINAMICI

Abbiamo visto che a differenza degli array, nelle liste concatenate non c'è un offset che ci permetta di trovare l'elemento successivo, ma si salva in ogni elemento un puntatore che punta all'elemento successivo.
L'ultimo elemento deve puntare a NULL.
Una volta che tutti gli elementi sono concatenati, a noi serve è un puntatore alla nostra lista, per sapere qual è l'indirizzo di memoria solo del I elemento.
Ogni elemento della lista quindi è costituito da più campi:

- uno informativo, che rappresenta il contenuto dell'elemento (può essere un intero, un char, etc.);
- uno spazio per memorizzare l'indirizzo dell'elemento successivo.

Ad esempio, se ho una lista di interi, avrò in generale 4byte per l'intero, più 8 byte per il puntatore, quindi (almeno) 12 byte in totale. In generale, possono esserci motivi per cui ne occupi più di 12, ma non di meno.
L'inserimento o l'eliminazione di un elemento in una lista, anche se non necesariamente è più facile da scrivere in c, è più rapido, perché non richiede di scorrere tutti gli elementi.
Queste sono le liste lineari semplicemente concatenate. Un elemento conosce l'indirizzo del successivo. Esistono anche liste dove ogni elemento conosce anche la posizione dell'elemento precedente (doppiamente concatenate).

Avendo ogni elemento la necessità di avere quantomeno 2 campi (esistono liste di lettura, dove ci sono decine o più informazioni da inserire in ogni elemento della lista stessa), non possiamo avere una struttura dati derivata da un tipo semplice, come 

#   int v[N];

Ma abbiamo necessità di utilizzare le strutture, con le quali definire un tipo nuovo, più complesso.
Questo tipo che definisco, avrà ad esempio con un campo int e un campo puntatore, questo puntatore dovrà puntare a un indirizzo di unaltro elemento dello stesso tipo complesso che ho definito!
Poi quando dereferenzio, dovrò dereferenziare i singoli campi che costituiscono il mio tipo che ho definito con una struttura.
"""

#include  <stdio.h>
#include <stdlib.h>

//////// STRUTTURE ///////////

struct elemento {
    int valore;
    struct elemento *next; // Il puntatore deve puntare all'elemento successivo, che è del tipo "struct elemento"
};

struct altro_elemento {
    float valore;
    struct elemento *next;
};


//////// FUNZIONI //////////

struct elemento *creaLista(); // restituirà l'indirizzo al primo elemento, che dev'essere di tipo struct elemento.
struct altro_elemento *creaListaStrana(); // restituirà l'indirizzo al primo elemento, che dev'essere di tipo struct altro elemento.
void stampa_lista(struct elemento *);
void liberaLista(struct elemento *p);

int main(void) {
//     struct elemento x;
//     printf("%ld", sizeof(x));
//     x.valore = 0;
    struct elemento *p_lista;
    p_lista = creaLista();
    if (p_lista != NULL) stampa_lista(p_lista);
    return 0;
}

//////////////////////////////////////////////////

"""
Nota importante: noi qui non ne stiamo tenendo conto, ma bisognerebbe liberare la memoria allocata!
E bisogna fare attenzione a come lo si fa! non basta un 

#    free(p_lista);

che libererebbe solo il primo elemento, e perderei l'informazione su dove sono gli altri!
Questo vedilo dal codice che manda il professore.
"""


struct elemento *creaLista(){
    struct elemento *p; // con questo, ho definito un puntatore (quindi di 8 byte) nella memoria stack. Che cosa voglio mettere in questo p? Un elemento struc elemento. Ma quale in particolare? lo assegno dopo.
    int n;

    printf{"\nQuanti elementi vuoi inserire?"};
    scanf("%d", &n);

    if (n>0) {
        p = malloc(sizeof(struct elemento)); // se voglio almeno un elemento, allora lo creo con malloc, delle dimensioni di struct elemento, e lo metto dentro p. 
        // Da qui in poi il puntatore "p", che occupa al solito 8 byte, sa dove si trova il primo elemento della mia lista, un elemento di 12 byte (ad esempio).
        printf("\nInserisci valore:");
        scanf("%d", &p->valore); // Se voglio accedere a un campo di una variabile attraverso un puntatore, non è &p.valore, ma la sintassi cambia e si usa la freccia.
        // Ho creato il primo elemento con il suo indirizzo, e gli ho assegnato un valore.
        // Per gli elementi successivi uso un for. Il primo sta fuori dal for perché sennò sovrascriverei sempre il puntatore al primo elemento.
        //ora mi serve un puntatore per puntare a p. Un puntatore ausiliario (perché il puntatore p stesso non voglio sovrascriverlo! Facendo così il vero p resta quello che ho assegnato all'inizio.
        paux = p;
        for (i=2; i<=n; i++) {
            paux->next = malloc(sizeof(struct elemento)); // Se entro nel ciclo for è perché mi serve allocare memoria, per questo malloc. Poi ci penso a creare paux, ma dopo, perché mi rendo conto che mi serve.
            // Al campo che contiene l'indirizzo, cioé il campo next (vedi definizione struct elemento), assegno l'indirizzo di questi nuovi byte di memoria che mi restituisce la malloc.
            paux = paux->next // aggiorno paux all'indirizzo a cui sta puntando il campo next dell'elemento a cui paux stava puntando, così avanza all'elemento successivo, e il campo next a cui si riferirà nel prossimo ciclo sarà quello dell'elemento ancora successivo.
            printf("\nAssegna un valore:");
            scanf("%d", &paux->valore);
        }
        paux->next = NULL; // L'ultimo elemento, nel campo next, deve puntare a NULL.
    } else p = NULL;

    return p;
};



struct elemento *creaListaStrana(){
    struct altro_elemento *p; 
    int n;

    printf{"\nQuanti elementi vuoi inserire?"};
    scanf("%d", &n);

    if (n>0) {
        p = malloc(sizeof(struct altro_elemento)); 
        printf("\nInserisci valore float:");
        scanf("%d", &p->valore); 


        for (i=2; i<=n; i++) {
            
        }
        paux->next = NULL; 
    } else p = NULL;

    return p;
};

void stampa_lista() {
    printf("\nLista:");
    wihle (p != NULL){
        printf("%d", p->valore);
        p = p->next;
    }
};


void liberaLista(struct elemento *p) {
    struct elemento *paux;
    while (p != NULL) {
        p = p->next;
        free(paux);
    }
}


"""
Sui file:

I programmi scritti così hanno il limite di essere fini a se stessi: i valori che calcolo sono salvati in RAM, e spariscono come chiudo il file.
La soluzione è quella di salvare questi risultati in files, quell'entità che permette di memorizzare i dati, e i risultati, in maniera permanente.

In c i file si usano a basso livello: serve creare una connessione tra RAM e hard disk usando i puntatori.
dichiaro una variabile puntatore a un tipo che isi chiama file:

#   FILE *fp;

Attenzione però al sistema operativo: a seconda di come la libreria è implementata, il codice potrebbe dover essere modificato per essere portato tra sistemi operativi diversi.
Esistono file di due tipi:
- binari: byte esatti della memoria, leggibile solo da programmi, senza nessuna conversione. Perfetti per strutture e array
- testo: un file come la trascrizione dei miei dati in caratteri, leggibili all'utente, parsing (trasformazione dei dati contenuti in un file di testo (caratteri) in dati strutturati contenuti nel programma) se necessario.

dipende tutto da: a chi è destinata la ''lettura'' di quel file?
nota che il parsing può essere anche estremamente complesso, quindi se non è necessario, è meglio evitarlo del tutto.
Ovviamente, però, se non lo faccio non posso aprire il file con un editor.

Come creo la connessione tra un avariabile e una locazione del mio disco fisso?

#   fopen('path/to/file', modalita_di_apertura);  già solo il path dipende dall'OS. la modalità di apertura dipende da cosa voglio fare con il file, e bisogna fare attenzione, perché a seconda della modalità potrei trovarmi a sovrascrivere il file! ad esempio r: read, w: write, a: append, rw lettura e scrittura, a volte appare una b, come bw, che in alcuni OS serve, in altri no, quindi è buona abitudine metterla. La b sta per binary.

#   fclose()

Esistono funzioni per leggere e scrivere dai file:

#   fprintf();
#   fscanf();

VEDI ESEMPI IN SLIDES

"""