#include "Narudzba.h"
#include <iostream>

Narudzba::Narudzba(Kupac k)
    : kupac(k), ukupnaCijena(0.0) {}

void Narudzba::dodajProizvod(Proizvod p) {
    proizvodi.push_back(p);
    ukupnaCijena += p.dohvatiCijenu() * p.dohvatiKolicinu();
}

double Narudzba::izracunajUkupnuCijenu() {
    return ukupnaCijena;
}

void Narudzba::prikaziNarudzbu() const {
    std::cout << "Kupac: " << kupac.dohvatiIme() << "\n"
              << "Adresa: " << kupac.dohvatiAdresu() << "\n"
              << "Proizvodi:\n";
    for (const auto& proizvod : proizvodi) {
        proizvod.prikaziInformacije();
    }
    std::cout << "Ukupna cijena: " << ukupnaCijena << std::endl;
}

