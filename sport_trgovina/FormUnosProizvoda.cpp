#include <vcl.h>
#pragma hdrstop
#include "FormUnosProizvoda.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormUnosProizvoda *FormUnosProizvoda;

__fastcall TFormUnosProizvoda::TFormUnosProizvoda(TComponent* Owner, TStringList *proizvodi)
    : TForm(Owner), proizvodi(proizvodi)
{
}

void __fastcall TFormUnosProizvoda::ButtonSpremiProizvodClick(TObject *Sender)
{
    String naziv = EditNaziv->Text;
    String cijena = EditCijena->Text;
    String kolicina = EditKolicina->Text;

    String proizvod = naziv + "," + cijena + "," + kolicina;
    proizvodi->Add(proizvod);

    ShowMessage("Proizvod spremljen!");
    Close();
}

