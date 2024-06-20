//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

pair<bool,int> resuelve(vector<int>v,int c,int f){
    int m;
    pair<bool,int>sol_d,sol_i,solucion;
    if(c+1==f){
        return {true,v[c]};
    }
    else{
        m=(c+f)/2;
        sol_i=resuelve(v,c,m);
        sol_d=resuelve(v,m,f);
        solucion.first = sol_d.first && sol_i.first && sol_i.second < sol_d.second;
        solucion.second=sol_i.second+sol_d.second;
        return solucion;
    }
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int N,M;
    cin>>N>>M;
    if(!cin)
        return false;
    vector<int>v(M);
    pair<bool,int> sol;
    sol.first=true;
    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < M; j++)
        {
            cin>>v[j];
        }
        if(!resuelve(v,0,M).first){
            sol.first=false;
        }
    }
    
    //Escribir resultado
    if(sol.first)
        cout<<"SI\n";
    else
        cout<<"NO\n";

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