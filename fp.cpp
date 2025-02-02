/* Standard C++ includes */
#include <iostream> // untuk mendeklarasikan bahasa c++
#include <ctime> // mengambil Lib Tanggal, berkaitan dengan fungsi print struk
#include <fstream> // untuk menerapkan varfile (akses file)
#define MAX 100 // mendefinisikan besar daya tampung untuk queue 

using namespace std; // agar bisa menggunakan fungsi cout dan cin endl, tanpa std::cout;
/*
Judul FP 		: Aplikasi Perbankan
Materi			: 
a. Array
b. Pointer
c. Struck
d. Sorting (Selection)
e. Seacrh (Squential search)
f. Queue
Aplikasi Di buat oleh :
Irvan 									(21.11.4224)
Muhammad Gilang Dwi Saputra 			(21.11.4233)
Chindy Arendika Putri 					(21.11.4234)
Andi Dermawan 							(21.11.4237)
Osama Alfa 								(21.11.4252)
*/

/*global Scope Variabel, kenapa 4? karena mula mula kita ada 4 data juga, nanti x ini
menjadi fleksibel bisa kurang atau tambah nilainya, tetapi jika program di close akan kembali
menjadi seperti semula yaitu 4, beda cerita kalau pake db :) */
int x = 4, indt, pil;

//Tempat Menampung Data Member Bank Dan Informasi Lain.
struck data
{
		string username[100] = { "susilopwr", "ahmadtnj", "makmur34", riyadiaja" };
		string name[100] = { "Susilo pawiro", "Ahmad Tanjung", "Makmur Abadi", Slamet Riyadi" };
		string identity[100] = { "3131313", "131311", "312132", "123212" };
		float tabungan [100] = { 70000, 80000, 50000, 90000 };
} member;