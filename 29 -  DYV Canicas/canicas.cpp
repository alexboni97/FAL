//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

pair<string,int>ganador_final(vector<pair<string,int>>v,int c,int f){
    pair<string,int> ganador_iz,ganador_der,ganador;
    int m;
    if(c+1==f){
        return{v[c].first,v[c].second};
    }else{
        m=(c+f)/2;
        ganador_iz=ganador_final(v,c,m);
        ganador_der=ganador_final(v,m,f);
        if(ganador_iz.second>=ganador_der.second){
            ganador=ganador_iz;
            ganador.second+=ganador_der.second/2;
        }
        else{
            ganador=ganador_der;
            ganador.second+=ganador_iz.second/2;

        }
        return ganador;
    }

}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int N;
    cin>>N;
    if(!cin){
        return false;
    }
    cin.ignore();
    vector<pair<string,int>>v(N);
    string nombre;
    int canicas;
    for (int i = 0; i < N; i++)
    {

        cin >> nombre>>canicas;
        v[i].first =nombre;
        v[i].second=canicas;
    }
    pair<string,int> ganador;
    //Resolver problema
    ganador=ganador_final(v,0,N);
    //Escribir resultado
    cout << ganador.first << " " << ganador.second << endl;
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