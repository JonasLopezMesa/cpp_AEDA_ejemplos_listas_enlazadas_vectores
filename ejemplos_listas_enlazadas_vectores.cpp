#include <iostream>
using namespace std;
#include <string>

//int main () {
	//EJERCICIO 2////////////////////////////////////////////////////////////////////////////////////////////
	
	int p = 1;
	int dd, mm, aa;
	while (p == 1) {
		cout << "Introduzca una fecha:" << endl;
		cout << "día: ";
		cin >> dd;
		cout << endl;
		
		if (dd < 1 || dd > 31) {
			cout << "ERROR, mal escrito" << endl;
			p--;
		}
		p++;
	}
	p--;
	while (p == 1) {
		cout << "mes: ";
		cin >> mm;
		cout << endl;
		
		if (mm < 1 || mm > 12) {
			cout << "ERROR, mal escrito" << endl;
			p--;
		}
		p++;
	}
	cout << "año: ";
	cin >> aa;
	cout << endl;
	
	cout << dd << " " << mm << " " << aa << endl;
	int x, n, resto;
	
	x = dd + mm + aa;
	while (x > 9) {
		n = x;
		x = 0;
		do {
			resto = n % 10;
			x += resto;
			n = n / 10;
		} while (n != 0);
	}
	
	cout << "El número del tarot es: " << x << endl;
	
	//EJERICIO 3////////////////////////////////////////////////////////////////////////////////////////////
	
	int numero, x, y;
	x = 0;
	y = 0;
	while (numero != -1) {
		
	
		cout << "introduce un número: " << endl;
		cin >> numero;
	
		for (int i = 1; i < numero; i++) {
			x = 0;
			for (int j = 0; j <= i-1; j++) {
				x += j;
			}
			y = 0;
			for (int k = i+1; k <= numero-1; k++) {
				y += k;
				if (x == y) {
					cout << i << " es un centro numérico" << endl;
				}
			}
		}
	
	}
	
	
	//EJERICIOS////////////////////////////////////////////////////////////////////////////////////////////
	







	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VECTOR_CIRCULAR//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class vector_circular
{
private:
	int *vector_;
	int n_;
public:
	vector_circular(int n);
	~vector_circular();
	void insertar_objeto(int a, int i);
	void mostrar_objeto();
};

vector_circular::vector_circular(int n) {
	cout << 1;
	vector_ = new (nothrow) int[n];
	n_ = n;
	if (vector_ == 0) {
		cout << "Insuficiente espacio en memoria" << endl;
	}
	
}
vector_circular::~vector_circular() {
	delete [] vector_;
}

void vector_circular::insertar_objeto(int a, int i) {
	if (i >= n_) {
		i = i % n_;
	}
	vector_[i] = a;
	
	cout << "Se ha introducido el elemento: " << vector_[i] << " En la posición: " << i << " de forma satisfactoria." << endl;
}

