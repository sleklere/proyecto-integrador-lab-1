#include <iostream>
#include "opcionesMenu.h"
#include "juego/juego.cpp"
using namespace std;

// FUNCION PARA CREAR EL JUEGO
void juego()
{
  int cantidadPorCartaJ1[5] = {};
  int cantidadPorCartaJ2[5] = {};
  char confirmar;
  bool cartasRepartidas[20] = {};
  bool nombresConfirmados = false;
  bool empiezaJugador1;
  bool hayGanador = false;

  // PEDIR NOMBRES
  cout << "CLUTCH" << endl
       << "------------------------------------------";
  cout << endl
       << "Antes de comenzar deben registrar sus nombres:" << endl;
  cout << endl;

  while (!nombresConfirmados)
  {
    cout << "Ingrese nombre 1: ";
    cin >> vJugadores[0].nombre;
    cout << "Ingrese nombre 2: ";
    cin >> vJugadores[1].nombre;
    cout << "Confirmar nombres (S/N)?: ";
    cin >> confirmar;
    cout << endl;
    if (confirmar == 's' || confirmar == 'S')
    {
      nombresConfirmados = true;
    }
    else
    {
      cout << "Completar nuevamente:" << endl;
    }
  }

  // EMPIEZA EL JUEGO

  /// 10 CARTAS AL AZAR

  srand(time(NULL));

  crearCorral(vJugadores[0].nombre, cartasRepartidas, vJugadores[0].corral);
  crearCorral(vJugadores[1].nombre, cartasRepartidas, vJugadores[1].corral);

  // CONTAR CARTAS DE AMBOS JUGADORES
  contarCartas(vJugadores[0].corral, cantidadPorCartaJ1);
  contarCartas(vJugadores[1].corral, cantidadPorCartaJ2);

  // EVALUAR A - K - Q - J - 10 PARA VER QUIEN EMPIEZA
  empiezaJugador1 = empiezaJ1(cantidadPorCartaJ1, cantidadPorCartaJ2);

  if (empiezaJugador1)
  {
    cout << "EMPIEZA JUGADOR 1";
    indiceJ1 = 0;
    indiceJ2 = 1;
  }
  else
  {
    indiceJ1 = 1;
    indiceJ2 = 0;
  }

  // RONDAS
  int contadorRonda = 0;
  while (!hayGanador)
  {
    contadorRonda++;
    ronda(contadorRonda, indiceJ1, indiceJ2);
    ronda(contadorRonda, indiceJ2, indiceJ1);

    if (contadorRonda == 3)
    {
      hayGanador = true;
    }
  }
}

// FUNCION CREDITOS
void creditos()
{
  cout << endl;
  cout << "------------------------" << endl;
  cout << "CREDITOS" << endl;
  cout << "------------------------" << endl;
  cout << "Miembros del equipo:" << endl;
  cout << "------------------------" << endl;
  cout << "TOMAS GARCIA , LEGAJO: 29780" << endl;
  cout << "JERONIMO BELEC , LEGAJO: 29700" << endl;
  cout << "SANTIAGO LEKLERE , LEGAJO: " << endl;
  cout << endl;
}