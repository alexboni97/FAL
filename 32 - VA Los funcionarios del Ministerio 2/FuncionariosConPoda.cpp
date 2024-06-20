// NOMBRE Y APELLIDOS:Sergio S�nchez Carrasco

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
EXPLICACI�N DEL PROBLEMA:

Se trata de un problema de recursi�n en el cual tenemos que aplicar vuelta atr�s. El objetivo es
MINIMIZAR el tiempo en el que los funcionarios tardan en realizar los trabajos, de forma que
asignemos a un funcionario un trabajo para conseguir que el resultado final sea m�nimo.

DATOS:

    �int n: representa tanto el n�mero de funcionarios como el n�mero de trabajos, ya que es sim�trico (Son el mismo n�mero)
    �vector<vector<int>> tiempos(n, vector<int>(n, 0)): matriz que almacena cuanto tarda el funcionario 'i' en realizar el trabajo 'j'.

�RBOL DE EXPLORACI�N:

El �rbol de exploraci�n que he construido tiene profundidad n y anchura n. En cada nivel del �rbol tomamos la decisi�n de
asignarle al funcionario i un trabajo j E {0,1... n-1}.

COSTE COMO CONSECUENCIA DEL �RBOL DE EXPLORACI�N:

El coste de nuestro algoritmo pertenece a O(n^n). Lo cual es bastante caro.

RESTRICCIONES:

    -EXPLICITAS:

        �1<=n<=20 es el n�mero de funcionarios y trabajos.
        �El tiempo que trarda un funcionario en realizar un trabajo esta entre 1 y 10000.

    -IMPLICITAS:
        �Cada funcionario se encargar� de un �nico trabajo.
        �Cada trabajo ser� asignado como maximo a un funcionario.
        �Todos los funcioanrios saben hacer todos los trabajos.
        �El tiempo que tarden debe ser M�NIMO.-> MINIMIZACI�N.

MARCADORES:

    � vector<bool> trabajos_asignados(n, false): Vector que almacena para cada trabajo si ha sido asignado o no.
    � int tiempo_parcial: Entero que almacena el tiempo que vamos calculando.
    � tiempo_mejor: Entero que almacena el tiempo mejor, el resultado final.



PODA OPTIMALIDAD:

La poda de optimalidad nos sirve para podar soluciones que NO nos llevan a alcanzar la soluci�n �ptima de nuestro algoritmo.
Es importante recalcar que podemos tener distintas opciones a la hora de realizar la poda de optimalidad. Tendremos que valorar
la opci�n m�s eficiente y realista. �Qu� opciones observo yo que tiene este problema? 4 opciones, ordenadas de menos a m�s realistas:

    OPCION 1:
    
    Que el tiempo que tardan el resto de funcionarios en hacer el resto de trabajos sea 0.

    tiempoEstimado +=  tiempo_parcial + (n-k-1)*0;

    Coste O(1), pero es poco realista.

    OPCI�N 2:

    Que el tiempo que tarden el resto de funcionarios sea el m�nimo de todos los tiempos.

    tiempoEstimado += tiempo_parcial + (n-k-1)* min;

    Coste: O(n^2) puesto que tenemos que recorrer la  matriz.

    OPCI�N 3:

    Que el tiempo que tarden el resto de funcionarios sea el m�nimo de los tiempos de los funcionarios restantes.

    tiempoEstimado += tiempo_parcial + (n-k-1)* min[k].

    Coste: O(n^2) puesto que tenemos que recorrer la matriz y almacenar en un vector el m�nimo restante para cada funcionario.

    OPCI�N 4:

    Que el tiempo que tarden los restantes sea el m�nimo de cada uno de los funcionarios restantes

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

    sumaRapido[n - 1] = 0;//La estimaci�n de los siguientes al �ltimo funcionario es 0.

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
                    //Hemos llegado al �ltimo empleado.
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

    int n; //n representa tanto el n�mero de funcionarios como el n�mero de trabajos, ya que es sim�trico (Son el mismo n�mero)

    cin >> n;

    if (n == 0)//no m�s casos base.
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
    vector<int> mejor_solucion(n); //Vector de enteros donde almaceno la mejor soluci�n del algoritmo.
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

