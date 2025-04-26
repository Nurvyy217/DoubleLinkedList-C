#include <stdio.h>
#include "DLL.h"
#include <stdlib.h>
#include <string.h>
#include "linked.h"

void alokasiNodeKota(int jmlElemen, DLL *H)
{
    char buffer[100];
    char *cityName;
    addressKota P;
    for (int i = 0; i < jmlElemen; i++)
    {
        printf("masukkan nama kota: ");
        fgets(buffer, sizeof(buffer), stdin);
        // Hapus newline di akhir string
        buffer[strcspn(buffer, "\n")] = 0;
        cityName = strdup(buffer);
        P = Alokasi(cityName);
        if (P != NULL)
        {
            addKota(H, P);
        }
    }
}

alamat alokasiWarga(const char *namaWarga)
{
    alamat P;
    P = (alamat)malloc(sizeof(dataNama));
    if (P != NULL)
    {
        nextNama(P) = NULL;
        nama(P) = strdup(namaWarga);
        printf("alokasi warga berhasil!\n");
    }
    return (P);
}

addressKota searchKota(const char *cityName, DLL H)
{
    char buffer[100];
    start:
    addressKota current = FirstKota(H);
    while (current != NULL)
    {
        if (strcasecmp(namaKota(current), cityName) == 0)
        {
            return current;
        }
        current = nextKota(current);
    }
    printf("nama kota tidak ditemukan!\n");
    printf("masukkan nama kota: "); 
    scanf("%s", buffer);
    cityName = strdup(buffer);
    goto start;
    return Nil;
}

addressKota searchPrevKota(const char *cityName, DLL H){
    addressKota temp = FirstKota(H);

    while (nextKota(temp) != Nil)
    {
        if (strcasecmp(namaKota(nextKota(temp)), cityName) == 0)
        {
            return temp;
        }
        temp = nextKota(temp);
    }
    return Nil;    
}


void addWarga(addressKota alamatKota, alamat P)
{
    alamat current = headWarga(alamatKota);
    if (headWarga(alamatKota) == NULL)
    {
        headWarga(alamatKota) = P;
    }
    else
    {
        while (nextNama(current) != NULL)
        {
            current = nextNama(current);
        }
        nextNama(current) = P;
    }
    printf("add warga berhasil\n");
}

void delWarga(addressKota alamatKota, alamat current, alamat prev)
{
    if (prev == NULL)
    {
        // Kasus node pertama dihapus
        headWarga(alamatKota) = nextNama(current);
    }
    else
    {
        nextNama(prev) = nextNama(current);
    }
    printf("delete warga berhasil\n");
    free(current);
}

void addKota(DLL *H, addressKota P)
{
    addressKota current = FirstKota(*H);
    if (current == Nil)
    {
        FirstKota(*H) = P;
    }
    else
    {
        while (nextKota(current) != Nil)
        {
            current = nextKota(current);
        }
        nextKota(current) = P;
    }
    printf("add kota berhasil\n");
}

void delKota(DLL *H, const char *cityName, addressKota current, addressKota prev)
{
    if (headWarga(current) != NULL)
    {
        alamat Q = headWarga(current);
        while (Q != NULL)
        {
            alamat temporary = Q;
            Q = nextNama(Q);
            free(temporary);
        }
    }
    if (prev == NULL)
    {
            // Node pertama
            FirstKota(*H) = nextKota(current);
    }
    else
    {
            nextKota(prev) = nextKota(current);
    }
        free(current);
        printf("delete kota berhasil!\n");
}


void printDataWargaPerKota(addressKota alamatKota)
{
    alamat current = headWarga(alamatKota);
    printf("kota %s : \n", namaKota(alamatKota));
    if (headWarga(alamatKota) == NULL)
    {
        printf("Data nama kosong \a\n");
    }
    else
    {
        for (;;)
        {

            if (current != NULL)
            {
                printf("{%s} ", nama(current));
                current = nextNama(current);
            }
            else
            {
                break;
            }
        }
    }
}

int jmlDataNamaPerKota(addressKota alamatKota)
{
    alamat current = headWarga(alamatKota);
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = nextNama(current);
    }
    return count;
}

int jmlTotalKota(DLL H)
{
    addressKota current = FirstKota(H);
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = nextKota(current);
    }
    return count;
}

int jmlTotalNama(DLL H)
{
    addressKota current = FirstKota(H);
    int count = 0;
    while (current != NULL)
    {
        alamat Q = headWarga(current);
        while (Q != NULL)
        {
            count++;
            Q = nextNama(Q);
        }
        current = nextKota(current);
    }
    return count;
}

void printDataKota(DLL H)
{
    addressKota current = FirstKota(H);
    if (current == NULL)
    {
        printf("data kota kosong");
    }
    else
    {
        while (current != NULL)
        {
            printf("{%s} ", namaKota(current));
            current = nextKota(current);
        }
    }
}