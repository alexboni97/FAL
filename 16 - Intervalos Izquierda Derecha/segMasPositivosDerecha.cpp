//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int sumSegmentos(vector<int>v, const int& N, const int& K) {
    int s = 0, n = K, pi = 0, pd = K / 2, ci = 0, cd = 0;
    for (int i = 0; i < pd; i++) {
        if (v[i] > 0) ci++;
    }
    for (int i = pd; i < K; i++) {
        if (v[i] > 0) cd++;
    }
    if (ci >= cd)s++;
    while (n < N) {
        if (v[pd] > 0) {
            ci++;
            cd--;
        }
        if (v[pi] > 0) {
            ci--;
        }
        if (v[n] > 0) {
            cd++;
        }
        if (ci >= cd)s++;
        pd++;
        pi++;
        n++;
    }
    return s;
}

bool resuelveCaso() {
    int n, k;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin||n==0)
        return false;
    cin >> k;
    vector <int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //Resolver problema
    
    //Escribir resultado
    cout << sumSegmentos(v, n, k)<<endl;
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