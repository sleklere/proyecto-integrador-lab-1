#pragma once
#include <string>
using namespace std;

int tirarDado();
void ronda(int numRonda, int indiceJugador, int indiceRival, bool &hayJugador, int &indiceGanador);
void crearCorral(int corral[]);
void mostrarCorral(int indiceJugador);
bool empiezaJ1(int cantidadPorCartaJ1[], int cantidadPorCartaJ2[]);
void contarCartas(int corral[], int vectorCantidades[]);
