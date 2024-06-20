//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

pair<bool,int>equidiagonal(vector<vector<int>>&v,int N,int fc,int ff,int cc,int cf){
    pair<bool,int>sol,sol1,sol2,sol3,sol4;
    int m1,m2;
    int dp,ds,m;
    if(cc+1==cf&&fc+1==ff){
        return{true,v[fc][cc]};
    }else{
        m1=(fc+ff)/2;
        m2=(cc+cf)/2;
        sol1=equidiagonal(v,N/2,fc,m1,cc,m2);
        if(!sol1.first)return {false,0};
        sol2=equidiagonal(v,N/2,fc,m1,m2,cf);
        if(!sol2.first)return {false,0};
        sol3=equidiagonal(v,N/2,m1,ff,cc,m2);
        if(!sol3.first)return {false,0};
        sol4=equidiagonal(v,N/2,m1,ff,m2,cf);
        if(!sol4.first)return {false,0};

        dp=sol1.second*sol4.second;
        ds=sol2.second*sol3.second;
        sol.first=dp==ds;
        sol.second=dp;
        return sol;
    }

}
void resuelveCaso() {
    //resuelve aqui tu caso
    int N;
    cin>>N;
    vector<vector<int>>v(N,vector<int>(N,0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>v[i][j];
        }
        
    }
    pair<bool,int>sol;
    sol=equidiagonal(v,N,0,N,0,N);
    //Escribe el resultado
    if(sol.first){
        cout<<"SI "<<sol.second<<endl;
    }else
        cout<<"NO"<<endl;
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