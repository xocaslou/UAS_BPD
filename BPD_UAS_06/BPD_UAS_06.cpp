// BPD_UAS_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
	Nama	: Ignasia Gladys Princy Wulandari
	NIM		: 202004560006
	Tujuan	: Membuat program peng-inputan data laporan pembelian tiket
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

struct pem06 {
	string nama06, gender06, tujuan06;
	int usia06, noant06;
	int harga06 = 0, hpajak06, tktxjml06, jumtkt06;

};

int pajak06(int a06) {
	int b06 = a06 + (a06 * 5 / 100);
	return b06;
}

void print06(struct pem06 data06[], int jum06) {
	for (int i06 = 0; i06 < jum06; i06++) {
		cout << "\n" << data06[i06].noant06 << "\t\t"
			<< data06[i06].nama06 << "\t\t"
			<< data06[i06].gender06 << "\t\t"
			<< data06[i06].tujuan06 << "\t\t"
			<< data06[i06].jumtkt06 << "\t\t"
			<< data06[i06].harga06 << "\t\t"
			<< data06[i06].hpajak06 << endl;
	}
}

int total06 = 0;

int main() {

	string adm06;
	int noadm06, tgl06, bln06, thn06, pil06, jum06;


	//input data admin
	cout << "Nama admin: "; getline(cin, adm06);
	cout << "Nomor admin: "; cin >> noadm06;
	cout << "Tanggal: "; cin >> tgl06;
	cout << "Bulan: "; cin >> bln06;
	cout << "Tahun: "; cin >> thn06;


	struct pem06 data06[50];

	//input jumlah data yang ingin dimasukkan
	do {
		cout << "Jumlah data yang ingin diinput : "; cin >> jum06;
		if (jum06 <= 0 || jum06 > 50) {
			cout << "Ulangi. Jumlah data harus lebih dari 0 atau tidak lebih dari 50";
		}
	} while (jum06 <= 0 || jum06 > 50);

	//perulangan input data
	for (int i06 = 0; i06 < jum06; i06++) {

		cout << endl;
		cout << "Nama pembeli: "; cin.ignore(); getline(cin, data06[i06].nama06);
		cout << "Nomor antrian: "; cin >> data06[i06].noant06;
		cout << "Jenis kelamin: "; cin.ignore(); getline(cin, data06[i06].gender06);
		cout << "Usia: "; cin >> data06[i06].usia06;
		cout << "Pilihan Tujuan" << endl;
		cout << "1. Kota A " << endl;
		cout << "2. Kota B " << endl;
		cout << "3. Kota C " << endl;
		cout << "4. Kota D " << endl;
		cout << "5. Kota E " << endl;
		cout << "Tujuan [1/2/3/4/5]	 : "; cin >> pil06;
		cout << "Jumlah tiket yang dibeli: "; cin >> data06[i06].jumtkt06;

		//pilihan harga sesuai tujuan
		switch (pil06) {
		case 1:
			data06[i06].tujuan06 = "Kota A";
			data06[i06].harga06 = 150000;
			break;
		case 2:
			data06[i06].tujuan06 = "Kota B";
			data06[i06].harga06 = 100000;
			break;
		case 3:
			data06[i06].tujuan06 = "Kota C";
			data06[i06].harga06 = 130000;
			break;
		case 4:
			data06[i06].tujuan06 = "Kota D";
			data06[i06].harga06 = 200000;
			break;
		case 5:
			data06[i06].tujuan06 = "Kota E";
			data06[i06].harga06 = 160000;
			break;
		default:
			cout << "Tidak ada tujuan yang dimaksud";
		}

		//mengitung tikat x jumlah pembelian tiket
		data06[i06].tktxjml06 = data06[i06].harga06 * data06[i06].jumtkt06;

		//menghitung harga setelah pajak
		data06[i06].hpajak06 = pajak06(data06[i06].tktxjml06);

		//menghitung total harga seluruh pembelian
		total06 += data06[i06].hpajak06;

	}

	//print tabel laporan
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tAdmin	: " << adm06 << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tNo. Admin : " << noadm06 << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tTgl : " << tgl06 << "/" << bln06 << "/" << thn06 << endl;

	for (int i06 = 1; i06 < 60; i06++) {
		cout << "__";
	}

	cout << "\nNO.ANT\t\tNAMA\t\tGENDER\t\tTUJUAN\t\tTIKET\t\tHARGA\t\tTOTAL\n";

	for (int i06 = 1; i06 < 60; i06++) {
		cout << "__";
	}

	print06(data06, jum06);

	for (int i06 = 1; i06 < 60; i06++) {
		cout << "__";
	}

	//sorting untuk daftar harga
	for (int i06 = 0; i06 < jum06 - 1; i06++) {
		for (int j06 = 0; j06 < jum06 - i06 - 1; j06++) {
			if (data06[j06].hpajak06 > data06[j06 + 1].hpajak06) {
				int temp06 = data06[j06].hpajak06;
				data06[j06] = data06[j06 + 1];
				data06[j06 + 1].hpajak06 = temp06;
			}
		}
	}

	cout << endl << endl;

	for (int i06 = 1; i06 < 20; i06++) {
		cout << "__";
	}

	cout << "\nData Pemasukan Penjualan Tiket" << endl;

	for (int i06 = 1; i06 < 20; i06++) {
		cout << "__";
	}

	for (int i06 = 0; i06 < jum06; i06++) {
		cout << "\n" << i06 + 1 << ". " << data06[i06].hpajak06 << endl;
	}

	for (int i06 = 1; i06 < 20; i06++) {
		cout << "__";
	}

	cout << "\nTotal\t\t" << total06 << endl;
}