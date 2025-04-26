#ifndef ARRAYSLL_H
#define ARRAYSLL_H

#define nama(P) (P)->nama
#define nextNama(P) (P)->nextNama
#define headWarga(P) (P)-> headWarga
#define namaKota(P) (P)-> kota
#define nextKota(P) (P)->nextKota
#define FirstKota(P) (P).FirstKota

typedef struct dataNama *alamat;
typedef struct dataKota *addressKota;
typedef struct dataNama
{
    char *nama;
    alamat nextNama;
} dataNama;


typedef struct dataKota
{
    char *kota;
    alamat headWarga;
    addressKota nextKota;
} dataKota;

typedef struct DLL {
    addressKota FirstKota;
} DLL;

void alokasiNodeKota(int jmlElemen, DLL *H);
void printDataKota(DLL H);
int jmlTotalNama(DLL H);
int jmlTotalKota(DLL H);
int jmlDataNamaPerKota(addressKota alamatKota);
void printDataWargaPerKota(addressKota alamatKota);
void delKota(DLL *H, const char *cityName,addressKota current, addressKota prev);
void addKota(DLL *H, addressKota P);
void delWarga(addressKota alamatKota, alamat current, alamat prev);
void addWarga(addressKota alamatKota, alamat P);
addressKota searchKota(const char *namaKota, DLL H);
int jmlTotalNama(DLL H);
alamat alokasiWarga(const char *namaWarga);
addressKota searchPrevKota(const char *cityName, DLL H);
#endif