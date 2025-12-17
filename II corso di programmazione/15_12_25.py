"""
Docstring for II corso di programmazione.15_12_25

Le liste in python sono un po' come gli array in C ma molto più flessibili.



v = [10, 20, 30, 40]

for el in v:
    print(el)

In python si può usare un ciclo for senza bisogno della variabile "i", che può sembrare zucchero sintattico, un modo di var sembrare più carino il codice nascondendo la sintassi ma non cambiando in realtà nulla. Vedremo ora che in realtà non è così.

MODULARITÀ

Permette di affrontare il problema un pezzo alla volta. Posso dividere il lavoro con altri colleghi delegando a ciascuno un modulo.
I moduli, come le funzioni, comunicano fra loro attraverso i nomi delle funzioni del modulo, che rappresentano "l'interfaccia" del modulo rispetto agli altri moduli.
Se nel modulo ho 10 funzioni, non è detto che tutte e 10 le funzioni facciano parte dell'interfaccia: ci sono anche funzioni a scopo interno. Quelle che fanno parte dell'interfaccia sono quelle che non cambieranno. Quelle interne possono cambiare se conviene, perché riguardano l'implementazione.

L'uso delle variabili globali è molto limitante per quanto riguarda la riusabilità di un codice su altri programmi. Un compromesso può essere un oggetto globale, ma altrimenti si passa un oggetto contestuale alla funzione.

L'uso delle variebili globali è un esento di DEBITO TECNICO, un qualcosa di raffazzonato la cui risoluzione viene procrastinata. Il problema è che sono tutte pezze che si accumulano.

Il modulo che offre i suoi servizi agli altri si chiama SERVER, quello che usa questi servizi è il CLIENT.
Se scrivo un codice che usa numpy e le sue funzioni, questo codice è il client, numpy è il server.

La relazione che lega modulo che usa e modulo che viene usato è detta relazione USES.

Tra le funzioni di uno stesso modulo, può anche lì esserci dipendenza: ad esempio definisco il seno con l'espanzione di Taylor, ma poi il coseno lo definisco come sqrt(1-sin^2), e così per la tangente. 
La domanda quindi è: quale relazione conviene usare? dipende, da quanto ad esempio voglio che sia più lenta o più veloce una funzione, in baso a quanto la uso: se il seno lo uso spessissimo, lo definisco con taylor per farlo essere più veloce, ma se la tangente la uso pochissimo, può essere più comodo definirlo usando la funzione seno e coseno. La rendo più lenta consapevolmente, per rendere la implementazione più rapida e comoda.

Il codice quindi può essere progettato in modi diversi, a monte, prima dell'implementazione, a seconda degli scopi e delle necessità.

La progettazione piò essere gerarchica, o ciclica, dove A punta a B e B punta ad A. Il problema è che in questo modo non posso testare A senza aver prima fatto anche B, e non posso testare B finché non ho ancora fatto A. 
Nel caso gerarchico, a partire dall'alto, posso testare i moduli uno alla volta.

In genere se ho una situazione "ciclica" molto probabilmente ho sbagliato qualcosa nel design.
Gerarchico in genere è meglio: più comprensibile, testabile pezzo per pezzo, ...

Potrebbero forse esserci delle situazioni in cui la ciclicità è inevitabile, ma probabilmente quasi sempre questa ciclicità può essere spezzata.

Un altro tipo di relazione fra moduli è la relazione "IS_COMPONENT_OF", che serve a descrivere l'architettura in termini di un modulo che è fornito da A.
Per esempio, le funzioni seno, coseno e tangente sono contenuti dal modulo "trigonometrico", ma non è una relazione "USES", sono solo contenuti lì.
Si tratta più che altro di una gerarchia per fare ordine, un "albero" di appartenenze dove solo le "foglie" vanno programmate, sono codice, mentre i rami sono più che altro i "contenitori" delle funzioni foglia.  


Il modulo deve essere COESO, contenere tutte funzioni che trattano lo stesso argomento.
Quanto due moduli devono essere connessi, devono dialogare, e come, è il problema dell'ACCOPPIAMENTO. Per quanto possibile, devo fare si che un modulo sia accoppiato il minimo possible con gli altri moduli.

Il modulo abbiamo detto ha l'INTERFACCIA, e l'IMPLEMENTAZIONE.
Interfaccia sono le funzioni a disposizione del client, le altre sono quelle che non sono a disposizione, servono all'implementazione.
Sempre dell'interfaccia fanno parte i commenti che il client deve conoscere sulle funzioni a sua disposizione.
Anche eventualmente le strutture dati messe a disposizione dal modulo possono fare parte dell'interfaccia.

La funzione help() mostra le funzioni dell'interfaccia, non quelle interne.

Il client può ignorare l'implementazione, e dovrebbe anche farlo:

"""
"""

Supponiamo di avere, in C++, una struttura come:

// MODULO

struct t{int ore; int minuti};

struct t t1;

struct t set_time(int h, int m){
    t1.ore= h;
    t1.minuti= m;
}
//get_min, get_ore, ...

Dovrei ignorare l'implementazione interna, come sapere che la struttura dati contiene due interi, int ore e int minuti. Questo è un segreto del modulo, perché il progettista del modulo potrebbe cambiare idea, cambiare ad esempio il nome ore e minuti in inglese che ne so.


// CLIENT

struct t t_client;
t_client = set_time(10, 5);

// Ora magari il client decide di cambiare i minuti lasciando invariate le ore.
ore= get_ore(...)

t_client= set_time(ore, 6)

// Ora: il client potrebbe essere tentato di vedere che nel modulo il campo si chiama t_client.minuti, e fare

t_client.minuti = 6

// camnbiando solamente i minuti, anziché cambiarli entrambi con get_ore come abbiamo fatto prima, assegnando contemporaneamente le stesse ore e i minuti diversi.
// Se però ora il server cambia il nome da minuti a minutes, per esempio, il programma non funziona più!
// L'interfaccia può essere anche più complessa, avere ad esempio dei controlli critici, che se uno accede ai segreti del modulo potrebbe bypassare, inserendo valori magari impossibili, e generare degli errori.
"""

