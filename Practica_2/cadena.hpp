/*Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Símbolos, alfabetos y cadenas
Autor: Yago Pérez Molanes
Correo: alu0101254678@ull.edu.es
Fecha: 13/10/2021
Archivo Práctica_2/cadena.hpp: declaracion de la clase
cadena, una cadena pertenece a un determinado alfabeto,
se declaran los métodos para fijar la cadena,
obtener la cadena, añadir los simbolos de la cadena a un
alfabeto, imprimir la cadena, calcular su longitud, imprimirla,
y los distintas operaciones, (inversa, prefijos, sufijos, subcadenas)
*/

#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "./alfabeto.hpp"

class cadena {
  private:
    /** Un string como atributo privado
     * que almacena la cadena
     **/
    std::string palabra;
  public:
    cadena ();
    /** Un constructor con un char
     **/
    cadena (const char* s);
    /** Un constructor que inicializa el string
     * con otro que se le pasa por parametro
     **/ 
    cadena (const std::string str);

    /** El destructor borra el atributo del string
     * (palabra) borra la cadena
     **/
    ~cadena ();

    void set_cadena(std::string aux);
    std::string get_cadena();

    alfabeto anadir_alfabeto(alfabeto vacio);

    int longitud_cadena();
    void imprimir_cadena(std::ofstream fs);

    cadena inversa ();
    std::vector<std::string> prefijos ();
    std::vector<std::string> sufijos ();

    std::vector<cadena> prefijos_vc ();
    std::vector<std::string> subcadenas ();

};
