#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("nuevo.txt");  // Cambia el nombre del archivo según corresponda
    
    if (!inputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    char specialCharacter = '█';  // Caracter especial del laberinto
    char emptyCharacter = ' ';    // Caracter para espacios en blanco

    std::vector<std::vector<int>> mazeMatrix;  // Matriz para almacenar el laberinto

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<int> row;
        for (char currentChar : line) {
            if (currentChar == specialCharacter) {
                row.push_back(1);
            } else if (currentChar == emptyCharacter) {
                row.push_back(0);
            }
        }
        mazeMatrix.push_back(row);
    }

    inputFile.close();

    // Imprimir la matriz (solo para fines de visualización)
    for (const auto& row : mazeMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
