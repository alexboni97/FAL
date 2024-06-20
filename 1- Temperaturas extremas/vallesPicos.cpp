//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DATOS = 10000;
/*
ESPECIFICACION
pre:{ 0<N<=longitud(temperaturas)<=10000 ^ (Vi: 0<=i<N: -50<=temperaturas[i]<=60 )}
proc contarPicosValles(int temperaturas[], int N, inout int picos, inout int valles)
pos:{picos=(#w:1<w<N-1:esPico(w,temperaturas))^ valles=(#z:1<z<N-1 : esValle(z,temperaturas))}
donde
esPico(x,v)=(v[x-1]<v[x] && v[x+1]<v[x])
^ 
esValle(y,v)=(v[y-1]>v[y] && v[y+1]>v[y])

INVARIANTE: 0<n<=N ^ picos=(#w:1<w<n-1:esPico(w,temperaturas) ^ valles=(#z:1<z<n-1 : esValle(z,temperaturas)) )
COTA: N-n-1
*/
bool esPico(const int &x, const int v[]){
    return v[x-1]<v[x] && v[x+1]<v[x];
}
bool esValle(const int &y, const int v[]){
    return v[y-1]>v[y] && v[y+1]>v[y];
}
void contarPicosValles(int temperaturas[], int N, int& picos, int& valles) {
    int n=1;
    if(N>2){
        while (n < N-1)
        {
            if(esPico(n,temperaturas))
                picos++;
            else if(esValle(n,temperaturas))
                valles++;
            n++;
        }
    }
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int nTemp;
    int temperaturas[MAX_DATOS];
    cin >> nTemp;

    for (int i = 0; i < nTemp; i++) {
        cin >> temperaturas[i];
    }
    //Calcula el resultado
    int picos = 0;
    int valles = 0;

    contarPicosValles(temperaturas, nTemp, picos, valles);
    //Escribe el resultado
    cout << picos << "\t" << valles << endl;

}

int main() {
    // Para la entrada por fichero.

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    cin >> numCasos;
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