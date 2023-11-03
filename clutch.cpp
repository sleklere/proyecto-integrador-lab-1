#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./src/variablesGlobales.h"
#include "./src/opcionesMenu.cpp"
using namespace std;

string cartas[20] = {"10 Corazones", "10 Picas", "10 Diamantes", "10 Trebol",
                     "J Corazones", "J Picas", "J Diamantes", "J Trebol",
                     "Q Corazones", "Q Picas", "Q Diamantes", "Q Trebol",
                     "K Corazones", "K Picas", "K Diamantes", "K Trebol",
                     "A Corazones", "A Picas", "A Diamantes", "A Trebol"};
jugador vJugadores[2];
int turnoJugador;

// FUNCION PRINCIPAL
int main()
{
  // bool primerPartida = 1;
  srand(time(NULL));

  menu();

  return 0;
}