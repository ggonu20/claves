#include <iostream>
#include <locale.h>
#include <locale>
#include<fstream>
#include<string>
#include <windows.h>
#define CP_UTF8 65001 
#define CP_UTF32 12000 

#include <codecvt>

using std::cout;

std::wstring utf8_to_ws(std::string const&);

int main(){
    
    std::ifstream file;
    std::string text;

    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "error: UTF-8 codigo.\n";
        return 1;
    } 

    file.open("nuevo.txt");
    
    int linea = 0;
    
    if (file.fail()){
        
        cout<<"No se pudo abrir el archivo. \n";
        
        exit(1);
        
    }
    
    while(std::getline(file,text)){ 
                
        std::cout<<text<<"\n";
        
        linea++;
        
    }
    
    cout<<"\n";
    
    system("Pause");
    return 0;
}



std::wstring utf8_to_ws(std::string const& utf8)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cnv;
    std::wstring s = cnv.from_bytes(utf8);
    if(cnv.converted() < utf8.size())
        throw std::runtime_error("incomplete conversion");
    return s;
}