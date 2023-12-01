//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

char presoFugado(vector <char>const& v, int i, int f, int ci,int cf) {
    int c;
    int m;
    if (i == f) {
        if (v[i] -v[f] ==0) {
            c = v[i];
        }
        else c = 0;
    }
    else {
        m = (i + f) / 2;
        c=max(presoFugado(v,i,m,ci,cf/2),presoFugado(v,m+1,f,cf/2+1,cf));
    }
    return c;
}

void resuelveCaso() {
    //resuelve aqui tu caso
    char i, f;
    cin >> i >> f;
    vector<char>v(f-i);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    
    //Lee los datos

    //Calcula el resultado
    //Escribe el resultado
    cout << presoFugado(v,0,v.size()-1, i, f) << endl;
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