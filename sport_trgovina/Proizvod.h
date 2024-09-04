																							 #ifndef PROIZVOD_H
#define PROIZVOD_H
#include <string>
#include <fstream>

class Proizvod {
private:
    std::string naziv;
    double cijena;
    int kolicina;

public:
    Proizvod(std::string n, double c, int k);
    std::string dohvatiNaziv() const;
    double dohvatiCijenu() const;
    int dohvatiKolicinu() const;
    void postaviKolicinu(int k);
    void prikaziInformacije() const;

    // Binarno spremanje
    void spremiUBinarnuDatoteku(std::ofstream &out) const;
    // Binarno èitanje
    void ucitajIzBinarneDatoteke(std::ifstream &in);
};

#endif
