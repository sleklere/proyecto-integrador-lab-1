#include <iostream>
using namespace std;

int main() {
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

  while (!menuOptionValid) {
    cout << "OPCIÓN: ";
    cin >> menuOption;

    switch (menuOption) {
    case 1:
      cout << "OPCIÓN JUGAR" << endl;
      menuOptionValid = true;
      break;
    case 2:
      cout << "OPCIÓN ESTADÍSTICAS" << endl;
      menuOptionValid = true;
      break;
    case 3:
      cout << "OPCIÓN CRÉDITOS" << endl;
      menuOptionValid = true;
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

  cout << "OPCION VALIDA" << endl;

  return 0;
}