//ALEX GUILLERMO BONILLA TACO

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int maxIz(int n) {
    int m;
    if (n == 0) {
        m = 0;
    }
    else {
        m = max(n % 10, maxIz(n / 10));
    }
    return m;
}

int codificar(int n, int& r,int &md) {
    int s;
    if (n == 0) {
        return s = 0;
    }
    else {
        if (r % 2 == 0) { 
            r++;
            if (r == 1)md = n % 10;
            md=min(md, n % 10);
            s = codificar(n / 10, r,md) +2*( n % 10)+maxIz(n/10);
        }
        else {
            r++;
            s = 3 * (n % 10) + md;
            md = min(md, n % 10);
            s += codificar(n / 10, r,md);
        }
    }
    return s;
}
int codificar(int n, int& r) {
    int md = 0;
   return codificar(n, r, md);
}

void resuelveCaso() {
    int n, r;
    r = 0;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
    //Calcula el resultado
    n = codificar(n, r);
    
    //Escribe el resultado
    cout << n << endl;

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