/*Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Símbolos, alfabetos y cadenas
Autor: Yago Pérez Molanes
Correo: alu0101254678@ull.edu.es
Fecha: 13/10/2021
Archivo Práctica_2/cadena.cpp: implementacion de la clase
cadena, una cadena pertenece a un determinado alfabeto,
se implemenntan los métodos para fijar la cadena,
obtener la cadena, añadir los simbolos de la cadena a un
alfabeto, imprimir la cadena, calcular su longitud, imprimirla,
y los distintas operaciones, (inversa, prefijos, sufijos, subcadenas)
*/

#include <fstream>

#include "./cadena.hpp"
#include "./alfabeto.hpp"

cadena::cadena () {}
cadena::cadena (const char* s) {}

cadena::cadena (const std::string str) {
  if (str.size() == 0) {
    palabra = '&';
  }
  
  palabra = str;
}

cadena::~cadena () {
  palabra.clear();
}

/**
 * Establece el valor de la cadena
 * atributo interno importante (string)
 **/
void cadena::set_cadena(std::string aux) {
  palabra = aux;
}

/**
 * Obtiene el valor de la cadena
 **/
std::string cadena::get_cadena() {
  return palabra;
}

/**
 * Añade los simbolos de una cadena a un alfabeto
 * (para cuando no nos den el alfabeto)
 **/
alfabeto cadena::anadir_alfabeto(alfabeto alfab) {
  std::string aux;
  for (unsigned int i = 0; i < palabra.size(); i++) {
    aux.push_back(palabra[i]);
    alfab.add(aux);
    aux.clear();
  }
  return alfab;
}

void cadena::imprimir_cadena() {
  std::cout << palabra << std::endl;
}

/**
 * Imprime la cadena en un fichero
 **/
void cadena::imprimir_cadena(std::ofstream fs) {
  fs << palabra << "\n";
}

/**
 * Calcula la longitud de la cadena y
 * la devuelve
 **/
int cadena::longitud_cadena() {
  return palabra.size();
} 

/**
 * Calcula la inversa de una cadena, y
 * la devuelve como otra cadena 
 **/
cadena cadena::inversa() {
  std::string aux = palabra;
  int j = 0;
  for (int i = palabra.size() - 1; i >= 0; i--) {
    aux[j] = palabra[i];
    j++;
  }
  cadena cadena_invertida = cadena(aux);

  return cadena_invertida;
}

/**
 * Calcula los prefijos de una cadena y los
 * devuelve como un vector de strings
 **/
std::vector <std::string> cadena::prefijos() {
  std::vector <std::string> prefijos;
  std::string aux;
  
  prefijos.push_back("&");

  for (unsigned int i = 0; i < palabra.size(); i++) {
    aux += palabra[i];
    prefijos.push_back(aux); 
  }

  return prefijos;
}

std::vector <cadena> cadena::prefijos_vc() {
  std::vector <cadena> prefijos;
  cadena aux;

  aux.palabra = "&";

  prefijos.push_back(aux);

  for (unsigned int i = 0; i < palabra.size(); i++) {
    aux.palabra += palabra[i];
    prefijos.push_back(aux);
  }

  return prefijos;
}

/**
 * Calcula los sufijos de una cadena y los
 * devuelve como un vector de strings
 **/
std::vector <std::string> cadena::sufijos() {
  std::vector <std::string> sufijos;
  std::string aux;

  for (int i = palabra.size() - 1; i >= 0; i--) {
    aux = palabra[i] + aux;
    sufijos.push_back(aux);
  }

  sufijos.push_back("&");
  return sufijos;
}

/**
 * Calcula las subcadenas de una cadena y las devuelve
 * como un vector de strings
 **/
std::vector<std::string>cadena::subcadenas() {
  std::vector<std::string> subcadenas;	
  for (unsigned int i = 0; i < palabra.length(); i++) {
    for (unsigned int j = 1 + i; j < palabra.length()+1; j++) {
      subcadenas.push_back(palabra.substr(i, j - i)); 
    }
	}
  return subcadenas;
}

bool cadena::operator==(cadena cad) {
  if (get_cadena() == cad.get_cadena()) {
    return true;
  } else {
    return false;
  }
}

bool cadena::operator>(cadena cad) {
  std::vector<std::string> subcadenas_entrada = this->subcadenas();

  for (unsigned int i = 0; i < subcadenas_entrada.size(); i++) {
    if (cad.get_cadena() == subcadenas_entrada[i]) {
      return true;
    }
  }
  return false;
}

bool cadena::operator<(cadena cad) {
  std::vector<std::string> subcadenas_entrada = cad.subcadenas();

  for (unsigned int i = 0; i < subcadenas_entrada.size(); i++) {
    if (this->get_cadena() == subcadenas_entrada[i]) {
      return true;
    }
  }
  return false;
}

void cadena::concatenacion(cadena cad) {
  palabra += cad.palabra;
  return;
}

/**
 * Modificacion de clase, concatenacion alternativa
 * hola - adios = haodliaos
 **/
void cadena::concatenacion_alternativa(cadena cad) {
  cadena cad_aux = cadena();

  int contador = 0;

  for (unsigned int i = 0; i < palabra.size(); i++) {
    cad_aux.palabra += palabra[i];
    if (i < cad.palabra.size()) {
      cad_aux.palabra += cad.palabra[i];
    }
    
    // cad_aux.palabra += cad.palabra[i];
    contador = i;
  }

  if (cad.palabra.size() > palabra.size()) {
    for (unsigned int i = contador + 1; i <= cad.palabra.size(); i++) {
      cad_aux.palabra += cad.palabra[i];
    }
    
  }
  // std::cout << cad_aux.palabra << std::endl;
  palabra = cad_aux.palabra;
  
}

void cadena::potencia(int exponente) {
  std::string aux = palabra;
  for (int i = 1; i < exponente; i++) {
    palabra += aux;
  }
}
