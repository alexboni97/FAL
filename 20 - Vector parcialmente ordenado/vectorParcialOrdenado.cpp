
// ALEX GUILLERMO BONILLA TACO

#include <iostream>
#include <fstream>
#include<math.h>
#include<vector>
using namespace std;


/*
int minV(vector<int>const&v,int c,int f) {
    int s=v[c];
    for (int i = c+1; i < f; i++) {
        s=min(s, v[i]);
    }
    return s;
}
int maxV(vector<int>const& v, int c, int f) {
    int s = v[c];
    for (int i = c + 1; i < f; i++) {
        s = max(s, v[i]);
    }
    return s;
}
*/

bool parcialOrdenado(vector<int>const&v,int c,int f,int &mi,int& ma) {
    bool b1,b2;
    int r1, r2;
    if (f<=c+1) {
        b1 = true;
        b2 = true;
        r1=mi = v[c];
        r2=ma = v[c];
    }
    else {
        int m = (f+c) / 2;
        //b = (minV(v, c, m) <= minV(v, m, f)) && (maxV(v,c,m)<=maxV(v,m,f) )&& (parcialOrdenado(v, c, m) && parcialOrdenado(v, m, f));
        b1 = parcialOrdenado(v, c, m, mi, ma);
        r1 = mi;
        r2 = ma;
        b2 = parcialOrdenado(v, m, f, mi, ma) && r1 <= mi && r2 <= ma;
        mi = min(r1, mi);
        ma = max(r2, ma);
    }
    return b1&&b2;
}
bool parcialOrdenado(vector<int>const &v) {
    int c = 0, f = v.size(), mi = 0, ma = 0;
    return parcialOrdenado(v,c,f,mi,ma);

}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin || n == 0)
        return false;
    vector<int>v;
    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }
    
    //Resolver problema
    //Escribir resultado
    if (parcialOrdenado(v))cout << "SI" << endl;
    else cout << "NO" << endl;
    

    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}