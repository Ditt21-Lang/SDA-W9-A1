#ifndef nbtrees_h
#define nbtrees_h
#include "boolean.h"
//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20
//Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0
/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */
/* Kamus */
typedef char infotype;
typedef int address;
typedef struct { 
    infotype info;
    address first_son, next_brother, parent;
}nbtree;
typedef nbtree Tree[jml_maks+1];

/***************************/
/* S P E S I F I K A S I */
/***************************/
void Create_tree(Tree tree, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

boolean IsEmpty (Tree tree);
/* Mengirimkan true jika Isi_Tree KOSONG */

void PreOrderHelper(Tree tree, address index);

/***** Traversal *****/
void PreOrder (Tree tree);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */

void InOrderHelper(Tree tree, address index);

void InOrder (Tree tree);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */

void PostOrderHelper(Tree tree, address index);

void PostOrder (Tree tree);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */

void Level_order_Helper(Tree tree, int maks_level, address index, int level_sekarang);

void Level_order(Tree tree, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree (Tree tree);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */

boolean SearchHelper(Tree tree, infotype X, address index);

/***** Search *****/
boolean Search (Tree tree, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X *


/***** Fungsi Lain *****/
int nbElmtHelper(Tree tree, address index);

int nbElmt (Tree tree);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaunHelper(Tree tree, address index);

int nbDaun (Tree tree);
/* Mengirimkan banyak daun (node) pohon non biner P */

int levelHelper(Tree tree, infotype X,address index, int level_sekarang);

int Level (Tree tree, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int DepthHelper(Tree tree, address index, int level_sekarang);

int Depth (Tree tree);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

int Max (infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

int MaxInt(int data1, int data2);

#endif