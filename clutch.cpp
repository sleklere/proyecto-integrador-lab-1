#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./src/variablesGlobales.h"
#include "./src/opcionesMenu.cpp"
using namespace std;

string cartas[20] = {"10 Corazones", "10 Picas", "10 Diamantes", "10 Trebol",
                     "J Corazones", "J Picas", "J Diamantes", "J Trebol",
                     "Q Corazones", "Q Picas", "Q Diamantes", "Q Trebol",
                     "K Corazones", "K Picas", "K Diamantes", "K Trebol",
                     "A Corazones", "A Picas", "A Diamantes", "A Trebol"};
jugador vJugadores[2];
int turnoJugador;

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