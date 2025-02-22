import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Petshop> data = new ArrayList<>(); // Menggunakan ArrayList untuk menyimpan data produk
        Petshop tmp; // Objek sementara
        int pilihan; // Variabel untuk menyimpan pilihan menu

        // Data Dummy
        data.add(new Petshop(1, "Whiskas", "Makanan_Kucing", 50000)); // Menambahkan data dummy
        data.add(new Petshop(2, "Pedigree", "Makanan_Anjing", 75000)); // Menambahkan data dummy

        do {
            System.out.println("\nSelamat Datang di Database Petshop");
            System.out.println("Pilih Aksi yang Ingin Anda Lakukan");
            System.out.println("1. Tambah Data Petshop");
            System.out.println("2. Lihat Data Petshop");
            System.out.println("3. Ubah Data Petshop");
            System.out.println("4. Hapus Data Petshop");
            System.out.println("5. Cari Data Petshop");
            System.out.println("6. Keluar");
            System.out.print("Opsi yang Dipilih (1-6): ");
            pilihan = scanner.nextInt();

            switch (pilihan) {
                case 1: // Tambah Data
                    System.out.print("Masukkan ID Produk: ");
                    int tmp_id = scanner.nextInt();
                    scanner.nextLine(); // Membersihkan buffer
                    System.out.print("Masukkan Nama Produk: ");
                    String tmp_nama = scanner.nextLine();
                    System.out.print("Masukkan Kategori Produk: ");
                    String tmp_kategori = scanner.nextLine();
                    System.out.print("Masukkan Harga Produk: ");
                    int tmp_harga = scanner.nextInt();

                    tmp = new Petshop(tmp_id, tmp_nama, tmp_kategori, tmp_harga);
                    data.add(tmp); // Menambahkan objek ke ArrayList
                    System.out.println("Data berhasil ditambahkan");
                    break;

                case 2: // Lihat Data
                    System.out.println("Data Petshop:");
                    if (data.isEmpty()) {
                        System.out.println("Data kosong");
                    } else {
                        for (Petshop petshop : data) {
                            System.out.println("ID: " + petshop.getID());
                            System.out.println("Nama: " + petshop.getNama());
                            System.out.println("Kategori: " + petshop.getKategori());
                            System.out.println("Harga: " + petshop.getHarga());
                            System.out.println("-------------------------");
                        }
                    }
                    break;

                // Implementasi untuk pilihan 3, 4, dan 5 dapat ditambahkan di sini

                case 6: // Keluar
                    System.out.println("Terimakasih Telah Menggunakan Aplikasi ini");
                    break;

                default:
                    System.out.println("Pilihan Tidak Valid, harap pilih angka 1-6");
                    break;
            }
        } while (pilihan != 6);

        scanner.close(); // Menutup scanner
    }
}
