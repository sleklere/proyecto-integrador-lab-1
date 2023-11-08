#pragma once
#include <string>
using namespace std;

extern string cartas[20];
extern bool mazo[20];
struct jugador
{
  string nombre;
  int corral[5];
  int cartasIncorrectas = 0;
  int puntosTotales = 0;
  bool cartasBloqueadas[20] = {0};
  bool pasoTurno = 0;
  bool robadoPorRival = 0;
  bool ultimaAccion3 = 0;
};
extern jugador vJugadores[2];

extern bool primerPartida;
int indiceJ1, indiceJ2;