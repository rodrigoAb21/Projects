object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 551
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 24
    Top = 24
    Width = 729
    Height = 201
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 0
    Zoom = 100
  end
  object RichEdit2: TRichEdit
    Left = 24
    Top = 296
    Width = 737
    Height = 217
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit2')
    ParentFont = False
    TabOrder = 1
    Zoom = 100
  end
  object MainMenu1: TMainMenu
    Left = 384
    Top = 280
    object Desplazamiento1: TMenuItem
      Caption = 'Desplazamiento'
      object Puro1: TMenuItem
        Caption = 'Puro'
      end
      object Conclave1: TMenuItem
        Caption = 'Con clave'
      end
    end
    object ransposicion1: TMenuItem
      Caption = 'Transposicion'
      object Grupo1: TMenuItem
        Caption = 'Grupos'
        object Cifrado1: TMenuItem
          Caption = 'Cifrado'
          OnClick = Cifrado1Click
        end
        object Descifrado1: TMenuItem
          Caption = 'Descifrado'
          OnClick = Descifrado1Click
        end
      end
      object Series1: TMenuItem
        Caption = 'Series'
        object Cifrado2: TMenuItem
          Caption = 'Cifrado'
          OnClick = Cifrado2Click
        end
        object Descifrado2: TMenuItem
          Caption = 'Descifrado'
          OnClick = Descifrado2Click
        end
      end
      object Columnas1: TMenuItem
        Caption = 'Columnas'
      end
      object Filas1: TMenuItem
        Caption = 'Filas'
      end
      object ZigZag1: TMenuItem
        Caption = 'Zig - Zag'
      end
    end
    object Sustitucion1: TMenuItem
      Caption = 'Sustitucion'
      object MonoAlfabetica1: TMenuItem
        Caption = 'Mono Alfabetica'
      end
      object PoliAlfabetica1: TMenuItem
        Caption = 'Poli Alfabetica'
      end
    end
  end
end
