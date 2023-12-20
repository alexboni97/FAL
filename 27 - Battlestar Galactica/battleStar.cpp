#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int tiempoNecesario(vector<int>& v, int c, int f) {
    int n;
    int m,r1, r2;
    if (c+1 == f) {
        if (v[c] == c) {

        }
    }
    else {
        m = (c + f) / 2;
        r1 = tiempoNecesario(v, c, m);
        r2 = tiempoNecesario(v, m+1, f);
    }
    return n;
}

int tiempoNecesario(vector<int>&v) {
    int c, f;
    c = f = 0;
    return tiempoNecesario(v, c, f);
}
bool resuelveCaso() {
    int n;
    cin >> n;

    if (!cin) return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << navesNecesarias(v) << endl;
    return true;    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}