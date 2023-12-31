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
  bool cartaPropiaValida = 0;

  log("Elige una carta de tu propio corral e intercambia por una carta del mazo.", 9);
  cout << endl;
  cout << "¿Que carta desea intercambiar? : ";
  while (!cartaPropiaValida)
  {
    cout << "Carta propia: ";
    cin >> cartaPropia;
    if (validarNumCarta(cartaPropia))
    {
      cartaPropiaValida = 1;
    }
  }

  // generar una carta al azar del mazo y verificar que no haya sido repartida
  while (!cartaMazoValida)
  {
    cartaMazo = (1 + (rand() % 20)); // se genera la carta

    if (mazo[cartaMazo - 1]) // "mazo[cartaMazo - 1]" da true si la carta esta disponible
    {
      cartaMazoValida = 1;
      mazo[cartaMazo - 1] = 0;                                     // se actualiza el estado de disponibilidad de la carta
      mazo[vJugadores[indiceJugador].corral[cartaPropia - 1]] = 1; // la carta del jugador que fue intercambiada ahora esta en el mazo
    }
  }
  cout << "Carta robada del mazo :" << cartas[cartaMazo - 1] << endl;

  vJugadores[indiceJugador].cartasBloqueadas[vJugadores[indiceJugador].corral[cartaPropia - 1]] = 0; // desbloquear carta que va al mazo
  vJugadores[indiceJugador].corral[cartaPropia - 1] = cartaMazo - 1;                                 // asignar la carta robada al corral del jugador
}

void accion2(int indiceRival)
{
  int cartaRival, cartaMazo, indiceCarta;
  bool cartaMazoValida = 0;
  bool cartaRivalValida = 0;

  while (!cartaRivalValida)
  {
    log("Elige una carta del corral del rival e intercambia por una carta del mazo.", 9);
    cout << endl;
    cout << "¿Que carta desea intercambiar? : ";
    cin >> cartaRival;
    cout << endl;

    // si cartaRival esta bloqueada seguir preguntando, sino salir del while y seguir
    indiceCarta = vJugadores[indiceRival].corral[cartaRival - 1];

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
      log("Esa carta esta bloqueada! Elija otra.", 4);
      cout << endl;
    }
  }

  // generar una carta al azar del mazo y verificar que no haya sido repartida
  while (!cartaMazoValida)
  {
    cartaMazo = (1 + (rand() % 20)); // se genera la carta

    if (mazo[cartaMazo - 1]) // "mazo[cartaMazo - 1]" da true si la carta esta disponible
    {
      cartaMazoValida = 1;
      mazo[cartaMazo - 1] = 0; // se actualiza el estado de disponibilidad de la carta
      mazo[indiceCarta] = 1;   // la carta del jugador que fue intercambiada ahora esta en el mazo
    }
  }
  cout << "Carta robada del mazo :" << cartas[cartaMazo - 1] << endl;

  vJugadores[indiceRival].corral[cartaRival - 1] = cartaMazo - 1; // asignar la carta robada al corral del jugador
}

// FUNCION ACCION 3
void accion3(int indiceRival, int indiceJugador)
{
  int cartaPropia, cartaRival;
  bool cartaRivalValida = 0;
  bool cartaPropiaValida = 0;

  cout << endl;
  log("Elegir una carta del corral propio e intercambiarla por una carta del corral contrario.", 9);
  cout << endl;

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
    int indiceCarta = vJugadores[indiceRival].corral[cartaRival - 1];
    if (!vJugadores[indiceRival].cartasBloqueadas[indiceCarta] && validarNumCarta(cartaRival))
    {
      cartaRivalValida = true;
    }
    else if (!validarNumCarta(cartaRival))
    {
      log("Por favor elija una carta valida (1-5).", 9);
      cout << endl;
    }
    else if (vJugadores[indiceRival].cartasBloqueadas[indiceCarta])
    {
      log("Esa carta esta bloqueada! Elija otra.", 4);
      cout << endl;
    }
  }

  int aux = vJugadores[indiceJugador].corral[cartaPropia - 1];
  vJugadores[indiceJugador].corral[cartaPropia - 1] = vJugadores[indiceRival].corral[cartaRival - 1];
  vJugadores[indiceRival].corral[cartaRival - 1] = aux;
  vJugadores[indiceRival].robadoPorRival = 1;
  // desbloqueo carta propia por si estaba bloqueada
  vJugadores[indiceJugador].cartasBloqueadas[aux] = 0;
}

