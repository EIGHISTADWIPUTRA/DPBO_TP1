#include <bits/stdc++.h> // Mengimpor semua header standar C++ dengan satu perintah
using namespace std;     // Menggunakan namespace standar untuk memudahkan penulisan kode

class Petshop // Mendefinisikan kelas Petshop
{
private:             // Bagian akses private, hanya dapat diakses oleh anggota kelas
    int ID;          // Variabel untuk menyimpan ID produk
    string nama;     // Variabel untuk menyimpan nama produk
    string kategori; // Variabel untuk menyimpan kategori produk
    int harga;       // Variabel untuk menyimpan harga produk

public:       // Bagian akses public, dapat diakses dari luar kelas
    Petshop() // Konstruktor default
    {
    }

    Petshop(int ID, string nama, string kategori, int harga) // Konstruktor dengan parameter
    {
        this->ID = ID;             // Menginisialisasi ID produk dengan nilai parameter
        this->nama = nama;         // Menginisialisasi nama produk dengan nilai parameter
        this->kategori = kategori; // Menginisialisasi kategori produk dengan nilai parameter
        this->harga = harga;       // Menginisialisasi harga produk dengan nilai parameter
    }

    int getID() // Fungsi untuk mendapatkan ID produk
    {
        return this->ID; // Mengembalikan nilai ID produk
    }

    string getNama() // Fungsi untuk mendapatkan nama produk
    {
        return this->nama; // Mengembalikan nilai nama produk
    }

    string getKategori() // Fungsi untuk mendapatkan kategori produk
    {
        return this->kategori; // Mengembalikan nilai kategori produk
    }

    int getHarga() // Fungsi untuk mendapatkan harga produk
    {
        return this->harga; // Mengembalikan nilai harga produk
    }

    void setID(int ID) // Fungsi untuk menetapkan ID produk
    {
        this->ID = ID; // Menetapkan nilai ID produk dengan nilai parameter
    }

    void setNama(string nama) // Fungsi untuk menetapkan nama produk
    {
        this->nama = nama; // Menetapkan nilai nama produk dengan nilai parameter
    }

    void setKategori(string kategori) // Fungsi untuk menetapkan kategori produk
    {
        this->kategori = kategori; // Menetapkan nilai kategori produk dengan nilai parameter
    }

    void setHarga(int harga) // Fungsi untuk menetapkan harga produk
    {
        this->harga = harga; // Menetapkan nilai harga produk dengan nilai parameter
    }
    ~Petshop() // Destruktor
    {
    }
};
