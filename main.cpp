#include <iostream>
#include <string>

using namespace std;

string morse(int clave){ 
    string morse;
    switch (clave)
    {
    case 65:
    case 97:
        morse = ".-";
        break;
    case 66:
    case 98:
        morse = "-...";
        break;
    case 67:
    case 99:
        morse = "-.-.";
        break;
    case 68:
    case 100:
        morse = "-..";
        break;
    case 69:
    case 101:
        morse = ".";
        break;
    case 70:
    case 102:
        morse = "..-.";
        break;
    case 71:
    case 103:
        morse = "--.";
        break;
    case 72:
    case 104:
        morse = "....";
        break;
    case 73:
    case 105:
        morse = "..";
        break;
    case 74:
    case 106:
        morse = ".---";
        break;
    case 75:
    case 107:
        morse = "-.-";
        break;
    case 76:
    case 108:
        morse = ".-..";
        break;
    case 77:
    case 109:
        morse = "--";
        break;
    case 78:
    case 110:
        morse = "-.";
        break;
    case 79:
    case 111:
        morse = "---";
        break;
    case 80:
    case 112:
        morse = ".--.";
        break;
    case 81:
    case 113:
        morse = "--.-";
        break;
    case 82:
    case 114:
        morse = ".-.";
        break;
    case 83:
    case 115:
        morse = "...";
        break;
    case 84:
    case 116:
        morse = "-";
        break;
    case 85:
    case 117:
        morse = "..-";
        break;
    case 86:
    case 118:
        morse = "...-";
        break;
    case 87:
    case 119:
        morse = ".--";
        break;
    case 88:
    case 120:
        morse = "-..-";
        break;
    case 89:
    case 121:
        morse = "-.--";
        break;
    case 90:
    case 122:
        morse = "--..";
        break;
    case 46:
        morse = "●";
        break;

    case 48:
        morse = "-----";
        break;
    case 49:
        morse = ".----";
        break;
    case 50:
        morse = "..---";
        break;
    case 51:
        morse = "...--";
        break;
    case 52:
        morse = "....-";
        break;
    case 53:
        morse = ".....";
        break;
    case 54:
        morse = "-....";
        break;
    case 55:
        morse = "--...";
        break;
    case 56:
        morse = "---..";
        break;
    case 57:
        morse = "----.";
        break;
    default:
        morse = clave;
        break;
    }
    return morse;
};

string murcielago(int clave){ //arreglar de numero a letra
    string murcielago;
    switch (clave)
    {
    case 77:
    case 109:
        murcielago = "0";
        break;
    case 85:
    case 117:
        murcielago = "1";
        break;
    case 82:
    case 114:
        murcielago = "2";
        break;
    case 67:
    case 99:
        murcielago = "3";
        break;
    case 73:
    case 105:
        murcielago = "4";
        break;
    case 69:
    case 101:
        murcielago = "5";
        break;
    case 76:
    case 108:
        murcielago = "6";
        break;
    case 65:
    case 97:
        murcielago = "7";
        break;
    case 71:
    case 103:
        murcielago = "8";
        break;
    case 79:
    case 111:
        murcielago = "9";
        break;
    default:
        murcielago = clave;
        break;
    }
    return murcielago;
};

string cenitpolar(int clave){ 

    string cenit;
    switch (clave)
    {
    case 67:
    case 99:
        cenit = "p";
        break;
    case 69:
    case 101:
        cenit = "o";
        break;
    case 78:
    case 110:
        cenit = "l";
        break;
    case 73:
    case 105:
        cenit = "a";
        break;
    case 84:
    case 116:
        cenit = "r";
        break;
    
    case 80:
    case 112:
        cenit = "c";
        break;
    case 79:
    case 111:
        cenit = "e";
        break;
    case 76:
    case 108:
        cenit = "n";
        break;
    case 65:
    case 97:
        cenit = "i";
        break;
    case 82:
    case 114:
        cenit = "t";
        break;
    
    default:
        cenit = clave;
        break;
    }
    return cenit;
};

void traducir(char arreglo[], int length, string (*func)(int)) {
    string arregloc[300];
    int cont = 0;
    int ascii;
    string aux;

    while (arreglo[cont] != '\0') {
        ascii = static_cast<int>(arreglo[cont]);
        aux = func(ascii);
        arregloc[cont] = aux;
        cont++;
    }

    for (int i = 0; i < length; ++i) {
        cout << arregloc[i];
    }
}

void copiarCadenaEnArreglo(char arreglo[], const std::string& palabra) {
    int length = palabra.length();
    
    for (int i = 0; i < length; ++i) {
        arreglo[i] = palabra[i];
    }
    
    arreglo[length] = '\0';
}

int main() {
    string clave;
    char arreglo[300];
    int length;

    cout << "Ingrese una palabra a encriptar: " << endl;
    getline(cin, clave);
    length = clave.length();

    copiarCadenaEnArreglo(arreglo, clave);
    
    cout << "Arreglo: " << arreglo << endl;
    
    cout << "Morse: ";
    traducir(arreglo, length, morse);
    cout << endl;

    cout << "Murciélago: ";
    traducir(arreglo, length, murcielago);
    cout << endl;

    cout << "Cenitpolar: ";
    traducir(arreglo, length, cenitpolar);
    cout << endl;

    return 0;
}
