#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct Admin {
	string namaLengkap;
    string username;
    int umur;
    string noTelp;
    string role;
    string password;
};

struct User {
	string namaLengkap;
	string username;
	string password;
};

struct Buku {
	int idBuku;
	string judulBuku;
	string penulis;
	string genre;
	int tahunTerbit;
	string status;
};

struct Riwayat{
	string namaUser;
    string judulBuku;
};

//Global
vector<Admin> listAdmin;
vector<User> listUser;
vector<Buku> daftarBuku;
vector<Riwayat> listRiwayat;

string namaUserAktif = "";

//Utilitas
void clearScreen(){
	system("cls");
}

void lanjut() {
    system("pause");
    clearScreen();
}

//File Handling
void simpanAdmin(){
    ofstream file("admin.txt");

    for(int i = 0; i < listAdmin.size(); i++){
        file << listAdmin[i].namaLengkap << "|"
             << listAdmin[i].username << "|"
             << listAdmin[i].umur << "|"
             << listAdmin[i].noTelp << "|"
             << listAdmin[i].role << "|"
             << listAdmin[i].password << endl;
    }
    file.close();
}

void bacaAdmin(){
    ifstream file("admin.txt");
    string baris;
    while(getline(file, baris)){
        stringstream ss(baris);

        Admin adminBaru;

        string umur;

        getline(ss, adminBaru.namaLengkap, '|');
        getline(ss, adminBaru.username, '|');
        getline(ss, umur, '|');
        getline(ss, adminBaru.noTelp, '|');
        getline(ss, adminBaru.role, '|');
        getline(ss, adminBaru.password, '|');

        adminBaru.umur = stoi(umur);

        listAdmin.push_back(adminBaru);
    }
    file.close();
}

void simpanUser(){
    ofstream file("user.txt");
    for(int i = 0; i < listUser.size(); i++){
        file << listUser[i].namaLengkap << "|"
             << listUser[i].username << "|"
             << listUser[i].password << endl;
    }
    file.close();
}

void bacaUser(){
    ifstream file("user.txt");
    string baris;
    
    while(getline(file, baris)){
        stringstream ss(baris);

        User userBaru;

        getline(ss, userBaru.namaLengkap, '|');
        getline(ss, userBaru.username, '|');
        getline(ss, userBaru.password, '|');

        listUser.push_back(userBaru);
    }
    file.close();
}
void simpanBuku(){
    ofstream file("buku.txt");

    for(int i = 0; i < daftarBuku.size(); i++){
        file << daftarBuku[i].idBuku << "|"
             << daftarBuku[i].judulBuku << "|"
             << daftarBuku[i].penulis << "|"
             << daftarBuku[i].genre << "|"
             << daftarBuku[i].tahunTerbit << "|"
             << daftarBuku[i].status << endl;
    }

    file.close();
}
void bacaBuku(){
    ifstream file("buku.txt");

    string baris;
    while(getline(file, baris)){

        stringstream ss(baris);

        Buku bukuBaru;

        string id, tahun;

        getline(ss, id, '|');
        getline(ss, bukuBaru.judulBuku, '|');
        getline(ss, bukuBaru.penulis, '|');
        getline(ss, bukuBaru.genre, '|');
        getline(ss, tahun, '|');
        getline(ss, bukuBaru.status, '|');

        bukuBaru.idBuku = stoi(id);
        bukuBaru.tahunTerbit = stoi(tahun);

        daftarBuku.push_back(bukuBaru);
    }

    file.close();
}

void simpanRiwayat(){
    ofstream file("riwayat.txt");

    for(int i = 0; i < listRiwayat.size(); i++){
        file << listRiwayat[i].namaUser << "|"
             << listRiwayat[i].judulBuku << endl;
    }
    file.close();
}

void bacaRiwayat(){

    ifstream file("riwayat.txt");
    string baris;

    while(getline(file, baris)){
        stringstream ss(baris);

        Riwayat dataBaru;
        getline(ss, dataBaru.namaUser, '|');
        getline(ss, dataBaru.judulBuku, '|');

        listRiwayat.push_back(dataBaru);
    }

    file.close();
}
//Sorting
void SortJudulBuku() {

    for(int i = 0; i < daftarBuku.size() - 1; i++) {
        for(int j = 0; j < daftarBuku.size() - i - 1; j++) {
            if(daftarBuku[j].judulBuku >
               daftarBuku[j+1].judulBuku) {
                swap(daftarBuku[j],daftarBuku[j+1]);
            }
        }
    }
}

void SortIdBuku() {
	    for(int i = 0; i < daftarBuku.size() - 1; i++) {
        for(int j = 0; j < daftarBuku.size() - i - 1; j++) {
            if(daftarBuku[j].idBuku >
               daftarBuku[j+1].idBuku) {
                swap(daftarBuku[j], daftarBuku[j+1]);
            }
        }
    }
}