"""
Nota: in python è sempre possiblie acceder ai segreti del modulo. Con C e C++ diciamo che può capitare anche con incapsulamenti forti che un programma scritto 

In C e C++ è possibile inserire alcune funzioni nell'interfaccia e alcune nell'implementazione, e renderele così inaccessibli al client. 

In C e in C++ i file .h sono quelli che contengono le interfacce:

#include <stdio.h>


Se ho un mio main.cpp, e lo arricchisco con altri file, devo comunicare all'IDE che il nuovo file fa parte del progetto. Nel fare questo quindi l'IDE  hiede se associare un Header (l'interfaccia, il file .h) e se unirlo al main.c

Tutto ciò può essere fatto manualmente, creando a mano il make file, un file txt che contiene la lista degli elementi del codice che devono essere in qualche modo legati, integrati tra loro. 

"inclduere" il modulo, significa stabilire la relazione "USE" tra il mio codice e il server, il modulo.

Nel modulo che creo, che farà da server, devo quindi includere l'interfaccia. Poniamo che ho funzione foo1 e foo2, e voglio includere nell'interfaccia solo la prima:

// QUESTO IN modulo.c

void foo1(...){
    ...
}

void foo2(...){
    ...
}



Nel file.h, l'interfaccia, dovrò ricopiare tutte le signature delle funzioni che voglio esportare come interfaccia, ad esempio:

// QUESTO IN modulo.h

int foo1(...);


Dopodiché devo dire al main di usare quella interfaccia, con 

//QUESTO NEL MIO main.c

#include "modulo.h"


nota: uso le "" perché non deve cercarlo nelle cartele standard del C, ma nelle mie cartelle di progetto. Se modulo.h è in un certo path, farò

#include "path/modulo.h"


Come ci si comporta in questo senso come programmatore dipende molto anche dalle linee guida dell'azienda: mettere solo il nome della funzione nel modulo.h, oppure ??

Se il modulo dichiara una struttura dati e la mette nell'interfaccia, mettendola a disposizione del client, il client vede il nome delle variabili, e c'è il rischio del bypass. Qui l'interfaccia è astrazione ma non incapsuilamento. In python è sempre così, in C e C++ può essere così, come nell'esempio appena detto.

C'è modo anche di incapsulare le strutture dati, mettendole nel .c, e nell'interfaccia definisco un puntatore che punta alla struttura dati:

//in .c:

int struct T(int a; int b;);

// in .h:

//puntatore che punta alla struttura dati 'segreta' e le intrfacce per accedere, ad esempio


Se io scrivo le struct nell'interfaccia le do a disposizione del client. Se non voglio che questo agisca direttamente, allora posso scrivere un commento dicendogli di non farlo (unico modo in python, uno dei modi in C e C++), oppure in C/C++ obbligo l'uso dell'interfaccia scrivendo la struct nel modulo ma non nell'interfaccia, e mettendo puntatori alle struct nascoste nell'interfaccia.
è una scelta un po' pesante perché obbliga anche l'uso della memporia dinamico, e un uso pesante dei puntatori. Spesso infatti si preferisce il metodo coi commenti.

Se la struttura non è nel main e non è nell'interfaccia il main non può dichiarare una variabile di quel tipo di dato. Quello che tocca fare quindi è scrivere nel modulo una funzione che crea la struttura

In complex.c

ComplexPtr create_complex(float re, float img){
    ComplexPtr z;
    z= malloc(sizeof(*z));
    z->re=re;
    z->img=img;
    return z; //rende un puntatore
}

Nel .h:

typedef struct complex_tag_name * Complex_Ptr; // un puntatore alla struttura che permette al main di maneggiare puntatori a quel tipo di dato, ma non li può dereferenziare, perché non ha idea di come sia fatto questo tipo di struttura.

Nel main quindi:

int main(){
    ComplexPtr z1, z2, z3; //creo puntatori, sono obbligato
    z1= create_complex(z1, z2);
}

Posso insomma ottenere un incapsulamento totale, che obbliga il client a usare l'interfaccia, come strato di implementazione che tramite i puntatori consente al main di maneggiare la struttura tramite essi.

Si deve però così usare un'allocazione dinamica.

"""

