// ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
using namespace std;

void contarMaximo(int& numMax, int& cont) {
    int aux;
    cin >> numMax;
    cin >> aux;
    while (aux != 0) {
        if (aux == numMax) {
            cont++;
        }
        if (aux > numMax) {
            cont = 1;
            numMax = aux;
        }
        cin >> aux;
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