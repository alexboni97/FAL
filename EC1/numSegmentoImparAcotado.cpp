
// NOMBRE Y APELLIDOS 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

//ESPECIFICA la funcion que resuelve el problema
//Precondicion:

int resolver(std::vector<int> const& v, int k, int l) {
    int r=1;
    int n = 0, c = 0,posI=0, vposI = v[posI];
    n = k;
    int N = v.size();
    //aqui tu codigo
    while (n != N) {
        if (v[posI] % 2 != 0)c--;
        posI++;
        if (v[n] % 2 != 0) {
            c++;
        }
        if (c <= l)r++;
        n++;
    }
    
    //Funcion de cota:
    //Invariante:

    return r;
}

//Postcondicion:

//Analisis justificado del coste:







// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    int numElems = 0; size_t n; int k, l;
    std::cin >> numElems >> k >> l;
    std::vector<int> v(numElems);
    for (int& i : v) std::cin >> i;
    int sol = resolver(v, k, l);
    std::cout << sol << "\n";

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