// ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
int resolver(vector<string>paises,const string &pais) {
    int sol = 0;
    int i = paises.size();
    i--;
    while ( i  >= 0) {
        if (paises[i] == pais) return paises.size() - i;
        i--;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    cin >> numCasos;
    if (!std::cin||numCasos==0)
        return false;
    char c;
    string pais;
    cin >> pais;
    vector <string>paises(numCasos);
    for (int i = 0; i < paises.size(); i++) {
        cin >>  paises[i];
    }

    int sol = resolver(paises,pais);

    // escribir sol
    if (sol == 0) {
        cout << "NUNCA\n";
    }
    else {
        cout << sol<<endl;
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}