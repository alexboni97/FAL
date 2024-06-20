// NOMBRE Y APELLIDOS: Sergio Sánchez Carrasco E53

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Se trata de un algoritmo de recursión que se resuelve mediante vuelta atrás. Entonces para cada
decisión tenemos que saber que color escoger.

ÁRBOL DE EXPLORACIÓN:

El árbol de exploración que he planteado es un árbol de exploración de profundidad igual a la altura de la torre,
y la rama o la anchura del árbol es 3, ya que 3 es el número de colores de las piezas y en cada altura tenemos que
ver cual de las 3 piezas colocar.

COSTE:

Como consecuencia del árbol de exploración, el coste de nuestro árbol pertence al orden de 3^altura. O(3^altura).

RESTRICCIONES:

    EXPLICITAS:

        º Las torres contienen n>=2 piezas
        º No colocar dos piezas verdes juntas.
        º El número de piezas verdes debe ser menor o igual que el de piezas azules.
        º La pieza de la base debe ser roja.
        º En la torre final, el número de piezas rojas debe ser mayor que la suma de las piezas azules y verdes

    IMPLICITAS:

      º No utilizar más piezas que las que hay disponibles.
      º Seguir orden lexicográfico.

MARCADORES:

Nos ayudan a evitar utilizar funciones que aumenten el coste asintótico de nuestro algoritmo.

    º vector<int> piezas_colores(3), vector de cuantas piezas hay disponibles para cada color de nuestra torre. Primero azul,
    Segundo rojo, Tercero verde!
    º vector<int> piezas_usadas(3, 0) vector que almacena cuantas piezas de cada tipo usamos.

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
                    //Tenemos que hacer la comp`robación final
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

    int altura; //Variable que guarda cuál es la altura de la torre.

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
    bool hay_solucion= false; //Booleano para manejar si podemos llegar o no a una solución 
    
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

