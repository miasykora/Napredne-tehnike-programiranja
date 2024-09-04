#ifndef FormUnosProizvodaH
#define FormUnosProizvodaH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

class TFormUnosProizvoda : public TForm
{
__published:    // IDE-managed Components
    TEdit *EditNaziv;
    TEdit *EditCijena;
    TEdit *EditKolicina;
    TButton *ButtonSpremiProizvod;
    void __fastcall ButtonSpremiProizvodClick(TObject *Sender);

private:    // User declarations
    TStringList *proizvodi;

public:     // User declarations
    __fastcall TFormUnosProizvoda(TComponent* Owner, TStringList *proizvodi);
};

#endif

