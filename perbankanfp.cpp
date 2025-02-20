/* Standard C++ includes */
#include <iostream> // untuk mendeklarasikan bahasa c++
#include <ctime>    //Mengambil Lib Tanggal , berkaitan dengan fungsi print struk
#include <fstream>  //untuk menerapkan varfile (akses file)
#define MAX 100     //Mendefinisikan besar daya tampung untuk queue

using namespace std; //agar bisa menggunakan fungsi cout dan cin endl, tanpa std::cout;
/*
Judul FP    : Aplikasi Perbankan
Materi      :
a. Array
b. Pointer
c. Struct
d. Sorting (Selection)
e. Search (Squential search)
f. Queue

*/

/*global Scope Variabel, kenapa 4? karena mula2 kita ada 4 data juga, nanti x ini
menjadi fleksibel bisa kurang atau tambah nilainya, tetapi jika program di close akan kembali
menjadi seperti semula yaitu 4, beda cerita kalau pake db :)  */
int x = 4, indt, pil;

//Tempat Menampung Data Member Bank Dan Informasi Lain.
struct data
{
    string username[100] = { "Andider", "Os", "Chin", "Lang" };
    string nama[100] = { "Andi Dermawan", "Osama Alfa", "Chindy Arendika", "Gilang Dwi" };
    string identity[100] = { "422222", "422223", "422224", "422225" };
    long tabungan[100] = { 70000, 80000, 50000, 90000 };
} member;

//Struct Untuk menampung data Queue
struct antrian
{
    int data[MAX];
    int awal, akhir;
} antri;

void first()
{
    antri.awal = -1;
    antri.akhir = -1;
} /*Pada Queue terdapat head dan tail dimana, head adalah awal dan tail adalah akhir, agar
program Queue saat running pertama kali, memorynya dalam keadaan kosong maka perlu
di set assignmentnya -1 */

