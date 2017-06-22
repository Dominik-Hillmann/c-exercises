// Dominik Hillmann
// Matrikelnummer 1513306

#include <stdio.h>
#include <stdlib.h>

int main(){
  char c1 = "A";
  // Übersetzungszeitfehler
  // Bei der Initialisierung benötigt der Wert die 'A'-Anführungszeichen.
  char c2 = 256;
  // Übersetzungszeitfehler
  // Compiler: "overflow in implicit constant conversion"
  // Bei Zahlen bis 255 würde der Compiler die Zahl gemäß ASCII in ein Zeichen umwandeln.
  // Allerdings gibt es kein 256. Zeichen in der Tabelle, weshalb der Compiler "overflow" angibt. Es muss entweder ein Zeichen in '' genutzt werden oder eine Zahl bis 255.
  int a,b=a;
  // Übersezungszeitfehler
  // Da a nur deklariert, aber nicht initialisiert wurde, besitzt a kein Wert und kann so nicht b zugewiesen werden.
  unsigned short __1c, 2_c = 10;
  // Übersetzungszeitfehler
  // Es darf keine Zahl am Anfang eines Variablennamens stehen (2_c).
  int short = -3;
  // Übersetzungszeitfehler
  // Es wurde kein Name für die Variable angegeben.
  // Bzw. es wurde versucht, das Schlüsselwort "short" als Name der Variable zu nutzen.
  double x = 1, y = 1 / (1 - x);
  // Logikfehler/Fehler durch Versuch mit printf() entdeckt.
  // 1 - x = 0. Es wird versucht, durch 0 zu teilen.
  enum farben = {yellow, magenta, cyan};
  // Übersetzungszeitfehler
  // enum wird ohne "=" intialisiert: "enum farben {yellow, magenta, cyan};".
  z=7;
  // Übersetzungszeitfehler
  // Es wird versucht, z zu initialisieren, ohne vorher zu deklarieren.

  return EXIT_SUCCESS;
}
