// Nombre del alumno ..... Alberto
// Usuario del Juez ...... FAL-E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// llano= (0<ini<fin | ^ (Ak(v[ini] = v[k] < v[fin])))
bool llano(vector<int> &v, int ini,int fin){
    for(int i = ini; i < fin-1;i++){
        if(v[i] != v[i+1] ) return false;
    }
    if(v[fin-1] < v[fin]) return true;
    return false;
}


//P = {|datos| > 0 < c}
//Q = {Ei | (0<=i ^ i+c < |datos| ^ llano(datos,i,i+c))}
//coste = O(N)
bool resolver(vector<int> &datos, int c) {

    //if(datos.size()<= c || c<1)return false;

    int ini, fin, longitud=1;
    ini =1;
    for(int i =0; i+1 < datos.size();i++ ){
        if(datos[i] == datos[i+1]){
            longitud++;
        }else {;
            if(longitud >= c && datos[i] < datos[i+1])
                return true;
            longitud = 1;
        }
    }
    return false;
}
    /*int ini,fin;
    for(int i =0; i+c < datos.size();Si++){
        
        if(llano(datos,i,i+c)) return true;
    }*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,c,in;
    vector<int>v;
    cin >> n >> c;
    if (n == 0 && c == 0)
        return false;
    

    for(int i=0; i < n;i ++){
        cin >> in;
        v.push_back(in);
    }
    bool sol = resolver(v,c);
    
    if(sol) cout << "SI";
    else cout << "NO";
    cout << endl;
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
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
