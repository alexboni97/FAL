//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void equilibrio(vector<int>v, int& p) {
    int unos = 0;
    int ceros = 0;
    size_t i = 0;
    while ( i <v.size()) {
        
        if (v[i] == 0) {
            ceros += 1;
        }
        else if (v[i] == 1) {
            unos += 1;
        }
        if (ceros == unos) p = i;
        i++;
    }

    
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    //tam =v.size()
    int tam,p=-1;
    cin >> tam;

    vector <int>v(tam);
    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    
       //Calcula el resultado
    equilibrio(v, p);
       //Escribe el resultado
    cout << p << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
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