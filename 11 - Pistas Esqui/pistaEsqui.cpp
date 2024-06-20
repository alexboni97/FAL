//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
ACLARACIONES
vector<int>v: representa el conjunto de elementos que contiene cada caso de prueba, es decir, las alturas
longitud(v): es el tamaño del vector

ESPECIFICACION
PRE={N=longitud(v) ^  0 <= N <= 1000 ^ Vi: 0 <=i< N:4000>v[i]>0}
fun intervaloMax(vector<int>v , int N) dev int m
POS={m=(max p,q : 0<= p<q <=N ^ (Vw:p<w<q:v[w]<v[w-1]): p-q)}

INVARIANTE= 0<= n <=N ^ (max p,q : 0<= p<q <=n ^ (Vw:p<w<q:v[w]<v[w-1]): p-q)
COTA= N-n

COSTE: O(n), coste lineal, siendo n el numero de elemntos que tiene el vector, la instruccion critica es el bucle while()


*/
int intervaloMax(vector<int>v, const int& N) {
    int n = 0; int r = 0; int s = 0; int r2 = 0; int s2 = 0;
    while (n != N) {
        if (v[n] == 0)
            s = n + 1;
        r = max(r, (n + 1 - s));
        if (v[n] == 1)
            s2 = n + 1;
        r2 = max(r2, (n + 1 - s2));
        n = n + 1;
    }
    
    return max(r, r2);
}

void resuelveCaso() {
    int n;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
    if (n == 0)cout << 0<<endl;
    else {
        vector<int>v(n);
        v[0] = 0;
        int x, y;
        cin >> x;
        for (int i = 1; i < n; i++) {
            cin >> y;
            if (x >= y) {
                v[i] = v[i - 1];
            }
            else if (v[i - 1] == 0) {
                v[i] = 1;
            }
            else if (v[i - 1] == 1) {
                v[i] = 0;
            }
            x = y;
        }
        //Calcula el resultado

        //Escribe el resultado
        cout << intervaloMax(v, n) << endl;
    }
    
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