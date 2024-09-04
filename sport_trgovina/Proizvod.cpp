#include "Proizvod.h"
#include <iostream>

Proizvod::Proizvod(std::string n, double c, int k)
    : naziv(n), cijena(c), kolicina(k) {}

std::string Proizvod::dohvatiNaziv() const {
    return naziv;
}

double Proizvod::dohvatiCijenu() const {
    return cijena;
}

int Proizvod::dohvatiKolicinu() const {
    return kolicina;
}

void Proizvod::postaviKolicinu(int k) {
    kolicina = k;
}

void Proizvod::prikaziInformacije() const {
    std::cout << "Naziv: " << naziv << "\n"
              << "Cijena: " << cijena << "\n"
              << "Kolièina: " << kolicina << std::endl;
}

void Proizvod::spremiUBinarnuDatoteku(std::ofstream &out) const {
	size_t duzina = naziv.size();
	out.write(reinterpret_cast<const char*>(&duzina), sizeof(duzina));
    out.write(naziv.c_str(), duzina);
    out.write(reinterpret_cast<const char*>(&cijena), sizeof(cijena));
    out.write(reinterpret_cast<const char*>(&kolicina), sizeof(kolicina));
}

void Proizvod::ucitajIzBinarneDatoteke(std::ifstream &in) {
    size_t duzina;
    in.read(reinterpret_cast<char*>(&duzina), sizeof(duzina));
    naziv.resize(duzina);
    in.read(&naziv[0], duzina);
    in.read(reinterpret_cast<char*>(&cijena), sizeof(cijena));
    in.read(reinterpret_cast<char*>(&kolicina), sizeof(kolicina));
}
