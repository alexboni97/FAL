//ALEX GUILLERMO BONILLA TACO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


/*
	T(n)=c			n=0,1
	T(n)=2T(n/2)+nlog(n)	n>1

	T(n)=2T(n/2)+nlog(n)=2^kT(n/2^k)+nlog(n)*k=n*T(1)+log(n)*nlog(n)
		=nlog(n)

		n/2^k=1; 2^k=n; log(n)=log(2^k); log(n)=k;

	T(n) pertenece a O(nlog(n))
*/
// función que resuelve el problema
int resolver(std::vector<int> & v, int ini, int fin) {
	if (ini == fin) return 0;//vector sin elementos n=0
	else if (ini + 1 == fin){ // vector con un elemento n=1
		return 0;
	}
	else{
		int m = (ini + fin - 1) / 2;
		int iz = resolver(v, ini, m + 1);
		int dr = resolver(v, m + 1, fin);
		int aux = 0;
		int i = ini, j = m + 1;

		while (i < m + 1 && j < fin){
			if (v[i]>v[j]){
				aux += (m - i + 1);
				++j;
			}
			else ++i;
		}

		std::sort(v.begin() + ini, v.begin() + fin);

		return aux + iz + dr;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	if (!std::cin)
		return false;

	std::vector<int> v(tam);

	for (int i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	int n = resolver(v,0,tam);

	// escribir sol

	std::cout << n << "\n";
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