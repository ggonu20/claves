#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>

using namespace std;

void imprimirLaberinto(const vector<vector<string>>& laberinto) {
    for (int i = 0; i < laberinto.size(); i++) {
        for (int j = 0; j < laberinto[i][0].size(); j++) {
            cout << laberinto[i][0][j];
            
        }
        cout<<endl;
    }
}

int main() {
    // Se abre el archivo
    setlocale(LC_ALL, "en_US.UTF8");
    FILE* entrada = fopen("nuevo.txt", "r");
    if (!entrada) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer la cantidad de líneas en el archivo
    int row = 0;
    char line[100];
    while (fgets(line, sizeof(line), entrada) != NULL) {
        row++;
    }
    // Volver al inicio del archivo
    fseek(entrada, 0, SEEK_SET);


    // Se crea el vector
    int col = 50;
    vector<vector<string>> laberinto(row, vector<string>(col));

    // Leer datos del archivo y almacenar en el vector
    for (int i = 0; i < row; i++) {
        if (fgets(line, sizeof(line), entrada) == NULL) {
            cout << "Error al leer línea del archivo." << endl;
            break;
        }
        line[strcspn(line, "\n")] = '\0'; // Eliminar el salto de línea
        laberinto[i][0] = line;
    }

    // Cerrar el archivo
    fclose(entrada);

    // Imprimir los valores almacenados en el vector
    imprimirLaberinto(laberinto);

    return 0;
}