"""
Abbiamo detto che in python, se ho una lista, e voglio stampare i valori senza l'indice, c'è la possibilità di fare

v=[...]
for el in v:
    print(el)


Ora: supponiamo di avere una lista concatenata di C. Se voglio iterare sugli elementi della lista e stamparli, dovrò fare:

p->val //stampo il valore
p=p->next vado al prossimo

ste cose dovrò iterarle con un for. Ora, scrivendo queste cose, sto svelando il segreto del modulo: da questo codice si vede che è una lista concatenata! se cambio idea dovrò riscrivere il codice diversamente!

In python c'è uno strato sintattico che nasconde il modulo: il ciclo for si scriverà sempre allo stesso modo, senza che cambi a seconda del tipo di struttura:

for el in v:

La struttura dati può essere attraversata in modo diverso, e questo sta nell'interfaccia della struttura stessa. Il for non cambierà!
Qualunque struttura dati, comunque sia connessa, dato che ha un inizio, una fine (solo perché sennò il for non finisce mai), e un elemento successivo, può essere percorsa con questo ciclo for allo stesso modo.


L'interfaccia è un'astrazione del modulo: ciò che mi da l'interfaccia è sufficiente per usare il modulo. Usa l'interfaccia, non serve il resto.
L'incapsulamento è nascondere i segreti del modulo. Usa l'interfaccia, non puoi usare il resto.

Può essere utile includere nel modulo, .c, la propria interfaccia, .h, perché il compilatore così vede se c'è coerenza tra le due. Se ad esempio modifico l'interfaccia/modulo e non il modulo/interfaccia, il compilatore se ne accorge e mi da errore, se includo l'interfaccia nel modulo.


EXAMPLE - HIGH nad LOW COUPLING


"""


