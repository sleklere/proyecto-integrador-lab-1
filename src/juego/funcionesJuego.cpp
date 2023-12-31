#include "funcionesJuego.h"
#include <iostream>
#include "../variablesGlobales.h"
#include <string>
#include "acciones.cpp"
using namespace std;

// FUNCION PARA CREAR LAS RONDAS
void turno(int numRonda, int indiceJugador, int indiceRival, bool &hayGanador, int &indiceGanador)
{
  int valorDado;
  jugador jugadorActual = vJugadores[indiceJugador];
  jugador jugadorRival = vJugadores[indiceRival];
  bool ultimaAccionJugada3 = 0;

  log("------------------------------------------", 3);
  cout << endl;
  log("CLUTCH", 3);
  cout << endl;
  log("------------------------------------------", 3);
  cout << endl;
  cout << "RONDA #" << numRonda << endl;
  log(vJugadores[0].nombre, vJugadores[0].colorTexto);
  cout << " vs ";
  log(vJugadores[1].nombre, vJugadores[1].colorTexto);
  cout << endl;

  mostrarCorral(0);
  mostrarCorral(1);

  valorDado = tirarDado();

  cout << endl;
  log("LANZAMIENTO DADO: ", 3);
  log(to_string(valorDado), 3);
  cout << endl;

  log(" \t \t \t  TURNO DE ", jugadorActual.colorTexto);
  log(jugadorActual.nombre, jugadorActual.colorTexto);
  cout << endl;

  ///      ACCIONES     ///
  switch (valorDado)
  {
  case 1:
    accion1(indiceJugador);
    vJugadores[indiceJugador].ultimaAccion3 = 0;
    break;
  case 2:
    accion2(indiceRival);
    vJugadores[indiceJugador].ultimaAccion3 = 0;
    break;
  case 3:
    accion3(indiceRival, indiceJugador);
    vJugadores[indiceJugador].ultimaAccion3 = 1;
    break;
  case 4:
    accion4(indiceJugador);
    vJugadores[indiceJugador].ultimaAccion3 = 0;
    break;
  case 5:
    accion5(indiceJugador);
    vJugadores[indiceJugador].ultimaAccion3 = 0;
    break;
  case 6:
    accion6(indiceJugador, indiceRival);
    break;
  }

  // chequear si el jugador gano
  // VERIFICACION DE 10,J,Q,K,A DE CORRIDO

  // SOLO PARA PRUEBAS
  // vJugadores[indiceJugador].corral[0] = 0;
  // vJugadores[indiceJugador].corral[1] = 5;
  // vJugadores[indiceJugador].corral[2] = 10;
  // vJugadores[indiceJugador].corral[3] = 15;
  // vJugadores[indiceJugador].corral[4] = 19;

  int cartasValidasJugadorActual = chequearCartasValidas(indiceJugador);
  int cartasValidasJugadorRival = chequearCartasValidas(indiceRival);

  if (cartasValidasJugadorActual == 5)
  {
    hayGanador = 1;
    indiceGanador = indiceJugador;

    vJugadores[indiceRival].cartasIncorrectas = 5 - chequearCartasValidas(indiceRival);
    return;
  }
  else if (cartasValidasJugadorRival == 5)
  {
    hayGanador = 1;
    indiceGanador = indiceRival;

    vJugadores[indiceJugador].cartasIncorrectas = 5 - chequearCartasValidas(indiceJugador);
    return;
  }
}

