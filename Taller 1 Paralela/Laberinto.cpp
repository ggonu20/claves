#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("nuevo.txt"); // Cambia "matriz.txt" al nombre de tu archivo
   
    const int rows = 50;
    const int cols = 50;
    char matriz[rows][cols]; // Declaramos la matriz
    int maxsize;
    char test;
    int i=0;
    int j=0;

    if (inputFile.is_open()) {
        cout << "Se pudo abrir el archivo." << endl;
        string line;
        while(getline(inputFile,line)){
            //cout<<"linea leida: "<<line<<endl;
            maxsize = 50;
            while(i<50){
                while(j<maxsize){
                    matriz[i][j] = line[j];
                    j++;
                }
                j=0;
                i++;
            }
        } 

        for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < cols; ++j) {
            cout << matriz[i][j] << "\t";
            maxsize = static_cast<int>(matriz[i][j]);
            cout<<maxsize;
        }
            cout << endl;
    }


        inputFile.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
