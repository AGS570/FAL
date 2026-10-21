// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema


//P =  0 < |datos|
//Q = {(sol.first = sum(datos[k]) ^ ((0<=k<|datos|) ^ (Ak Ex: datos[x] < datos[k]) ^ sol.second = sum(k)}
pair<long long,int> resolver(vector<int>&datos) {
    int minimo = datos[0];
    long long sum =0,cont=0,numMinimo=0;
    for(int i =0 ; i < datos.size();i++){
        sum+=datos[i];
        cont++;
        if(minimo == datos[i]){
            numMinimo++;
        }else if(datos[i]< minimo){
            numMinimo =1;
            minimo = datos[i];
        }
    }

    sum -= (long long)minimo*numMinimo;
    cont-=numMinimo;

    return {sum,cont};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    vector<int>datos;
    int num,in;

    cin >> num;
    for(int i =0; i< num;i++){
        cin >>in;
        datos.push_back(in);
    }
    pair<long long,int> sol = resolver(datos);
    // escribir sol
    
    cout << sol.first << " " << sol.second << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}