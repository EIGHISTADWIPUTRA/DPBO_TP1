public class Petshop { // Mendefinisikan kelas Petshop
    private int ID; // Variabel untuk menyimpan ID produk
    private String nama; // Variabel untuk menyimpan nama produk
    private String kategori; // Variabel untuk menyimpan kategori produk
    private int harga; // Variabel untuk menyimpan harga produk

    public Petshop() { // Konstruktor default
    }

    public Petshop(int ID, String nama, String kategori, int harga) { // Konstruktor dengan parameter
        this.ID = ID; // Menginisialisasi ID produk dengan nilai parameter
        this.nama = nama; // Menginisialisasi nama produk dengan nilai parameter
        this.kategori = kategori; // Menginisialisasi kategori produk dengan nilai parameter
        this.harga = harga; // Menginisialisasi harga produk dengan nilai parameter
    }

    public int getID() { // Fungsi untuk mendapatkan ID produk
        return this.ID; // Mengembalikan nilai ID produk
    }

    public String getNama() { // Fungsi untuk mendapatkan nama produk
        return this.nama; // Mengembalikan nilai nama produk
    }

    public String getKategori() { // Fungsi untuk mendapatkan kategori produk
        return this.kategori; // Mengembalikan nilai kategori produk
    }

    public int getHarga() { // Fungsi untuk mendapatkan harga produk
        return this.harga; // Mengembalikan nilai harga produk
    }

    public void setID(int ID) { // Fungsi untuk menetapkan ID produk
        this.ID = ID; // Menetapkan nilai ID produk dengan nilai parameter
    }

    public void setNama(String nama) { // Fungsi untuk menetapkan nama produk
        this.nama = nama; // Menetapkan nilai nama produk dengan nilai parameter
    }

    public void setKategori(String kategori) { // Fungsi untuk menetapkan kategori produk
        this.kategori = kategori; // Menetapkan nilai kategori produk dengan nilai parameter
    }

    public void setHarga(int harga) { // Fungsi untuk menetapkan harga produk
        this.harga = harga; // Menetapkan nilai harga produk dengan nilai parameter
    }
}