//Display
void tampilHeader() {
	clearScreen();
    cout << "==================================" << endl;
    cout << "|   SISTEM PERPUSTAKAAN TERPADU  |" << endl;
    cout << "==================================" << endl;
}

void tampilanMenuAdmin() {
        cout << "\nSelamat Datang di Menu Admin" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>> LAMAN ADMIN SISTEM PERPUSTAKAAN <<<<<<<<<<<<<<<<<<<" << endl;
        cout << " |                  #        Menu Admin        #                        | " << endl;
        cout << " |     1. Tambah Buku                                                   | " << endl;
        cout << " |     2. Hapus Buku                                                    | " << endl;
        cout << " |     3. Lihat Daftar Buku                                             | " << endl;
        cout << " |     4. Lihat Riwayat Peminjaman Buku                                 | " << endl;
        cout << " |     5. Kembali ke Menu Utama                                         | " << endl;
        cout << " |                                                                      | " << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void tampilanMenuUser(string name) {
        cout << endl;
        cout << "||  Selamat datang, " << name << endl << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>> LAMAN USER SISTEM PERPUSTAKAAN <<<<<<<<<<<<<<<<<<<" << endl;
        cout << " |                  #        Peminjaman Buku        #                   | " << endl;
        cout << " |                                                                      | " << endl;
        cout << " |                           ~~ Menu Utama ~~                           | " << endl;
        cout << " |     1. Lihat Buku Tersedia                                           | " << endl;
        cout << " |     2. Pinjam Buku                                                   | " << endl;
        cout << " |     3. Cari Buku                                                     | " << endl;
        cout << " |     4. Kembali ke Menu Utama                                         | " << endl;
        cout << " |                                                                      | " << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void tampilBuku(int index){
    if(index >= daftarBuku.size()){
        return;
    }
    Buku *ptr = &daftarBuku[index];

    cout << "====================================" << endl;
    cout << "ID Buku      : " << ptr->idBuku << endl;
    cout << "Judul Buku   : " << ptr->judulBuku << endl;
    cout << "Penulis      : " << ptr->penulis << endl;
    cout << "Genre        : " << ptr->genre << endl;
    cout << "Tahun Terbit : " << ptr->tahunTerbit << endl;
    cout << "Status       : " << ptr->status << endl;
    cout << "====================================" << endl;
    tampilBuku(index + 1);
}

//Fitur ADMIN 
void tambahBuku(){
	Buku bukuBaru;
	
	clearScreen();
	
	    cout << "=======================================================================\n";
		cout << "|                            TAMBAH BUKU                              |\n";
		cout << "=======================================================================\n";
		cout << "ID Buku      : ";
		cin >> bukuBaru.idBuku;
    	cin.ignore();
    	
    	cout << "Judul Buku   : ";
    	getline(cin, bukuBaru.judulBuku);
    	
		cout << "Penulis      : ";
		getline(cin, bukuBaru.penulis);
		
		cout << "Genre        : ";
		getline(cin, bukuBaru.genre);
		
		cout << "Tahun Terbit : ";
		cin >> bukuBaru.tahunTerbit;
		cin.ignore();
		
		bukuBaru.status = "Tersedia";
		daftarBuku.push_back(bukuBaru);
		simpanBuku();
		
		cout << "\nBuku Berhasil ditambahkan!" << endl;
		lanjut();  	
}

void hapusBuku(){
    int id;
    bool ditemukan = false;

    clearScreen();

    cout << "Masukkan ID Buku yang ingin dihapus : ";
    cin >> id;
    for(int i = 0; i < daftarBuku.size(); i++){

        if(daftarBuku[i].idBuku == id){
            daftarBuku.erase(daftarBuku.begin() + i);
            
            simpanBuku();

            cout << "\nBuku berhasil dihapus!" << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "\nBuku tidak ditemukan!" << endl;
    }
    lanjut();
}

void lihatDaftarBuku(){
    clearScreen();
	int pilihan;
	
	cout << "====================================\n"; 
	cout << "|           URUTKAN BUKU           |\n";
	cout << "====================================\n"; 
    cout << "1. Berdasarkan ID Buku\n";
    cout << "2. Berdasarkan Judul Buku (A-Z)\n";
    cout << "Pilih : ";
    cin >> pilihan;
    cin.ignore();
    
 	if(pilihan == 1) {
        SortIdBuku();
    }
    else if(pilihan == 2) {
        SortJudulBuku();
    }
    else {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    cout << "====================================\n"; 
    cout << "|         DAFTAR BUKU              |\n";
    cout << "====================================\n";
	tampilBuku(0);
    lanjut();
}
void lihatRiwayat(){
    clearScreen();

    if(listRiwayat.empty()){
        cout << "Belum ada riwayat peminjaman." << endl;
    }
    else{
		for(int i = 0; i < listRiwayat.size(); i++){
        cout << "Nama User  : " << listRiwayat[i].namaUser << endl;
        cout << "Judul Buku : " << listRiwayat[i].judulBuku << endl;
        cout << "==============================" << endl;
        }
    }
    lanjut();
}
//Fitur User
void lihatBukuTersedia(){
	clearScreen();
    bool ada = false;

    for(int i = 0; i < daftarBuku.size(); i++){
        if(daftarBuku[i].status == "Tersedia"){
            ada = true;
            cout << "Judul Buku : " << daftarBuku[i].judulBuku << endl;
            cout << "Status     : " << daftarBuku[i].status << endl;
            cout << "============================" << endl;
        }
    }
    if(!ada){
        cout << "Tidak ada buku tersedia." << endl;
    }

    lanjut();
}
void pinjamBuku(string namaUser){
    string judul;
    bool ditemukan = false;

    clearScreen();

    cout << "Masukkan Judul Buku : ";
    getline(cin, judul);

    for(int i = 0; i < daftarBuku.size(); i++){
        Buku *ptr = &daftarBuku[i];
        if(ptr->judulBuku == judul &&
           ptr->status == "Tersedia"){
            ptr->status = "Dipinjam";
            
            simpanBuku();
            Riwayat dataBaru;

            dataBaru.namaUser = namaUser;
            dataBaru.judulBuku = judul;

            listRiwayat.push_back(dataBaru);
            
            simpanRiwayat();
            cout << "\nBuku berhasil dipinjam!" << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "\nBuku tidak tersedia!" << endl;
    }

    lanjut();
}
void cariBuku(){
    string cari;
    bool ditemukan = false;

    clearScreen();

    cout << "Masukkan Judul Buku : ";
    getline(cin, cari);

    for(int i = 0; i < daftarBuku.size(); i++){
        if(daftarBuku[i].judulBuku == cari){
            ditemukan = true;

            cout << "\nBuku Ditemukan!" << endl;
            cout << "ID Buku    : " << daftarBuku[i].idBuku << endl;
            cout << "Judul      : " << daftarBuku[i].judulBuku << endl;
            cout << "Penulis    : " << daftarBuku[i].penulis << endl;
            cout << "Genre      : " << daftarBuku[i].genre << endl;
            cout << "Status     : " << daftarBuku[i].status << endl;
        }
    }
    if(!ditemukan){
        cout << "\nBuku tidak ditemukan!" << endl;
    }

    lanjut();
}
//Authentication
bool loginUser() {
	clearScreen();
    string inputUsername, inputPassword;
    cout << "=====================\n";
    cout << "|     LOGIN USER    |\n";
    cout << "=====================" << endl;
    cout << "Username : "; getline(cin, inputUsername);
    cout << "Password : "; getline(cin, inputPassword);

    // Cek kecocokan data ke dalam vector listUser
    for (size_t i = 0; i < listUser.size(); i++) {
        if (listUser[i].username == inputUsername && listUser[i].password == inputPassword) {
            namaUserAktif = listUser[i].username; // Menyimpan nama untuk display laman user
            cout << "\n[Sukses] Login User Berhasil!" << endl;
            return true;
        }
    }
    cout << "\n[Gagal] Username atau Password User salah." << endl;
    return false;
}
bool loginAdmin() {
	clearScreen();
    string inputUsername, inputPassword, inputRole;
    cout << "=====================\n";
    cout << "|    LOGIN ADMIN    |\n";
    cout << "=====================" << endl;
    cout << "Username       : "; getline(cin, inputUsername);
    cout << "Password       : "; getline(cin, inputPassword);
    cout << "Jabatan / Role : "; getline(cin, inputRole);

    // Cek kecocokan data ke dalam vector listAdmin
    for (size_t i = 0; i < listAdmin.size(); i++) {
        if (listAdmin[i].username == inputUsername && 
            listAdmin[i].password == inputPassword && 
            listAdmin[i].role == inputRole) {
            cout << "\n[Sukses] Login Admin Berhasil!" << endl;
            return true;
        }
    }
    cout << "\n[Gagal] Username, Password, atau Role Admin salah." << endl;
    return false;
}
//Registrasi
void daftarAdmin() {
	clearScreen();
    Admin adminBaru;
    cout << "\n==========================";
    cout << "\n|    REGISTRASI ADMIN    |";
    cout << "\n==========================" << endl;
    
    cout << "Nama Lengkap    : "; getline(cin, adminBaru.namaLengkap);
    cout << "Username        : "; getline(cin, adminBaru.username);
    cout << "Umur            : "; cin >> adminBaru.umur; cin.ignore();
    cout << "Nomor Telepon   : "; getline(cin, adminBaru.noTelp);
    cout << "Jabatan / Role  : "; getline(cin, adminBaru.role);
    cout << "Password        : "; getline(cin, adminBaru.password);

    listAdmin.push_back(adminBaru);
    simpanAdmin();
    cout << "\n[Pesan] Pendaftaran Admin Berhasil! Silakan kembali login." << endl;
	
	lanjut();
}
void daftarUser() {
	clearScreen();
	User userBaru;
	cout << "==========================\n";
    cout << "|    REGRISTRASI USER    |\n";
    cout << "==========================" << endl;
    cout << "Nama Lengkap	: ";getline(cin, userBaru.namaLengkap);
    cout << "Username	: "; 	getline(cin, userBaru.username);
	cout << "Password	: "; 	getline(cin, userBaru.password);

    listUser.push_back(userBaru);
    simpanUser();
    cout << "\n[Pesan] Pendaftaran User Berhasil!" << endl;
    lanjut();
}
//Menu
void menuDaftar() {
	clearScreen();
    int pilihan;
    cout << "=========================\n";
    cout << "|      OPSI DAFTAR      |\n";
    cout << "=========================\n";
    cout << "1. Daftar sebagai Admin" << endl;
    cout << "2. Daftar sebagai User" << endl;
    cout << "Pilih opsi (1-2): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        daftarAdmin();
    } else if (pilihan == 2) {
        daftarUser();
    } else {
        cout << "Pilihan tidak valid! Kembali ke menu utama." << endl;
    }
}
int menuLogin() {
	clearScreen();
    int pilihan;
    cout << "========================\n";
    cout << "|     OPSI LOGIN       |\n";
    cout << "========================" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai User" << endl;
    cout << "Pilih opsi (1-2): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        if (loginAdmin()) {
            return 1; 
        }
    } else if (pilihan == 2) {
        if (loginUser()) {
            return 2; 
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
    return 0;
}
void menuAdmin(){
	int pilihanAdmin;
	do {
	clearScreen();
	tampilanMenuAdmin();
	cout << "Pilih Menu : ";
    cin >> pilihanAdmin;
    cin.ignore();
    	switch (pilihanAdmin) {
            case 1:
                cout << "[Fitur] Jalankan fungsi Tambah Buku..." << endl;
                tambahBuku();
                break;
            case 2:
                cout << "[Fitur] Jalankan fungsi Hapus Buku..." << endl;
                hapusBuku();
                break;
            case 3:
                cout << "[Fitur] Jalankan fungsi Lihat Daftar Buku..." << endl;
                lihatDaftarBuku();
                break;
			case 4:
                cout << "[Fitur] Jalankan fungsi Status Peminjaman Buku..." << endl;
                lihatRiwayat();
                break;
            case 5:
                cout << "Keluar dari Laman Admin. Kembali ke Halaman Utama..." << endl;
                break;                
           default : 
            cout << "Pilihan tidak valid!" << endl;
            cout << "Tekan Enter untuk mencoba lagi.";
            cin.ignore();
            cin.get();
            break;
        }	
	} 	while (pilihanAdmin != 5);

}

void menuUser(string nama){
	int pilihanUser;
	do {
	clearScreen();
	tampilanMenuUser(nama);
	cout << "Pilih Menu : ";
    cin >> pilihanUser;
    cin.ignore();
    
    	switch (pilihanUser) {
            case 1:
                cout << "[Fitur] Jalankan fungsi Buku Tersedia..." << endl;
                lihatBukuTersedia();
                break;
            case 2:
                cout << "[Fitur] Jalankan fungsi Pinjam Buku..." << endl;
                pinjamBuku(nama);
                break;
            case 3:
                cout << "[Fitur] Jalankan fungsi Cari Buku..." << endl;
                cariBuku();
                break;
            case 4:
            	cout << "Keluar dari Laman User. Kembali ke Halaman Utama..." << endl;
                return;
           default : 
            	cout << "Pilihan tidak valid!" << endl;
        }	
	}	while (pilihanUser != 5);
	lanjut();
}   

int main() {
	bacaAdmin();
    bacaUser();
    bacaBuku();
    bacaRiwayat();
    tampilHeader();
    
    int pilihan;
    int statusLogin = 0;
    
    do { 
    clearScreen();
        cout << "\n===============================" << endl;
        cout << "|         HALAMAN UTAMA       |" << endl;
        cout << "===============================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi (1-3): ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                statusLogin = menuLogin(); 
                if (statusLogin == 1) {
                    menuAdmin();
                } 
                else if (statusLogin == 2) {
                    menuUser(namaUserAktif);
                }
                break;
            case 2:
                menuDaftar();
                break; 
            case 3:
                cout << "\nTerima kasih telah menggunakan program ini!" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }     
    } while (pilihan != 3);
    return 0;
}
