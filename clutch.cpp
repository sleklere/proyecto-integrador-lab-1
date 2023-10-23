#include <iostream>
using namespace std;

string cartas[20] = {"10 Corazones", "10 Picas", "10 Diamantes", "10 Trebol",
                     "J Corazones",  "J Picas",  "J Diamantes",  "J Trebol",
                     "Q Corazones",  "Q Picas",  "Q Diamantes",  "Q Trebol",
                     "K Corazones",  "K Picas",  "K Diamantes",  "K Trebol",
                     "A Corazones",  "A Picas",  "A Diamantes",  "A Trebol"};

// FUNCION PARA PEDIR NOMBRES
void names() {
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

  switch (confirm) {
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

void crearCorral(string jugador, bool cartasRepartidas[], int corral[]) {
  int indiceCarta;
  bool chequearRepetida = true;

  cout << "--- Corral de " << jugador << " ---" << endl;
  for (int i = 0; i < 5; i++) {
    chequearRepetida = true;
    // PARA QUE NO SE REPITAN CARTAS
    indiceCarta = (1 + rand() % 20);
    while (chequearRepetida) {
      if (cartasRepartidas[indiceCarta]) {
        indiceCarta = (1 + rand() % 20);
      } else {
        cartasRepartidas[indiceCarta] = true;
        chequearRepetida = false;
      }
    }
    //
    corral[i] = indiceCarta;
    // para que se muestren alineados los numeros y las cartas
    if (corral[i] < 10) {
      cout << corral[i] << "    ";
    } else {
      cout << corral[i] << "   ";
    }
    cout << cartas[corral[i] - 1] << endl;
  }
}

void game() {
  string vNombre[2];
  int corralJugador1[5];
  int corralJugador2[5];
  bool cartasRepartidas[20] = {};
  char confirmar;
  bool nombresConfirmados = false;

  cout << "CLUTCH" << endl << "------------------------------------------";
  cout << endl << "Antes de comenzar deben registrar sus nombres:" << endl;

  while (!nombresConfirmados) {
    cout << "Ingrese nombre 1: ";
    cin >> vNombre[0];
    cout << "Ingrese nombre 2: ";
    cin >> vNombre[1];
    cout << "Confirmar nombres (S/N)?: ";
    cin >> confirmar;
    if (confirmar == 's' || confirmar == 'S') {
      cout << "confirmado" << endl;
      nombresConfirmados = true;
    } else {
      cout << "no confirmado" << endl;
    }
  }

  cout << "------------------------------------------" << endl;
  /*aca agregar función para esta parte*/

  cout << "CLUTCH" << endl;
  cout << "------------------------------------------" << endl;
  cout << "RONDA #1" << endl;
  cout << vNombre[0] << " vs " << vNombre[1] << endl;
  cout << "\n";

  /// 10 CARTAS AL AZAR ///

  srand(time(NULL));

  crearCorral(vNombre[0], cartasRepartidas, corralJugador1);
  crearCorral(vNombre[1], cartasRepartidas, corralJugador2);
}

// FUNCION CREDITOS
void credits() {
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

int main() {
  int menuOption;
  bool menuOptionValid = false;

  // PANTALLA PRINCIPAL
  cout << "CLUTCH" << endl;
  cout << "------------------------" << endl;
  cout << "1 - JUGAR" << endl;
  cout << "2 - ESTADISTICAS" << endl;
  cout << "3 - CREDITOS" << endl;
  cout << "------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "------------------------" << endl;

  while (!menuOptionValid) {
    cout << "ELIJA UNA OPCION: ";
    cin >> menuOption;

    switch (menuOption) {
    case 1:
      cout << "OPCION JUGAR" << endl;
      menuOptionValid = true;
      game();
      break;
    case 2:
      cout << "OPCION ESTADÍSTICAS" << endl;
      menuOptionValid = true;
      break;
    case 3:
      cout << "OPCION CRÉDITOS" << endl;
      menuOptionValid = true;
      credits();
      break;
    case 0:
      cout << "DESEA SALIR? (S/N): ";
      char op;
      cin >> op;
      if (op == 's' || op == 'S') {
        cout << "HA SIDO UN PLACER JUGAR CONTIGO :)";
        menuOptionValid = true;
        return 0;
      } else {
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