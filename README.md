# ED-sets_in_cpp-homework
CLASS CONJUNTOS
Consta de 2 Archivos cabecera(Conjunto.h, Element.h) y el principal(main.cpp). Para la implementación de la clase se usó una estructura de datos dinámica parecido a la Pila.
Se creó la clase Conjuntos con sus distintas propiedades, pero falta definir 
La clase Conjunto tiene los siguientes atributos y métodos:
Atributos:
•	Element *princ: Apunta al primer elemento que está en el conjunto, ya que este esta enlazado con los demás.
•	Conjunto *vacío: Todos los conjuntos tienen un elemento vacio.
•	Conjunto *subc: Apunta al primer subconjunto. (Falta implementar)
Métodos:
•	Conjunto: Inicializa todos los atributos en NULL.
•	void Push(int): Reserva espacio para un Element con el parámetro pasado, se lo da al atributo siguiente del Elemento. Pero se comprueba si el conjunto ya tiene ese elemento.
•	Int RetElem(int pos): Devuelve el valor de la posición pos comenzando desde 1.
•	Int numElem(): Devuelve la cantidad de elementos.
•	Bool IsEmpty(): Devuelve 1 si el conjunto es vacio, sino 0.
•	Bool ElemExist(int val): Devuelve 1 si el conjunto contiene el valor val, sino 0.
•	Bool ItsIncludedIn(Conjunto *B): Devuelve 1 si el conjunto actual esta incluido en el conjunto B, sino 0.
•	Bool Include(Conjunto *B): Devuelve 1 si el conjunto actual incluye al conjunto B, sino 0.
•	Bool IsUnitary(): Devuelve 1 si el conjunto es unitario, sino 0.
•	Conjunto* operator || (Conjunto *B): Sobrecarga que devuelve la unión de dos conjuntos.
•	Conjunto* operator && (Conjunto *B): Sobrecarga que devuelve la intersección de dos conjuntos.
•	Conjunto* operator - (Conjunto *B): Sobrecarga que devuelve la resta de dos conjuntos.
•	Conjunto* Complemento (Conjunto *Universo): Devuelve el complemento de un conjunto respecto al argumento Universo.
•	Bool operator == (Conjunto *B): Sobrecarga que devuelve 1 si el conjunto actual es igual que el conjunto B, sino 0.
•	Int numSubsets(): Devuelve la cantidad de Conjuntos Potencia.
•	Int numPropSubsets(): Devuelve la cantidad de subconjuntos propios.
•	Bool areDijs(Conjunto *B): Devuelve 1 si los conjunto son disjuntos, sino 0.
•	Conjunto* SymDif(Conjunto *B): Devuelve el conjunto diferencia simétrica entre el conjunto actual y el conjunto B.
•	Conjunto operator >>(int val):  Sobrecarga que me devuelve el mismo Conjunto, insertando el val, con el método Push (facilita el ingreso de datos).
La clase Element tiene atributos y métodos:
Atributos
•	Int dato: es el numero que contiene el elemento del conjunto.
•	Element *Next: Recibe la dirección de memoria del siguiente elemento del conjunto. Este atributo nos enlaza los Elementos del conjunto.
Metodos
•	Element(): Inicializa dato en 0 y Next en NULL.
•	Element(int dat): Inicializa dato en dat y Next en NULL.
•	Void setNext(Element *Aux): Asigna una dirección de memoria Aux a dato.
•	Element* retNext(): Devuelve Next;
•	Void setVal(int dat): Asigna un valor a dato.
•	Int retVal(): Devuelve dato.
