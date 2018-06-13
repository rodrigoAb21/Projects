//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

// --------------------------- METODOS AUXILIARES ---------------------------


String limpiarCadena(String mensaje){
	String resultado = "";
	mensaje = mensaje.UpperCase();
	String c = " ";
	for(int i = 1; i <= mensaje.Length(); i++){
		c = mensaje[i];
		if(c >= "A" && c <= "Z"){
		   resultado = resultado + c;
		}else{
			if(c == "�"){
				resultado = resultado + "A";
			}else{
				if(c == "�"){
					resultado = resultado + "E";
				}else{
					if(c == "�"){
						resultado = resultado + "I";
					}else{
						if(c == "�"){
							resultado = resultado + "O";
						}else{
							 if(c == "�" || c == "�"){
								resultado = resultado + "U";
							}else{
								if(c == "�"){
									resultado = resultado + "�";
								}
							}
						}
					}
				}
			}
		}
	}

	return resultado;

}


String rellenar(String mensaje, int c){
	String resultado = mensaje;
	int mod = mensaje.Length() % c;
	if(mod > 0){
		for(int i = c - mod; (i > 0); i--){
			resultado = resultado + "X";
		}
	}
	return resultado;
}

bool primo(int n) {
    if(n == 1) return false;
	int raiz = int(sqrtf(n));
	for(int i = 2; i <= raiz; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

bool par(int n){
	if(n % 2 == 0){
		return true;
	}
	return false;
}

bool impar(int n){
	return !par(n);
}

int cantPrimos(int n){
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(primo(i)){
			c++;
		}
	}
	return c;
}

int cantPares(int n){
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0){
			c++;
		}
	}
	return c;
}

int cantParesNoP(int n){
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0){
			c++;
		}
	}
	return c - 1;
}


int cantImparesNoP(int n){
	int c = 0;
	for(int i = 1; i <= n; i++){
		if((!primo(i)) && (i % 2 == 1)){
			c++;
		}
	}
	return c;
}

int cantImpares(int n){
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			c++;
		}
	}
	return c;
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//CIFRAR POR GRUPO
	String s = RichEdit1->Text;
	String clave = "";
	do{
		clave = InputBox("Key o Clave", "Clave: ", "Solo numeros [1 - 9]");
		clave = clave.Trim();
	} while(clave.Length() == 0);

	int const columnas = clave.Length();
	String mensaje = rellenar(limpiarCadena(s), columnas);
	int const filas = mensaje.Length() / columnas;

	String matriz[1000][20];
	String matriz2[1000][20];

	// Cargando matriz
	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= filas; i++){
			for(int j = 1; j <= columnas; j++){
				matriz[i][j] = mensaje[m];
				m++;
			}
		}
	}

	String colX = "";

	//copiando ordenado segun la clave
	int col = 0;

	//se recorre toda la clave
	for(int x = 1; x <= clave.Length(); x++){

		//se copia la columna correspondiente al primer caracter de la clave
		col = StrToInt(clave[x]);
		for(int i = 1; i <= filas; i++){
			colX = colX + matriz[i][col];
		}

		//se pega en la nueva matriz recorriendo la columna copiada
		for(int f = 1; f <= filas; f++){
			matriz2[f][x] = colX[f];
		}
		colX = "";
	}


	String cifrado = "";

	for(int j = 1; j <= filas; j++){
		for(int i = 1; i <= columnas; i++){
			cifrado = cifrado + matriz2[j][i];
		}
		cifrado = cifrado + " ";
	}


	RichEdit2->Text = cifrado;

}






