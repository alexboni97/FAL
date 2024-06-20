//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int sumValorPosicionK(vector<int>v,int c,int f, int K){
    int m,suma;
    if(c+1==f){
        if(c+K==v[c])
        return v[c];
        else return -1;
    }
    else{
        m=(c+f)/2;
        if ((K + m - 1) > v[m - 1]){
            suma=sumValorPosicionK(v,m,f,K);
        }
        else{
            suma=sumValorPosicionK(v,c,m,K);
        }
        return suma;
    }
}
void resuelveCaso() {
    //resuelve aqui tu caso
    int N,K;
    cin >>N>>K;
    vector<int>v(N);
    //Lee los datos
    for (int i = 0; i < N; i++)
    {
        cin>>v[i];
    }
    

    //Calcula el resultado
    //Escribe el resultado
    int suma=sumValorPosicionK(v,0,N,K);
    if(suma==-1)
        cout<<"NO\n";
    else 
        cout<<suma<<endl;

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