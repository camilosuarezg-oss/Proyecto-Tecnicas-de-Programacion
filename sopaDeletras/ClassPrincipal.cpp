//
// Created by csuar on 25/11/2026.
//
#include "ClassPrincipal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //trae tolower y toupper
#include <vector>

using namespace std;

//funcion para convertir minuscula la palabra ingresada
string minuscula (string palabra){
    for(int i=0; i<palabra.length(); i++){
        palabra[i]=tolower(palabra[i]);
    }
    return palabra;
}

//ifstream para que lea el archivo de sopa de letras
bool cargarSopa(vector <string>& lineaSopa){
    ifstream archivoSopa("Sopa.txt");
    if(!archivoSopa.is_open()){
        cout<<"No se encuentra el archivo de la sopa de letras"<<endl;
        return false;
    }
    //para guardar cada línea que se lea
    string linea;
    //getline lee una línea completa del archivo. El while se repite hasta que no queden más líneas.
    while(getline(archivoSopa, linea)){
        if(linea!=""){
            //si la linea no esta vacia agregela al vector esa linea leida
            lineaSopa.push_back(linea);
        }
    }
    archivoSopa.close();
    return true;
}

bool cargarPalabra(vector <string>& palabras){
    ifstream archivoPalabras("Palabras.txt");
    if (!archivoPalabras.is_open()){
        cout<<"No se pudo abrir el archivo de palabras";
        return false;
    }
    string linea;
    while(getline(archivoPalabras, linea)){
        if(linea!=""){
            palabras.push_back(linea);
        }
    }
    archivoPalabras.close();
    return true;
}

//funcion para buscar la palabra en la sopa de letra
//la sopa de letras que tenemos sin que la modifique solo la lea y trabaje con la original
//                                                   recibe la palabra que ingreso el usuario, q buscamos en la sopa de letras
//                                                                                                                          letra de la palabra toca comparar ahora
bool buscarDireccion(const vector <string>& sopaLetra, const string palabra, int fila, int columna, int mueveFila, int mueveCol, int posicionPalabra) {
    if (posicionPalabra == palabra.size()) {
        return true;
    }
    if (fila<0 || fila>=sopaLetra.size() || columna<0 || columna>=sopaLetra[fila].size()){
        return false;
    }
    if (tolower(sopaLetra[fila][columna] ) != palabra[posicionPalabra]) {
        return false;
    }
    return buscarDireccion(sopaLetra, palabra, fila +mueveFila, columna+mueveCol, mueveFila, mueveCol, posicionPalabra+1);
}   