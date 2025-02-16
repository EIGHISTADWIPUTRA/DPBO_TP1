#include "Petshop.cpp" // Mengimpor file Petshop.cpp yang berisi definisi kelas Petshop
using namespace std;   // Menggunakan namespace standar untuk memudahkan penulisan kode

int main(int argc, char const *argv[]) // Fungsi utama program
{
    vector<Petshop> data; // Membuat vector untuk menyimpan data produk petshop
    Petshop tmp;          // Membuat objek sementara dari kelas Petshop
    int tmp_id;           // Variabel untuk menyimpan ID produk sementara
    string tmp_nama;      // Variabel untuk menyimpan nama produk sementara
    string tmp_kategori;  // Variabel untuk menyimpan kategori produk sementara
    int tmp_harga;        // Variabel untuk menyimpan harga produk sementara
    int pilihan;          // Variabel untuk menyimpan pilihan menu yang dipilih oleh pengguna

    // Data Dummy
    data.push_back(Petshop(1, "Whiskas", "Makanan_Kucing", 50000));  // Menambahkan data dummy ke vector
    data.push_back(Petshop(2, "Pedigree", "Makanan_Anjing", 75000)); // Menambahkan data dummy ke vector

    do // Melakukan perulangan sampai pengguna memilih untuk keluar
    {
        cout << endl
             << "Selamat Datang di Database Petshop" << endl; // Menampilkan pesan selamat datang
        cout << "Pilih Aksi yang Ingin Anda Lakukan" << endl; // Menampilkan pesan pilihan aksi
        cout << "1. Tambah Data Petshop" << endl;             // Menampilkan pilihan menu tambah data
        cout << "2. Lihat Data Petshop" << endl;              // Menampilkan pilihan menu lihat data
        cout << "3. Ubah Data Petshop" << endl;               // Menampilkan pilihan menu ubah data
        cout << "4. Hapus Data Petshop" << endl;              // Menampilkan pilihan menu hapus data
        cout << "5. Cari Data Petshop" << endl;               // Menampilkan pilihan menu cari data
        cout << "6. Keluar" << endl;                          // Menampilkan pilihan menu keluar

        cout << "Opsi yang Dipilih (1-6): "; // Menampilkan pesan untuk memasukkan pilihan
        cin >> pilihan;                      // Menerima input pilihan dari pengguna

        switch (pilihan) // Melakukan pengecekan pilihan yang dipilih oleh pengguna
        {
            {
            case 1:                             // Jika pengguna memilih pilihan 1
                cout << "Masukkan ID Produk: "; // Menampilkan pesan untuk memasukkan ID produk
                cin >> tmp_id;                  // Menerima input ID produk dari pengguna

                cout << "Masukkan Nama Produk: "; // Menampilkan pesan untuk memasukkan nama produk
                cin >> tmp_nama;                  // Menerima input nama produk dari pengguna

                cout << "Masukkan Kategori Produk: "; // Menampilkan pesan untuk memasukkan kategori produk
                cin >> tmp_kategori;                  // Menerima input kategori produk dari pengguna

                cout << "Masukkan Harga Produk: "; // Menampilkan pesan untuk memasukkan harga produk
                cin >> tmp_harga;                  // Menerima input harga produk dari pengguna

                tmp.setID(tmp_id);             // Menetapkan ID produk ke objek sementara
                tmp.setNama(tmp_nama);         // Menetapkan nama produk ke objek sementara
                tmp.setKategori(tmp_kategori); // Menetapkan kategori produk ke objek sementara
                tmp.setHarga(tmp_harga);       // Menetapkan harga produk ke objek sementara

                data.push_back(tmp); // Menambahkan objek sementara ke vector data

                cout << "Data berhasil ditambahkan" << endl; // Menampilkan pesan bahwa data berhasil ditambahkan
                break;                                       // Keluar dari switch case

            case 2:                              // Jika pengguna memilih pilihan 2
                cout << "Data Petshop:" << endl; // Menampilkan pesan data petshop
                if (data.size() == 0)            // Jika vector data kosong
                {
                    cout << "Data kosong" << endl; // Menampilkan pesan bahwa data kosong
                }
                else // Jika vector data tidak kosong
                {
                    for (int i = 0; i < data.size(); i++) // Melakukan perulangan untuk menampilkan semua data
                    {
                        cout << "ID: " << data[i].getID() << endl;             // Menampilkan ID produk
                        cout << "Nama: " << data[i].getNama() << endl;         // Menampilkan nama produk
                        cout << "Kategori: " << data[i].getKategori() << endl; // Menampilkan kategori produk
                        cout << "Harga: " << data[i].getHarga() << endl;       // Menampilkan harga produk
                        cout << "-------------------------" << endl;           // Menampilkan garis pemisah
                    }
                }

                break; // Keluar dari switch case

            case 3: // Jika pengguna memilih pilihan 3
            {
                int find_id;                                      // Variabel untuk menyimpan ID produk yang ingin diubah
                cout << "Masukkan ID Produk yang Ingin Diubah: "; // Menampilkan pesan untuk memasukkan ID produk yang ingin diubah
                cin >> find_id;                                   // Menerima input ID produk dari pengguna

                int i = 0;          // Variabel untuk indeks perulangan
                bool found = false; // Variabel untuk menandakan apakah produk ditemukan

                while (i < data.size() && !found) // Melakukan perulangan untuk mencari produk
                {
                    if (data[i].getID() == find_id) // Jika ID produk ditemukan
                    {
                        found = true; // Menandakan bahwa produk ditemukan

                        // Mengubah data produk
                        string newName, newCategory; // Variabel untuk menyimpan nama dan kategori produk baru
                        int newPrice, newID;         // Variabel untuk menyimpan ID dan harga produk baru

                        cout << "Masukkan ID Baru: ";       // Menampilkan pesan untuk memasukkan ID produk baru
                        cin >> newID;                       // Menerima input ID produk baru dari pengguna
                        cout << "Masukkan Nama Baru: ";     // Menampilkan pesan untuk memasukkan nama produk baru
                        cin >> newName;                     // Menerima input nama produk baru dari pengguna
                        cout << "Masukkan Kategori Baru: "; // Menampilkan pesan untuk memasukkan kategori produk baru
                        cin >> newCategory;                 // Menerima input kategori produk baru dari pengguna
                        cout << "Masukkan Harga Baru: ";    // Menampilkan pesan untuk memasukkan harga produk baru
                        cin >> newPrice;                    // Menerima input harga produk baru dari pengguna

                        data[i].setID(newID);             // Menetapkan ID produk baru ke objek yang ditemukan
                        data[i].setNama(newName);         // Menetapkan nama produk baru ke objek yang ditemukan
                        data[i].setKategori(newCategory); // Menetapkan kategori produk baru ke objek yang ditemukan
                        data[i].setHarga(newPrice);       // Menetapkan harga produk baru ke objek yang ditemukan

                        cout << "Produk berhasil diubah!" << endl; // Menampilkan pesan bahwa produk berhasil diubah
                    }
                    i++; // Menambahkan indeks perulangan
                }

                if (!found) // Jika produk tidak ditemukan
                {
                    cout << "Produk dengan ID " << find_id << " tidak ditemukan." << endl; // Menampilkan pesan bahwa produk tidak ditemukan
                }
                break; // Keluar dari switch case
            }
            case 4: // Jika pengguna memilih pilihan 4
            {
                int find_id;                                       // Variabel untuk menyimpan ID produk yang ingin dihapus
                cout << "Masukkan ID Produk yang Ingin Dihapus: "; // Menampilkan pesan untuk memasukkan ID produk yang ingin dihapus
                cin >> find_id;                                    // Menerima input ID produk dari pengguna
                int i = 0;                                         // Variabel untuk indeks perulangan
                bool found = false;                                // Variabel untuk menandakan apakah produk ditemukan
                while (i < data.size() && !found)                  // Melakukan perulangan untuk mencari produk
                {
                    if (data[i].getID() == find_id) // Jika ID produk ditemukan
                    {
                        found = true;                               // Menandakan bahwa produk ditemukan
                        data.erase(data.begin() + i);               // Menghapus objek yang ditemukan dari vector
                        cout << "Produk berhasil dihapus!" << endl; // Menampilkan pesan bahwa produk berhasil dihapus
                    }
                    i++; // Menambahkan indeks perulangan
                }
                if (!found) // Jika produk tidak ditemukan
                {
                    cout << "Produk dengan ID " << find_id << " tidak ditemukan." << endl; // Menampilkan pesan bahwa produk tidak ditemukan
                }
                else // Jika produk ditemukan dan berhasil dihapus
                {
                    cout << "Produk Berhasil Dihapus!" << endl; // Menampilkan pesan bahwa produk berhasil dihapus
                }
                break; // Keluar dari switch case
            }

            case 5: // Jika pengguna memilih pilihan 5
            {
                string find_name;                                   // Variabel untuk menyimpan nama produk yang ingin dicari
                cout << "Masukkan Nama Produk yang Ingin Dicari: "; // Menampilkan pesan untuk memasukkan nama produk yang ingin dicari
                cin >> find_name;                                   // Menerima input nama produk dari pengguna

                int i = 0;          // Variabel untuk indeks perulangan
                bool found = false; // Variabel untuk menandakan apakah produk ditemukan

                while (i < data.size() && !found) // Melakukan perulangan untuk mencari produk
                {
                    if (data[i].getNama() == find_name) // Jika nama produk ditemukan
                    {
                        found = true;                                          // Menandakan bahwa produk ditemukan
                        cout << "ID: " << data[i].getID() << endl;             // Menampilkan ID produk
                        cout << "Nama: " << data[i].getNama() << endl;         // Menampilkan nama produk
                        cout << "Kategori: " << data[i].getKategori() << endl; // Menampilkan kategori produk
                        cout << "Harga: " << data[i].getHarga() << endl;       // Menampilkan harga produk
                        cout << "-------------------------" << endl;           // Menampilkan garis pemisah
                    }
                    i++; // Menambahkan indeks perulangan
                }

                if (!found) // Jika produk tidak ditemukan
                {
                    cout << "Produk dengan nama " << find_name << " tidak ditemukan." << endl; // Menampilkan pesan bahwa produk tidak ditemukan
                }
                break; // Keluar dari switch case
            }

            case 6:                                                           // Jika pengguna memilih pilihan 6
                cout << "Terimakasih Telah Menggunakan Aplikasi ini" << endl; // Menampilkan pesan terima kasih
                break;                                                        // Keluar dari switch case

            default:                                                          // Jika pengguna memilih pilihan yang tidak valid
                cout << "Pilihan Tidak Valid, harap pilih angka 1-6" << endl; // Menampilkan pesan bahwa pilihan tidak valid
                break;                                                        // Keluar dari switch case
            }
            return 0; // Keluar dari fungsi main
        }
    } while (pilihan != 6); // Melakukan perulangan sampai pengguna memilih untuk keluar
}
