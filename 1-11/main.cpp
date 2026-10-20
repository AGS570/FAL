// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> &datos,int error) {
    int pos =0;
    for(int i=0; i < datos.size();i++){
        if(datos[i] != error){
            datos[pos]=datos[i];
            pos++;
        }
    }
    datos.resize(pos);
    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num,in,error;
    vector<int>datos;
    
    cin >> num >> error;

    for(int i =0; i < num; i++){
        cin >> in ;
        datos.push_back(in);
    }
    

    vector<int> sol = resolver(datos,error);
    // escribir sol
    cout << sol.size() << endl;
    for(int i =0; i < sol.size();i++){
        cout << sol[i] << " ";
    }
    cout << endl;
    
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