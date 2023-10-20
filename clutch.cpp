#include <iostream>
using namespace std;

// FUNCION PARA PEDIR NOMBRES
void names()
{
  string nameP1, nameP2;
  char confirm;

  cout << endl;
  cout << "¿Nombre Jugador 1? ";
  cin >> nameP1;
  cout << "¿Nombre Jugador 2? ";
  cin >> nameP2;
  cout << endl;
  cout << "¿Confirmar nombres? (S/N) ";
  cin >> confirm;

  switch (confirm)
  {
  case 'S':
    cout << "COMIENZA EL JUEGO";
    break;
  case 'N':
    names();
    break;
  default:
    cout << "Opcion no valida";
    cout << endl;
    names();
  }
}

// FUNCION JUEGO
void game()
{
  cout << endl;
  cout << "CLUTCH" << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Antes de comenzar deben registrar sus nombres:" << endl;

  names();
}

// FUNCION CREDITOS
void credits()
{
  cout << endl;
  cout << "------------------------" << endl;
  cout << "CREDITOS" << endl;
  cout << "------------------------" << endl;
  cout << endl;
  cout << "Miembros del equipo:" << endl;
  cout << endl;
  cout << "Apellido y nombre: Leklere, Santiago" << endl;
  cout << "Nro de legajo: " << endl;
  cout << endl;
  cout << "Apellido y nombre: Belec, Jeronimo" << endl;
  cout << "Nro de legajo: 29700" << endl;
}

// FUNCION PRINCIPAL
int main()
{
  // VARIABLES GLOBALES
  int menuOption;
  bool menuOptionValid = false;

  // PANTALLA PRINCIPAL
  cout << "CLUTCH" << endl;
  cout << "------------------------" << endl;
  cout << "1 - JUGAR" << endl;
  cout << "2 - ESTADÍSTICAS" << endl;
  cout << "3 - CRÉDITOS" << endl;
  cout << "------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "------------------------" << endl;

  while (!menuOptionValid)
  {
    cout << "OPCIÓN: ";
    cin >> menuOption;

    switch (menuOption)
    {
    case 1:
      cout << "OPCIÓN JUGAR" << endl;
      menuOptionValid = true;
      game();
      break;
    case 2:
      cout << "OPCIÓN ESTADÍSTICAS" << endl;
      menuOptionValid = true;
      break;
    case 3:
      cout << "OPCIÓN CRÉDITOS" << endl;
      menuOptionValid = true;
      credits();
      break;
    case 0:
      cout << "OPCIÓN SALIR" << endl;
      return 0;
      menuOptionValid = true;
      break;
    default:
      cout << "+--------------------+" << endl;
      cout << "| OPCIÓN INVÁLIDA! |" << endl;
      cout << "+--------------------+" << endl;
      break;
    }
  }

  // cout << "OPCION VALIDA" << endl;

  return 0;
}