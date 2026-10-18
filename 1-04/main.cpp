// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


bool subida(vector<int>v,int ini, int fin){
    for(int i = ini; i < fin-1; i++){
        if(v[i] >= v[i+1])return false;
    }
    return true;
}

bool valido(vector<int> &v, int ini,int fin, int d){
    int cont =0;
    int in,f;
    for(int i = ini; i < fin-1;i++ ){
        if(subida(v,i,fin)&& fin - i > d)return false;
        
    }
    return true;
}
// función que resuelve el problema
int resolver(vector<int> &v, int d) {
    int max =0;
    int cont =0;
    int ini,fin;
    ini=0;
    fin= ini;
    for(int i =0; i < v.size();i++){
        if(ini < 0) return max;
        if(valido(v,ini,fin+1,d)){
            fin++;
            
        }else{
            ini++;
        }
        cont = fin - ini;

       if(cont > max) max = cont;

    }
    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int>v;
    int d,n,in;
    cin >> n >> d;
    for(int i =0; i < n; i++){
        cin >> in;
        v.push_back(in);
    }

    int sol = resolver(v,d);
    // escribir sol
    
    cout << sol<< endl;
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