#include <iostream>
#include "opcionesMenu.h"
#include "juego/juego.cpp"
using namespace std;

void mostrarPuntos()
{
  //
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

int menu()
{
  int opcionMenu;
  bool opcionValidaMenu = false;

  // PANTALLA PRINCIPAL
  cout << "CLUTCH" << endl;
  cout << "------------------------" << endl;
  cout << "1 - JUGAR" << endl;
  cout << "2 - ESTADISTICAS" << endl;
  cout << "3 - CREDITOS" << endl;
  cout << "------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "------------------------" << endl;

  while (!opcionValidaMenu)
  {
    cout << "ELIJA UNA OPCION: ";
    cin >> opcionMenu;

    switch (opcionMenu)
    {
    case 1:
      cout << "OPCION JUGAR" << endl;
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

  if (primerPartida)
  {
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
        cout << "Completar nuevamente:" << endl;
      }
    }
    primerPartida = 0;
  }
  else
  {
    // re-inicializar cartasBloqueadas y pasoTurno para ambos jugadores
    for (int j = 0; j < 2; j++)
    {
      vJugadores[j].pasoTurno = 0;
      vJugadores[j].ultimaAccion3 = 0;
      vJugadores[j].robadoPorRival = 0;
      vJugadores[j].cartasIncorrectas = 0;
      for (int i = 0; i < 20; i++)
      {
        vJugadores[j].cartasBloqueadas[i] = 0;
      }
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
    ronda(contadorRonda, indiceJ1, indiceJ2, hayGanador, indiceGanador);
    if (!hayGanador)
    {
      ronda(contadorRonda, indiceJ2, indiceJ1, hayGanador, indiceGanador);
    }
  }
  cout << "AFUERA DEL WHILE" << endl;

  puntosPartida = calcularPuntosPartida(indiceGanador);

  vJugadores[indiceGanador].puntosTotales += puntosPartida;
  // mostrar cartas
  mostrarCorral(indiceGanador);
  // mostrar puntos
  mostrarPuntos();

  // preguntar si jugar de nuevo o salir al menu
  char respuesta;
  bool jugarDeNuevo = 0;
  bool respuestaValida = 0;

  cout << "------------------------" << endl;
  cout << "Desea jugar de nuevo?(S/N): ";
  cout << "------------------------" << endl;
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