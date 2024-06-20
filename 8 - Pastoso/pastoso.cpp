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

bool esPastoso(vector<int>v,int&pos) {
    long long suma = 0;
    bool loEs = false;
    int i = v.size() - 1;
    while (i >= 0 && !loEs) {
        if (v[i] == suma) {
            pos = i;
            loEs = true;
            return loEs;
        }
        else { suma += v[i]; }
            i--;
    }
    //if (v[v.size() - 1] == 0) { pos = v.size() - 1; return loEs=true; }

    return loEs;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int N;
    cin >> N;
    //CASO ESPECIAL N==0
    if (N > 0) {
        vector<int>v(N);
        for (size_t i = 0; i < v.size(); i++) {
            cin >> v[i];
        }
    int p=0;
    if (!esPastoso(v,p)) cout << "NO\n";
    else cout << "SI " << p<< endl;
    }
    else
    {
        cout << "NO" << endl;
    }
       //Calcula el resultado
       //Escribe el resultado
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