from Petshop import Petshop  # Mengimpor kelas Petshop dari file petshop.py

def main():
    data = []  # List untuk menyimpan data produk petshop
    
    # Data Dummy
    data.append(Petshop(1, "Whiskas", "Makanan_Kucing", 50000))
    data.append(Petshop(2, "Pedigree", "Makanan_Anjing", 75000))

    while True:  # Perulangan utama program
        print("\nSelamat Datang di Database Petshop")
        print("Pilih Aksi yang Ingin Anda Lakukan")
        print("1. Tambah Data Petshop")
        print("2. Lihat Data Petshop")
        print("3. Ubah Data Petshop")
        print("4. Hapus Data Petshop")
        print("5. Cari Data Petshop")
        print("6. Keluar")

        try:
            pilihan = int(input("Opsi yang Dipilih (1-6): "))
            
            if pilihan == 1:  # Tambah Data
                tmp_id = int(input("Masukkan ID Produk: "))
                tmp_nama = input("Masukkan Nama Produk: ")
                tmp_kategori = input("Masukkan Kategori Produk: ")
                tmp_harga = int(input("Masukkan Harga Produk: "))

                tmp = Petshop()  # Membuat objek sementara
                tmp.setID(tmp_id)
                tmp.setNama(tmp_nama)
                tmp.setKategori(tmp_kategori)
                tmp.setHarga(tmp_harga)

                data.append(tmp)
                print("Data berhasil ditambahkan")

            elif pilihan == 2:  # Lihat Data
                print("Data Petshop:")
                if len(data) == 0:
                    print("Data kosong")
                else:
                    for item in data:
                        print(f"ID: {item.getID()}")
                        print(f"Nama: {item.getNama()}")
                        print(f"Kategori: {item.getKategori()}")
                        print(f"Harga: {item.getHarga()}")
                        print("-------------------------")

            elif pilihan == 3:  # Ubah Data
                find_id = int(input("Masukkan ID Produk yang Ingin Diubah: "))
                found = False

                for i, item in enumerate(data):
                    if item.getID() == find_id:
                        found = True
                        new_id = int(input("Masukkan ID Baru: "))
                        new_name = input("Masukkan Nama Baru: ")
                        new_category = input("Masukkan Kategori Baru: ")
                        new_price = int(input("Masukkan Harga Baru: "))

                        data[i].setID(new_id)
                        data[i].setNama(new_name)
                        data[i].setKategori(new_category)
                        data[i].setHarga(new_price)
                        print("Produk berhasil diubah!")
                        break

                if not found:
                    print(f"Produk dengan ID {find_id} tidak ditemukan.")

            elif pilihan == 4:  # Hapus Data
                find_id = int(input("Masukkan ID Produk yang Ingin Dihapus: "))
                found = False

                for i, item in enumerate(data):
                    if item.getID() == find_id:
                        found = True
                        data.pop(i)
                        print("Produk berhasil dihapus!")
                        break

                if not found:
                    print(f"Produk dengan ID {find_id} tidak ditemukan.")

            elif pilihan == 5:  # Cari Data
                find_name = input("Masukkan Nama Produk yang Ingin Dicari: ")
                found = False

                for item in data:
                    if item.getNama() == find_name:
                        found = True
                        print(f"ID: {item.getID()}")
                        print(f"Nama: {item.getNama()}")
                        print(f"Kategori: {item.getKategori()}")
                        print(f"Harga: {item.getHarga()}")
                        print("-------------------------")
                        break

                if not found:
                    print(f"Produk dengan nama {find_name} tidak ditemukan.")

            elif pilihan == 6:  # Keluar
                print("Terimakasih Telah Menggunakan Aplikasi ini")
                break

            else:
                print("Pilihan Tidak Valid, harap pilih angka 1-6")

        except ValueError:
            print("Input tidak valid. Masukkan angka.")

if __name__ == "__main__":
    main()