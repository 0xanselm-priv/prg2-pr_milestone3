# prg2-pr: MS3
Für die Ausführung des Programms sollte in einem System mit GNU C++11 
```
make
```
ausgeführt werden. Es ist eine Datei angehängt, die das URL-Klassendiagramm des Projekts zeigt.

Für eine Ausgabe eines neuronalen Netzes in einen `ostream` (etwa eine Datei) kann der `<<`-Operator verwendet werden.

## Projektteam
Andreas Haupt hat ungefähr 40 Stunden gearbeitet, Robert und Niels etwa jeweils 10 Stunden.

## Bekannte Fehler
 - Leider führt die Ausführung des Constructor zu einem Segmentation Fault. Da keine Dangling Pointers verwendet werden, ist uns nicht klar, wo diese herkommen
 - Weiterhin sind aus diesem Grunde auch die Pointer in die Rückrichtung (Member `in_edges_` von Objekten vom Type `node`) nicht implementiert.
 - Der Konstruktor von `NeuralNet`, der lediglich einen Dateinamen nimmt, ist nicht fertig implementiert.