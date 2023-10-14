//ALEX GUILLERMO BONILLA TACO
//E012


#include <iostream>
#include <fstream>
#include<vector>
#include<math.h>
using namespace std;

/*REVISAR
ESPECIFICACION
PRE{v.size>=0 ^ n<=v.size ^ (0<=n<=100000)}
fun esPastoso(vector<int>v,int n) dev bool b
POS{b=(Existe max p:p<=n : v[p]=(sumatorio(i):p<i<v.size:v[i]))}
*/

int esPastoso(vector<int>v) {
    int suma = v[v.size()-1];
    int pos =0;
    bool loEs = false;
    int i = v.size() - 2;
    while (i >= 0 && !loEs) {
        if (v[i] == suma) {
            pos = i;
            loEs = true;
        }
        else { suma += v[i]; }
            i--;
    }
    if (v[v.size() - 1] == 0) { pos = v.size() - 1; }
    return pos;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int N;
    cin >> N;
    vector<int>v(N);
    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

       //Calcula el resultado
    int sol = esPastoso(v);
       //Escribe el resultado
    if (sol == 0) cout << "NO\n";
    else cout << "SI " << sol<< endl;
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