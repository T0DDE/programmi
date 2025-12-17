"""
professore: Gian Luca Marcialis 

Si occupa di interpretare e individuare caratteristiche distintive di serie di dati mono o multidimensionali.
Fa insomma pattern recognition, facendo un'estrazione di caratteristiche, attraverso degli algoritmi, che servono a riconoscere delle anomalie in un segnale.

Forse a fine corso vedremo anche come si implementa una rete neurale, alla base dei Large Language Models (LLM), strumento sempre più importante anche in questo settore.

!!!!!!!!!  IMPORTANTE !!!!!!!!!!
Il 18 e il 22 non ci sarà lezione. Ci sarà lezione però il 7 Gennaio, dalle 9 alle 12. Il 12 dalle 18 alle 20 due orette di lezione.
!!!!!!!!!  IMPORTANTE !!!!!!!!!!

Algoritmo è una sequenza precisa di passi elementari, non ambigua, semplice. Il suo scopo è quindi quello di realizzare un compito, risolvere un problema.

Più formalmente:
Un algoritmo è un insieme ordinato di operazioni non ambigue ed effettivamente computabili che, qunaod eseguito, produce un risultato osservabile e si arresta in un tempo finito.


I Linguaggi di programmazione si dividono in:

- INTERPRETI, la classe di linguaggi che traducono istantaneamente le singole frasi dell'algoritmo e le fanno eseguire al calcolatore, senza osservare passato o futuro: è istantaneo, esegue una frase alla volta. Può non vedere errori che possono presentarsi all'improvviso.
Python nasce come linguaggio interpretato, ma essendo basato sulla traduzione istantanea, è anche molto lento (deve prendere l'istruzione, tradurla nel linguaggio della macchina, ed eseguirla)

- COMPILATI, che invece traducono l'intero programma prima dell'esecuzione in linguaggio macchina, così che ci si riapra almeno dagli errori sintattici, che rendono il programma non eseguibile.
Compilatori e interpreti non ci riparano dagli errori in fase di esecuzione. Python può essere anche compilato.

Per evitatre di scrivere un programma sbagliato e pieno di errori, la sintassi non può essere alterata.

"""

print("\nInserire due valori da sommare:\n")
a=int(input("Inserire il primo valore: "))
b=int(input("Inserire il secondo numero: "))

"""
Nota: ciò che c'è a destra dell'uguale può provenire da
- un file
- tastiera (input)
- dalla memoria stessa

Se mi interessa memorizzare un intero, devo dirglielo. 

In python, a differenza del C, non c'è un input formattato (es. %f, %d, per indicare di che tipo di variabile stiamo parlando).
input() è equivalente a scanf, ma nelle () si scrive una stringa di cortesia che viene stampata a video (può anche non esserci).
input() da solo si prepara ad accogliere qualunque tipo di stringa. con int() elaboro l'output di input(), cioé la stringa che viene passata ad input(), come un intero.

si potrebbe anche fare 

    a=input()
    a=int(a)

e ottenere lo stesso risultato.
"""

somma = a + b

print(a, "+", b, "=",somma)













