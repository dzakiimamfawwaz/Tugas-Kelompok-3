/*
soal no 2 TK 3
Kelompok 7

Dikhi Martin           - 2301969484
Dzaki Imam Fawwaz      - 2702367486
Tomas Warren Wuisang   - 2702368715
Ahmad Abdul Aziz       - 2702346916
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Tipe data untuk pegawai
struct Pegawai {
    char nip[11]; // NIP maksimal 10 digit
    char nama[50];
    char alamat[100];
    char no_hp[15]; // Nomor HP maksimal 14 digit
    char jabatan[30];
    char golongan[3];
};

// Fungsi-fungsi deklarasi
void inputPegawai(struct Pegawai *pegawai);
int hitungGajiPokok(const char *golongan);
int hitungGajiLembur(const char *golongan, int jumlahJamLembur);
bool isNumeric(const char *str);
bool isAlphaWithSpaces(const char *str);
void clearScreen();
void mainMenu(int *choice);
void validasi_check();
void terimakasih();

int main() {
    int choice;
    do {
        clearScreen();
        mainMenu(&choice);
        switch (choice) {
            case 1: {
                struct Pegawai pegawai;
                int jumlahJamLembur;

                // Input data pegawai
                inputPegawai(&pegawai);

                int gajiPokok = hitungGajiPokok(pegawai.golongan);
                printf("\n------------------------\n");
                printf("\033[32m Gaji %s = %d\033[0m\n", pegawai.nama , gajiPokok);
                printf("------------------------\n");

                // Input data lembur
                printf("\nInput 2:\n");
                printf("NIP                 = %s\n", pegawai.nip);
                
                bool validGolongan = false;
                do {
                    printf("Golongan (D1/D2/D3) = ");
                    scanf("%s", pegawai.golongan);
                    if (strcmp(pegawai.golongan, "D1") == 0 || strcmp(pegawai.golongan, "D2") == 0 || strcmp(pegawai.golongan, "D3") == 0) {
                        validGolongan = true;
                    } else {
                        printf("Golongan tidak valid. Hanya diizinkan D1, D2, atau D3.\n");
                    }
                } while (!validGolongan);
                
                printf("Jumlah Jam Lembur   = ");
                scanf("%d", &jumlahJamLembur);
                
                int gajiLembur = hitungGajiLembur(pegawai.golongan, jumlahJamLembur);
                int totalGaji = gajiPokok + gajiLembur;
                printf("\n------------------------------------------\n");
                printf("\x1b[32mTotal Gaji %s Bulan ini = %d\x1b[0m\n", pegawai.nama, totalGaji);
                printf("------------------------------------------");
                printf("\n\x1b[34;47mTekan \"enter\" untuk kembali ke menu.\033[0m\n");
                getchar(); // Membaca karakter baru (Enter)
  				getchar(); // Menunggu Enter lagi
				
                break;
            }
            case 2:
                terimakasih(); //exit program
                break;
            default:
                validasi_check(); //validasi check
                break;
                
        }
    } while (choice != 2);

    return 0;
}

// Fungsi untuk menginput data pegawai
void inputPegawai(struct Pegawai *pegawai) {
    printf("\nInput 1:\n\n");

    do {
        printf("NIP                 = ");
        scanf("%10s", pegawai->nip); // Maksimal 10 karakter
        if (strlen(pegawai->nip) != 10 || !isNumeric(pegawai->nip)) {
            printf("\n\033[41mNIP harus terdiri dari 10 digit angka.\n\033[0m\n");
        }
    } while (strlen(pegawai->nip) != 10 || !isNumeric(pegawai->nip));

    do {
        printf("Nama                = ");
        scanf(" %[^\n]", pegawai->nama);
        if (!isAlphaWithSpaces(pegawai->nama)) {
            printf("\n\033[41mNama hanya boleh mengandung huruf dan spasi.\n\033[0m\n");
        }
    } while (!isAlphaWithSpaces(pegawai->nama));

    printf("Alamat              = ");
    scanf(" %[^\n]", pegawai->alamat);

    do {
        printf("No HP               = ");
        scanf("%14s", pegawai->no_hp); // Maksimal 14 karakter
        if (strlen(pegawai->no_hp) > 14 || !isNumeric(pegawai->no_hp)) {
            printf("\n\033[41mNo HP tidak valid.\n\033[0m\n");
        }
    } while (strlen(pegawai->no_hp) > 14 || !isNumeric(pegawai->no_hp));

    do {
        printf("Jabatan             = ");
        scanf(" %[^\n]", pegawai->jabatan);
        if (!isAlphaWithSpaces(pegawai->jabatan)) {
            printf("\n\033[41mJabatan hanya boleh mengandung huruf dan spasi.\033[0m\n");
        }
    } while (!isAlphaWithSpaces(pegawai->jabatan));

    bool validGolongan = false;
    do {
        printf("Golongan (D1/D2/D3) = ");
        scanf("%s", pegawai->golongan);
        if (strcmp(pegawai->golongan, "D1") == 0 || strcmp(pegawai->golongan, "D2") == 0 || strcmp(pegawai->golongan, "D3") == 0) {
            validGolongan = true;
        } else {
            printf("\n\033[41mGolongan tidak valid. Hanya diizinkan D1, D2, atau D3.\033[0m\n");
        }
    } while (!validGolongan);
}

// Fungsi untuk menghitung gaji berdasarkan golongan
int hitungGajiPokok(const char *golongan) {
    if (strcmp(golongan, "D1") == 0) {
        return 2500000;
    } else if (strcmp(golongan, "D2") == 0) {
        return 2000000;
    } else if (strcmp(golongan, "D3") == 0) {
        return 1500000;
    } else {
        return 0; // Golongan tidak valid
    }
}

// Fungsi untuk menghitung gaji lemburan
int hitungGajiLembur(const char *golongan, int jumlahJamLembur) {
    if (strcmp(golongan, "D1") == 0) {
        return 10000 * jumlahJamLembur;
    } else if (strcmp(golongan, "D2") == 0) {
        return 5000 * jumlahJamLembur;
    } else if (strcmp(golongan, "D3") == 0) {
        return 2500 * jumlahJamLembur;
    } else {
        return 0; // Golongan tidak valid
    }
}

// Fungsi untuk memeriksa apakah string hanya mengandung angka
bool isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

// Fungsi untuk memeriksa apakah string hanya mengandung huruf dan spasi
bool isAlphaWithSpaces(const char *str) {
    while (*str) {
        if (!isalpha(*str) && *str != ' ') {
            return false;
        }
        str++;
    }
    return true;
}

// Fungsi untuk membersihkan layar
void clearScreen() {
    printf("\033[2J"); // Menggunakan ANSI escape code untuk membersihkan layar
    printf("\033[H");  // Mengatur kursor ke posisi awal (0,0)
}

// Fungsi untuk menampilkan menu utama
void mainMenu(int *choice) {
    printf("\n============================================\n");
    printf("      Selamat datang di TK2 soal no.1\n");
    printf("                Kelompok 7\n");
    printf("=============================================\n\n");
    printf("Pilihan\n");
    printf("===============\n");
    printf("1. Jalankan Program\n");
    printf("2. Exit\n");
    printf("Masukkan Pilihan : ");
    scanf("%d", choice);
}

// Fungsi untuk menampilkan pesan kesalahan jika input tidak valid
void validasi_check() {
    printf("\n\033[41mInput Invalid. Masukkan input 1-2\033[0m\n");
}

// Fungsi untuk menampilkan pesan terima kasih
void terimakasih() {
    printf("\n\033[32m----------------------------------\n");
    printf("          Terimakasih\n");
    printf("   Semoga harimu menyenangkan :)\n");
    printf("----------------------------------\033[0m\n");
}

