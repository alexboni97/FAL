
//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*
a) todosPares(v,p,q)=(Vi:p<=i<=q:v[i]mod2==0)
b) noMas(v,p,q,k)=(Vz,l:p<=z<=l<=q&&todosPares(v,z,l):l-z<=k)
c) ESPECIFICACION
    PRE:{v.size>=0 /\ k>=0 /\ N=v.size}
    func (int v[], int N, int K)dev int s
    POS:{s=(max p,q : 0<=p<q<N && noMas(v,p,q,K) : q-p)}
e) I= {0<=n<=N /\ max p,q : 0<=p<q<N && noMas(v,p,q,K) : q-p }
    funcion de cota: C=N-n
        ·C>=0 al empezar el bucle(N-n=N-0>=0 entonces N>=0 al empezar el bucle)
        ·C decrece al avanzar el bucle(se incrementa n disminuyendo en cada iteracion N-n)
f) coste asintotico = O(N)
*/

int intervaloMax(vector<int>v, const int& N, const int&K) {
    int n = 0; int r = 0; int s = 0;  
    int c = 0,caux=0;
    while (n != N) {
        caux++;
        if (v[n] != 0)//cuenta ceros consecutivos
            s = n + 1;
        r = max(r, (n + 1 - s));
        if (K < r) {//reseteo si me paso de k consecutivos
            r = K; 
            caux = K;
        }
        n = n + 1;
        c = max(caux, c);//me quedo con el contador mayor en cada iteracion
    }

    return c;
}
void resuelveCaso() {
    int n, k;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n >> k;
    if (n == 0)cout << 0 << endl;
    else {
        vector<int>v(n);
   
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x % 2 == 0) v[i] = 0;
            else v[i] = 1;
        }
        
        //Calcula el resultado

        //Escribe el resultado
       cout << intervaloMax(v,n,k) << endl;
    }

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