// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
//coste O(N)
//P = {0 < |datos|}
//Q = 
// función que resuelve el problema
vector<int> resolver(vector<int> datos) {
    vector<int>res;
    int win,veces,last;
    win =0; veces=0;last=0;
    res.push_back(win);
    res.push_back(veces);
    res.push_back(veces);
    for(int i=0; i < datos.size();i++){
        
        if(datos[i] > 0 ){
            win++;
            if(win > res[0]){
                res[0] = win;
                res[1] = 1;
                res[2]= 0;
            } 
            else if(win == res[0]){
                res[1]++;
                res[2]=0;    
            }
            else{
                res[2]++; 
            } 
        }else{
            res[2]++;
            win =0;
        }
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int partidos, in; 
    cin >>partidos;
    vector<int> datos;
    if (! std::cin)
        return false;
    
        for(int i=0; i < partidos; i++){
            cin >> in;
            datos.push_back(in);
        }
    vector<int> sol = resolver(datos);
    
    // escribir sol
    
    cout << sol[0] <<" "<< sol[1] <<" "<<sol[2] << endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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