//ALEX GUILLERMO BONILLA TACO

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int calcularComplementario(int digito) {
    return 9 - digito;
}

// Funci�n recursiva para calcular el n�mero de d�gitos complementarios
int complementario(int n,int &r) {
    int c;
    if (n <10) {
        c=9-n;
        r++;
    }
    else {
        c = (complementario(n / 10,r))*10+complementario(n%10,r);
    }
    return c;
}
int inverso(int n, int&r,int inv) {
    int i;
    if (n == 0) {
       i=inv*pow(10,r);
    }
    else {
        r--;
        i=inverso(n / 10, r,10*inv+n%10);
    }
    return i;
}

int inverso(int n,int &r) {
    int inv = 0;
    return inverso(n, r,inv);
}
void resuelveCaso() {
    int n, r;
    r = 0;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
        //Calcula el resultado
    n = complementario(n, r);
    r = inverso(n, r);
        //Escribe el resultado
    cout << n << " " << r << endl;

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