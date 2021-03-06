//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProyecto_Cripto *Proyecto_Cripto;
//---------------------------------------------------------------------------
__fastcall TProyecto_Cripto::TProyecto_Cripto(TComponent* Owner)
	: TForm(Owner)
{
	RichEdit1->Text = "";
	RichEdit2->Text = "";
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


String limpiarCadenaI(String mensaje){
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
									resultado = resultado + "N";
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

String nuevoABC(String clave){

	String alfabeto = "ABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	String c = limpiarCadena(clave);
	String n = c[1];

	for(int i = 1; i <= c.Length(); i++){
		if(n.Pos(c[i]) <= 0){
			n = n + c[i];
		}
	}

	for(int i = 1; i <= alfabeto.Length(); i++){
		if(n.Pos(alfabeto[i]) <= 0){
			n = n + alfabeto[i];
		}
	}

	return n;
}


String rellenoZigZag(String texto, int filas){
	int elementos = (filas * 2) - 2;
	while(true){
		if(texto.Length() % elementos == 0){
			break;
		}
		texto = texto + "X";
	}
	return texto;
}


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


void __fastcall TProyecto_Cripto::Button1Click(TObject *Sender)
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


void __fastcall TProyecto_Cripto::Button2Click(TObject *Sender)
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

void __fastcall TProyecto_Cripto::Button3Click(TObject *Sender)
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


void __fastcall TProyecto_Cripto::Cifrado1Click(TObject *Sender)
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

void __fastcall TProyecto_Cripto::Descifrado1Click(TObject *Sender)
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

void __fastcall TProyecto_Cripto::Cifrado2Click(TObject *Sender)
{
    // Cifrado por Series
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




void __fastcall TProyecto_Cripto::Descifrado2Click(TObject *Sender)
{
    // Descifrado por series
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

void __fastcall TProyecto_Cripto::Cifrar2Click(TObject *Sender)
{
	//Cifrado por Filas

	String mensaje = RichEdit1->Text;

	int clave = 0;

	try{
		clave = StrToInt(InputBox("Key o Clave", "Cantidad de filas: ", "3"));
	} catch(const Exception &e){
		ShowMessage("Debe ingresar un numero valido!");
	}

	String matriz[500][500];

	mensaje = rellenar(limpiarCadena(mensaje), clave);


	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= (mensaje.Length()/clave); i++){
			for(int j = 1; j <= clave; j++){
				matriz[j][i] = mensaje[m];
				m++;
			}
		}
	}

	String cifrado = "";

	for(int i = 1; i <= clave; i++){
		for(int j = 1; j <= (mensaje.Length()/clave); j++){
			cifrado = cifrado + matriz[i][j];
		}
	}


	RichEdit2->Text = cifrado;

}
//---------------------------------------------------------------------------


void __fastcall TProyecto_Cripto::Descifrar2Click(TObject *Sender)
{
    // Descifrado por filas
	String mensaje = RichEdit1->Text;

	int clave = 0;

	try{
		clave = StrToInt(InputBox("Key o Clave", "Cantidad de filas: ", "3"));
	} catch(const Exception &e){
		ShowMessage("Debe ingresar un numero valido!");
	}

	String matriz[500][500];

	mensaje = limpiarCadena(mensaje);


	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= clave; i++){
			for(int j = 1; j <= (mensaje.Length()/clave); j++){
				matriz[j][i] = mensaje[m];
				m++;
			}
		}
	}

	String descifrado = "";

	for(int i = 1; i <= (mensaje.Length()/clave); i++){
		for(int j = 1; j <= clave; j++){
			descifrado = descifrado + matriz[i][j];
		}
	}


	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Cifrar1Click(TObject *Sender)
{
    //Cifrado por columnas
	   String mensaje = RichEdit1->Text;

	int clave = 0;

	try{
		clave = StrToInt(InputBox("Key o Clave", "Cantidad de filas: ", "3"));
	} catch(const Exception &e){
		ShowMessage("Debe ingresar un numero valido!");
	}

	String matriz[500][500];
	String cadena = "";
	mensaje = rellenar(limpiarCadena(mensaje), clave);

	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= (mensaje.Length()/clave); i++){
			for(int j = 1; j <= clave; j++){
				matriz[i][j] = mensaje[m];
				m++;
			}

		}
	}

	String cifrado = "";

	for(int i = 1; i <= clave; i++){
		for(int j = 1; j <= (mensaje.Length()/clave); j++){
			cifrado = cifrado + matriz[j][i];
		}
	}


	RichEdit2->Text = cifrado;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar1Click(TObject *Sender)
{
    // Descifrado por columnas
	String mensaje = RichEdit1->Text;

	int clave = 0;

	try{
		clave = StrToInt(InputBox("Key o Clave", "Cantidad de columnas: ", "3"));
	} catch(const Exception &e){
		ShowMessage("Debe ingresar un numero valido!");
	}

	String matriz[500][500];

	mensaje = limpiarCadena(mensaje);


	for(int m = 1; m <= mensaje.Length(); m++){
		for(int i = 1; i <= clave; i++){
			for(int j = 1; j <= (mensaje.Length()/clave); j++){
				matriz[i][j] = mensaje[m];
				m++;
			}
		}
	}

	String descifrado = "";

	for(int i = 1; i <= (mensaje.Length()/clave); i++){
		for(int j = 1; j <= clave; j++){
			descifrado = descifrado + matriz[j][i];
		}
	}


	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------


void __fastcall TProyecto_Cripto::Cifrar3Click(TObject *Sender)
{
 //Cifrado monoalfabetica (Afin)  a = 11  b = 3

	String algo = RichEdit1->Text;
	algo = limpiarCadena(algo);
	String alfabeto = "ABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	String a = "";
	int posLetra = 0;
	int nuevaPos = 0;

	for(int i = 1; i <= algo.Length(); i++){
		posLetra = alfabeto.Pos(algo[i]);
		if(posLetra > 0){
			// formula = ((m * a )+ b) mod 27
			// se agrego el -1 y +1 debido a que el lenguaje no trabaja desde el indice 0
			nuevaPos = (((posLetra - 1) * 11) + 3) % 27 + 1;

			a = a + alfabeto[nuevaPos];
		}
	}

	RichEdit2->Text = a;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar3Click(TObject *Sender)
{
//Descifrado monoalfabetica (Afin) b = 3  inv(a,27) = 5
	String algo = RichEdit1->Text;
	algo = limpiarCadena(algo);

	String alfabeto = "ABCDEFGHIJKLMN�OPQRSTUVWXYZ";

	String a = "";
	int posLetra = 0;
	int nuevaPos = 0;

	for(int i = 1; i <= algo.Length(); i++){
		posLetra = alfabeto.Pos(algo[i]);
		if(posLetra > 0){
			// formula = ((posCifrado - b ) * inv(a,27)) mod 27
			// se agrego el -1 y +1 debido a que el lenguaje no trabaja desde el indice 0
			nuevaPos = (((posLetra - 3 - 1) * 5) % 27) + 1;

			//caso especial... en caso de que posCifrado sea menor que "b" (b = 3) se debe sumarle +27
			if(posLetra < 4) nuevaPos = (((posLetra + (-3 + 27 - 1)) * 5) % 27) + 1;
			a = a + alfabeto[nuevaPos];
		}
	}

	RichEdit2->Text = a;
}
//---------------------------------------------------------------------------



void __fastcall TProyecto_Cripto::Cifrar4Click(TObject *Sender)
{
	//Desplazamiento Puro (Cesar) -- Cifrado
	String texto = RichEdit1->Text;
	texto = limpiarCadena(texto);

	String alfabeto = "ABCDEFGHIJKLMN�OPQRSTUVWXYZ";

	String cifrado = "";
	int posLetra = 0;
	int nuevaPos = 0;
	int desplazamiento = 3;
	desplazamiento = StrToInt(InputBox("Ingresar desplazamiento", "Desplazamiento", "1"));

	for(int i = 1; i <= texto.Length(); i++){
		posLetra = alfabeto.Pos(texto[i]);
		nuevaPos = ((posLetra + desplazamiento - 1) % 27) + 1;
		cifrado = cifrado + alfabeto[nuevaPos];
	}

	RichEdit2->Text = cifrado;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar4Click(TObject *Sender)
{
	//Desplazamiento Puro (Cesar) -- Descifrado
	String texto = RichEdit1->Text;
	texto = limpiarCadena(texto);

	String alfabeto = "ABCDEFGHIJKLMN�OPQRSTUVWXYZ";

	String descifrado = "";
	int posLetra = 0;
	int nuevaPos = 0;

	int desplazamiento = 3;
	desplazamiento = StrToInt(InputBox("Ingresar desplazamiento", "Desplazamiento", "1"));

	for(int i = 1; i <= texto.Length(); i++){
		posLetra = alfabeto.Pos(texto[i]);
		nuevaPos = ((posLetra - desplazamiento + 27 - 1) % 27) + 1;
		descifrado = descifrado + alfabeto[nuevaPos];
	}

	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Cifrar5Click(TObject *Sender)
{
	//Desplazamiento con Clave (Cesar) -- Cifrado
    String clave = InputBox("Clave", "Clave: ", "Clave");
	String alfabeto = nuevoABC(clave);

    String texto = RichEdit1->Text;
	texto = limpiarCadena(texto);

	String cifrado = "";
	int posLetra = 0;
	int nuevaPos = 0;
	int desplazamiento = 3;
	desplazamiento = StrToInt(InputBox("Ingresar desplazamiento", "Desplazamiento", "1"));

	for(int i = 1; i <= texto.Length(); i++){
		posLetra = alfabeto.Pos(texto[i]);
		nuevaPos = ((posLetra + desplazamiento - 1) % 27) + 1;
		cifrado = cifrado + alfabeto[nuevaPos];
	}

	RichEdit2->Text = cifrado;

}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar5Click(TObject *Sender)
{
	//Desplazamiento con Clave (Cesar) -- Descifrado

	String clave = InputBox("Clave", "Clave: ", "Clave");
	String alfabeto = nuevoABC(clave);

    String texto = RichEdit1->Text;
	texto = limpiarCadena(texto);

	String descifrado = "";
	int posLetra = 0;
	int nuevaPos = 0;

	int desplazamiento = 3;
	desplazamiento = StrToInt(InputBox("Ingresar desplazamiento", "Desplazamiento", "1"));

	for(int i = 1; i <= texto.Length(); i++){
		posLetra = alfabeto.Pos(texto[i]);
		nuevaPos = ((posLetra - desplazamiento + 27 - 1) % 27) + 1;
		descifrado = descifrado + alfabeto[nuevaPos];
	}

	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------


void __fastcall TProyecto_Cripto::Cifrar6Click(TObject *Sender)
{
	// Cifrado Zig Zag
	String texto = RichEdit1->Text;
	int filas = StrToInt(InputBox("Filas", "Filas: ", "3"));
	texto  = rellenoZigZag(limpiarCadena(texto), filas);
	int f = 1;
	int c = 1;
	bool sw = true;
	String matriz[100][500];

	for(int i = 1; i <= filas; i++){
		for(int j = 1; j <= texto.Length(); j++){
			matriz[i][j] = "";
		}
	}


	for(int i = 1; i <= texto.Length(); i++){
		matriz[f][c] = texto[i];
		//desciende
		if(sw){
			if(f != filas){
				f++;
			} else {
				sw = false;
				f--;
			}
		}else{
			if(f != 1){
				f--;
			} else {
				sw = true;
				f++;
			}
		}
		c++;
	}

	String cifrado = "";
	for(int i = 1; i <= filas; i++){
		for(int j = 1; j <= texto.Length(); j++){
			cifrado = cifrado + matriz[i][j];
		}
	}

	RichEdit2->Text = cifrado;



}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar6Click(TObject *Sender)
{
	// Descifrado Zig Zag

	String texto = RichEdit1->Text;
	int filas = StrToInt(InputBox("Filas", "Filas: ", "3"));

	String descifrado = "";

	//inicializando
	int msgLen = texto.Length(), i, j, k = -1, row = 1, col = 1, m = 1;
	String railMatrix[100][500];

	//matriz vacia
	for(i = 1; i <= filas; ++i)
		for(j = 1; j <= msgLen; ++j)
			railMatrix[i][j] = "";

	//rellenar con * el zig zag
	for(i = 1; i <= msgLen; ++i){
		railMatrix[row][col++] = "*";

		if(row == 1 || row == filas)
			k= k * (-1);

        row = row + k;
    }

	//Reemplazando * por el texto
	for(i = 1; i <= filas; ++i)
		for(j = 1; j <= msgLen; ++j)
			if(railMatrix[i][j] == "*")
				railMatrix[i][j] = texto[m++];

	row = col = 1;
	k = -1;

    //Leyendo en zig zag
	for(i = 1; i <= msgLen; ++i){
		descifrado = descifrado + railMatrix[row][col++];

		if(row == 1 || row == filas)
			k= k * (-1);

        row = row + k;
	}

	RichEdit2->Text = descifrado;

}
//---------------------------------------------------------------------------


void __fastcall TProyecto_Cripto::Cifrar7Click(TObject *Sender)
{
	// Cifrado Polialfabetica

	char texto[1000];
	AnsiString r(limpiarCadenaI(RichEdit1->Text).c_str());
	strcpy(texto, r.c_str());

	AnsiString clave(InputBox("Clave", "Clave: ", "HELLO"));
	char key[1000];
	strcpy(key, clave.c_str());

	int msgLen = strlen(texto), keyLen = strlen(key), i, j;

	char nuevaClave[500], cifrado[500];

	//creando una clave nueva
	for(i = 0, j = 0; i < msgLen; ++i, ++j){
		if(j == (keyLen))
			j = 0;
		nuevaClave[i] = key[j];
	}

	nuevaClave[i] = '\0';


	//cifrando
	for(i = 0; i < msgLen; ++i)
		cifrado[i] = (((texto[i] + nuevaClave[i]) % 26) ) + 'A';

	cifrado[i] = '\0';


	RichEdit2->Text = cifrado;
}
//---------------------------------------------------------------------------

void __fastcall TProyecto_Cripto::Descifrar7Click(TObject *Sender)
{
	//Descifrado Polialfabetica

	char texto[1000];
	AnsiString r(limpiarCadenaI(RichEdit1->Text).c_str());
	strcpy(texto, r.c_str());

	AnsiString clave(InputBox("Clave", "Clave: ", "HELLO"));
	char key[1000];
	strcpy(key, clave.c_str());

	int msgLen = strlen(texto), keyLen = strlen(key), i, j;

	char nuevaClave[500], descifrado[500];

	//creando una clave nueva
	for(i = 0, j = 0; i < msgLen; ++i, ++j){
		if(j == (keyLen))
			j = 0;
		nuevaClave[i] = key[j];
	}

	nuevaClave[i] = '\0';

    //Descifrando
    for(i = 0; i < msgLen; ++i)
		descifrado[i] = (((texto[i] - nuevaClave[i]) + 26) % 26) + 'A';

	descifrado[i] = '\0';

	RichEdit2->Text = descifrado;
}
//---------------------------------------------------------------------------


