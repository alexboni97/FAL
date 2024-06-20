//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// int segmentoMasCorto(vector<int>v, const int& N, const int& K) {
//     int r=0, c=0,f=0;
//     int cmin=N+1;
//     while (c<N)
//     {
//         if(r<K){
//             if(v[f]==1){
//                 r++;
//             }
//             f++;
//         }else{
//             if(v[c]==1)
//                 r--;
//             c++;
//         }
//         if(r==K){
//             if (f - c < cmin) {
// 				cmin = f - c;
// 			}
//         }
        
//     }
//     return cmin;
// }
int segmentoMasCorto(vector<int>v, const int& N, const int& K) {
    int c=0,f=0,cont=0;
    int min_long=N+1;
    while (f < N && min_long==N+1)
    {
        if(v[f]==1){
            if(cont==0)
                c=f;
            cont++;
        }
        if(cont==K){
            min_long=min(min_long,f-c+1);
        }
        f++;
    }
    while (f<N)
    {
        if(v[f]==1){
            c++;
            while (v[c]!=1)
            {
                c++;
            }
            min_long=min(min_long,f-c+1);
        }
        f++;
    }
    return min_long;
    
}


bool resuelveCaso() {
    int n, k;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin || n == -1)
        return false;
    vector <int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;

    //Resolver problema

    //Escribir resultado
    cout << segmentoMasCorto(v, n, k) << endl;
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