//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//DESCIFRAR POR GRUPO
	String s = RichEdit1->Text;
	String clave = "";
	do{
		clave = InputBox("Key o Clave", "Clave: ", "Solo numeros [1 - 9]");
		clave = clave.Trim();
	} while(clave.Length() == 0);

	int const columnas = clave.Length();
	String mensaje = rellenar(limpiarCadena(s), columnas);
	int const filas = mensaje.Length() / columnas;

	String matriz[1000][20];
	String matriz2[1000][20];

	// Cargando matriz
	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= filas; i++){
			for(int j = 1; j <= columnas; j++){
				matriz[i][j] = mensaje[m];
				m++;
			}
		}
	}

	String colX = "";

	//copiando ordenado segun la clave
	int col = 0;

	//se recorre toda la clave
	for(int x = 1; x <= clave.Length(); x++){

		//se copia la columna correspondiente al primer caracter de la clave
		col = StrToInt(clave[x]);
		for(int i = 1; i <= filas; i++){
			colX = colX + matriz[i][x];
		}

		//se pega en la nueva matriz recorriendo la columna copiada
		for(int f = 1; f <= filas; f++){
			matriz2[f][col] = colX[f];
		}
		colX = "";
	}


	String cifrado = "";

	for(int j = 1; j <= filas; j++){
		for(int i = 1; i <= columnas; i++){
			cifrado = cifrado + matriz2[j][i];
		}
		cifrado = cifrado + " ";
	}


	RichEdit2->Text = cifrado;




}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	String mensaje = RichEdit1->Text;
    mensaje = limpiarCadena(mensaje);
	String primos = "";
	String pares = "";
	String impares = "";

	for(int i = 1; i <= mensaje.Length(); i++){
		if(primo(i)){
			primos = primos + mensaje[i];
		} else {
			if(par(i)){
				pares = pares + mensaje[i];
			} else {
				impares = impares + mensaje[i];
			}
		}
	}

	String cifrado = primos + pares + impares;

    RichEdit2->Text = cifrado;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Cifrado1Click(TObject *Sender)
{
    //CIFRAR POR GRUPO
	String s = RichEdit1->Text;
	String clave = "";
	do{
		clave = InputBox("Key o Clave", "Clave: ", "Solo numeros [1 - 9]");
		clave = clave.Trim();
	} while(clave.Length() == 0);

	int const columnas = clave.Length();
	String mensaje = rellenar(limpiarCadena(s), columnas);
	int const filas = mensaje.Length() / columnas;

	String matriz[1000][20];
	String matriz2[1000][20];

	// Cargando matriz
	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= filas; i++){
			for(int j = 1; j <= columnas; j++){
				matriz[i][j] = mensaje[m];
				m++;
			}
		}
	}

	String colX = "";

	//copiando ordenado segun la clave
	int col = 0;

	//se recorre toda la clave
	for(int x = 1; x <= clave.Length(); x++){

		//se copia la columna correspondiente al primer caracter de la clave
		col = StrToInt(clave[x]);
		for(int i = 1; i <= filas; i++){
			colX = colX + matriz[i][col];
		}

		//se pega en la nueva matriz recorriendo la columna copiada
		for(int f = 1; f <= filas; f++){
			matriz2[f][x] = colX[f];
		}
		colX = "";
	}


	String cifrado = "";

	for(int j = 1; j <= filas; j++){
		for(int i = 1; i <= columnas; i++){
			cifrado = cifrado + matriz2[j][i];
		}
		cifrado = cifrado + " ";
	}


	RichEdit2->Text = cifrado;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Descifrado1Click(TObject *Sender)
{
    	//DESCIFRAR POR GRUPO
	String s = RichEdit1->Text;
	String clave = "";
	do{
		clave = InputBox("Key o Clave", "Clave: ", "Solo numeros [1 - 9]");
		clave = clave.Trim();
	} while(clave.Length() == 0);

	int const columnas = clave.Length();
	String mensaje = rellenar(limpiarCadena(s), columnas);
	int const filas = mensaje.Length() / columnas;

	String matriz[1000][20];
	String matriz2[1000][20];

	// Cargando matriz
	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= filas; i++){
			for(int j = 1; j <= columnas; j++){
				matriz[i][j] = mensaje[m];
				m++;
			}
		}
	}

	String colX = "";

	//copiando ordenado segun la clave
	int col = 0;

	//se recorre toda la clave
	for(int x = 1; x <= clave.Length(); x++){

		//se copia la columna correspondiente al primer caracter de la clave
		col = StrToInt(clave[x]);
		for(int i = 1; i <= filas; i++){
			colX = colX + matriz[i][x];
		}

		//se pega en la nueva matriz recorriendo la columna copiada
		for(int f = 1; f <= filas; f++){
			matriz2[f][col] = colX[f];
		}
		colX = "";
	}


	String cifrado = "";

	for(int j = 1; j <= filas; j++){
		for(int i = 1; i <= columnas; i++){
			cifrado = cifrado + matriz2[j][i];
		}
		cifrado = cifrado + " ";
	}


	RichEdit2->Text = cifrado;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cifrado2Click(TObject *Sender)
{
	String mensaje = RichEdit1->Text;
	mensaje = limpiarCadena(mensaje);
	String primos = "";
	String pares = "";
	String impares = "";

	for(int i = 1; i <= mensaje.Length(); i++){
		if(primo(i)){
			primos = primos + mensaje[i];
		} else {
			if(par(i)){
				pares = pares + mensaje[i];
			} else {
				impares = impares + mensaje[i];
			}
		}
	}

	String cifrado = primos + pares + impares;

    RichEdit2->Text = cifrado;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Descifrado2Click(TObject *Sender)
{
	String mensaje = RichEdit1->Text;
	mensaje = limpiarCadena(mensaje);
	int const longitud = mensaje.Length();
	int pri = cantPrimos(longitud);
	int seg = cantParesNoP(longitud);
	String des[1500];

	//ordenando el grupo de los primos
	for(int i = 1; i <= pri; i++){
		for(int j = 1; j <= longitud; j++){
			if(primo(j)){
				des[j] = mensaje[i];
				i++;
			}
		}
	}

	//ordenando el grupo de pares NO PRIMOS
	for(int i = pri + 1; i <= pri+seg; i++){
		for(int j = 1; j <= longitud; j++){
			if(j != 2 && j % 2 == 0){
				des[j] = mensaje[i];
				i++;
			}
		}
	}

	//ordenando el ultimo grupo
	for(int i = pri+seg + 1; i <= longitud; i++){
		for(int j = 1; j <= longitud; j++){
			if(!primo(j) && impar(j)){
				des[j] = mensaje[i];
				i++;
			}
		}
	}


	String descifrado = "";
	for(int i = 1; i <= longitud; i++){
		descifrado = descifrado + des[i];
	}
	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------
