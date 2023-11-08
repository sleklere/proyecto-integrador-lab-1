#include <iostream>
#include "acciones.h"
#include "../variablesGlobales.h"
using namespace std;

bool validarNumCarta(int numCarta)
{
  if (numCarta < 6 && numCarta > 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void accion1(int indiceJugador)
{
  int cartaPropia, cartaMazo;
  bool cartaMazoValida = 0;

  cout << "Elige una carta de tu propio corral e intercambia por una carta del mazo." << endl;
  cout << "¿Que carta desea intercambiar? : " << endl;
  cin >> cartaPropia;

  // generar una carta al azar del mazo y verificar que no haya sido repartida
  while (!cartaMazoValida)
  {
    cartaMazo = (1 + (rand() % 20)); // se genera la carta

    if (mazo[cartaMazo - 1]) // "mazo[cartaMazo - 1]" da true si la carta esta disponible
    {
      cartaMazoValida = 1;
      mazo[cartaMazo - 1] = 0;   // se actualiza el estado de disponibilidad de la carta
      mazo[cartaPropia - 1] = 1; // la carta del jugador que fue intercambiada ahora esta en el mazo
    }
  }
  cout << "Carta robada del mazo :" << cartas[cartaMazo - 1] << endl;

  vJugadores[indiceJugador].corral[cartaPropia - 1] = cartaMazo - 1; // asignar la carta robada al corral del jugador
}

void accion2(int indiceRival)
{
  int cartaRival, cartaMazo;
  bool cartaMazoValida = 0;

  cout << "Elige una carta del corral del rival e intercambia por una carta del mazo." << endl;
  cout << "¿Que carta desea intercambiar? : " << endl;
  cin >> cartaRival;

  // generar una carta al azar del mazo y verificar que no haya sido repartida
  while (!cartaMazoValida)
  {
    cartaMazo = (1 + (rand() % 20)); // se genera la carta

    if (mazo[cartaMazo - 1]) // "mazo[cartaMazo - 1]" da true si la carta esta disponible
    {
      cartaMazoValida = 1;
      mazo[cartaMazo - 1] = 0;  // se actualiza el estado de disponibilidad de la carta
      mazo[cartaRival - 1] = 1; // la carta del jugador que fue intercambiada ahora esta en el mazo
    }
  }
  cout << "Carta robada del mazo :" << cartas[cartaMazo - 1] << endl;

  vJugadores[indiceRival].corral[cartaRival - 1] = cartaMazo - 1; // asignar la carta robada al corral del jugador
}

// FUNCION ACCION 3
void accion3(int corralPropio[], int corralRival[], int indiceRival, int indiceJugador)
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
    cout << "INDICE CARTA: " << indiceCarta << endl;
    cout << "ESTADO BLOQUEADA" << vJugadores[indiceRival].cartasBloqueadas[indiceCarta] << endl;
    if (!vJugadores[indiceRival].cartasBloqueadas[indiceCarta] && validarNumCarta(cartaRival))
    {
      cartaRivalValida = true;
    }
    else if (!validarNumCarta(cartaRival))
    {
      cout << "Por favor elija una carta valida (1-5)." << endl;
    }
    else if (vJugadores[indiceRival].cartasBloqueadas[indiceCarta])
    {
      cout << "Esa carta esta bloqueada! Elija otra." << endl;
    }
  }

  cout << "CARTA PROPIA VIEJA: " << corralPropio[cartaPropia - 1] << endl;
  cout << "CARTA RIVAL VIEJA: " << corralRival[cartaRival - 1] << endl;
  int aux = vJugadores[indiceJugador].corral[cartaPropia - 1];
  vJugadores[indiceJugador].corral[cartaPropia - 1] = vJugadores[indiceRival].corral[cartaRival - 1];
  vJugadores[indiceRival].corral[cartaRival - 1] = aux;
  cout << "CARTA PROPIA NUEVA: " << corralPropio[cartaPropia - 1] << endl;
  cout << "CARTA RIVAL NUEVA: " << corralRival[cartaRival - 1] << endl;
}

// FUNCION ACCION 4
void accion4(int indiceJugador)
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

  int aux = vJugadores[indiceJugador].corral[cartaPropia1 - 1];
  vJugadores[indiceJugador].corral[cartaPropia1 - 1] = vJugadores[indiceJugador].corral[cartaPropia2 - 1];
  vJugadores[indiceJugador].corral[cartaPropia2 - 1] = aux;
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

  int indiceCartaBloquear = vJugadores[indiceJugador].corral[numCartaBloquear - 1];

  vJugadores[indiceJugador].cartasBloqueadas[indiceCartaBloquear] = 1;
}

void accion6(int indiceJugador, int indiceRival, bool &ultimaAccionJugada3)
{
  int opcion;
  bool opcionValida = 0;

  while (!opcionValida)
  {
    cout << endl;
    cout << "Elija cualquiera de las acciones (1 - 5), o pase el turno (0): ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      accion1(indiceJugador);
      opcionValida = true;
      break;
    case 2:
      accion2(indiceRival);
      opcionValida = true;
      break;
    case 3:
      accion3(vJugadores[indiceJugador].corral, vJugadores[indiceRival].corral, indiceRival, indiceJugador);
      opcionValida = true;
      ultimaAccionJugada3 = 1;
      break;
    case 4:
      accion4(indiceJugador);
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