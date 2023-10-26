//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



bool resuelveCaso() {
    int d, n;
    //Leer caso de prueba: cin>>...
    cin >> d >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    v[0] = 0;
    int x, y,z;
    cin >> x;
    z = 0;
    for (int i = 1; i < n; i++) {
        cin >> y;
        if (x < y && z < d) {
            v[i] = v[i - 1];
            z += y - x;
        }
        else if (v[i - 1] == 0) {
            v[i] = 1;
            z = 0;
        }
        else if (v[i - 1] == 1) {
            v[i] = 0;
            z = 0;
        }
        x = y;
        
    }
    for (int i = 0; i < n; i++) {

        cout << v[i] << " ";

    }
    cout << endl;


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