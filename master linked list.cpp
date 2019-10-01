/**
	PRAKTIKUM LISTLINEAR
	DEFENISI
	1. List Kosong <-> First(L) bernilai Nil
	2. P merupakan pointer ke ElementList
	3. Dikatakan Element terakhir apabila Next(P) bernilai Nil
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct ElmtList {
	infotype 	Info;
	address 	Next;
} ElmtList;

typedef struct {
	address		first;
} List;


//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

bool isListEmpty (List L){
	/* Mengirim true jika list kosong */
	return (;
}

void createList (List *L){
	/*	I.S. sembarang
		F.S. Terbentuk list kosong 
	*/
	First(L)=Null;

}

address alokasi (infotype X){
	/*	Mengirimkan address hasil alokasi sebuah elemen
		Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
		Info(P) = X, Next(P) = Nil
		Jika alokasi gagal, mengirimkan Nil
	*/
	address P = address(malloc(sizeof(ElmtList)));
	if(P==Null)
		return Nil;

	Info(P) = X;
	Next(P) = Null;
	return (P);
	
}

void dealokasi (address *P){
	/*	I.S. P terdefinisi
		F.S. P dikembalikan ke sistem
		Melakukan dealokasi/pengembalian address P
	*/
	free(*P);
}

void insertFirst (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		nilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P
	}
}

void insertAfter (List *L, address P, address Prec){
	/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
		P sudah dialokasi
		F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
	*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}



void insertLast (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	P = alokasi(X);
	if(isListEmpty(*L))
		S.InsertFirst(&(*L),X);
	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}

address getLast (List L){
	P = First(L);
	while(Next(P)!=Nil){
		P = Next(P);
	}
	return P;
}


/*
* Fungsi Overloading => merupakan fungsi yang memiliki nama sama
* namum memiliki parameter dan iplementasi yang berbeda.
* contoh : 
* insertFirst(List *L,address P) dan insertFirst (List *L, infotype X)
* Beberda di parameter kedua, fungsi tersebut akan otomatis memilih fungsi yang akan
* di jalankan , sesuai dengan parameter pembedanya( kedua ).
*/
void insertFirst(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		P hasil Alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	Next(P)=First(*L);
	First(*L) =P;
}

void insertLast(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai P hasil alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	if(isListEmpty(*L))
		insertFirst(&(*L),P);
	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}

void deleteFirst (List *L, infotype *X){
	/*	I.S. List L tidak kosong
		F.S. Elemen pertama list dihapus : nilai info disimpan pada X
		dan alamat elemen pertama di-dealokasi
	*/
	address P = First(*L);
	*X = Info(P);
    if (Next(First(*L))==Null)    // 1 element only
        First(*L)=Null;
    else
        First(*L)=Next(P);
	Next(P)=Null;
	dealokasi(P);
}

void deleteAfter (List *L, address *Pdel, address Prec){
	/*	I.S. List tidak kosong. Prec adalah anggota list L.
		F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
	*/
	*Pdel = Next(Prec);
	if(*Pdel!=Nil) {
		Next(Prec)=Next(Pdel);
		Next(Pdel)=Null;
	}
	dealokasi(Pdel);
}

void deleteLast(List *L, infotype *X){
	/*	I.S. list tidak kosong
		F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
		dan alamat elemen terakhir di-dealokasi
	*/
	if(Next(First(*L)==Nil){
		//one element only
		*X = Info(First(*L));
		createList(L);
	}else{
		address prev = First(*L);
		while(Next(Next(Next(Prev)!=Nil ){
			prev = Next(prev);
		}
		address last =Next(Prev);
		*X = Info(last);
		Next(Prev)=Null;
		dealokasi(last);
	}
}

void printInfo (List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<<...(16)...;
	if(!isListEmpty(L)){
		address P = First(L);
		while(...(17)...){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<...(18)...;
	}
	cout<<...(19)...<<endl;
}
