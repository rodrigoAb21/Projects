object Proyecto_Cripto: TProyecto_Cripto
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Proyecto_Cripto'
  ClientHeight = 594
  ClientWidth = 804
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 297
    Width = 225
    Height = 25
    Caption = 'RESULTADO OBTENIDO'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 296
    Top = 8
    Width = 194
    Height = 25
    Caption = 'ENTRADA DE TEXTO'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object RichEdit1: TRichEdit
    Left = 24
    Top = 48
    Width = 737
    Height = 225
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    Zoom = 100
  end
  object RichEdit2: TRichEdit
    Left = 24
    Top = 344
    Width = 737
    Height = 217
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit2')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    Zoom = 100
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 240
    object Desplazamiento1: TMenuItem
      Caption = 'Desplazamiento'
      object Puro1: TMenuItem
        Caption = 'Puro'
        object Cifrar4: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar4Click
        end
        object Descifrar4: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar4Click
        end
      end
      object Conclave1: TMenuItem
        Caption = 'Con clave'
        object Cifrar5: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar5Click
        end
        object Descifrar5: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar5Click
        end
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
        object Cifrar1: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar1Click
        end
        object Descifrar1: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar1Click
        end
      end
      object Filas1: TMenuItem
        Caption = 'Filas'
        object Cifrar2: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar2Click
        end
        object Descifrar2: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar2Click
        end
      end
      object ZigZag1: TMenuItem
        Caption = 'Zig - Zag'
        object Cifrar6: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar6Click
        end
        object Descifrar6: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar6Click
        end
      end
    end
    object Sustitucion1: TMenuItem
      Caption = 'Sustitucion'
      object MonoAlfabetica1: TMenuItem
        Caption = 'Mono Alfabetica'
        object Cifrar3: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar3Click
        end
        object Descifrar3: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar3Click
        end
      end
      object PoliAlfabetica1: TMenuItem
        Caption = 'Poli Alfabetica'
        object Cifrar7: TMenuItem
          Caption = 'Cifrar'
          OnClick = Cifrar7Click
        end
        object Descifrar7: TMenuItem
          Caption = 'Descifrar'
          OnClick = Descifrar7Click
        end
      end
    end
  end
end
