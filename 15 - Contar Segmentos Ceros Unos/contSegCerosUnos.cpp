
//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int segmentosCerosUnos(vector<int>v, const int& N, const int& L) {
    int n = L; int r0 = 0,r1=0; int s = 0;
    int c = 1, caux=0;
    if (v[n] != 0 && v[n] != 1) caux = L-1;
    
    while (n != N) {
        caux++;
        if (v[n] == 0)//cuenta unos
            r0 ++;
        if (v[n] == 1)//cuenta ceros 
            r1++;
        if (caux == L) {
            if (r0 == r1)c++;
            else {

            }
        }
        if (v[n] == 1) {//reseteo si me paso de k consecutivos
            r = 0;
        }
        n = n + 1;
        c += r;//me quedo con el contador mayor en cada iteracion
    }

    return c;
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