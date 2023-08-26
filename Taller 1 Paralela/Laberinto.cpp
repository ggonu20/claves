#include <iostream>
#include <vector>
#include <locale>
#include <chrono>
using namespace std;

void EntradaSalida(vector<string>& laberinto) {
    int entradaFila = -1;
    int entradaColumna;
    int salidaFila = -1;
    int salidaColumna;
    
    for (int fila = 0; fila < laberinto.size(); ++fila) {
        for (int columna = 0; columna < laberinto[fila].size(); ++columna) {
            if (laberinto[fila][columna] == ' ') {
                if (entradaFila == -1) {
                    entradaFila = fila;
                    entradaColumna = columna;
                }
                else {
                    salidaFila = fila;
                    salidaColumna = columna;
                }
            }
            
            //cout<<laberinto[fila][columna];
        }
    }


    if (entradaFila != -1) {
        laberinto[entradaFila][entradaColumna] = 'e';

    }
    if (salidaFila != -1) {
        laberinto[salidaFila][salidaColumna] = 's';
    }
}

void imprimir(vector<string>& laberinto){
    for (const string& fila : laberinto) {
        cout << fila;
    }
}

void salidar(vector<string>& laberinto, int i, int j, int F, int C) {
    
   if(laberinto[i][j]=='s'){return;}
   else if (laberinto[i][j]!='x' && laberinto[i][j]!='e'){return;}
   else{
    if(j+1<C){salidar(laberinto,i,j+1,F,C);}
    if(i+1<F){salidar(laberinto,i+1,j,F,C);}
    if(j-1>=0){salidar(laberinto,i,j-1,F,C);}
    if(i-1>=0){salidar(laberinto,i-1,j,F,C);}
    laberinto[i][j] = '*';
   }

}


void salidam(vector<string>& laberinto, int i, int j, int F, int C) {
    
    if (i < 0 || i >= F || j < 0 || j >= C ) {
        return;
    }

    else if (laberinto[i][j] == 's') {
        imprimir(laberinto);
        return;
    }
    else if (laberinto[i][j] != 'x'){
        return;
    }
    else { 
    laberinto[i][j] = '*'; // Marcar el camino de regreso  
    salidar(laberinto, i, j + 1, F, C); // derecha
    salidar(laberinto, i + 1, j, F, C); // abajo
    salidar(laberinto, i, j - 1, F, C); // izquierda
    salidar(laberinto, i - 1, j, F, C); // arriba
    imprimir(laberinto);
    return;
    }

}

void llenar_x(vector<string>& laberinto){
        const int rows = 50;
        const int cols = 50;
        char laberintos[rows][cols];
        for (int fila = 0; fila < laberinto.size(); ++fila) {
            for (int columna = 0; columna < laberinto[fila].size(); ++columna) {
                if (laberinto[fila][columna] == ' ') {
                    laberintos[fila][columna]='x';}
            }
        }
        for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << laberintos[i][j];
        }
        cout <<endl;
    }
}






int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    FILE* entrada;
    fopen_s(&entrada,"nuevo.txt", "r");

    const int max_f = 50;
    const int max_c = 50;
    vector<string> laberinto;
    char linea[max_c];
    while (fgets(linea, max_c, entrada)) {
        laberinto.push_back(linea);
    }

    fclose(entrada);

    EntradaSalida(laberinto);
    //imprimir(laberinto);
    //se encuentra e para partir el laberinto
    int start_i, start_j;
    for (int i = 0; i < laberinto.size(); ++i) {
        for (int j = 0; j < laberinto[0].size(); ++j) {
            if (laberinto[i][j] == 'e') {
                start_i = i;
                start_j = j;
                break;
            }
        }
    }
    llenar_x(laberinto);
    imprimir(laberinto);
    salidar(laberinto, start_i, start_j, max_f, max_c);
    imprimir(laberinto);


    return 0;
}