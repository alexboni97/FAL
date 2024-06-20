//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

char presoFugado(vector <char>const& v, int c, int f, char& viz,char& vd) {
    int m;
    char fug_iz=0,fug_d=0,max_iz=0,min_iz=0,max_d=0,min_d=0;
    if (c+1 == f) {
        viz=v[c];
        vd=v[c];
        return 0;
    }
    else {
        m = (c + f) / 2;
        fug_iz = presoFugado(v, c, m, max_iz, min_iz);
        fug_d = presoFugado(v, m, f, max_d, min_d);
        viz = max(max_iz, max_d);
        vd = min(min_iz, min_d);
        if (max_iz == min_d - 2)
            return max_iz + 1;
        if (fug_iz != 0)
            return fug_iz;
        if (fug_d != 0)
            return fug_d;
        else
            return 0;
    }
}
char presoFugado(vector <char>const& v, int N, int c,int f) {
    char viz=0,vd=0;
    if(v[0]!=c)
        return c;
    else if(v[N-1]!=f)
        return f;
    else
       return presoFugado(v,0,N,viz,vd);
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
    cout << presoFugado(v,v.size(), i, f) << endl;
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