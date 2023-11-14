//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool esApto(vector <int>v, const int& d) {
    
    int c = 0;
    size_t i = 1;
    while (i<v.size()) {
        if (v[i - 1] < v[i]) {
            c += (v[i] - v[i - 1]);
        }
        else c = 0;
        if (c > d) {
            return false;
        }
        
        i++;
    }
    return true;
}

bool resuelveCaso() {
    int d, n;
    //Leer caso de prueba: cin>>...
    cin >> d >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n;i++) {
        cin >> v[i];
    }
    
    if (esApto(v, d)) {
        cout << "APTA" << endl;
    }
    else cout << "NO APTA"<< endl;


    //Resolver problema
    //Escribir resultado
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