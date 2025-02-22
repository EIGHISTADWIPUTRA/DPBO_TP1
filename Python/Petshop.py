class Petshop:
    def __init__(self, ID=None, nama=None, kategori=None, harga=None):
        self._ID = ID              
        self._nama = nama          
        self._kategori = kategori
        self._harga = harga

    # Getter methods
    def getID(self):
        """Fungsi untuk mendapatkan ID produk"""
        return self._ID

    def getNama(self):
        """Fungsi untuk mendapatkan nama produk"""
        return self._nama

    def getKategori(self):
        """Fungsi untuk mendapatkan kategori produk"""
        return self._kategori

    def getHarga(self):
        """Fungsi untuk mendapatkan harga produk"""
        return self._harga

    # Setter methods
    def setID(self, ID):
        """Fungsi untuk menetapkan ID produk"""
        self._ID = ID

    def setNama(self, nama):
        """Fungsi untuk menetapkan nama produk"""
        self._nama = nama

    def setKategori(self, kategori):
        """Fungsi untuk menetapkan kategori produk"""
        self._kategori = kategori

    def setHarga(self, harga):
        """Fungsi untuk menetapkan harga produk"""
        self._harga = harga