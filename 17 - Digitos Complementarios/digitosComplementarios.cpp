
//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



int calcularComplementario(int digito) {
    return 9 - digito;
}

// Función recursiva para calcular el número de dígitos complementarios
int complementario(int n, int&r) {
    if (n == 0) {
        return r;
    }
    else {
        int d = 9 - n % 10;
        return complementario(n / 10, r * 10 + c);
    }
}
int inverso(int numero, int resultado) {
    if (numero == 0) {
        return resultado;
    }

    int digito = numero % 10;

    return inverso(numero / 10, resultado * 10 + digito);
}
void resuelveCaso() {
    int n;
    //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
        //Calcula el resultado

        //Escribe el resultado
    cout << complementario(n,0) << " " << inverso(n,0) << endl;

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