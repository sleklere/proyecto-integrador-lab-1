#pragma once
#include <string>
using namespace std;

int tirarDado();
void ronda(int numRonda, bool empiezaJugador1, int corralJugador1[], int corralJugador2[]);
void crearCorral(string jugador, bool cartasRepartidas[], int corral[]);
void mostrarCorral(string jugador, int corral[]);
bool empiezaJ1(int cantidadPorCartaJ1[], int cantidadPorCartaJ2[]);
void contarCartas(int corral[], int vectorCantidades[]);
