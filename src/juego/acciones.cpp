#include <iostream>
#include "acciones.h"
#include "../variablesGlobales.h"
using namespace std;

void accion1() {}
void accion2() {}

// FUNCION ACCION 3
void accion3(int corralPropio[], int corralRival[], int indiceJugador)
{
  int cartaPropia, cartaRival;
  bool cartaValida = false;

  cout << endl;
  cout << "Elegir una carta del corral propio e intercambiarla por una carta del corral contrario." << endl;

  cout << "¿Que cartas desea intercambiar?" << endl;
  cout << "Carta propia: ";
  cin >> cartaPropia;
  // accion5, si el rival bloqueó una de sus cartas pedir de elegir otra
  while (!cartaValida)
  {
    cout << "Carta del rival: ";
    cin >> cartaRival;
    cout << endl;
    // si cartaRival esta bloqueada seguir preguntando, sino salir del while y seguir
    int indiceCarta = corralRival[cartaRival - 1];
    if (!vJugadores[indiceJugador].cartasBloqueadas[indiceCarta])
    {
      cartaValida = true;
    }
  }

  int aux = corralPropio[cartaPropia - 1];
  corralPropio[cartaPropia - 1] = corralRival[cartaRival - 1];
  corralRival[cartaRival - 1] = aux;
}

// FUNCION ACCION 4
void accion4(int corralPropio[])
{
  int cartaPropia1, cartaPropia2;

  cout << endl;
  cout << "Intercambiar dos cartas del propio corral." << endl;

  cout << "¿Que cartas desea intercambiar?" << endl;
  cout << "Carta propia: ";
  cin >> cartaPropia1;
  cout << "Carta propia: ";
  cin >> cartaPropia2;
  cout << endl;

  int aux = corralPropio[cartaPropia1 - 1];
  corralPropio[cartaPropia1 - 1] = corralPropio[cartaPropia2 - 1];
  corralPropio[cartaPropia2 - 1] = aux;
}

void accion5(int indiceJugador) // pasar el numero del jugador para poder bloquear la carta
{
  int numCartaBloquear;

  cout << endl;
  cout << "Elija una carta para bloquear: ";
  cin >> numCartaBloquear;

  vJugadores[indiceJugador].cartasBloqueadas[numCartaBloquear - 1] = 1;
}

void accion6(int indiceJugador, int indiceRival)
{
  int opcion;
  bool opcionValida;

  while (!opcionValida)
  {
    cout << endl;
    cout << "Elija cualquiera de las acciones (1 - 5), o pase el turno (0): ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      accion1();
      opcionValida = true;
      break;
    case 2:
      accion2();
      opcionValida = true;
      break;
    case 3:
      accion3(vJugadores[indiceJugador].corral, vJugadores[indiceRival].corral, indiceJugador);
      opcionValida = true;
      break;
    case 4:
      accion4(vJugadores[indiceJugador].corral);
      opcionValida = true;
      break;
    case 5:
      accion5(indiceJugador);
      opcionValida = true;
      break;
    case 0:
      opcionValida = true;
      break;
    default:
      break;
    }
  }
}