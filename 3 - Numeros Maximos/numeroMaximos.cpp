// ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
using namespace std;
/*
ACLARACIONES
int v[]:es el vector de enteros que representara el conjunto de elementos de entrada aunque no se usen por requisitos del programa
int N: el el tamaño del vector de enteros anterior
ESPECIFICACION
PRE:{N=longitud(v) ^(Vi : 0<=i<N : v[i]!=0 && -1000000<=v[i] && v[i]<=1000000 }
proc contarMaximo(inout int maximo, inout int cont)
POS:{maximo=(max w : 0<=w<N ^ (Vz : 0<=z<N ^ z!=w : v[z]<=v[w]) : v[w]) ^ cont=(#w : : 0<=w<N ^ (Vz : 0<=z<N ^ z!=w : v[z]<=v[w]) : v[w])}

INVARIANTE= 0<=n<N ^ maximo=(max w : 0<=w<n ^ (Vz : 0<=z<n ^ z!=w : v[z]<=v[w]) : v[w]) ^ cont=(#w : : 0<=w<n ^ (Vz : 0<=z<n ^ z!=w : v[z]<=v[w]) : v[w])
FUNCION DE COTA= N-n

COSTE: es O(n), siendo n el numero de elementos de entrada, es decir el numero de puntuaciones que hay en cada caso, siendo la instruccion critica el numero de iteraciones del bucle while
*/
void contarMaximo(int& maximo, int& cont) {
    int aux;
    cin >> maximo;
    cin >> aux;
    while (aux != 0) {//coste O(n)
        if (aux == maximo) {//coste O(1)
            cont++;//coste O(1)
        }
        if (aux > maximo) {//coste O(1)
            cont = 1;//coste O(1)
            maximo = aux;//coste O(1)
        }
        cin >> aux;//coste O(1)
    }
}


void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int maximo = 0; int cont = 1;
    //Calcula el resultado

    contarMaximo(maximo, cont);

    //Escribe el resultado
    cout << maximo << " " << cont<<endl;
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