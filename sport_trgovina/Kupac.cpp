#include "Kupac.h"
#include <iostream>

Kupac::Kupac(std::string i, std::string a)
    : ime(i), adresa(a) {}

std::string Kupac::dohvatiIme() const {
    return ime;
}

std::string Kupac::dohvatiAdresu() const {
    return adresa;
}

void Kupac::prikaziInformacije() const {
    std::cout << "Ime: " << ime << "\n"
              << "Adresa: " << adresa << std::endl;
}

