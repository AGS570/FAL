// Nombre del alumno ..... Alberto
// Usuario del Juez ...... FAL-E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


void ordenar(vector<int> &v){
    int min = 0,aux;
    for(int i =0; i < v.size();i++){
        min = i;
        for(int j = min; j < v.size();j++){
            if(v[j] < v[min]){
                aux = v[min];
                v[min] = v[j];
                v[j]= aux;
            }
        }
    }
}

//coste O(n)+ O(nlogn)
//P = {|datos|> 0}
//Q = {(Ei : 0<=i<|datos|: datos[i] = k) ^ (Ej : 0<=j<|datos|: (Es €datos: datos[j] = s)) ^ (As € datos: apariciones(s)< apariciones(k)}
// función que resuelve el problema 
//invariante = {(0 < i < |datos|)}
int resolver(vector<int> &datos) {
    int max =datos[0],curr;
    int numMax =0;;
    int cont=0;
    //ordenar(datos);
    sort(datos.begin(),datos.end());
    for(int i =0; i < datos.size();i++){
        if(datos[i] != curr){
            curr = datos[i];
            cont = 1;
        }else{
            cont++;
        }
        if(datos[i] != max){
            if(numMax < cont){
                numMax = cont;
                max = datos[i];
            }
        }else{
            numMax++;
        }
    }
    return max;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int accidentes,in;
    cin >> accidentes;
    vector<int>datos;
    if (accidentes == -1)
        return false;
    

    for(int i =0;i< accidentes; i++){
        cin >> in;
        datos.push_back(in);
    }
    int sol = resolver(datos);
    
    // escribir sol
    cout << sol <<endl;
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
