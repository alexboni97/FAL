// NOMBRE Y APELLIDOS:Sergio Sánchez Carrasco

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
EXPLICACIÓN DEL PROBLEMA:

Se trata de un problema de recursión en el cual tenemos que aplicar vuelta atrás. El objetivo es
MINIMIZAR el tiempo en el que los funcionarios tardan en realizar los trabajos, de forma que
asignemos a un funcionario un trabajo para conseguir que el resultado final sea mínimo.

DATOS:

    ºint n: representa tanto el número de funcionarios como el número de trabajos, ya que es simétrico (Son el mismo número)
    ºvector<vector<int>> tiempos(n, vector<int>(n, 0)): matriz que almacena cuanto tarda el funcionario 'i' en realizar el trabajo 'j'.

ÁRBOL DE EXPLORACIÓN:

El árbol de exploración que he construido tiene profundidad n y anchura n. En cada nivel del árbol tomamos la decisión de
asignarle al funcionario i un trabajo j E {0,1... n-1}.

COSTE COMO CONSECUENCIA DEL ÁRBOL DE EXPLORACIÓN:

El coste de nuestro algoritmo pertenece a O(n^n). Lo cual es bastante caro.

RESTRICCIONES:

    -EXPLICITAS:

        º1<=n<=20 es el número de funcionarios y trabajos.
        ºEl tiempo que trarda un funcionario en realizar un trabajo esta entre 1 y 10000.

    -IMPLICITAS:
        ºCada funcionario se encargará de un único trabajo.
        ºCada trabajo será asignado como maximo a un funcionario.
        ºTodos los funcioanrios saben hacer todos los trabajos.
        ºEl tiempo que tarden debe ser MÍNIMO.-> MINIMIZACIÓN.

MARCADORES:

    º vector<bool> trabajos_asignados(n, false): Vector que almacena para cada trabajo si ha sido asignado o no.
    º int tiempo_parcial: Entero que almacena el tiempo que vamos calculando.
    º tiempo_mejor: Entero que almacena el tiempo mejor, el resultado final.



PODA OPTIMALIDAD:

La poda de optimalidad nos sirve para podar soluciones que NO nos llevan a alcanzar la solución óptima de nuestro algoritmo.
Es importante recalcar que podemos tener distintas opciones a la hora de realizar la poda de optimalidad. Tendremos que valorar
la opción más eficiente y realista. ¿Qué opciones observo yo que tiene este problema? 4 opciones, ordenadas de menos a más realistas:

    OPCION 1:
    
    Que el tiempo que tardan el resto de funcionarios en hacer el resto de trabajos sea 0.

    tiempoEstimado +=  tiempo_parcial + (n-k-1)*0;

    Coste O(1), pero es poco realista.

    OPCIÓN 2:

    Que el tiempo que tarden el resto de funcionarios sea el mínimo de todos los tiempos.

    tiempoEstimado += tiempo_parcial + (n-k-1)* min;

    Coste: O(n^2) puesto que tenemos que recorrer la  matriz.

    OPCIÓN 3:

    Que el tiempo que tarden el resto de funcionarios sea el mínimo de los tiempos de los funcionarios restantes.

    tiempoEstimado += tiempo_parcial + (n-k-1)* min[k].

    Coste: O(n^2) puesto que tenemos que recorrer la matriz y almacenar en un vector el mínimo restante para cada funcionario.

    OPCIÓN 4:

    Que el tiempo que tarden los restantes sea el mínimo de cada uno de los funcionarios restantes

    tiempoEstimado += tiempo_parcial + sumaRapido[k];

    Coste: O(n^2) puesto que tenemos que recorrer la matriz y almacenar los minimos y despues sumarlos.
*/

void poda_optimalidad(vector<vector<int>> const& tiempos, vector<int>& sumaRapido, int n) {

    vector<int> minimo_por_funcionario(n, 0);

    for (int i = 0; i < n; i++)
    {
        minimo_por_funcionario[i] = tiempos[i][0];

        for (int j = 1; j  < n; j ++)
        {
            minimo_por_funcionario[i] = min(minimo_por_funcionario[i], tiempos[i][j]);
        }
    }

    sumaRapido[n - 1] = 0;//La estimación de los siguientes al último funcionario es 0.

    for (int i = n-2; i >=0; --i)
    {
        sumaRapido[i] = sumaRapido[i + 1] + minimo_por_funcionario[i + 1];
    }
}

void funcionarios_trabajos_con_poda(vector<vector<int>> const& tiempos, int const& n, vector<int>& solucion, vector<int>& mejor_solucion,
    vector<bool>& trabajos_asignados, int& tiempo_parcial, int& tiempo_mejor, int k, vector<int> const & sumaRapido)
{
    for (int trabajo = 0; trabajo < n; trabajo++)
    {
        //Comprobamos que el trabajo NO este asignado...
        if (!trabajos_asignados[trabajo])
        {
            solucion[k] = trabajo;//Asignamos al funcionario k el trabajo j.

            /*MARCAJE*/
            trabajos_asignados[trabajo] = true;
            tiempo_parcial += tiempos[k][trabajo];

            int tiempoEstimado = tiempo_parcial + sumaRapido[k];

            if (tiempoEstimado < tiempo_mejor)
            {
                //Como no hay poda
                if (k == n - 1)
                {
                    //Hemos llegado al último empleado.
                    if (tiempo_parcial < tiempo_mejor)
                    {
                        tiempo_mejor = tiempo_parcial;
                        mejor_solucion = solucion;
                    }
                }
                else
                {
                    funcionarios_trabajos_con_poda(tiempos, n, solucion, mejor_solucion, trabajos_asignados, tiempo_parcial, tiempo_mejor, k + 1, sumaRapido);
                }
            }

            
            /*DESMARCAJE (al mismo nivel que marcaje)*/
            trabajos_asignados[trabajo] = false;
            tiempo_parcial -= tiempos[k][trabajo];
        }
    }
}


bool resuelveCaso() {

    int n; //n representa tanto el número de funcionarios como el número de trabajos, ya que es simétrico (Son el mismo número)

    cin >> n;

    if (n == 0)//no más casos base.
        return false;

    vector<vector<int>> tiempos(n, vector<int>(n, 0));//Matriz que almacena cuanto tarda el funcionario 'i' en realizar el trabajo 'j'.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tiempos[i][j];//Leemos elementos de la matriz.
        }
    }

    vector<int> solucion(n); //Vector de enteros en el cual almaceno para cada funcionario su trabajo.
    vector<int> mejor_solucion(n); //Vector de enteros donde almaceno la mejor solución del algoritmo.
    vector<bool> trabajos_asignados(n, false);//Vector que almacena para cada trabajo si ha sido asignado o no. (marcador).
    int tiempo_parcial = 0, tiempo_mejor = 1000000;//Enteros que almacenan el tiempo parcial y el tiempo mejor respectivamente(marcadores).

    vector<int> sumaRapido(n,0);//Vector que nos va a servir para realizar la poda de optimalidad.

    poda_optimalidad(tiempos, sumaRapido, n);

    funcionarios_trabajos_con_poda(tiempos, n, solucion, mejor_solucion, trabajos_asignados, tiempo_parcial, tiempo_mejor, 0, sumaRapido);

    cout << tiempo_mejor << endl;

    //Resolver problema
    //Escribir resultado
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}

