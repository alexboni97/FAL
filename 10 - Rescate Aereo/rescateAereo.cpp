//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int>posIntervalo(vector<int>&v,const int &N) {
    pair<int, int>posiciones;
    
    int pI = 0, pF = 0;
    int n = 0; int r = 0; int s = 0;
    while (n != N) {
        if (v[n] != 1) {
            s = n + 1;
        }
        if (r < (n + 1 - s)) {
            pI = n - r;
            pF = n;
        }
            r = max(r,(n + 1 - s));
        n = n + 1;
    }
    posiciones = { pI,pF };

    return posiciones;
}

void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos
    int n, t;//n numero de edificios; t altura del transporte
    int x;
    cin >> n >> t;
    vector<int>v(n);
    pair<int, int>sol;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > t) {
            v[i] = 1;
        }
        else v[i] = 0;
    }
    //Calcula el resultado
    sol = posIntervalo(v, n);
    //Escribe el resultado
    cout << sol.first << " " << sol.second << endl;
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