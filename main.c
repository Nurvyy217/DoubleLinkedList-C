#include <stdio.h>
#include "DLL.h"
#include <string.h>
#include <stdlib.h>
#include "linked.h"

int main()
{
    DLL H;
    int choice, jmlNodeKota;
    char *cityName;
    char *peopleName;
    addressKota alamatKota;
    char buffer[100];

    CreateList(&H);
start:
    printf("Masukkan jumlah elemen array (minimal 5): ");
    scanf("%d", &jmlNodeKota);
    getchar();
    if (jmlNodeKota < 5)
    {
        printf("jumlah elemen array minimal 5\n");
        goto start;
    }
    else
    {
        alokasiNodeKota(jmlNodeKota, &H);
        do
        {
            printf("\n\n ------MENU UTAMA------- \n");
            printf("1. Tambahkan data warga \n");
            printf("2. Delete warga \n");
            printf("3. Hapus kota \n");
            printf("4. Tambah kota \n");
            printf("5. Print data nama per kota \n");
            printf("6. Print data kota \n");
            printf("7. Print jumlah total kota \n");
            printf("8. Print jumlah total data nama \n");
            printf("9. Print jumlah total warga untuk suatu kota \n");
            printf("10. Keluar program \n");
            printf("Pilihan: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("masukkan nama kota yang ingin diisi data warga: ");
                scanf("%s", buffer);
                cityName = strdup(buffer);
                alamatKota = searchKota(cityName, H);
                printf("masukkan nama warga yang akan ditambahkan: ");
                scanf("%s", buffer);
                peopleName = strdup(buffer);
                alamat warga = alokasiWarga(peopleName);
                addWarga(alamatKota, warga);
                break;
            case 2:
                printf("masukkan nama kota yang data warganya akan di delete: ");
                scanf("%s", buffer);
                cityName = strdup(buffer);
                alamatKota = searchKota(cityName, H);
                printf("masukkan nama warga yang akan di delete: ");
                scanf("%s", buffer);
                peopleName = strdup(buffer);
                alamat current = Search(alamatKota, peopleName);
                alamat prev = SearchPrec(peopleName, alamatKota);
                if (current == NULL)
                {
                    printf("Warga dengan nama '%s' tidak ditemukan!\n", peopleName);
                }
                else
                {
                    delWarga(alamatKota, current, prev);
                    printf("Warga berhasil dihapus!\n");
                }
                break;
            case 3:
                printf("masukkan nama kota yang akan di delete: ");
                scanf("%s", buffer);
                cityName = strdup(buffer);
                addressKota curr = searchKota(cityName, H);
                addressKota prec = searchPrevKota(cityName, H);
                delKota(&H, cityName, curr, prec);
                break;
            case 4:
                printf("masukkan nama kota yang akan di ditambahkan: ");
                scanf("%s", buffer);
                cityName = strdup(buffer);
                addressKota P = Alokasi(cityName);
                addKota(&H, P);
                break;
            case 5:
                printf("masukkan nama kota yang akan dilihat data warganya: ");
                scanf("%s", cityName);
                alamatKota = searchKota(cityName, H);
                printDataWargaPerKota(alamatKota);
                break;
            case 6:
                printDataKota(H);
                break;
            case 7:
                int totalKota = jmlTotalKota(H);
                printf("jumlah total kota adalah: %d\n", totalKota);
                break;
            case 8:
                int totalWarga = jmlTotalNama(H);
                printf("jumlah total data nama warga: %d\n", totalWarga);
                break;
            case 9:
                printf("masukkan nama kota yang akan dilihat total warga nya: ");
                scanf("%s", buffer);
                cityName = strdup(buffer);
                alamatKota = searchKota(cityName, H);
                int totWarga = jmlDataNamaPerKota(alamatKota);
                printf("jumlah total warga di kota %s adalah: %d\n", cityName, totWarga);
                break;
            case 10:
                printf("program selesai\n");
                break;
            default:
                printf("pilihan tidak valid!\n");
                break;
            }
        } while (choice != 10);
    }
    return 0;
}