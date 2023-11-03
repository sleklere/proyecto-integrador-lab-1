#include <iostream>
#include "acciones.h"
#include "../variablesGlobales.h"
using namespace std;

bool validarNumCarta(int numCarta)
{
  int numerosValidos[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
  {
    if (numCarta == numerosValidos[i])
    {
      return 1;
    }
  }
  return 0;
}

void accion1() {}
void accion2() {}

// FUNCION ACCION 3
void accion3(int corralPropio[], int corralRival[], int indiceJugador)
{
  int cartaPropia, cartaRival;
  bool cartaRivalValida = 0;
  bool cartaPropiaValida = 0;

  cout << endl;
  cout << "Elegir una carta del corral propio e intercambiarla por una carta del corral contrario." << endl;

  cout << "¿Que cartas desea intercambiar?" << endl;
  while (!cartaPropiaValida)
  {
    cout << "Carta propia: ";
    cin >> cartaPropia;
    if (validarNumCarta(cartaPropia))
    {
      cartaPropiaValida = 1;
    }
  }
  // accion5, si el rival bloqueó una de sus cartas pedir de elegir otra
  while (!cartaRivalValida)
  {
    cout << "Carta del rival: ";
    cin >> cartaRival;
    cout << endl;
    // si cartaRival esta bloqueada seguir preguntando, sino salir del while y seguir
    int indiceCarta = corralRival[cartaRival - 1];
    if (!vJugadores[indiceJugador].cartasBloqueadas[indiceCarta] && validarNumCarta(cartaRival))
    {
      cartaRivalValida = true;
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
  bool cartasValidas = 0;

  cout << endl;
  cout << "Intercambia dos cartas del propio corral entre si." << endl;

  cout << "¿Que cartas desea intercambiar?" << endl;
  while (!cartasValidas)
  {
    cout << "Carta propia: ";
    cin >> cartaPropia1;
    cout << "Carta propia: ";
    cin >> cartaPropia2;
    cout << endl;
    if (validarNumCarta(cartaPropia1) && validarNumCarta(cartaPropia2))
    {
      cartasValidas = 1;
    }
  }

  int aux = corralPropio[cartaPropia1 - 1];
  corralPropio[cartaPropia1 - 1] = corralPropio[cartaPropia2 - 1];
  corralPropio[cartaPropia2 - 1] = aux;
}

void accion5(int indiceJugador) // pasar el numero del jugador para poder bloquear la carta
{
  int numCartaBloquear;
  bool cartaValida = 0;

  cout << endl;
  while (!cartaValida)
  {
    cout << "Elija una carta propia para bloquear (el rival no podra elegirla para intercambiar) : ";
    cin >> numCartaBloquear;
    if (validarNumCarta(numCartaBloquear))
    {
      cartaValida = 1;
    }
  }

  vJugadores[indiceJugador].cartasBloqueadas[numCartaBloquear - 1] = 1;
}

void accion6(int indiceJugador, int indiceRival, bool &ultimaAccionJugada3)
{
  int opcion;
  bool opcionValida=0 ; 

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
      ultimaAccionJugada3 = 1;
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