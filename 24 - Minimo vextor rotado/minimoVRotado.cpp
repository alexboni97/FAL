//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int minimo(vector<int>const& v, int c, int f) {
    int m,r;
    if(c+1==f){
        return v[c];
    }else{
        m=(c+f)/2;
        if(v[m-1]>v[m]&&v[c]>=v[m-1]){//miro que este en orden decreciente la primera mitad y que el valor final es mayor que el primero de la segunda mitad
            r=minimo(v,m,f);
        }
        else{
            r=minimo(v,c,m);
        }
        return r;
    }
}
int minimo(vector<int>v) {
    int n = v.size();
    return minimo(v, 0, n);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //Resolver problema
    //Escribir resultado
    cout << minimo(v) << endl;
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