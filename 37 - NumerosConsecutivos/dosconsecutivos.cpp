
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

int intervaloMax(vector<int>v, const int& N) {
    int n = 1; int r = 0; int s1 = 0,s0=0;
    int c = 0, caux = 0;
    int sol = 0;
    while (n != N) {
        if (v[n] == 1 && v[n - 1] == 0) {
            
            s0 = 0;
        }
        if (v[n] == 0 && v[n - 1] == 1) {
           
            s1 = 0;
        }
        if (v[n] == 0 && v[n - 1] == 0) {
            s0++;
            sol += s0;
        }
            
        if (v[n] == 1 && v[n - 1] == 1) {
            s1++;
            sol += s1;
        }
           
        n++;
    }

    return sol;
}
void resuelveCaso() {
    int n;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n ;
    if (n == 0)cout << 0 << endl;
    else if (n == 1) {
        cin >> n;
        cout << 0 << endl;
    }
    else {
        vector<int>v(n);

        int x,y;
        cin >> y;
        v[0] = 0;
        for (int i = 1; i < n; i++) {
            cin >> x;
            if (x ==y+1||x==y-1) v[i] = v[i-1];
            else {
                if (v[i - 1] == 0)v[i] = 1;
                else v[i] = 0;
            }
            y = x;
        }

        //Calcula el resultado

        //Escribe el resultado
        cout << intervaloMax(v, n) << endl;
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