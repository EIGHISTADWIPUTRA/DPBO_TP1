<?php
class Petshop {
    private $id;
    private $nama;
    private $kategori;
    private $harga;
    private $gambar;

    public function __construct($id = null, $nama = null, $kategori = null, $harga = null, $gambar = null) {
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->gambar = $gambar;
    }

    // Getter methods
    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getKategori() { return $this->kategori; }
    public function getHarga() { return $this->harga; }
    public function getGambar() { return $this->gambar; }

    // Setter methods
    public function setId($id) { $this->id = $id; }
    public function setNama($nama) { $this->nama = $nama; }
    public function setKategori($kategori) { $this->kategori = $kategori; }
    public function setHarga($harga) { $this->harga = $harga; }
    public function setGambar($gambar) { $this->gambar = $gambar; }
}
?>