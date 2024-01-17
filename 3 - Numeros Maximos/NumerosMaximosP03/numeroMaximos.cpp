// ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
using namespace std;
/*
ACLARACIONES:
n= numero de puntuaciones y tamaño del vector v
v= vector que representas las puntuaciones aunque no se use para almacenar los valores de entrada.

ESPECIFICACION:
PRE {Vp: 0<=p<n:v[p]!=0 ^ v[p] <= 1000000 ^ n>0}
fun contarMaximo()   dev int numMax, cont
POS {numMax=max i:0<=i<n:v[i]^cont= #j:0<=j<n:v[j]=numMax}
*/

//funcion que resuelve el problema 
/*la funcion de coste es O(n), donde n es el numero de puntuaciones para cada caso de prueba, ya que la instruccion critica del programa se ejecuta n veces*/
void contarMaximo(int& numMax, int& cont) {
    int aux;
    cin >> numMax;
    cin >> aux;
    while (aux != 0) {//coste O(n)
        if (aux == numMax) {//coste O(1)
            cont++;//coste O(1)
        }
        if (aux > numMax) {//coste O(1)
            cont = 1;//coste O(1)
            numMax = aux;//coste O(1)
        }
        cin >> aux;//coste O(1)
    }
}


void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int numMax = 0; int cont = 1;
    //Calcula el resultado
    contarMaximo(numMax, cont);
    //Escribe el resultado
    cout << numMax << " " << cont<<endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}