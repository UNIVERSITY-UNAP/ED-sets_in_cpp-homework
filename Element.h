class Element {
	int data;
	Element *Next;
public:
	Element() {
		data = 0;
		Next = NULL;
	}
	Element(int dat) {
		data = dat;
		Next = NULL;
	}
	void setNext(Element *Aux) {
		Next = Aux;
	}
	Element* retNext() {
		return Next;
	}
	void setVal(int dat) {
		data = dat;
	}
	int retVal() {
		return data;
	}
};