// FUNCION ACCION 4
void accion4(int indiceJugador)
{
  int cartaPropia1, cartaPropia2;
  bool cartasValidas = 0;

  cout << endl;
  log("Intercambia dos cartas del propio corral entre si.", 9);
  cout << endl;

  cout << "¿Que cartas desea intercambiar?" << endl;
  while (!cartasValidas)
  {
    cout << "Carta propia 1: ";
    cin >> cartaPropia1;
    cout << "Carta propia 2: ";
    cin >> cartaPropia2;
    cout << endl;
    if (cartaPropia1 == cartaPropia2)
    {
      log("Por favor elija cartas diferentes.", 4);
      cout << endl;
    }
    else if (validarNumCarta(cartaPropia1) && validarNumCarta(cartaPropia2))
    {
      cartasValidas = 1;
    }
    else
    {
      log("Por favor elija numeros de carta del 1 al 5.", 4);
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
    log("Elija una carta propia para bloquear (el rival no podra elegirla para intercambiar", 9);
    cout << endl;
    cin >> numCartaBloquear;
    if (validarNumCarta(numCartaBloquear) && vJugadores[indiceJugador].cartasBloqueadas[vJugadores[indiceJugador].corral[numCartaBloquear - 1]] == 0)
    {
      cartaValida = 1;
    }
    else if (!validarNumCarta(numCartaBloquear))
    {
      log("Por favor elija una carta valida (1-5).", 9);
      cout << endl;
    }
    else if (vJugadores[indiceJugador].cartasBloqueadas[vJugadores[indiceJugador].corral[numCartaBloquear - 1]])
    {
      log("Ya has bloqueado esa carta! Elija otra.", 4);
      cout << endl;
    }
  }

  int indiceCartaBloquear = vJugadores[indiceJugador].corral[numCartaBloquear - 1];

  vJugadores[indiceJugador].cartasBloqueadas[indiceCartaBloquear] = 1;
}

void accion6(int indiceJugador, int indiceRival)
{
  int opcion;
  bool opcionValida = 0;

  while (!opcionValida)
  {
    cout << endl;
    log("1- Intercambia una carta de tu corral por una del mazo.", 9);
    cout << endl;
    log("2- Intercambia una carta del corral contrario por una del mazo.", 9);
    cout << endl;
    log("3- Intercambia una carta de tu propio corral por una del rival.", 9);
    cout << endl;
    log("4- Intercambia dos cartas de tu propio corral.", 9);
    cout << endl;
    log("5- Bloquear una carta de tu propio corral. El rival no podra intercambiarla. ", 9);
    cout << endl;
    cout << "Elija cualquiera de las acciones (1 - 5), o pase el turno (0): " << endl;

    cin >> opcion;

    switch (opcion)
    {
    case 1:
      accion1(indiceJugador);
      vJugadores[indiceJugador].ultimaAccion3 = 0;
      opcionValida = true;
      break;
    case 2:
      accion2(indiceRival);
      vJugadores[indiceJugador].ultimaAccion3 = 0;
      opcionValida = true;
      break;
    case 3:
      accion3(indiceRival, indiceJugador);
      vJugadores[indiceJugador].ultimaAccion3 = 1;
      opcionValida = true;
      break;
    case 4:
      accion4(indiceJugador);
      vJugadores[indiceJugador].ultimaAccion3 = 0;
      opcionValida = true;
      break;
    case 5:
      accion5(indiceJugador);
      vJugadores[indiceJugador].ultimaAccion3 = 0;
      opcionValida = true;
      break;
    case 0:
      vJugadores[indiceJugador].pasoTurno = 1;
      vJugadores[indiceJugador].ultimaAccion3 = 0;
      opcionValida = true;
      break;
    default:
      break;
    }
  }
}