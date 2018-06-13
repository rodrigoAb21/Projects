//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
	TRichEdit *RichEdit2;
	TMainMenu *MainMenu1;
	TMenuItem *Desplazamiento1;
	TMenuItem *ransposicion1;
	TMenuItem *Sustitucion1;
	TMenuItem *Puro1;
	TMenuItem *Conclave1;
	TMenuItem *Grupo1;
	TMenuItem *Series1;
	TMenuItem *Columnas1;
	TMenuItem *Filas1;
	TMenuItem *ZigZag1;
	TMenuItem *MonoAlfabetica1;
	TMenuItem *PoliAlfabetica1;
	TMenuItem *Cifrado1;
	TMenuItem *Descifrado1;
	TMenuItem *Cifrado2;
	TMenuItem *Descifrado2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Cifrado1Click(TObject *Sender);
	void __fastcall Descifrado1Click(TObject *Sender);
	void __fastcall Cifrado2Click(TObject *Sender);
	void __fastcall Descifrado2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif