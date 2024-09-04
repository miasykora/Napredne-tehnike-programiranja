object FormUnosProizvoda: TFormUnosProizvoda

  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object EditNaziv: TEdit
    Left = 176
    Top = 24
    Width = 209
    Height = 82
    TabOrder = 0
    Text = 'EditNaziv'
  end
  object EditCijena: TEdit
    Left = 176
    Top = 224
    Width = 209
    Height = 81
    TabOrder = 1
    Text = 'EditCijena'
  end
  object EditKolicina: TEdit
    Left = 176
    Top = 128
    Width = 209
    Height = 81
    TabOrder = 2
    Text = 'EditKolicina'
  end
  object ButtonSpremiProizvod: TButton
    Left = 128
    Top = 360
    Width = 185
    Height = 41
    Caption = 'Spremi'
    TabOrder = 3
  end
  object ButtonOdustani: TButton
    Left = 344
    Top = 360
    Width = 185
    Height = 41
    Caption = 'Odustani'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 4
  end
end