bool isfull()
{
    if (antri.akhir == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty()
{
    if (antri.akhir == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int a = 1; //pemberian nilai awal antrian, kenapa 1 ? karena nanti akan ditambah 1++
int tambah()
{
    return a++;
} /*Membuat Fungsi Otomatis Pada Queue agar tidak perlu menginputkan
dan akan bertambah */

void tampilkanantrian()
{
    if (!isempty())
    {
        cout << "STATUS SAAT INI : " << endl
            


<< endl;
        for (int ant = antri.awal; ant < antri.akhir; ant++)
        {
            cout << antri.data[ant] << " | ";
        }
        cout << endl;
    }
    else
    {
        a = 1; // reset nilai a kembali ke 0
        cout << "STATUS SAAT INI : " << endl
            << endl;
        cout << "UNTUK SAAT INI TIDAK ADA ANTRIAN" << endl;
    }
    cout << endl;
} /*Fungsi Untuk Menampilkan Queue */

void ambilantrian()
{
    int nomer;
    float total;
    if (!isfull())
    {
        cout << endl;
        cout << "Nomer Antrian Telah Diambil, Mohon Menunggu Nomer Antrian Anda di Panggil" << endl
            << endl;
        antri.data[antri.akhir] = tambah();
        total = total + antri.data[antri.akhir];
        antri.akhir++;
        system("pause");
    }
    else
    {
        cout << "Antrian penuh" << endl
            << endl;
    }
} /*Fungsi Untuk Mengambil Antrian */

void format()
{
    antri.awal = -1;
    antri.akhir = -1;
    a = 1; //reset nila a menjadi 0 lagi.
    cout << "Antrian Berhasil Dikosongkan..." << endl
        << endl;
} //Fungsi Untuk Format/mengosongkan seluruh queue

void panggilantrian()
{
    if (!isempty())
    {
        cout << endl;
        cout << "Silakan Nomer Antrian Ke - " << antri.data[antri.awal] << " Untuk Menuju Ke Teller/CS" << endl;
        for (int i = antri.awal; i < antri.akhir; i++)
        {
            antri.data[i] = antri.data[i + 1];
        }
        antri.akhir--;
        cout << endl;
        system("pause");
    }
    else
    {
        cout << endl;
        cout << "Untuk Saat Ini Tidak Ada Antrian" << endl;
        cout << endl;
        system("pause");
    }
} /*Fungsi Untuk memanggil antrian (dequeue) ingat metode queue adalah FIFO */

// Fungsi Menampilkan Dashborad Menu
void header()
{

    system("cls");
    cout << "========================================================\n";
    cout << "                   WELCOME ADMIN !!!\n";
    cout << "              PT. BANK MILIK KITA SAJA  \n";
    cout << endl;
    cout << "            Aplikasi Perbankan Version 1.0   " << endl;
    cout << "========================================================\n";
    cout << endl;
    cout << "[1] No.Antrian" << endl;
    cout << "[2] List Member Bank" << endl;
    cout << "[3] Input Data Member Baru" << endl;
    cout << "[4] Edit Data Member" << endl;
    cout << "[5] Hapus Data Member" << endl;
    cout << "[6] Menabung" << endl;
    cout << "[7] Penarikan" << endl;
    cout << "[8] Pencarian Data" << endl;
    cout << "[9] Keluar" << endl;
    cout << endl;
}

//Main Program
int main()
{
home:
    header();                     //Pemanggilan Tampilan Dashboard Menu
    cout << "INPUT PILIHAN =>> "; //Tempat Input Pilihan Menu
    cin >> pil;
    if (pil == 1)
    {
    ant: //label
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                          Antrian                                     |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Ambil Dan Panggil Antrian" << endl;
        cout << "[1] Ambilkan Antrian" << endl;
        cout << "[2] Panggil Antrian" << endl;
        cout << "[3] Kosongkan Antrian" << endl;
        cout << "[4] Kembali Ke Menu" << endl;
        cout << endl;
        tampilkanantrian();
        int antr;
        cout << "Masukan Pilihan Anda [1/2/3/4] > ";
        cin >> antr;
        if (antr == 1)
        {
            ambilantrian();
            goto ant;
        }
        else if (antr == 2)
        {
            panggilantrian();
            goto ant;
        }
        else if (antr == 3)
        {
            format();
            


goto ant;
        }
        else if (antr == 4)
        {
            goto home;
        }
        else
        {
            cout << "Inputan Anda Salah ,INputkan Pilihan [1 / 2 / 3]" << endl;
            system("pause");
            goto ant;
        }
    }
    else if (pil == 2)
    {
    sor: //label
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      List Member Bank                                |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
        int i; 
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "."
                << "\t" << member.username[i] << "\t\t" << member.nama[i] << "\t\t\t" << member.identity[i] << "\t\t\tRp. " << member.tabungan[i] << endl;
        }
        cout << endl;
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Lakukan Per-Sortingan " << endl;
        cout << "[1] Mode Ascending (A to Z)" << endl;
        cout << "[2] Mode Discending (Z to A)" << endl;
        cout << "[3] Kembali Ke Menu" << endl;
        cout << endl;
        int sort;
        cout << "Masukan Pilihan Anda [1/2/3] > ";
        cin >> sort;
        if (sort == 1)
        {
            //deklarasi tampungan array untuk sorting, mengapa ada array lagi? agar array utama tidak berubah.
            string copynama[100], copyusername[100], copyidentity[100], tempnama, tempusername, tempidentity;
            float copytabungan[100], temptabungan;
            int f, g, u, r;
            int h = x;
            for (f = 0; f < x; f++)
            {
                copynama[f] = member.nama[f];
                copyusername[f] = member.username[f];
                copyidentity[f] = member.identity[f];
                copytabungan[f] = member.tabungan[f];
            } //mengcopy array utama ke array khusus sorting
            for (g = 0; g < h; g++)
            {
                u = g;
                for (r = g + 1; r < h; r++)
                {
                    if (copynama[r] < copynama[u])
                    {
                        u = r;
                    }
                }
                tempnama = copynama[g];
                copynama[g] = copynama[u];
                copynama[u] = tempnama;

                tempusername = copyusername[g];
                copyusername[g] = copyusername[u];
                copyusername[u] = tempusername;

                tempidentity = copyidentity[g];
                copyidentity[g] = copyidentity[u];
                copyidentity[u] = tempidentity;

                temptabungan = copytabungan[g];
                copytabungan[g] = copytabungan[u];
                copytabungan[u] = temptabungan;
            } //Lopping Untuk Sorting Data.
            cout << endl;
            cout << "|======================================================================================|\n";
            cout << "|                           Data Terurut Dengan Mode Ascending (A-Z)                   |\n";
            cout << "|======================================================================================|\n";
            cout << endl;
            cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
            for (int ur = 0; ur < x; ur++)
            {
                cout << ur + 1 << "."
                    << "\t" << copyusername[ur] << "\t" << copynama[ur] << "\t\t\t" << copyidentity[ur] << "\t\t\tRp. " << copytabungan[ur] << endl;
            } //Menampilkan Data yang sudah Ter Sort
            cout << endl;
            cout << "|======================================================================================|\n";
            system("pause");
            goto sor;
        }
        else if (sort == 2)
        {
            //deklarasi tampungan array untuk sorting, mengapa ada array lagi? agar array utama tidak berubah.
            string copynama[100], copyusername[100], copyidentity[100], tempnama, tempusername, tempidentity;
            float copytabungan[100], temptabungan;
            int f, g, u, r;
            int h = x;
            for (f = 0; f < x; f++)
            {
                copynama[f] = member.nama[f];
                copyusername[f] = member.username[f];
                copyidentity[f] = member.identity[f];
                copytabungan[f] = member.tabungan[f];
            } //mengcopy array utama ke array khusus sorting
            for (g = 0; g < h; g++)
            {
                u = g;
                for (r = g + 1; r < h; r++)
                {
                    if (copynama[r] > copynama[u])
                    {
                        u = r;
                    }
                }
                tempnama = copynama[g];
                copynama[g] = copynama[u];
                copynama[u] = tempnama;

                tempusername = copyusername[g];
                copyusername[g] = copyusername[u];
                copyusername[u] = tempusername;

                tempidentity = copyidentity[g];
                copyidentity[g] = copyidentity[u];
                copyidentity[u] = tempidentity;

                temptabungan = copytabungan[g];
                copytabungan[g] = copytabungan[u];
                copytabungan[u] = temptabungan;
            } //Lopping Untuk Sorting Data.
            cout << endl;
            cout << "|======================================================================================|\n";
            cout << "|                           Data Terurut Dengan Mode Descending (Z-A)                   |\n";
            cout << "|======================================================================================|\n";
            cout << endl;
            cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
            for (int ur = 0; ur < x; ur++)
            {
                cout << ur + 1 << "."
                    << "\t" << copyusername[ur] << "\t" << copynama[ur] << "\t\t\t" << copyidentity[ur] << "\t\t\tRp. " << copytabungan[ur] << endl;
            } //Menampilkan Data yang sudah Ter Sort
            cout << endl;
            cout << "|======================================================================================|\n";
            system("pause");
            goto sor;
        }
        else if (sort == 3)
        {
            goto home;
        }
        else
        {
            cout << "Inputan Anda Salah ,INputkan Pilihan [1 / 2 / 3]" << endl;
            system("pause");
            goto sor;
        }
        system("pause");
        goto home;
    }
    else if (pil == 3)
    {
        system("cls"); //Menu Tambah Member
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Tambah Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Berapa Jumlah Data yang akan Anda Inputkan > ";
        cin >> indt;
        //B= 4;
        int b = x;

        //++//INCREMENT
        //--//DECR
        for (x; x < indt + b; x++)
        {
            cout << "Masukan Data Member ke - " << x + 1 << endl;
            cout << "Input Nama Lengkap : ";
            cin.ignore();
            getline(cin, member.nama[x]);
            cout << "No. Identitas      : ";
            cin >> member.identity[x];
            cout << "Tabungan Awal      : Rp. ";
            cin >> member.tabungan[x];
            cout << "Buat Username      : ";
            cin >> member.username[x];
            cout << endl;
        }
        //update global x variable
        x = (x + indt) - indt;
        //x=x;
        cout << "Data Berhasil Di Inputkan !!!" << endl;
        cout << endl;
        system("pause");
        goto home;
    }
    else if (pil == 4)
    {
    mbalik:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                   Menu Edit Data Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << "NO.\tUsername" << endl;
        int i;
        bool edit = false;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string nm;
        cout << "Untuk Edit Data Input Username Member = ";
        cin >> nm;
        for (i = 0; i < x; i++)
        {
            if (nm == member.username[i])
            {
                edit = true;
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                char pila;
            ehe:
                cout << "Apakah Anda Yakin Ingin Mengubah Data Tersebut ? (Y/N) =>> ";
                cin >> pila;
                if (pila == 'y' || pila == 'Y')
                {
                    cout << "Ubah Data member " << member.username[i] << endl;
                    cout << "Ubah Nama          : ";
                    cin.ignore();
                    getline(cin, member.nama[i]);
                    cout << "Ubah no Identitas  : ";
                    cin >> member.identity[i];
                    cout << "Ubah Username      : ";
                    cin >> member.username[i];
                    cout << endl;
                    cout << "DATA BERHASIL DIUBAH !!!" << endl;
                    system("pause");
                    goto home;
                }
                else if (pila == 'n' || pila == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Yang anda Masukan Salah !!!, Inputkan (Y/N)" << endl
                        << endl;
                    system("pause");
                    goto ehe;
                }
            }
        }
        if (edit == false)
        {
            cout << "Username Yang Anda Masukkan Tidak Ada!!!" << endl;
            system("pause");
            goto mbalik;
        }
    }
    else if (pil == 5)
    {
    busak:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                  Menu Hapus Data Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string busak;

        cout << "Untuk Hapus Data Input Username Member = ";
        cin >> busak;
        bool delstatus = false;
        //Perulangan untuk mencari data yang di inputkan user di index array
        for (int j = 0; j < x; j++)
        {
            if (busak == member.username[j])
            {
                //Jika nilai yang di masukkan user sesuai dengan salah satu
                //Nilai data di index array
                cout << "Halo !!!, " << member.username[j];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[j] << endl;
                cout << "Nama Member    : " << member.nama[j] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[j] << endl;
                cout << "No. Identitas  : " << member.identity[j] << endl;
                cout << endl;
                char hps;
                cout << "Apakah Anda Yakin Ingin Mengahupus Data Tersebut ? (y/n) > ";
                cin >> hps;
                if (hps == 'y' || hps == 'Y')
                {
                    for (int k = j /* dimulai dari index nilai yang ditemukan */; k < x; k++)
                    {
                        //Menggeser nilai data pada index array sampai jumlah maksimal data array
                        member.username[k] /* Nilai index saat ini / = member.username[k + 1] / Nilai index selanjutnya */;
                        member.nama[k] /* Nilai index saat ini / = member.nama[k + 1] / Nilai index selanjutnya */;
                        member.identity[k] /* Nilai index saat ini / = member.identity[k + 1] / Nilai index selanjutnya */;
                        member.tabungan[k] /* Nilai index saat ini / = member.tabungan[k + 1] / Nilai index selanjutnya */;
                    }
                    // Mengurangi jumlah array karena saah satu datanya telah dihapus
                    x -= 1;
                    delstatus = true;
                    cout << "Data Berhasil Dihapus !!!" << endl;
                    cout << endl;
                    break;
                }
                else if (hps == 'n' || hps == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Salah,Inputkan (y/n)" << endl;
                    system("pause");
                    goto home;
                }
            }
        }
        if (delstatus == false)
        {
            cout << "Username " << busak << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto busak;
        }
        system("pause");
        goto home;
    }
    else if (pil == 6)
    {
    tabg:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Menabung                                   |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string tab;
        cout << "Untuk Menabung ,Silakan Input Username Member = ";
        cin >> tab;
        bool tabung = false;
        for (i = 0; i < x; i++)
        {
            if (tab == member.username[i])
            {
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                float baru;
                cout << "Masukan Jumlah Uang Yang akan Ditabung = Rp. ";
                cin >> baru;
                member.tabungan[i] = baru + member.tabungan[i];
                tabung = true;
                cout << endl;
                cout << "Berhasil Menambahkan Saldo Ke Akun Anda !!! " << endl;
                //revisi
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                system("pause");
                goto home;
            }
        }
        if (tabung == false)
        {
            cout << "Username " << tab << "Tidak Ditemukan !!!" << endl;
            system("pause");
            goto tabg;
        }
    }
    else if (pil == 7)
    {
    bali:
        system("cls");
        string ambil;
        float buang;
        cout << "|======================================================================================|\n";
        cout << "|                                  Menu Penarikan Uang                                 |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string tarik;
        cout << "Untuk Melakukan Penarikan Uang  ,Silakan Input Username Member = ";
        cin >> tarik;
        bool take = false;
        for (i = 0; i < x; i++)
        {
            if (tarik == member.username[i])
            {
                take = true;
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                float baru;
                cout << "Masukan Jumlah Uang yang akan diambil = Rp. ";
                cin >> baru;
                if (baru >= member.tabungan[i])
                {
                    cout << "Maaf, Saldo Anda Tidak Mencukupi Untuk Melakukan Penarikan !!!" << endl;
                    system("pause");
                    goto bali;
                }
                else if (baru < member.tabungan[i])
                {
                    member.tabungan[i] = member.tabungan[i] - baru;
                    cout << endl;
                    cout << "Berhasil Melakukan Penarikan Uang !!! " << endl;
                    cout << endl;
                    cout << "Informasi Data Anda Saat Ini" << endl;
                    cout << "Username       : " << member.username[i] << endl;
                    cout << "Nama Member    : " << member.nama[i] << endl;
                    cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                    cout << "No. Identitas  : " << member.identity[i] << endl;
                    cout << endl;
                print:
                    char ps;
                    cout << "Apakah Anda Akan Print Struck ? (y/n) > ";
                    cin >> ps;
                    if (ps == 'y' || ps == 'Y')
                    {
                        //fungsi untuk mengambil tanggal dan waktu saat ini
                        time_t now = time(0);
                        char* dt = ctime(&now);
                        //cout << << endl;

                        //fungsi create file struk.txt
                        ofstream struk;
                        struk.open("struk.txt");
                        struk << "==================================================\n";
                        struk << "\t\tPT. BANK MELETRE ASEEK\n";
                        struk << "\tWaktu Penarikan : " << dt;
                        struk << "==================================================\n";
                        struk << endl;
                        struk << "Nama Member           : " << member.nama[i] << "\n";
                        struk << "Jumlah Uang Diambil   : Rp. " << baru << "\n";
                        struk << "Sisa Saldo Tabungan   : Rp. " << member.tabungan[i] << "\n";
                        struk << endl;
                        struk << "=================================================\n";
                        struk << "\tTERIMAKASIH TELAH MELAKUKAN TRANSAKSI\n";
                        struk.close();
                        system("notepad.exe struk.txt");
                        system("pause");
                        goto home;
                    }
                    else if (ps == 'n' || ps == 'N')
                    {
                        system("pause");
                        goto home;
                    }
                    else
                    {
                        cout << "Inputan Salah,Inputkan (y/n)" << endl;
                        system("pause");
                        goto print;
                    }
                }
            }
        


}
        if (take == false)
        {
            cout << "Username " << tarik << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto bali;
        }
    }
    else if (pil == 8)
    {
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Pencarian Data                             |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUSERNAME" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        cout << "|======================================================================================|\n";
        string cari;
        cout << endl;
        bool golek = false;
        cout << "Inputkan Username Data yang Akan Anda Cari > ";
        cin >> cari;
        int q;
        for (q = 0; q < x; q++)
        {
            if (cari == member.username[q])
            {

                cout << "Username " << member.username[q] << " Ditemukan !!!" << endl;
                cout << endl;
            ifdta:
                char pl;
                cout << "Tampilkan Informasi Lengkap Data ? (y/n) => ";
                cin >> pl;
                if (pl == 'y' || pl == 'Y')
                {
                    cout << endl;
                    cout << "Informasi Data Anda Saat Ini" << endl;
                    cout << "Username       : " << member.username[q] << endl;
                    cout << "Nama Member    : " << member.nama[q] << endl;
                    cout << "Saldo Tabungan : " << member.tabungan[q] << endl;
                    cout << "No. Identitas  : " << member.identity[q] << endl;
                    cout << endl;
                    system("pause");
                    goto home;
                }
                else if (pl == 'n' || pl == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Anda Salah !!!, Inputkan (y/n)" << endl;
                    system("pause");
                    goto ifdta;
                }
                golek = true;
            }
        }
        if (golek == false)
        {
            cout << "Username " << cari << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto home;
        }
    }
    else if (pil == 9)
    {
        system("cls");
        cout << endl;
        cout << "+-+-+-+-+-+-+ +-+-+-+-+-+" << endl;
        cout << "|T|e|r|i|m|a| |K|a|s|i|h|" << endl;
        cout << "+-+-+-+-+-+-+ +-+-+-+-+-+" << endl;
        cout << endl;
        system("pause");
        return 0;
    }
    else
    {
        cout << "Inputan Salah !!!,SIlakan Masukan Pilihan yang Benar [ 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9]" << endl;
        system("pause");
        goto home;
    }
}