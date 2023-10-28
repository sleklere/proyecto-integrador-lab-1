#include "juego.h"
#include <iostream>
#include "../variablesGlobales.h"
#include <string>
#include "acciones.cpp"
using namespace std;

int tirarDado()
{
  return (1 + (rand() % 6));
}

// FUNCION PARA CREAR LAS RONDAS
void ronda(int numRonda, int indiceJugador, int indiceRival)
{
  // int indicePrimerJugador;
  int valorDado;

  cout << "------------------------------------------" << endl;
  cout << "CLUTCH" << endl;
  cout << "------------------------------------------" << endl;
  cout << "RONDA #" << numRonda << endl;
  cout << vJugadores[0].nombre << " vs " << vJugadores[1].nombre << endl;
  cout << "TURNO DE " << vJugadores[indiceJugador].nombre << endl;
  cout << endl;

  mostrarCorral(vJugadores[0].nombre, vJugadores[0].corral);
  mostrarCorral(vJugadores[1].nombre, vJugadores[1].corral);

  valorDado = tirarDado();

  cout << endl;
  cout << "LANZAMIENTO DADO: " << valorDado << endl;

  switch (valorDado)
  {
  case 1:
    accion1();
    break;
  case 2:
    accion2();
    break;
  case 3:
    accion3(vJugadores[indiceJugador].corral, vJugadores[indiceRival].corral, indiceJugador);
    break;
  case 4:
    accion4(vJugadores[indiceJugador].corral);
    break;
  case 5:
    accion5(indiceJugador);
    break;
  case 6:
    accion6(indiceJugador, indiceRival);
    break;
  }
}

// FUNCION PARA CREAR LOS CORRALES
void crearCorral(string jugador, bool cartasRepartidas[], int corral[])
{
  int indiceCarta;
  bool chequearRepetida = true;

  for (int i = 0; i < 5; i++)
  {
    chequearRepetida = true;
    // PARA QUE NO SE REPITAN CARTAS
    indiceCarta = (rand() % 20);
    while (chequearRepetida)
    {
      if (cartasRepartidas[indiceCarta])
      {
        indiceCarta = (rand() % 20);
      }
      else
      {
        cartasRepartidas[indiceCarta] = true;
        chequearRepetida = false;
      }
    }
    //
    corral[i] = indiceCarta;
  }

  // VERIFICACION DE 10,J,Q,K,A DE CORRIDO
  if (cartas[corral[0]][0] == '1' && cartas[corral[1]][0] == 'J' && cartas[corral[2]][0] == 'Q' && cartas[corral[3]][0] == 'K' && cartas[corral[4]][0] == 'A')
  {
    crearCorral(jugador, cartasRepartidas, corral);
  }
}

// FUNCION PARA MOSTRAR CORRAL
void mostrarCorral(string jugador, int corral[])
{
  // MOSTRAR CORRALES
  cout << "--- Corral de " << jugador << " ---" << endl;
  for (int i = 0; i < 5; i++)
  {
    // para que se muestren alineados los numeros y las cartas
    if (corral[i] < 10)
    {
      cout << i + 1 << "    ";
    }
    else
    {
      cout << i + 1 << "    ";
    }
    cout << cartas[corral[i]] << endl;
  }
}

// FUNCION PARA VER SI EMPIEZA EL JUGADOR 1
bool empiezaJ1(int cantidadPorCartaJ1[], int cantidadPorCartaJ2[])
{
  for (int i = 0; i < 5; i++)
  {
    if (cantidadPorCartaJ1[i] > cantidadPorCartaJ2[i])
    {
      return true;
    }
    if (cantidadPorCartaJ2[i] > cantidadPorCartaJ1[i])
    {
      return false;
    }
  }
  return true;
}

// FUNCION PARA CONTAR CARTAS
void contarCartas(int corral[], int vectorCantidades[])
{
  for (int i = 0; i < 5; i++)
  {
    int indiceCarta = corral[i];
    char primerCaracter = cartas[indiceCarta][0];

    switch (primerCaracter)
    {
    case '1':
      vectorCantidades[4]++;
      break;
    case 'J':
      vectorCantidades[3]++;
      break;
    case 'Q':
      vectorCantidades[2]++;
      break;
    case 'K':
      vectorCantidades[1]++;
      break;
    case 'A':
      vectorCantidades[0]++;
      break;
    }
  }
  return;
}