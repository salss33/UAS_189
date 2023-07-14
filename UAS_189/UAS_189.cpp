#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	string namaProduk;
	int jumlahProduk;
	string tipeProduk;
	Node* next;
};


class ManajemenProduk {
private:
	Node* head;
public:
	ManajemenProduk() {
		head = NULL;
	}
	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;
		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);
		Node* newNode = new Node();
		newNode->namaProduk = nama;
		newNode->jumlahProduk = jumlah;
		newNode->tipeProduk = tipe;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}

		cout << "Produk berhasil ditambahkan!" << endl;
	}
	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			while (current != NULL) {
				cout << "Nama: " << current->namaProduk << endl;
				cout << "Jumlah: " << current->jumlahProduk << endl;
				cout << "Tipe: " << current->tipeProduk << endl;
				cout << "==============" << endl;
				current = current->next;
			}
		}
	}
	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;

			int posisi = 0;

			while (current != NULL) {
				posisi++;

				if (current->namaProduk == targetNama) {
					cout << "Nama: " << current->namaProduk << endl;
					cout << "Jumlah: " << current->jumlahProduk << endl;
					cout << "Tipe: " << current->tipeProduk << endl;
					cout << "ditemukan pada posisi: " << posisi << endl;
					return;

				}
				if (current == NULL) {
				}
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
			}
		}
	}

	void algorithmaSortByJumlahProduk() {
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}

		Node* current = head;
		Node* index = NULL:
		Node* last = NULL;
		int tempJumlah;
		string tempNama, tempTipe;
		
		while (current != NULL) {
			index = current->next;
			while (index != NULL) {
				if (current->jumlahProduk < index->jumlahProduk) {
					tempNama = current->namaProduk;
					tempJumlah = current->jumlahProduk;
					tempTipe = current->tipeProduk;
					current->namaProduk = index->namaProduk;
					current->jumlahProduk = index->jumlahProduk;
					current->tipeProduk = index->tipeProduk;
					index->namaProduk = tempNama;
					index->jumlahProduk = tempJumlah;
					index->tipeProduk = tempTipe;
				}
				index = index->next;
			}
			current = current->next
		}
		cout << "Data produk berhasil diurutkan berdasarkan jumlah produk." << endl;
	}
};


int main() {
	ManajemenProduk manajemenProduk;
	int pilihan;

	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();

		switch (pilihan) {
		case 1:
			manejemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.algorithmaSortByJumlahProduk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}

		cout << endl;

	} while (pilihan != 5);

	return 0;
}


//Menjawab Pertanyaan :
//1. Algoritma yang digunakan dalam program di atas :

//Algoritma penambahan produk : Produk baru ditambahkan dengan membuat node baru dan menghubungkannya dengan node terakhir pada linked list.
//Algoritma tampilan semua produk : Semua data produk ditampilkan dengan menggunakan perulangan pada linked list dan mencetak data produk pada setiap node.
//Algoritma pencarian produk berdasarkan nama : Data produk dicari dengan menggunakan perulangan pada linked list dan membandingkan nama produk pada setiap node dengan nama yang dicari.
//Algoritma pengurutan produk berdasarkan jumlah : Algoritma pengurutan bubble sort digunakan untuk mengurutkan data produk berdasarkan jumlah produk dalam urutan menurun.
//Untuk menyelesaikan masalah menggunakan algoritma queue dengan menggunakan array, kita dapat menggunakan dua indeks, yaitu front dan rear, serta sebuah array dengan ukuran tertentu untuk menyimpan elemen - elemen dalam queue.Berikut adalah langkah - langkah untuk menyelesaikan masalah tersebut :

//Inisialisasi array dengan ukuran tertentu, misalnya MAX_SIZE.
//Inisialisasi front dan rear dengan nilai - 1.
