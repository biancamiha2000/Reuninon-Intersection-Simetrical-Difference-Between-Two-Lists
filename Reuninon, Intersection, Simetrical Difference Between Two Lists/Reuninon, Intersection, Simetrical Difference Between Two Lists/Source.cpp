//PITIGOI BIANCA 



#include<iostream>
using namespace std;


//LISTA SIMPLU INLANTUITA
struct Node {
	int data;
	struct Node* urm;
};

//FUNCTIE CARE INSEREAZA UN NOD LA INCEPUTUL LISTEI
void push(struct Node** cap_ref, int data_noua) {

	//ALOCA NODUL
	struct Node* node_nou
		= (struct Node*)malloc(
			sizeof(struct Node));

	//SE PUN DATELE
	node_nou->data = data_noua;

	//CONECTEAZA VECHEA LISTA LA NOUL NOD
	node_nou->urm = (*cap_ref);

	//MUTA CAPUL SA POINTEZE CATRE NOUL NOD
	(*cap_ref) = node_nou;
}

//FUNCTIE CARE RETURNEAZA TRUE DACA A GASIT NR CAUTAT IN LISTA SI FALSE DACA NU
bool isPresent(struct Node* cap, int data) {

	Node* t = cap;
	while (t != NULL) {
		if (t->data == data) {
			return 1;
		}
		t = t->urm;
	}
	return 0;
}

//FUNCTIE CARE FACE REUNIUNEA DINTRE 2 LISTE CU CAPETELE CAP1 SI CAP2
struct Node* reuniune(struct Node* cap1, struct Node* cap2)
{
	Node* rezultat = NULL;
	Node* t1 = cap1, * t2 = cap2;

	//INSEREAZA TOATE ELEMENTELE LISTEI 1 IN LISTA REZULTAT
	while (t1 != NULL) {
		push(&rezultat, t1->data);
		t1 = t1->urm;
	}

	//INSEREAZA TOATE ELEMENTELE LISTEI 2 CARE NU SUNT PREZENTE IN LISTA REZULTAT
	while (t2 != NULL) {
		if (!isPresent(rezultat, t2->data)) {
			push(&rezultat, t2->data);
		}
		t2 = t2->urm;
	}
	return rezultat;
}

//FUNCTIE CARE FACE INTERSECTIA DINTRE 2 LISTE CU CAPETELE CAP1 SI CAP2
struct Node* intersectie(struct Node* cap1, struct Node* cap2) {

	Node* rezultat = NULL;
	Node* t1 = cap1;

	//PARCURGE LISTA 1 SI CAUTA FIECARE ELEMENT DIN EA IN LISTA 2.
	//DACA ELEMENTUL ESTE PREZENT IN LISTA 2 ATUNCI IL ADAUNGA IN LISTA REZULTAT
	while (t1 != NULL) {
		if (isPresent(cap2, t1->data))
			push(&rezultat, t1->data);
		t1 = t1->urm;
	}
	return rezultat;
}

//FUNCTIE CARE FACE DIFERENTA DINTRE 2 LISTE CU CAPETELE CAP1 SI CAP2
struct Node* diferenta(struct Node* cap1, struct Node* cap2) {

	Node* rezultat = NULL;
	Node* t1 = cap1;

	//PARCURCE LISTA 1 SI CAUTA FIECARE ELEMENT DIN EA IN LISTA 2.
	//DACA ELEMENTUL NU ESTE PREZENT IN LISTA 2 ATUNCI IL ADAUNGA IN LISTA REZULTAT
	while (t1 != NULL) {
		if (!isPresent(cap2, t1->data))
			push(&rezultat, t1->data);
		t1 = t1->urm;
	}
	return rezultat;
}

//FUNCTIE CARE AFISEAZA LISTA
void afisareLista(struct Node* node) {
	while (node != NULL) {
		cout << " " << node->data;
		node = node->urm;
	}
}

int main() {

	//FACEM NISTE LISTE NULE
	Node* cap1 = NULL;
	Node* cap2 = NULL;
	Node* reun = NULL;
	Node* inter = NULL;
	Node* dif1 = NULL;
	Node* dif2 = NULL;

	int n, m, nr1, nr2;

	//ADAUGAM NUMERE IN LISTE
	cout << "Cate elemente sa aiba prima lista? "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Numar " << i + 1 << ": ";
		cin >> nr1;
		push(&cap1, nr1);
	}

	cout << "Cate elemente sa aiba a doua lista? "; cin >> m;

	for (int i = 0; i < m; i++) {
		cout << "Numar " << i + 1 << ": ";
		cin >> nr2;
		push(&cap2, nr2);
	}

	cout << "Prima lista este: ";
	afisareLista(cap1);
	cout << "\nA doua lista este: ";
	afisareLista(cap2);
	reun = reuniune(cap1, cap2);
	inter = intersectie(cap1, cap2);
	cout << "\nReuniunea este: ";
	afisareLista(reun);
	cout << "\nIntersectia este: ";
	afisareLista(inter);
	cout << "\nDiferenta intre lista1 si lista2 este: ";
	dif1 = diferenta(cap1, cap2);
	afisareLista(dif1);
	cout << "\nDiferenta intre lista2 si lista1 este: ";
	dif2 = diferenta(cap2, cap1);
	afisareLista(dif2);
	cout << "\nDiferenta simetrica este: ";
	afisareLista(dif1);
	afisareLista(dif2);

	return 0;
}