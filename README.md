# 📚 Sistem Perpustakaan Terpadu (C++)

Sistem Perpustakaan Terpadu adalah aplikasi berbasis **C++ Console** yang dibuat menggunakan konsep **Pemrograman Terstruktur** dengan memanfaatkan **Struct, Vector, Pointer, Rekursif, File Handling, dan Sorting**. Program ini dirancang untuk membantu proses pengelolaan data buku serta transaksi peminjaman pada sebuah perpustakaan sederhana.

## ✨ Fitur Utama

### 👨‍💼 Admin

* Registrasi dan Login Admin
* Menambahkan data buku
* Menghapus data buku
* Melihat daftar buku

  * Urut berdasarkan ID Buku
  * Urut berdasarkan Judul Buku (A-Z)
* Melihat riwayat peminjaman buku

### 👤 User

* Registrasi dan Login User
* Melihat daftar buku yang tersedia
* Mencari buku berdasarkan judul
* Meminjam buku
* Status buku otomatis berubah menjadi **Dipinjam** setelah dipinjam

## 🛠 Konsep Pemrograman yang Digunakan

* Struct
* Vector (Dynamic Array)
* Pointer
* Rekursif
* Bubble Sort
* File Handling (`fstream`)
* String Stream (`stringstream`)
* Modular Programming (Function)
* Authentication System (Login & Register)

## 💾 Penyimpanan Data

Program menggunakan file `.txt` sebagai media penyimpanan sehingga data tidak akan hilang setelah program ditutup.

File yang digunakan:

* `admin.txt`
* `user.txt`
* `buku.txt`
* `riwayat.txt`

## 📂 Struktur Data

### Admin

* Nama Lengkap
* Username
* Umur
* Nomor Telepon
* Role/Jabatan
* Password

### User

* Nama Lengkap
* Username
* Password

### Buku

* ID Buku
* Judul Buku
* Penulis
* Genre
* Tahun Terbit
* Status (Tersedia / Dipinjam)

### Riwayat

* Nama User
* Judul Buku

## 🚀 Cara Menjalankan Program

1. Clone repository ini.
2. Buka project menggunakan Code::Blocks, Dev-C++, Visual Studio, atau compiler C++ lainnya.
3. Compile dan jalankan file utama (`main.cpp`).
4. Program akan otomatis membaca data dari file `.txt` yang tersedia.

## 📖 Tujuan Pembuatan

Project ini dibuat sebagai media pembelajaran dan memenuhi tugas mata kuliah **Algoritma dan Pemrograman / Struktur Data**, dengan implementasi berbagai konsep dasar C++ dalam sebuah studi kasus sistem perpustakaan.

---

**Bahasa Pemrograman:** C++
**Paradigma:** Pemrograman Terstruktur
**Penyimpanan Data:** Text File (.txt)
