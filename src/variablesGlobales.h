#pragma once
#include <windows.h>
#include <string>
using namespace std;

extern string cartas[20];
extern bool mazo[20];
extern HANDLE hConsole;
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
  int colorTexto;
};
extern jugador vJugadores[2];

extern bool primerPartida;
int indiceJ1, indiceJ2;

void log(string texto, int color);