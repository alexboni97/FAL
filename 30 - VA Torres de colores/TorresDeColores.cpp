// NOMBRE Y APELLIDOS: Sergio S�nchez Carrasco E53

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Se trata de un algoritmo de recursi�n que se resuelve mediante vuelta atr�s. Entonces para cada
decisi�n tenemos que saber que color escoger.

�RBOL DE EXPLORACI�N:

El �rbol de exploraci�n que he planteado es un �rbol de exploraci�n de profundidad igual a la altura de la torre,
y la rama o la anchura del �rbol es 3, ya que 3 es el n�mero de colores de las piezas y en cada altura tenemos que
ver cual de las 3 piezas colocar.

COSTE:

Como consecuencia del �rbol de exploraci�n, el coste de nuestro �rbol pertence al orden de 3^altura. O(3^altura).

RESTRICCIONES:

    EXPLICITAS:

        � Las torres contienen n>=2 piezas
        � No colocar dos piezas verdes juntas.
        � El n�mero de piezas verdes debe ser menor o igual que el de piezas azules.
        � La pieza de la base debe ser roja.
        � En la torre final, el n�mero de piezas rojas debe ser mayor que la suma de las piezas azules y verdes

    IMPLICITAS:

      � No utilizar m�s piezas que las que hay disponibles.
      � Seguir orden lexicogr�fico.

MARCADORES:

Nos ayudan a evitar utilizar funciones que aumenten el coste asint�tico de nuestro algoritmo.

    � vector<int> piezas_colores(3), vector de cuantas piezas hay disponibles para cada color de nuestra torre. Primero azul,
    Segundo rojo, Tercero verde!
    � vector<int> piezas_usadas(3, 0) vector que almacena cuantas piezas de cada tipo usamos.

*/

bool esValida(vector<int> const &solucion, int k, int color, vector<int> const &piezas_usadas) {

    if (k > 0 && solucion[k - 1] == 2 && color == 2) return false;
    if (piezas_usadas[2] > piezas_usadas[0]) return false;
    if (piezas_usadas[1] + solucion.size() - 1 - k <= piezas_usadas[0] + piezas_usadas[2]) return false;
    return true;
 }


//Por referencia porque vamos a tener que modificar los vectores.
void construir_torre(vector<int>& solucion, vector<int>& piezas_colores, vector<int> &piezas_usadas, bool &hay_solucion, int k) {
    //Uso el size por si acaso se anyadieran en un futuro nuevas piezas.
    for (int color = 0; color < piezas_colores.size(); color++)
    {
        if (piezas_colores[color]>0)//Si el numero de piezas restantes de ese color es >0. Podriamos llamar al vector piezas_restantes..
        {
            solucion[k] = color;//ponemos en la torre el color correspondiente.

            /*MARCAJE*/
            piezas_colores[color]--;//Quedan menos piezas
            piezas_usadas[color]++;

            if (esValida(solucion,k,color,piezas_usadas))
            {
                if (k == solucion.size()-1)
                {
                    //Tenemos que hacer la comp`robaci�n final
                    hay_solucion = true;
                    for (int i = 0; i < solucion.size(); i++)
                    {
                        if (solucion[i]==0)
                        {
                            cout << "azul ";
                        }
                        else if (solucion[i]==1)
                        {
                            cout << "rojo ";
                        }
                        else
                        {
                            cout << "verde ";
                        }
                    }

                    cout << endl; 


                }
                else
                {
                    construir_torre(solucion, piezas_colores, piezas_usadas, hay_solucion, k + 1);
                }
            }       
              
            /*DESMARCAJE AL MISMO NIVEL QUE EL MARCAJE*/
            piezas_colores[color]++;
            piezas_usadas[color]--;
        }
    }
}


bool resuelveCaso() {

    int altura; //Variable que guarda cu�l es la altura de la torre.

    cin >> altura;

    if (altura ==0)//Salir.
        return false;

    vector<int> piezas_colores(3);//Tendremos un vector de cuantas piezas hay para cada color de nuestra torre. Primero azul, Segundo rojo, Tercero verde!
    
    for (int i = 0; i < 3; i++)
    {
        //Leemos cuantas piezas hay para cada color
        cin >> piezas_colores[i];
    }
    
    vector<int> solucion(altura);//Vector que almacena la solucion parcial
    vector<int> piezas_usadas(3, 0);//El segundo 0 es porque inicializamos las posiciones del vector a 0.
    
    solucion[0] = 1;//Primera pieza siempre es roja
    piezas_usadas[1]++;//Hemos usado una pieza roja
    piezas_colores[1]--;//Por tanto, nos queda una pieza roja menos.
    bool hay_solucion= false; //Booleano para manejar si podemos llegar o no a una soluci�n 
    
    construir_torre(solucion, piezas_colores, piezas_usadas, hay_solucion, 1);

    if (!hay_solucion)
    {
        cout << "SIN SOLUCION\n";
    }
    cout << endl;
    
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}

