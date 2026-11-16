// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// función que resuelve el problema
int complementario(int num, int m, int p){
    int n = num/10;
    int mod = num%10;
    int np = p+1;
    int nm;
    //caso base

    if(n == 0){
        
        return ((9-mod)*pow(10,p)+m);
    }
    else{
        nm = (9-mod)*pow(10,p)+m;
        return complementario(n,nm, np);
    } 

}

int invertir(int num, int m){
    int n = num/10;
    int mod = num%10;
    
    if(n == 0){
        return m+(9-num);
    }else{
        return invertir(n,  ((m+(9-mod))*10));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
   
    int sol = complementario(num,0,0);
    cout << sol <<" " <<  invertir(num, 0) << endl;;;
    // escribir sol
    
    
    return true;
    
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