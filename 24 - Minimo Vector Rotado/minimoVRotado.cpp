//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int minimo(vector<int>const& v, int i, int j) {
    int m, d;
    if (j == i)m = v[i];
    else {
        d = (i + j) / 2;
        m = min(minimo(v, i, d), minimo(v, d + 1, j));
    }
    return m;
}
int minimo(vector<int>v) {
    int n = v.size() - 1;
    return minimo(v, 0, n);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //Resolver problema
    //Escribir resultado
    cout << minimo(v) << endl;
    return true;
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