// FUNCION PARA CREAR LOS CORRALES
void crearCorral(int corral[])
{
  int indiceCarta;
  bool chequearRepetida = true;

  for (int i = 0; i < 5; i++)
  {
    chequearRepetida = true;
    // PARA QUE NO SE REPITAN CARTAS
    indiceCarta = (rand() % 19);
    while (chequearRepetida)
    {
      if (!mazo[indiceCarta])
      {
        indiceCarta = (rand() % 19);
      }
      else
      {
        mazo[indiceCarta] = false;
        chequearRepetida = false;
      }
    }
    corral[i] = indiceCarta;
  }

  // VERIFICACION DE 10,J,Q,K,A DE CORRIDO
  if (cartas[corral[0]][0] == '1' && cartas[corral[1]][0] == 'J' && cartas[corral[2]][0] == 'Q' && cartas[corral[3]][0] == 'K' && cartas[corral[4]][0] == 'A')
  {
    crearCorral(corral);
  }
  else
  {
    return;
  }
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

// FUNCION PARA MOSTRAR CORRAL
void mostrarCorral(int indiceJugador)
{
  // MOSTRAR CORRALES

  SetConsoleTextAttribute(hConsole, vJugadores[indiceJugador].colorTexto);
  cout << "--- Corral de " << vJugadores[indiceJugador].nombre << " ---" << endl;
  SetConsoleTextAttribute(hConsole, 7);
  for (int i = 0; i < 5; i++)
  {
    // para que se muestren alineados los numeros y las cartas
    if (vJugadores[indiceJugador].corral[i] < 10)
    {
      cout << i + 1 << "    ";
    }
    else
    {
      cout << i + 1 << "    ";
    }
    cout << cartas[vJugadores[indiceJugador].corral[i]] << endl;
  }
}

int tirarDado()
{
  return (1 + (rand() % 6));
}

int chequearCartasValidas(int indiceJugador)
{
  char caracteresOrdenados[5] = {'1', 'J', 'Q', 'K', 'A'};
  int cartasValidas = 0;

  for (int i = 0; i < 5; i++)
  {
    // chequear ganador
    if (cartas[vJugadores[indiceJugador].corral[i]][0] == caracteresOrdenados[i])
    {
      cartasValidas++;
    }
  }

  return cartasValidas;
}

int calcularPuntosPartida(int indiceGanador)
{
  int puntos = 0;
  int indiceRival;
  if (indiceGanador == 0)
  {
    indiceRival = 1;
  }
  else
  {
    indiceRival = 0;
  }

  // puntos por ganar
  puntos += 15;

  // puntos si nunca paso de turno
  if (vJugadores[indiceGanador].pasoTurno == 0)
  {
    puntos += 10;
  }

  // puntos si nunca fue robado por el rival
  if (vJugadores[indiceGanador].robadoPorRival == 0)
  {
    puntos += 5;
  }

  // puntos por cada carta incorrecta del rival
  puntos += vJugadores[indiceRival].cartasIncorrectas * 5;

  // puntos si la ultima accion para ganar la partida fue la accion3
  if (vJugadores[indiceGanador].ultimaAccion3)
  {
    puntos += 5;
  }

  return puntos;
}

void mostrarPuntos(int indiceGanador, int puntosPartida)
{
  int indiceRival;
  if (indiceGanador == 0)
  {
    indiceRival = 1;
  }
  else
  {
    indiceRival = 0;
  }

  cout << endl;
  cout << "CLUTCH" << endl;
  log("---------------------------------------------------------------", 3);
  cout << endl;
  SetConsoleTextAttribute(hConsole, vJugadores[indiceGanador].colorTexto);
  cout << "HITO                                       " << vJugadores[indiceGanador].nombre << endl;
  SetConsoleTextAttribute(hConsole, 7);
  log("---------------------------------------------------------------", 3);
  cout << endl;

  // GANAR PARTIDA
  cout << "Ganar la partida                           "
       << "+15 PDV" << endl;

  // ROBO ULTIMA CARTA JUGADOR RIVAL
  if (vJugadores[indiceGanador].ultimaAccion3)
  {
    cout << "Robo ultima carta al jugador rival         "
         << "+10 PDV" << endl;
  }
  else
  {
    cout << "Robo ultima carta al jugador rival         "
         << "+0  PDV" << endl;
  }

  // CARTAS MAL UBICADAS RIVAL
  int cartasErroneas = vJugadores[indiceRival].cartasIncorrectas;
  if (cartasErroneas)
  {
    cout << "Cartas mal ubicadas del rival x " << cartasErroneas << "         "
         << "+" << cartasErroneas * 5 << " PDV" << endl;
  }
  else
  {
    cout << "Cartas mal ubicadas del rival x 0          "
         << "+0  PDV" << endl;
  }

  // SIN PASAR DE TURNO
  if (vJugadores[indiceGanador].pasoTurno == 0)
  {
    cout << "Sin pasar de turno                         "
         << "+10 PDV" << endl;
  }
  else
  {
    cout << "Sin pasar de turno                         "
         << "+0  PDV" << endl;
  }

  // Sin haber sufrido un rodo del rival
  if (vJugadores[indiceGanador].robadoPorRival == 0)
  {
    cout << "Sin haber sufrido un robo del rival        "
         << "+5  PDV" << endl;
  }
  else
  {
    cout << "Sin haber sufrido un robo del rival        "
         << "+0  PDV" << endl;
  }

  SetConsoleTextAttribute(hConsole, 5);
  cout << "TOTAL                                      " << puntosPartida << " PDV" << endl;
  SetConsoleTextAttribute(hConsole, 7);
  log("---------------------------------------------------------------", 3);
  cout << endl;
  SetConsoleTextAttribute(hConsole, vJugadores[indiceGanador].colorTexto);
  cout << "GANADOR: " << vJugadores[indiceGanador].nombre << " con " << puntosPartida << " puntos de victoria." << endl;
  SetConsoleTextAttribute(hConsole, 7);
}