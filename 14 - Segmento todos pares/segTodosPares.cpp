
//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*
todosPares(v,p,q)=(Vi:p<=i<q:v[i]mod2==0)
pre: {Vp,q:0<=p<q<=N ^todosPares(v,p,q):p-q}
*/

int segmentoTodosPar(vector<int>v, const int& N) {
    int n = 0; int r = 0; int s = 0;
    int c = 0;
    while (n != N) {
        
        if (v[n] != 0)//cuenta ceros consecutivos
            s = n + 1;
        r = max(r, (n + 1 - s));
        if (v[n]==1) {//reseteo si me paso de k consecutivos
            r = 0;
        }
        n = n + 1;
        c +=r;//me quedo con el contador mayor en cada iteracion
    }

    return c;
}
void resuelveCaso() {
    int n, k;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
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
        cout << segmentoTodosPar(v, n) << endl;
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