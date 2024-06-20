//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



int suma(std::vector<int>& v, int ini, int fin) {
    int sol = 0;
    for (int i = ini; i < fin; i = i + 1) {
        sol = sol + v[i];
    }
    return sol;
}

bool resolver(std::vector<int>& v, int ini, int fin) {
    if (ini + 1 == fin) {
        return true;
    }
    else {
        int medio = (ini + fin) / 2;
        if (suma(v, ini, medio) < suma(v, medio, fin)) {
            return resolver(v, ini, medio) && resolver(v, medio, fin);
        }
        else {
            return false;
        }
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) {
        return false;
    }
    else {
        int m;
        std::cin >> m;
        std::vector<int> v(m);
        bool solucion = true;
        for (int i = 0; i < n; i = i + 1) {
            for (int j = 0; j < m; j = j + 1) {
                std::cin >> v[j];
            }
            bool sol = resolver(v, 0, m);
            if (!sol) {
                solucion = false;
            }
        }
        if (solucion) {
            std::cout << "SI\n";
        }
        else {
            std::cout << "NO\n";
        }
        return true;
    }
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}