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
string vNombre[2];

int tirarDado()
{
  return (1 + (rand() % 6));
}

void accion1() {}
void accion2() {}
void accion3() {}
void accion4() {}
void accion5() {}
void accion6() {}

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

void ronda(int numRonda, bool empiezaJugador1, int corralJugador1[], int corralJugador2[])
{
  int indicePrimerJugador;
  int valorDado;

  if (empiezaJugador1)
  {
    indicePrimerJugador = 0;
  }
  else
  {
    indicePrimerJugador = 1;
  }

  cout << "------------------------------------------" << endl;
  cout << "CLUTCH" << endl;
  cout << "------------------------------------------" << endl;
  cout << "RONDA #" << numRonda << endl;
  cout << vNombre[0] << " vs " << vNombre[1] << endl;
  cout << "TURNO DE " << vNombre[indicePrimerJugador] << endl;
  cout << endl;

  mostrarCorral(vNombre[0], corralJugador1);
  mostrarCorral(vNombre[1], corralJugador2);

  valorDado = tirarDado();

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
    accion3();
    break;
  case 4:
    accion4();
    break;
  case 5:
    accion5();
    break;
  case 6:
    accion6();
    break;
  }
}

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
  int corralJugador1[5];
  int corralJugador2[5];
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
  // EVALUAR A - K - Q - J - 10
  if (cantidadPorCartaJ1[0] > cantidadPorCartaJ2[0])
  {
    // empieza jugador 1
    empiezaJugador1 = true;
  }
  else if (cantidadPorCartaJ2[0] > cantidadPorCartaJ1[0])
  {
    // empieza jugador 2
    empiezaJugador1 = false;
  }
  else
  {
    if (cantidadPorCartaJ1[1] > cantidadPorCartaJ2[1])
    {
      empiezaJugador1 = true;
    }
    else if (cantidadPorCartaJ2[1] > cantidadPorCartaJ1[1])
    {
      empiezaJugador1 = false;
    }
    else
    {
      if (cantidadPorCartaJ1[2] > cantidadPorCartaJ2[2])
      {
        empiezaJugador1 = true;
      }
      else if (cantidadPorCartaJ2[2] > cantidadPorCartaJ1[2])
      {
        empiezaJugador1 = false;
      }
      else
      {
        if (cantidadPorCartaJ1[3] > cantidadPorCartaJ2[3])
        {
          empiezaJugador1 = true;
        }
        else if (cantidadPorCartaJ2[3] > cantidadPorCartaJ1[3])
        {
          empiezaJugador1 = false;
        }
        else
        {
          if (cantidadPorCartaJ1[4] > cantidadPorCartaJ2[4])
          {
            empiezaJugador1 = true;
          }
          else if (cantidadPorCartaJ2[4] > cantidadPorCartaJ1[4])
          {
            empiezaJugador1 = false;
          }
        }
      }
    }
  }

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