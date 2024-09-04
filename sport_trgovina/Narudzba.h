
                                                                                                               #ifndef NARUDZBA_H
#define NARUDZBA_H
#include <vector>
#include "Proizvod.h"
#include "Kupac.h"

class Narudzba {
private:
    Kupac kupac;
    std::vector<Proizvod> proizvodi;
    double ukupnaCijena;

public:
    Narudzba(Kupac k);
    void dodajProizvod(Proizvod p);
    double izracunajUkupnuCijenu();
    void prikaziNarudzbu() const;
};

#endif
