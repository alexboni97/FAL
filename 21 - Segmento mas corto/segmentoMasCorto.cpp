//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int segmentoMasCorto(vector<int>v, const int& N, const int& K) {
    int s = N+1, saux = 0, n = 0, pi = 0, c = 0;
    
    while (c == 0) {
        if (v[n] == 1) {
            c++;
            pi = n;

        }
        n++;
    }
    
    while (n < N) {
        
        if (v[n] == 1) {
            c++;
            saux++;
            if (c == 0) {
                pi = n;
            }
        }
        if (v[n] == 0) {
            saux++;
        }
        if (c == K) {
            s = min(s, saux);
            c--;
            pi++;
            if (pi < n) {
                while (v[pi] == 0) {
                    pi++;
                }
            }
            
            saux = (n - pi+1);

        }
        n++;
    }
    return s;
}

bool resuelveCaso() {
    int n, k;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin || n == -1)
        return false;
    vector <int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;

    //Resolver problema

    //Escribir resultado
    cout << segmentoMasCorto(v, n, k) << endl;
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