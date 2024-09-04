#ifndef KUPAC_H
#define KUPAC_H

#include <string>

class Kupac {
private:
    std::string ime;
    std::string adresa;

public:
    Kupac(std::string i, std::string a);
    std::string dohvatiIme() const;
    std::string dohvatiAdresu() const;
    void prikaziInformacije() const;
};

#endif

