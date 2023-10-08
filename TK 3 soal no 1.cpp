/*
soal no 1 TK 3
Kelompok 7

Dikhi Martin          - 2301969484
Dzaki Imam Fawwaz     - 2702367486
Tomas Warren Wuisang  - 2702368715
Ahmad Abdul Aziz      - 2702346916
*/

#include <stdio.h>
#include <stdlib.h>
// header fungsi yang diperlukan
void mainMenu(int *choice);
void logicMenu(int *choice);
void terimakasih();
void clearScreen();
void validasi_check();

int main()
{
    // melakukan perulangan
    while (1)
    {
        int choice;
        mainMenu(&choice);
        logicMenu(&choice);
    }

    return 0;
}
// main menu
void mainMenu(int *choice)
{
    printf("\n============================================\n");
    printf("      Selamat datang di TK2 soal no.1\n");
    printf("                Kelompok 7\n\n");
    printf("============================================\n");
    printf("Pilihan\n");
    printf("============================================\n");
    printf("1. Jalankan Program\n");
    printf("2. Clear screen\n");
    printf("3. Exit\n");
    printf("Masukkan Pilihan : ");
    scanf("%d", choice);
}
// logic atau proses yang dilakukkan
void logicMenu(int *choice)
{
    float total_pembelian;
    int kupon_undian = 0;
    float diskon = 0;
    switch (*choice)
    {
    case 1:
        do
        {
            // Meminta input dari pengguna
            printf("\nMasukkan total pembelian: Rp. ");
            scanf("%f", &total_pembelian);

            // Memeriksa apakah total pembelian memenuhi syarat untuk kupon undian dan diskon
            if (total_pembelian >= 100000)
            {
                // Menghitung jumlah kupon undian dan diskon
                kupon_undian = total_pembelian / 100000;
                diskon = total_pembelian * 0.1;

                // Menghitung total yang harus dibayar setelah diskon
                float total_bayar = total_pembelian - diskon;

                // Menampilkan informasi
                printf("\n--------------------------------------------------\n");
                printf("\x1b[34;47mSelamat anda mendapatkan %d kupon undian :)\x1b[0m\n\n", kupon_undian);
                printf("Total belanja            : Rp. %.2f\n", total_pembelian);
                printf("Diskon                   : Rp. %.2f\n", diskon);
                printf("Total yang harus dibayar : Rp. %.2f\n", total_bayar);
            }
            else if (total_pembelian > 0)
            {
                // Jika total pembelian tidak memenuhi syarat
                printf("\n--------------------------------------------------\n");
                printf("\x1b[31;47mAnda tidak mendapatkan kupon undian dan diskon :( \x1b[0m\n\n");
                printf("Total yang harus dibayar: Rp. %.2f\n", total_pembelian);
            }
            else
            {
                printf("\n\033[41mInput Invadlid. Masukkan nilai > 0\033[0m\n");
            }
        } while (total_pembelian <= 0);

        break;

    case 2:
        // untuk clear screen
        clearScreen();
        break;

    case 3:
        // untuk exit program
        terimakasih();
        exit(0);
        break;

    default:
        validasi_check();
    }
}

void validasi_check()
{
    printf("\n\033[41mInput Invadlid. Masukkan input 1-3\033[0m\n");
}

void terimakasih()
{
    printf("\n\033[32m----------------------------------\n");
    printf("          Terimakasih :)\n");
    printf("   Semoga harimu menyenangkan :)\n");
    printf("----------------------------------\033[0m\n");
}

void clearScreen()
{
    printf("\033[2J"); // Menggunakan ANSI escape code untuk membersihkan layar
    printf("\033[H");  // Mengatur kursor ke posisi awal (0,0)
}

