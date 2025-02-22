<?php
require_once 'Petshop.php';
require_once 'storage.php';

$message = '';
$products = getAllProducts();
$searchResults = null;

// Handle search
if (isset($_GET['search'])) {
    $searchTerm = strtolower($_GET['search']);
    $searchResults = array_filter($products, function($product) use ($searchTerm) {
        return strpos(strtolower($product->getNama()), $searchTerm) !== false;
    });
}

// Handle form submissions
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['action'])) {
        switch ($_POST['action']) {
            case 'add':
                $newProduct = new Petshop(
                    $_POST['id'],
                    $_POST['nama'],
                    $_POST['kategori'],
                    $_POST['harga']
                );
                
                // Handle file upload
                if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === 0) {
                    $targetDir = "uploads/";
                    $fileName = basename($_FILES["gambar"]["name"]);
                    $targetFile = $targetDir . $fileName;
                    
                    if (move_uploaded_file($_FILES["gambar"]["tmp_name"], $targetFile)) {
                        $newProduct->setGambar($fileName);
                        addProduct($newProduct);
                        $message = "Produk berhasil ditambahkan";
                    } else {
                        $message = "Gagal mengupload gambar";
                    }
                }
                break;

            case 'delete':
                if (deleteProduct($_POST['id'])) {
                    $message = "Produk berhasil dihapus";
                }
                break;

            case 'update':
                $updatedProduct = new Petshop(
                    $_POST['id'],
                    $_POST['nama'],
                    $_POST['kategori'],
                    $_POST['harga'],
                    $_POST['gambar_lama']
                );

                if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === 0) {
                    $targetDir = "uploads/";
                    $fileName = basename($_FILES["gambar"]["name"]);
                    $targetFile = $targetDir . $fileName;
                    
                    if (move_uploaded_file($_FILES["gambar"]["tmp_name"], $targetFile)) {
                        $updatedProduct->setGambar($fileName);
                    }
                }

                if (updateProduct($_POST['id'], $updatedProduct)) {
                    $message = "Produk berhasil diupdate";
                }
                break;
        }
        
        // Refresh products after modification
        $products = getAllProducts();
    }
}

?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sistem Manajemen Petshop</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .product-image {
            max-width: 150px;
            max-height: 150px;
            object-fit: cover;
        }
        .search-alert {
            margin-top: 1rem;
            margin-bottom: 1rem;
        }
        .alert {
            margin-bottom: 1rem;
        }
    </style>
