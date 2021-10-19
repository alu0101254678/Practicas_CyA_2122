#include <iostream>

#include "./lenguaje.hpp"
#include "./cadena.hpp"

lenguaje::lenguaje() {}

lenguaje::~lenguaje() {}

void lenguaje::add(cadena cad) {
  leng.insert(cad.get_cadena());
}

std::set<std::string> lenguaje::get_lenguaje() {
  return leng;
}

std::ostream& lenguaje::operator<< (std::ostream& os) {

  os << "{ ";
  std::set<std::string> cad = this->get_lenguaje();

  for (auto it = cad.cbegin(); it != cad.cend(); it++) {
    os << *it << ' ';
  }

  os << "}";
  os << "\n";
  return os;

}


