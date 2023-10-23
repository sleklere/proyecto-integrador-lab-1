#include <iostream>
using namespace std;

// CREACION DEL MAZO
string cartas[20] = {"10 Corazones", "10 Picas", "10 Diamantes", "10 Trebol",
                     "J Corazones", "J Picas", "J Diamantes", "J Trebol",
                     "Q Corazones", "Q Picas", "Q Diamantes", "Q Trebol",
                     "K Corazones", "K Picas", "K Diamantes", "K Trebol",
                     "A Corazones", "A Picas", "A Diamantes", "A Trebol"};

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

  //MOSTRAR MAZO EN PANTALLA
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

// FUNCION PARA CREAR EL JUEGO
void juego()
{
  string vNombre[2];
  int corralJugador1[5];
  int corralJugador2[5];
  bool cartasRepartidas[20] = {};
  char confirmar;
  bool nombresConfirmados = false;

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
  cout << "------------------------------------------" << endl;
  /*aca agregar función para esta parte*/

  cout << "CLUTCH" << endl;
  cout << "------------------------------------------" << endl;
  cout << "RONDA #1" << endl;
  cout << vNombre[0] << " vs " << vNombre[1] << endl;
  cout << "\n";

  /// 10 CARTAS AL AZAR

  srand(time(NULL));

  crearCorral(vNombre[0], cartasRepartidas, corralJugador1);
  crearCorral(vNombre[1], cartasRepartidas, corralJugador2);
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