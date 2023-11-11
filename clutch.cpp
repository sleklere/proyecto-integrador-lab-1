#include <windows.h>
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

bool mazo[20] = {1};
jugador vJugadores[2];
bool primerPartida = 1;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void log(string texto, int color)
{
  SetConsoleTextAttribute(hConsole, color);
  cout << texto;
  SetConsoleTextAttribute(hConsole, 7);
  return;
}

// FUNCION PRINCIPAL
int main()
{
  srand(time(NULL));

  for (int i = 0; i < 20; i++)
  {
    mazo[i] = 1;
  }

  menu();

  return 0;
}