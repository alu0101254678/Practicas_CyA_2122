#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>

#include "./cadena.hpp"

class lenguaje {
  private:
    std::set<std::string> leng;
  public:
    lenguaje ();
    ~lenguaje ();
    void add (cadena cad);
    std::set<std::string> get_lenguaje();

    std::ostream& operator<< (std::ostream& os);
    
};
