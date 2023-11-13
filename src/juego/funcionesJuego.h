#pragma once
#include <string>
using namespace std;

void turno(int numRonda, int indiceJugador, int indiceRival, bool &hayJugador, int &indiceGanador);
void crearCorral(int corral[]);
void contarCartas(int corral[], int vectorCantidades[]);
bool empiezaJ1(int cantidadPorCartaJ1[], int cantidadPorCartaJ2[]);
void mostrarCorral(int indiceJugador);
int tirarDado();
int chequearCartasValidas(int indiceJugador);
int calcularPuntosPartida(int indiceGanador);
void mostrarPuntos(int indiceGanador, int puntosPartida);
