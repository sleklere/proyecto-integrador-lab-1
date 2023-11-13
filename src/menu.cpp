#include <iostream>
#include <windows.h>
#include "menu.h"
#include "juego/funcionesJuego.cpp"
using namespace std;

int menu()
{
  int opcionMenu;
  bool opcionValidaMenu = false;

  // PANTALLA PRINCIPAL
  cout << endl;
  cout << "CLUTCH" << endl;
  log("------------------------", 3);
  cout << endl;
  cout << "1 - JUGAR" << endl;
  cout << "2 - ESTADISTICAS" << endl;
  cout << "3 - CREDITOS" << endl;
  log("------------------------", 3);
  cout << endl;
  cout << "0 - SALIR" << endl;
  log("------------------------", 3);
  cout << endl;

  while (!opcionValidaMenu)
  {
    cout << "ELIJA UNA OPCION: ";
    cin >> opcionMenu;
    cout << endl;
    switch (opcionMenu)
    {
    case 1:
      cout << "\t BUENA ELECCION, HORA DE DIVERTIRSE!" << endl;
      opcionValidaMenu = 1;
      juego();
      break;
    case 2:
      cout << "OPCION ESTADÍSTICAS" << endl;
      opcionValidaMenu = 1;
      break;
    case 3:
      cout << "OPCION CRÉDITOS" << endl;
      opcionValidaMenu = 1;
      creditos();
      break;
    case 0:
      cout << "DESEA SALIR? (S/N): ";
      char op;
      cin >> op;
      if (op == 's' || op == 'S')
      {
        cout << "HA SIDO UN PLACER JUGAR CONTIGO :)";
        opcionValidaMenu = 1;
        return 0;
      }
      else
      {
        break;
      };
    default:
      cout << "+--------------------+" << endl;
      cout << "| OPCION INVÁLIDA! |" << endl;
      cout << "+--------------------+" << endl;
      break;
    }
  }

  return 0;
}

// FUNCION PARA CREAR EL JUEGO
void juego()
{
  int cantidadPorCartaJ1[5] = {};
  int cantidadPorCartaJ2[5] = {};
  int puntosPartida = 0;
  int indiceGanador;
  char confirmar;
  bool nombresConfirmados = false;
  bool empiezaJugador1;
  bool hayGanador = false;

  // SE INICIALIZA EL MAZO
  for (int i = 0; i < 20; i++)
  {
    mazo[i] = 1;
  }

  log("---------------------------------", 3);
  cout << endl;
  cout << "CLUTCH" << endl;
  log("---------------------------------", 3);
  cout << endl;

  if (primerPartida)
  {
    // PEDIR NOMBRES
    cout
        << "Antes de comenzar deben registrar sus nombres por favor:" << endl;
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
        nombresConfirmados = 1;
      }
      else
      {
        log("Seleccione opcion valida (S/N)", 4);
        cout << endl;
      }
    }
    primerPartida = 0;
    vJugadores[0].colorTexto = 6;  // letra amarilla
    vJugadores[1].colorTexto = 10; // letra verde
  }
  else
  {
    // re-inicializar cartasBloqueadas, pasoTurno, etc. para ambos jugadores
    for (int j = 0; j < 2; j++)
    {
      vJugadores[j].pasoTurno = 0;
      vJugadores[j].ultimaAccion3 = 0;
      vJugadores[j].robadoPorRival = 0;
      vJugadores[j].cartasIncorrectas = 0;
      for (int i = 0; i < 5; i++)
      {
        vJugadores[j].corral[i] = 0;
      }
      for (int i = 0; i < 20; i++)
      {
        vJugadores[j].cartasBloqueadas[i] = 0;
      }
    }
    for (int i = 0; i < 20; i++)
    {
      mazo[i] = 1;
    }
  }

  // EMPIEZA EL JUEGO
  srand(time(NULL));

  // 10 CARTAS AL AZAR
  crearCorral(vJugadores[0].corral);
  crearCorral(vJugadores[1].corral);

  // CONTAR CARTAS DE AMBOS JUGADORES
  contarCartas(vJugadores[0].corral, cantidadPorCartaJ1);
  contarCartas(vJugadores[1].corral, cantidadPorCartaJ2);

  // EVALUAR A - K - Q - J - 10 PARA VER QUIEN EMPIEZA
  empiezaJugador1 = empiezaJ1(cantidadPorCartaJ1, cantidadPorCartaJ2);

  if (empiezaJugador1)
  {
    indiceJugador = 0;
    indiceRival = 1;
  }
  else
  {
    indiceJugador = 1;
    indiceRival = 0;
  }

  // RONDAS
  int contadorRonda = 0;
  while (!hayGanador)
  {
    contadorRonda++;
    turno(contadorRonda, indiceJugador, indiceRival, hayGanador, indiceGanador);
    if (!hayGanador)
    {
      turno(contadorRonda, indiceRival, indiceJugador, hayGanador, indiceGanador);
    }
  }

  puntosPartida = calcularPuntosPartida(indiceGanador);
  vJugadores[indiceGanador].puntosTotales += puntosPartida;

  // mostrar cartas
  mostrarCorral(indiceGanador);
  mostrarCorral(!indiceGanador);
  // mostrar puntos
  mostrarPuntos(indiceGanador, puntosPartida);

  // preguntar si jugar de nuevo o salir al menu
  char respuesta;
  bool jugarDeNuevo = 0;
  bool respuestaValida = 0;

  log("------------------------", 3);
  cout << endl;
  cout << "Desea jugar de nuevo? (S/N) : " << endl;
  log("------------------------", 3);
  cout << endl;
  cin >> respuesta;
  while (!respuestaValida)
  {
    switch (respuesta)
    {
    case 'S':
      jugarDeNuevo = 1;
      respuestaValida = 1;
      break;
    case 's':
      jugarDeNuevo = 1;
      respuestaValida = 1;
      break;
    case 'N':
      jugarDeNuevo = 0;
      respuestaValida = 1;
      break;
    case 'n':
      jugarDeNuevo = 0;
      respuestaValida = 1;
      break;
    default:
      break;
    }
  }

  if (jugarDeNuevo)
  {
    juego();
  }
  else
  {
    menu();
  }
}

// FUNCION CREDITOS
void creditos()
{
  int input;
  cout << endl;
  log("------------------------", 3);
  cout << endl;
  cout << " CREDITOS " << endl;
  log("------------------------", 3);
  cout << endl;
  cout << "Miembros del equipo:" << endl;
  log("------------------------", 3);
  cout << endl;
  cout << "TOMAS GARCIA , LEGAJO: 29780" << endl;
  cout << "JERONIMO BELEC , LEGAJO: 29700" << endl;
  cout << "SANTIAGO LEKLERE , LEGAJO: 29816" << endl;
  cout << endl;
  log("Presione -ENTER- para volver al menu principal: ", 10);
  input = getch();
  if (input == 13)
  {
    menu();
    system("cls");
  }
  else
  {
    creditos();
  }
}

void estadisticas() {}