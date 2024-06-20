// ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
ALCLARACIONES
vector<string>paises: es la representacion del conjunto de paises, elementos que vamos a procesar
int N: es el numero de elementos por entrada, es decir el tamaño del vector anterior

ESPECIFICACION
PRE={longitud(paises)=N ^ 0<N<100000}
fun resolver(vector<string>paises, int N, string pais) dev int a
POS={a=(max w: 0<=w<N ^ paises[w]=pais : w) || a=0 si (Vq:0<=q<N:paises[q]!=pais)}

INVARIANTE= 0<=n<N ^ a=(max w: 0<=w<n ^ paises[w]=pais : w)
FUNCION DE COTA= n

COSTE=O(n)en el caso peor, siendo n el numero de elementos que tiene el vector, siendo la instruccion critica el while de la funcion resolver()

*/

// función que resuelve el problema
int resolver(vector<string> paises, const int& N, const string &pais)
{
    int a=0;
    bool encontrado = false;
    int n = N - 1;
    while (!encontrado && n >= 0)
    {   
        a++;
        if (paises[n] == pais){
            encontrado = true;
        }
        else {
            n--;
        }
    }
    if (a == N && !encontrado)
        return 0;
    else
        return a;
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

    int sol = resolver(paises,paises.size(),pais);

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