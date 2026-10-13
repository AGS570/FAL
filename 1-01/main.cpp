// Nombre del alumno ..... Alberto
// Usuario del Juez ...... FAL-E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int,int> resolver(vector<int> datos) {
    
    int max = datos[0];
    int numMax =0;;

    for(int i =0; i < datos.size(); i++){
        if(datos[i] == max){
            numMax++;
        }else if(datos[i] > max){
            max = datos[i];
            numMax=1;
        }
    }
    return {max,numMax};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int in = -1;
    vector<int> v;

    while(in != 0){
        cin >> in;

        if(in != 0) v.push_back(in);
    }


    pair<int,int> sol = resolver(v);
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