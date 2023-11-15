
//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int segmentosCerosUnos(vector<int>v, const int& N, const int& L) {
    int c1 = 0, c0 = 0, s = 1, p = L, pI = 0;;
    while (p < N) {
        if (v[p] == 0) {
            c0++;
        }
        if (v[p] == 1) {
            c1++;
        }
        if (v[pI] == 0) {
            c0--;
        }
        if (v[pI] == 1) {
            c1--;
        }
        if (c0 == c1) {
            s++;
        }
        pI++;
        p++;
    }

    return s;
}
void resuelveCaso() {
    int n, l;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> l >>n;
    vector<int>v(n);

        
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
        //Calcula el resultado
        //Escribe el resultado
    cout << segmentosCerosUnos(v, n,l) << endl;
    /*
        if (n == 0)cout << 0 << endl;
    else {
    }
    */

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