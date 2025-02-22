<?php
session_start();

if (!isset($_SESSION['products'])) {
    $_SESSION['products'] = [
        new Petshop(1, "Whiskas", "Makanan_Kucing", 50000, "whiskas.jpg"),
        new Petshop(2, "Pedigree", "Makanan_Anjing", 75000, "pedigree.jpg")
    ];
}

function getAllProducts() {
    return $_SESSION['products'];
}

function addProduct($product) {
    $_SESSION['products'][] = $product;
}

function updateProduct($id, $product) {
    foreach ($_SESSION['products'] as $key => $item) {
        if ($item->getId() == $id) {
            $_SESSION['products'][$key] = $product;
            return true;
        }
    }
    return false;
}

function deleteProduct($id) {
    foreach ($_SESSION['products'] as $key => $item) {
        if ($item->getId() == $id) {
            unset($_SESSION['products'][$key]);
            $_SESSION['products'] = array_values($_SESSION['products']);
            return true;
        }
    }
    return false;
}

function findProduct($id) {
    foreach ($_SESSION['products'] as $product) {
        if ($product->getId() == $id) {
            return $product;
        }
    }
    return null;
}
?>