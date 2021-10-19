/*Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Símbolos, alfabetos y cadenas
Autor: Yago Pérez Molanes
Correo: alu0101254678@ull.edu.es
Fecha: 13/10/2021
Archivo Práctica_2/alfabeto.hpp: declaracion de la clase
alfabeto, contiene los métodos de inserción, imprimir, y
cálculo del numero de elementos de un alfabeto
*/

#pragma once

#include <iostream>
#include <set>

class alfabeto {

  /** Contiene dos atributos privados,
   * un conjunto, o set, y un entero
   * para almacenar el numero de elementos
   **/
  private:
    std::set<std::string> alf;
    int num_elem = 0;

  public:
    /** Constructor (no hace nada)
     * Destructor (borra los elementos del conjunto)
     **/
    alfabeto ();
    ~alfabeto ();

    void add (std::string c);
    void imprimir_alfabeto ();

    int cardinal ();
};
