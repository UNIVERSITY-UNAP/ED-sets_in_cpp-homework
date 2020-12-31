//Archivo main.cpp
#include <iostream>
#include "Conjunto.h"
using namespace std;

void MostrarConjunto(Conjunto*);;
int main() {
	/*Conjunto<int> *c1 = new Conjunto<int>();
	Conjunto<int> *c2 = new Conjunto<int>();
	Conjunto<int> *c3 = new Conjunto<int>();
	Elemento<int> *e1 = new Elemento<int>(3);
	c1->InsertarConj(*c2);*/
	Conjunto *A = new Conjunto();
	A->Push(3);
	A->Push(4);
	A->Push(5);
	A->Push(3);
	Conjunto *B = new Conjunto();
	for (int i = 0; i < 10; i++) {
		B->Push(i + 1);
	}
	Conjunto *D = new Conjunto();
	D->Push(4);
	Conjunto *C;
	cout << "A = "; MostrarConjunto(A);
	cout << "B = "; MostrarConjunto(B);
	cout << "D = "; MostrarConjunto(D);
	cout << endl;
	C = A->operator||(B);
	cout << "Conj C(A||B): ";	MostrarConjunto(C);
	C = A->operator&&(B);
	cout << "Conj C(A&&B): ";	MostrarConjunto(C);
	C = A->operator-(D);
	cout << "Conj C(A-D): ";	MostrarConjunto(C);
	C = A->Complemento(B);
	cout << "Conj C(~A), U=B: ";	MostrarConjunto(C);
	C = (A->Complemento(B))->Complemento(B);
	cout << "Conj C(~(~A)): ";	MostrarConjunto(C);
	C = A->SymDif(D);
	cout << "Conj C A-DifSimet-D: ";	MostrarConjunto(C);
	*C >> 5 >> 7 >> 8;
	cout << "Conj C>>5>>7>>8: ";	MostrarConjunto(C);
	if (D->ItsIncludedIn(A))
		cout << "D esta incluido en A" << endl;
	else
		cout << "D no esta incluido en A" << endl;
	if (B->Include(A))
		cout << "B incluye a A" << endl;
	else
		cout << "B no incluye a A" << endl;
	cout << "A tiene " << A->numElem() << " elementos" << endl;
	cout << "A tiene " << A->numSubsets() << " Conjuntos Potencia" << endl;
	if (D->IsUnitary())
		cout << "D es unitario" << endl;
	else
		cout << "D no es unitario" << endl;
	return 0;
}

void MostrarConjunto(Conjunto *A) {
	int tam = A->numElem();
	cout << "{";
	for (int i = 1; i <= tam; i++) {
		cout << A->RetElem(i);
		if (i != tam)
			cout << ",";
	}
	cout << "}\n";
}
