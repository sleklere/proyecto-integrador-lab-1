#pragma once
#include <string>
using namespace std;

struct jugador
{
  string nombre;
  int corral[5];
  bool cartasBloqueadas[20] = {0};
};

extern jugador vJugadores[2];
extern string cartas[20];
int indiceJ1, indiceJ2;