</head>
<body>
    <div class="container py-5">
        <h1 class="text-center mb-4">Sistem Manajemen Petshop</h1>
        
        <?php if ($message): ?>
            <div class="alert alert-success"><?php echo $message; ?></div>
        <?php endif; ?>

        <!-- Form Pencarian -->
        <div class="card mb-4">
            <div class="card-header">
                <h5 class="mb-0">Cari Produk</h5>
            </div>
            <div class="card-body">
                <form method="GET" class="row g-3">
                    <div class="col-md-10">
                        <input type="text" 
                            name="search" 
                            class="form-control" 
                            placeholder="Masukkan nama produk..."
                            value="<?php echo isset($_GET['search']) ? htmlspecialchars($_GET['search']) : ''; ?>">
                    </div>
                    <div class="col-md-2">
                        <button type="submit" class="btn btn-primary w-100">Cari</button>
                    </div>
                </form>
                <!-- Tampilkan Semua Produk Button -->
                <div class="mt-3">
                    <form method="GET" class="d-inline">
                        <input type="hidden" name="search" value="">
                        <button type="submit" class="btn btn-secondary w-100">Tampilkan Semua Produk</button>
                    </form>
                </div>
            </div>
        </div>


        <?php if (isset($_GET['search'])): ?>
            <?php if (empty($searchResults)): ?>
                <div class="alert alert-warning search-alert">
                    Produk dengan nama "<?php echo htmlspecialchars($_GET['search']); ?>" tidak ditemukan.
                </div>
            <?php else: ?>
                <div class="alert alert-info search-alert">
                    Ditemukan <?php echo count($searchResults); ?> produk dengan nama "<?php echo htmlspecialchars($_GET['search']); ?>".
                </div>
            <?php endif; ?>
        <?php endif; ?>

        <!-- Form Tambah Produk -->
        <div class="card mb-4">
            <div class="card-header">
                <h5 class="mb-0">Tambah Produk</h5>
            </div>
            <div class="card-body">
                <form method="POST" enctype="multipart/form-data">
                    <div class="mb-3">
                        <label class="form-label">ID Produk</label>
                        <input type="number" name="id" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Nama Produk</label>
                        <input type="text" name="nama" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Kategori</label>
                        <input type="text" name="kategori" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Harga</label>
                        <input type="number" name="harga" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Gambar</label>
                        <input type="file" name="gambar" class="form-control" required>
                    </div>
                    <button type="submit" name="action" value="add" class="btn btn-success">Tambah Produk</button>
                </form>
            </div>
        </div>

        <!-- Tabel Produk -->
        <div class="card">
            <div class="card-header">
                <h5 class="mb-0">Daftar Produk</h5>
            </div>
            <div class="card-body">
                <div class="table-responsive">
                    <table class="table table-bordered">
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Gambar</th>
                                <th>Nama</th>
                                <th>Kategori</th>
                                <th>Harga</th>
                                <th>Aksi</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php 
                            // Display search results if search was performed, otherwise display all products
                            $displayProducts = isset($searchResults) ? $searchResults : $products;
                            foreach ($displayProducts as $product): 
                            ?>
                            <tr>
                                <td><?php echo $product->getId(); ?></td>
                                <td>
                                    <?php if ($product->getGambar()): ?>
                                        <img src="uploads/<?php echo $product->getGambar(); ?>" 
                                             class="product-image"
                                             alt="<?php echo $product->getNama(); ?>">
                                    <?php else: ?>
                                        <span class="text-muted">No image</span>
                                    <?php endif; ?>
                                </td>
                                <td><?php echo $product->getNama(); ?></td>
                                <td><?php echo $product->getKategori(); ?></td>
                                <td>Rp <?php echo number_format($product->getHarga(), 0, ',', '.'); ?></td>
                                <td>
                                    <button class="btn btn-sm btn-warning mb-1" 
                                            onclick="editProduct(<?php echo htmlspecialchars(json_encode($product)); ?>)">
                                        Edit
                                    </button>
                                    <form method="POST" class="d-inline">
                                        <input type="hidden" name="action" value="delete">
                                        <input type="hidden" name="id" value="<?php echo $product->getId(); ?>">
                                        <button type="submit" class="btn btn-sm btn-danger" 
                                                onclick="return confirm('Yakin ingin menghapus?')">
                                            Hapus
                                        </button>
                                    </form>
                                </td>
                            </tr>
                            <?php endforeach; ?>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>

    <!-- Modal Edit -->
    <div class="modal fade" id="editModal" tabindex="-1">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title">Edit Produk</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                </div>
                <div class="modal-body">
                    <form method="POST" enctype="multipart/form-data" id="editForm">
                        <input type="hidden" name="action" value="update">
                        <input type="hidden" name="gambar_lama" id="gambar_lama">
                        <div class="mb-3">
                            <label class="form-label">ID Produk</label>
                            <input type="number" name="id" id="edit_id" class="form-control" readonly>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Nama Produk</label>
                            <input type="text" name="nama" id="edit_nama" class="form-control" required>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Kategori</label>
                            <input type="text" name="kategori" id="edit_kategori" class="form-control" required>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Harga</label>
                            <input type="number" name="harga" id="edit_harga" class="form-control" required>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Gambar Baru (Opsional)</label>
                            <input type="file" name="gambar" class="form-control">
                        </div>
                        <button type="submit" class="btn btn-primary">Simpan Perubahan</button>
                    </form>
                </div>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js"></script>
    <script>
        function editProduct(product) {
            document.getElementById('edit_id').value = product.id;
            document.getElementById('edit_nama').value = product.nama;
            document.getElementById('edit_kategori').value = product.kategori;
            document.getElementById('edit_harga').value = product.harga;
            document.getElementById('gambar_lama').value = product.gambar;
            
            new bootstrap.Modal(document.getElementById('editModal')).show();
        }
    </script>
</body>
</html>
