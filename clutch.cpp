#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

// CREACION DEL MAZO
string cartas[20] = {"10 Corazones", "10 Picas", "10 Diamantes", "10 Trebol",
                     "J Corazones", "J Picas", "J Diamantes", "J Trebol",
                     "Q Corazones", "Q Picas", "Q Diamantes", "Q Trebol",
                     "K Corazones", "K Picas", "K Diamantes", "K Trebol",
                     "A Corazones", "A Picas", "A Diamantes", "A Trebol"};
bool cartasBloqueadas[2][20] = {0};
string vNombre[2];
int corralJugador1[5];
int corralJugador2[5];
int turnoJugador;

int tirarDado()
{
  return (1 + (rand() % 6));
}

void accion1() {}
void accion2() {}

// FUNCION ACCION 3
void accion3(int corralPropio[], int corralRival[])
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
    if (!cartasBloqueadas[indiceCarta])
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

void accion5(int numJugador) // pasar el numero del jugador para poder bloquear la carta
{
  int numCartaBloquear;

  cout << endl;
  cout << "Elija una carta para bloquear: ";
  cin >> numCartaBloquear;

  cartasBloqueadas[numJugador - 1][numCartaBloquear - 1] = 1;
}

void accion6(int numJugador)
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
      accion3(corralJugador1, corralJugador2);
      opcionValida = true;
      break;
    case 4:
      accion4(corralJugador1);
      opcionValida = true;
      break;
    case 5:
      accion5(numJugador);
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

// FUNCION PARA CREAR LAS RONDAS
void ronda(int numRonda, bool empiezaJugador1, int corralJugador1[], int corralJugador2[])
{
  // int indicePrimerJugador;
  int valorDado;

  if (empiezaJugador1)
  {
    // indicePrimerJugador = 0;
    turnoJugador = 1;
  }
  else
  {
    // indicePrimerJugador = 1;
    turnoJugador = 2;
  }

  cout << "------------------------------------------" << endl;
  cout << "CLUTCH" << endl;
  cout << "------------------------------------------" << endl;
  cout << "RONDA #" << numRonda << endl;
  cout << vNombre[0] << " vs " << vNombre[1] << endl;
  cout << "TURNO DE " << vNombre[turnoJugador - 1] << endl;
  cout << endl;

  mostrarCorral(vNombre[0], corralJugador1);
  mostrarCorral(vNombre[1], corralJugador2);

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
    accion3(corralJugador1, corralJugador2);
    break;
  case 4:
    accion4(corralJugador1);
    break;
  case 5:
    accion5(turnoJugador);
    break;
  case 6:
    accion6(turnoJugador);
    break;
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

// FUNCION PARA CREAR LOS CORRALES
void crearCorral(string jugador, bool cartasRepartidas[], int corral[])
{
  int indiceCarta;
  bool chequearRepetida = true;

  cout << "--- Corral de " << jugador << " ---" << endl;
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

// FUNCION PARA CREAR EL JUEGO
void juego()
{
  int cantidadPorCartaJ1[5] = {};
  int cantidadPorCartaJ2[5] = {};
  bool cartasRepartidas[20] = {};
  char confirmar;
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
    cin >> vNombre[0];
    cout << "Ingrese nombre 2: ";
    cin >> vNombre[1];
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

  crearCorral(vNombre[0], cartasRepartidas, corralJugador1);
  crearCorral(vNombre[1], cartasRepartidas, corralJugador2);

  // CONTAR CARTAS DE AMBOS JUGADORES
  contarCartas(corralJugador1, cantidadPorCartaJ1);
  contarCartas(corralJugador2, cantidadPorCartaJ2);

  // EVALUAR A - K - Q - J - 10 PARA VER QUIEN EMPIEZA
  empiezaJugador1 = empiezaJ1(cantidadPorCartaJ1, cantidadPorCartaJ2);
  if (empiezaJugador1)
  {
    cout << "verdaderooooooo";
  }

  // RONDAS
  int contadorRonda = 0;
  while (!hayGanador)
  {
    contadorRonda++;
    ronda(contadorRonda, empiezaJugador1, corralJugador1, corralJugador2);

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

// FUNCION PRINCIPAL
int main()
{
  srand(time(NULL));

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
      opcionValidaMenu = true;
      juego();
      break;
    case 2:
      cout << "OPCION ESTADÍSTICAS" << endl;
      opcionValidaMenu = true;
      break;
    case 3:
      cout << "OPCION CRÉDITOS" << endl;
      opcionValidaMenu = true;
      creditos();
      break;
    case 0:
      cout << "DESEA SALIR? (S/N): ";
      char op;
      cin >> op;
      if (op == 's' || op == 'S')
      {
        cout << "HA SIDO UN PLACER JUGAR CONTIGO :)";
        opcionValidaMenu = true;
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