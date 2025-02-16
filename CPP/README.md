# Janji
Saya Muhammad Bintang Eighista dengan NIM 2304137 mengerjakan Tugas Praktikum 1 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

# Database Petshop
## Deskripsi
Program ini adalah aplikasi sederhana untuk mengelola data produk petshop menggunakan Pemrograman Berorientasi Objek (OOP). Pengguna dapat menambah, melihat, mengubah, menghapus, dan mencari data produk petshop.

## Struktur OOP
Kode program ini mempunyai 1 class yaitu Petshop. Petshop memiliki 4 buah atribut yaitu ID, nama, kategori, dan harga.

## Alur Kode Program

1. **Inisialisasi dan Deklarasi:**
   - Program dimulai dengan mengimpor file `Petshop.cpp`, yang berisi definisi kelas `Petshop`.
   - Menggunakan `vector<Petshop>` untuk menyimpan data produk petshop. `vector` adalah struktur data dinamis yang memungkinkan penambahan dan penghapusan elemen secara efisien.

2. **Data Dummy:**
   - Dua data dummy ditambahkan ke dalam vector untuk memudahkan pengujian aplikasi:
     - Produk 1: ID = 1, Nama = "Whiskas", Kategori = "Makanan_Kucing", Harga = 50000
     - Produk 2: ID = 2, Nama = "Pedigree", Kategori = "Makanan_Anjing", Harga = 75000
![image](https://github.com/user-attachments/assets/6212be6a-dc10-45c1-b7de-9b3a918f6dbe)

3. **Menu Utama:**
   - Program menampilkan menu utama yang memungkinkan pengguna untuk memilih aksi yang ingin dilakukan. Pengguna dapat memilih dari 6 opsi:
     1. Tambah Data Petshop
     2. Lihat Data Petshop
     3. Ubah Data Petshop
     4. Hapus Data Petshop
     5. Cari Data Petshop
     6. Keluar
![image](https://github.com/user-attachments/assets/45c0fcc8-2260-4d29-b955-b49f40a78f2d)


## Input dan Output

### 1. Tambah Data Petshop
- **Tangkapan Layar:**
  - ![image](https://github.com/user-attachments/assets/b625283d-a688-4fb0-b497-de5b3e53847f)

- **Input:**
  - ID Produk
  - Nama Produk
  - Kategori Produk
  - Harga Produk
    
- **Output:**
  - Menampilkan pesan "Data berhasil ditambahkan" jika data berhasil ditambahkan ke dalam vector.

### 2. Lihat Data Petshop
- **Tangkapan Layar:**
  - ![image](https://github.com/user-attachments/assets/8e749f3b-095b-4fdb-b43c-1ca1fb944711)

- **Output:**
  - Menampilkan semua data produk yang ada dalam vector. Jika vector kosong, menampilkan pesan "Data kosong".

### 3. Ubah Data Petshop
- **Tangkapan Layar:**
  - JIka Data Ditemukan
    Sebelum data diubah:
      ![image](https://github.com/user-attachments/assets/6c3c7998-79f2-468c-af63-cd6b0dec1bc5)
    Setelah data diubah:
      ![image](https://github.com/user-attachments/assets/58b3a85c-38a2-4b9e-b301-02360fed6128)
    Jika ID produk tidak ditemukan:
      ![image](https://github.com/user-attachments/assets/73351881-0a50-4b0a-899d-b5d1b0f55c5e)

- **Input:**
  - ID Produk yang ingin diubah
  - ID Baru
  - Nama Baru
  - Kategori Baru
  - Harga Baru
- **Output:**
  - Menampilkan pesan "Produk berhasil diubah!" jika produk dengan ID yang dimasukkan ditemukan dan berhasil diubah. Jika tidak ditemukan, menampilkan pesan "Produk dengan ID [ID] tidak ditemukan."

### 4. Hapus Data Petshop
- **Input:**
  - ID Produk yang ingin dihapus
- **Output:**
  - Menampilkan pesan "Produk berhasil dihapus!" jika produk dengan ID yang dimasukkan ditemukan dan berhasil dihapus. Jika tidak ditemukan, menampilkan pesan "Produk dengan ID [ID] tidak ditemukan."

### 5. Cari Data Petshop
- **Input:**
  - Nama Produk yang ingin dicari
- **Output:**
  - Menampilkan informasi produk (ID, Nama, Kategori, Harga) jika produk dengan nama yang dimasukkan ditemukan. Jika tidak ditemukan, menampilkan pesan "Produk dengan nama [nama] tidak ditemukan."

### 6. Keluar
- **Input:**
  - Tidak ada input dari pengguna.
- **Output:**
  - Menampilkan pesan "Terimakasih Telah Menggunakan Aplikasi ini" dan keluar dari program.
