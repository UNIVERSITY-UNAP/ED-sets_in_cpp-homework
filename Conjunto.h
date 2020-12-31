#include "Elemento.h"
class Conjunto {
	Element *princ;
	Conjunto *subc;
	Conjunto *vacio;
public:
	Conjunto() {
		princ = NULL;
		vacio = NULL;
	}
	void Push(int val) {
		if (!ElemExist(val)) {
			Element *Aux = new Element(val);
			if (princ != NULL) {
				Aux->setNext(princ);
			}
			princ = Aux;
		}
	}
	int RetElem (int pos) {
		Element *Aux = princ;
		int count = 0;
		int N = numElem();
		while (Aux != NULL) {
			if (N - count == pos) {
				return Aux->retVal();
			}
			Aux = Aux->retNext();
			count++;
		}
		return 0;
		//	|1||2||3||4||5|
	}
	int numElem() {
		Element *Aux = princ;
		int count = 0;
		while (Aux != NULL) {
			Aux = Aux->retNext();
			count++;
		}
		return count;
	}
	bool IsEmpty() {
		return princ == NULL;
	}
	bool ElemExist(int val) {
		Element *Aux = princ;
		while (Aux != NULL) {
			if (Aux->retVal() == val)
				return 1;
			Aux = Aux->retNext();
		}
		Aux = NULL;
		return 0;
	}
	bool ItsIncludedIn(Conjunto *B) {
		if (IsEmpty() && !B->IsEmpty()) return 1;//Para un A vacio
		if (IsEmpty() && B->IsEmpty()) return 0;
		int tam = numElem();
		if (tam <= B->numElem()) {
			for (int i = 1; i <= tam; i++) {
				if (!B->ElemExist(RetElem(i))) {
					return 0;
				}
			}
			return 1;
		}
		else return 0;
	}
	bool Include(Conjunto *B) {
		if (B->IsEmpty()) return 1;//Si para un B vacio
		int tam = B->numElem();
		if (numElem() >= tam) {
			for (int i = 1; i <= tam; i++) {
				if (!ElemExist(B->RetElem(i))) {
					return 0;
				}
			}
			return 1;
		}
		else return 0;
	}
	bool IsUnitary() {
		return numElem() == 1;
	}
	Conjunto* operator || (Conjunto *B) {//UNION
		if (B->IsEmpty()) return this;//Ley de Identidad
		if (B->Include(this)) return B;//Ley de Dominacion
		if (Include(B)) return this;// '' '' ''
		if (this == B) return this;//Ley Idempotente
		Conjunto* Aux = new Conjunto();
		int i = 1, tam = numElem();
		while (i <= tam) {
			Aux->Push(RetElem(i++));
		}
		i = 1, tam = B->numElem();
		while (i <= tam) {
			Aux->Push(B->RetElem(i++));
		}
		return Aux;//Cumple las leyes Conmutativa y Asociativa
	}
	Conjunto* operator && (Conjunto *B) {
		if (B->Include(this)) return this;//Ley de Identidad
		if (B->IsEmpty()) return B;// Ley  de Dominacion
		if (this == B) return this;//Ley Idempotente
		Conjunto* Aux = new Conjunto();
		int i = 1, tam = B->numElem();
		while (i <= tam) {
			if (ElemExist(B->RetElem(i))) {
				Aux->Push(B->RetElem(i));
			}
			i++;
		}
		return Aux;//Sin elementos en comun retorna conjunto vacio
					//Cumple Las leyes conmutativa y asociativa
	}
	Conjunto* operator - (Conjunto *B) {
		if (B->IsEmpty()) return this;
		if (IsEmpty()) return this;
		Conjunto *Aux = new Conjunto();
		int i = 1, tam = numElem();
		while (i <= tam) {
			if (!B->ElemExist(RetElem(i))) {
				Aux->Push(RetElem(i));
			}
			i++;
		}
		return Aux;
	}
	Conjunto* Complemento(Conjunto *Universo) {
		if (!Universo->Include(this)) {
			Conjunto *Aux = new Conjunto();
			return Aux;
		}
		if (Universo->IsEmpty()) return Universo;
		if (IsEmpty()) return Universo;
		Conjunto *Aux = new Conjunto();
		int i = 1, tam = Universo->numElem();
		while (i <= tam) {
			if (!ElemExist(Universo->RetElem(i))) {
				Aux->Push(Universo->RetElem(i));
			}
			i++;
		}
		return Aux;//Complemento(Complemento(A,U),U) == A
	}
	bool operator == (Conjunto *B) {
		int i = 1, tam = numElem();
		if (tam == B->numElem()) {
			while (i <= tam) {
				if (!B->ElemExist(RetElem(i))) {
					return 0;
				}
				i++;
			}
			return 1;
		}
		else return 0;
	}
	int numSubsets() {//Conjuntos Potencia
		if (!IsEmpty()) {
			int a = 1;
			for (int i = 1, tam = numElem(); i <= tam; i++) {
				a *= 2;
			}
			return a;
		}
		return 1;
	}
	int numPropSubsets() {
		return numSubsets() - 1;
	}
	bool areDisj(Conjunto *B) {
		if (IsEmpty() || B->IsEmpty()) return 1;//1.Interseccion en el vacio;
		int i = 1, tam = numElem();
		while (i <= tam) {
			if (B->ElemExist(RetElem(i))) {
				return 0;
			}
			i++;
		}
		return 1;//2.Interseccion en el vacio
	}
	Conjunto* SymDif(Conjunto *B) {
		if (B->IsEmpty() && !IsEmpty()) return this;
		if (IsEmpty() && !B->IsEmpty()) return B;
		if (IsEmpty() && B->IsEmpty()) return this;
		Conjunto *Aux = new Conjunto();
		/*	if (areDisj(B)) Aux = this || B;*/
		int i = 1, tam = numElem();
		while (i <= tam) {
			if (!B->ElemExist(RetElem(i))) {
				Aux->Push(RetElem(i));
			}
			i++;
		}
		i = 1, tam = B->numElem();
		while (i <= tam) {
			if (!ElemExist(B->RetElem(i))) {
				Aux->Push(B->RetElem(i));
			}
			i++;
		}
		return Aux;
	}
	Conjunto& operator >>(int a) {
		Push(a);
		return *this;
	}
};=
