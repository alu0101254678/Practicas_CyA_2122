/*Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Símbolos, alfabetos y cadenas
Autor: Yago Pérez Molanes
Correo: alu0101254678@ull.edu.es
Fecha: 13/10/2021
Archivo Práctica_2/alfabeto.cpp: implementacion de la clase
alfabeto, contiene los métodos de inserción, imprimir, y
cálculo del numero de elementos de un alfabeto
*/

#include "./alfabeto.hpp"

alfabeto::alfabeto () {}

alfabeto::~alfabeto () { 
  num_elem = 0;
  alf.clear(); 
}

/** add: añadir un elemento al alfabeto
**/
void alfabeto::add (std::string c) { 
  alf.insert(c);
  num_elem++; 
}

/** imprimir_alfabeto: imprime por pantalla
 * los elementos del alfabeto
 **/ 
void alfabeto::imprimir_alfabeto () {
  std::set<std::string>::iterator it =  alf.begin();

  while (it != alf.end()) {
    std::cout << *it << ", ";
    it++;
  }

  std::cout << "\n";

}

/** cardinal: devuelve el numero de elementos
 * del alfabeto
 **/
int alfabeto::cardinal() {
  return num_elem;
}

