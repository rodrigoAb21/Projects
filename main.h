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
class TProyecto_Cripto : public TForm
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
	TMenuItem *Cifrar1;
	TMenuItem *Descifrar1;
	TMenuItem *Cifrar2;
	TMenuItem *Descifrar2;
	TMenuItem *Cifrar3;
	TMenuItem *Descifrar3;
	TMenuItem *Cifrar4;
	TMenuItem *Descifrar4;
	TMenuItem *Cifrar5;
	TMenuItem *Descifrar5;
	TMenuItem *Cifrar6;
	TMenuItem *Descifrar6;
	TMenuItem *Cifrar7;
	TMenuItem *Descifrar7;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Cifrado1Click(TObject *Sender);
	void __fastcall Descifrado1Click(TObject *Sender);
	void __fastcall Cifrado2Click(TObject *Sender);
	void __fastcall Descifrado2Click(TObject *Sender);
	void __fastcall Cifrar2Click(TObject *Sender);
	void __fastcall Descifrar2Click(TObject *Sender);
	void __fastcall Cifrar1Click(TObject *Sender);
	void __fastcall Descifrar1Click(TObject *Sender);
	void __fastcall Cifrar3Click(TObject *Sender);
	void __fastcall Descifrar3Click(TObject *Sender);
	void __fastcall Cifrar4Click(TObject *Sender);
	void __fastcall Descifrar4Click(TObject *Sender);
	void __fastcall Cifrar5Click(TObject *Sender);
	void __fastcall Descifrar5Click(TObject *Sender);
	void __fastcall Cifrar6Click(TObject *Sender);
	void __fastcall Descifrar6Click(TObject *Sender);
	void __fastcall Cifrar7Click(TObject *Sender);
	void __fastcall Descifrar7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TProyecto_Cripto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProyecto_Cripto *Proyecto_Cripto;
//---------------------------------------------------------------------------
#endif
