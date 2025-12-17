"""
Qualità del Software

Cosa si intende davvero per qualità?
Può essere interna (è scritto bene o male? ci sono bug? ha chiaramente un riflesso sulla qualità esterna) o esterna (da parte dell'utente, nel nostro caso gli altri settori di Terna, che useranno i nostri programmi)
C'è poi una serie di requisiti, in base a ciò che il cliente vuole (anchhe senza sapere di volerlo).
Questi possono essere 
- funzionali (il legame tra input e output) 
    - correttezza di ciò che fa il software (non sempre è semplice valutare la correttezza del software) 
- non-funzionali 
    - Affidabilità,
    - preformance
    - efficienza
    - Sicurezza
    - un codice scritto in modo così contorto che è praticamente impossibile da modificare e migliorare
    - ...

Nota: mentre la correttezza è un parametro che c'è o non c'è, l'affidabilità dipende molto dal contesto (es. bilancia da cucina, o da laboratorio)

Sulla correttezza:

- Verifica formale: 
Una dimostrazione matematica della correttezza dell'algoritmo. Si usa in contesti molto critici, in cui si deve dimostrare che alcune parti del compilatore sono corrette. Costa molto, e non sempre è fattibile. Inoltre, l'algoritmo è il procedimento. Se anche lo dimostriamo perfettamente, ci sono altri possibili problemi: il computer (l'hardware potrebbe non essere perfetto, ed è controllato in maniera molto indiretta dal programma, perché c'è anche il sistema operativo), il sistema operativo stesso.
In genere si verifica formalmente solo un pezzettino, si testa in maniera quasi esaustiva il suo funzionamento nel complesso, nell'ambiente in cui dialoga con altri software e con l'hardware, e se tutto va bene si blocca la situazione così com'è, senza installare altro.
Insomma la verifica formale è utile, ma non è sufficiente.

Nel concreto, posso ispezionare il codice (possibilmente non scritto da noi), seguendo anche delle linee guida, come una checklist di errori comuni a seconda del linguaggio, generalmente dettate dall'azienda. Ne esistono anche di generali, come quelle OSWAP.

Infine il terzo modo è il test del software. Il problema è che non è sempre facile calcolare l'output che mi aspetto per confrontarlo con quello che da il software.
A volte ad esempio si usano vecchi software, che hanno molti difetti ma della correttezza siamo abbastanza convinti (magari viene usato da tanti anni), e confronto il suo output con quello del mio software più nuovo.

Se provo il programma con dei dati, quello che posso dire è solo che quel programma funziona (o meno) con quei particolari dati.
Quello che devo fare è cercare di testarlo in modo da coprire più scenari possibili.

Gli IDE moderni possono creare uno scheletro di tutte le funzioni che voglio testare, vedi bene come funziona.

Testare mi permette di vedere se ci sono errori, ma non di dimostrarne l'assenza: per quella serve la dimostrazione formale!

Come si migliora la correttezza?
- Al netto di vincoli uso il linguaggio migliore per il mio scopo (es. creare liste concatenate con python anziché con c). 
- Non reinventare la ruota:
    - usare algoritmi standard
    - usare librerie già esistenti
    - design patterns: soluzioni standard a problemi ricorrenti, delle quali sono già stati mostrati i pro e i contro.
    - usare metodologie e processi provati

Deve rimanere però il fatto che NON ci sono software completamente privi di difetti.
Questo è il motivo per cui i programmatori si devono proteggere legalmente, presentando il software senza garanzie incluse.
Una particolare qualità non funzionale del software è l'usabilità: quando scrivi un codice che non devi usare tu, fallo usare almeno una volta ad almeno un'altra persona.
Come si rende una misura oggettiva dell'usabilità? Mi chiedo quanto è 
- Efficacie, 
- Efficiente  
- Soddisfacente.

Da notare che la misura dell'usabilità è relativa allo specifico contesto d'uso e dall'utente. Quello che si fa è quantificare le misure dei tre parametri. Numero di click, o tempo impiegato, e se funziona, si o no, o che percentuale di successo ha avuto un utente che l'ha provata senza averla scritta.
Sarà anche quantificato, ma è oggettiva la misura?

Nel '93 fu dimostrato che se io faccio un'applicazione e la faccio usare a tre persone, tiro fuori il 70 percento degli errori di usabilità. 15 persone e praticamente li ho trovati tutti.

Mantenibilità:
Metter mano al codice per correggerlo, migliorarlo, etc. Tutte quest eattività costano più del 50 percento del costo del software! 

Riusabilità:
Faccio un lavoro più volte possibile, e questo lavoro lo riciclo il più possibile. Creo una libreria di funzioni che hanno uno scopo specifico, con una coesione interna, che siano facilmente riutilizzabili.

Portabilità:
Se il programma è scritto in modo modulare, come classi, librerie, moduli (gruppi di classi), allora è facile portare questo programma in un'altra piattaforma: cambio il modulo, ma la parte di logica resta invariata.

Comprensibilità:
Se il software è modulare, posso cercare di comprendere ogni modulo uno alla volta, ed è molto più facile da comprendere e analizzare.

"""
