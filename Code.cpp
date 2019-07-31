#include <iostream>
#include <cmath>

using namespace std;

class Resolucion{

  private:

    int *puntos;
    int tam = 0;
    int maximo = 0;
    int aumento = 0;

  public:

    Resolucion(int maximo, int aumento){

      this->maximo = maximo;
      this->aumento = aumento;

      tam = maximo / (aumento + 1);
      puntos = new int [tam + 1];

      if(maximo % (aumento + 1) == 0){

        puntos[0] = aumento + 1;

      }else{

        puntos[0] = maximo % (aumento + 1);

      }

      for(int i = 1; i < tam; i++){

        puntos[i] = puntos[0] + i * (aumento + 1);

      }

      puntos[tam] = maximo;

      tam ++;

    }

    void LeerPuntos(){

      for(int i = 0; i < tam; i++){

        cout << puntos[i] << " ";

      }

    }

    int Aniadir(int principal){

      bool encontrado = false;
      int devolver = 0;
      int aux = 0;

      for(int i = 0; i < tam; i++){

        if(puntos[i] == principal){

          encontrado = true;

        }

      }

      if(encontrado == true && puntos[tam - 1] != principal){

        devolver = 1;

      }else if(puntos[tam - 1] != principal){

        while(puntos[aux] - principal < 0){

          aux ++;

        }

        devolver = puntos[aux] - principal;
        aux = 0;


      }else{

        devolver = 0;

      }

      return devolver;

    }

    ~Resolucion(){

      delete[] puntos ;

    }

};

int main(){

  int max = 0;
  int cantidad = 0;
  bool fin = false;
  int suma = 0;
  int cantidad2 = 0;
  bool ganador = false;

  cout << endl << "REGLAS DEL JUEGO: ";
  cout << endl << "1.- Se define un numero hasta el que se desea contar.";
  cout << endl << "2.- Se define cual va ser el maximo de unidades que se pueden aumentar por turno.";
  cout << endl << "3.- Se empieza a aumentar la cantidad desde el 1 hasta la cifra definida.";
  cout << endl << "4.- La persona que llegue al numero definido en el paso 1 sera el ganador.";

  cout << endl << endl << "Introduzca la cifra hasta la que desea contar: ";
  cin >> max;

  while(max < 1){

    cout << endl << "Cifra incorrecta, introduzca un nuevo valor: ";
    cin >> max;

  }

  cout << endl << "Introduzca la cantidad de cifras que puede aumentar en un turno: ";
  cin >> cantidad;

  while(cantidad < 1 || cantidad > max){

    cout << endl << "Cantidad incorrecta, introduzca un nuevo valor: ";
    cin >> cantidad;

  }

  Resolucion r1(max, cantidad);

  while(fin == false){

    cout << endl << endl << "Introduzca la cantidad de unidades que desea aumentar: ";
    cin >> cantidad2;

    while(cantidad2 < 1 || cantidad2 > cantidad){

      cout << endl << "Cantidad incorrecta, introduzca un nuevo valor: ";
      cin >> cantidad2;

    }

    suma += cantidad2;

    cout << "CANTIDAD: " << suma;

    cout << endl << "La maquina aniade " << r1.Aniadir(suma) << " unidades.";

    if(r1.Aniadir(suma) == 0){

      ganador = true;

    }else{

      ganador = false;

    }


    suma += r1.Aniadir(suma);

    cout << endl << "CANTIDAD: " << suma;

    if(suma == max){

      fin = true;

    }

  }

  cout << endl << endl << "****************************************************************************************";

  if(ganador == true){

    cout << endl << "ENHORABUENA, HAS GANADO" << endl;

  }else{

    cout << endl << "GANA LA MAQUINA, LA PROXIMA VEZ SERA" << endl;

  }

    cout << "****************************************************************************************" << endl << endl;

}