void vector_circular::mostrar_objeto() {
	for (int i = 0; i < n_; i++) {
		cout << vector_[i];
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SLL_ITEM/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class sll_item 
{
private:
	sll_item *next_;
	vector_circular* dato_;
public:
	sll_item(); 
	sll_item(vector_circular* dato);
	~sll_item();
	void establecer_siguiente(sll_item* n);
	sll_item* mostrar_siguiente();
	void escribir_dato(int a, int i);
	void mostrar_dato();
};

sll_item::sll_item() : next_(NULL), dato_(NULL) {}
sll_item::sll_item(vector_circular* dato) : next_(NULL), dato_(dato) {} 
sll_item::~sll_item() {
	delete [] dato_;
	next_ = NULL;
}
void sll_item::establecer_siguiente(sll_item* n) {
	next_ = n;
}
sll_item* sll_item::mostrar_siguiente() {
	return next_;
}
void sll_item::escribir_dato(int a, int i) {
	dato_->insertar_objeto(a, i);
}
void sll_item::mostrar_dato() {
	dato_->mostrar_objeto();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SLL//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class sll
{
private:
	sll_item* inicio_;
public:
	sll(void);
	~sll();
	void insertar_final();
	void borrar_principio();
	void imprimir();
};

sll::sll(void) : inicio_(NULL) {}
sll::~sll() {}
	
void sll::insertar_final() {
	int n;
	cout << "Introduce el tamaño de el array " << endl;
	cin >> n;
	vector_circular D(n);
	int a;
	int h = 1;
	int i = 0;
	while (h == 1) {
		cout << "Introduce el valor del dato que quieras introducir en el array " << endl;
		cout << "-1 = salir" << endl;
		cin >> a;
		if (a == -1) {
			h++;
		}
		else {
			D.insertar_objeto(a, i);
			i++;
		}

		
	}
	sll_item* aux;
	aux = new sll_item(&D);
	
	aux->establecer_siguiente(NULL);
	if (inicio_ == NULL) {
		inicio_ = aux;
	}
	else {
		sll_item* aux2 = inicio_;
		while (aux2->mostrar_siguiente() != NULL) {
			aux2 = aux2->mostrar_siguiente();
		}
		aux2->establecer_siguiente(aux);
	}
}

void sll::borrar_principio() {
	sll_item* aux = inicio_;
	inicio_ = aux->mostrar_siguiente();
	delete aux;
}

void sll::imprimir() {
	sll_item* aux = inicio_;
	while (aux->mostrar_siguiente() != NULL) {
		aux->mostrar_dato();
		aux = aux->mostrar_siguiente();
	}
}
	
	

						 						

int main()
{
	sll r;
	int hh = 1;
	int c;
	while (hh == 1) {
		cout << "Introduce que opcion quieres: " << endl;
		cout << "1 Insertar Objeto:" << endl;
		cout << "2 Borrar Objeto:" << endl;
		cout << "3 Imprimir Todo:" << endl;
		cout << "4 Salir:" << endl;
		
		cin >> c;
		
		switch (c) {
			case 1:
				r.insertar_final();
				break;
			case 2:
				r.borrar_principio();
				break;
			case 3:
				r.imprimir();	
				break;
			case 4:
				hh++;
				cout << "Adios" << endl;
				break;
			default:
				cout << "ERROR opcion incorrecta." << endl;
				break;
		}
	}
	return 0;
}



#define NWORDS 4
#define WORDSIZE 64
#define EMPTY_SET 0x0
#define MASK_ONE 0x1

class bit_set {
public:
	unsigned long b_[NWORDS];
public:
	bit_set(void) 
	{
		for (int i = 0; i < NWORDS; i++)
			b_[i] = EMPTY_SET;
	}
	~bit_set(void) {}
	void insert(unsigned short i)
	{
		const unsigned short pos = i / WORDSIZE;
		cout << pos << endl;
		const unsigned short shift = i % WORDSIZE;
		cout << shift << endl;
		unsigned long aux = 0;
		aux = MASK_ONE << shift;
		b_[pos] |= aux;
		cout << b_[3] << b_[2] << b_[1] << b_[0] << endl;
	}
	void union_conjuntos(const bit_set& i)
	{
		for (int j = 0; j < NWORDS; j++) {
			b_[j] |= i.b_[j];
		}
		cout << b_[3] << b_[2] << b_[1] << b_[0] << endl;
	}
	void interseccion(const bit_set& i)
	{
		for (int j = 0; j < NWORDS; j++) {
			b_[j] &= i.b_[j];
		}
		cout << b_[3] << b_[2] << b_[1] << b_[0] << endl;
	}
	bool incluido(const bit_set& s)
	{
		bool contain = true;
		for ( int i = 0; (i < NWORDS) && (contain); i++)
			if (( b_[i] & s.b_[i])  != s.b_[i])
				contain = false;
		return contain;
	}
	bool vacio()
	{
		bool vac = true;
		for (int i = 0; i < NWORDS; i++) {
			if (b_[i] != 0) {
				vac = false;
			}
		}
		return vac;
	}
};


int main()
{
	unsigned int i, h = 0;
	bit_set b;
	cout << "Introduce la posición donde quieras introdicir un elemento en el conjunto:(1-256)" << endl;
	cin >> i;
	b.insert(i);
	
	bit_set r;
	while (h != 1) {
		cout << "Introduce la posición donde quieras introdicir un elemento en el conjunto:(1-256)" << endl;
		cin >> h;
		if (h != 1) {
			r.insert(h);
		}
	}
	
	r.union_conjuntos(b);
	r.interseccion(b);
	
	
	return 0;
}


int main()
{
	bool a;
	cout << "Introduce un número (1 o 0)" << endl;
	cin >> a;
	if (a) {
		cout << a << endl;
	}
	
	
}









	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

