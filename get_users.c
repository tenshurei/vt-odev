#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToLower(char *str) { // https://www.tutorialspoint.com/c_standard_library/c_function_tolower.htm
   while (*str) {
      *str = tolower(*str);
      str++;
   }
}

int main() 
{
    int 
        id, 
        secim,
        sayi = 0;

    bool 
        bulundu = false,
        zatenGonderildi = false;

    char 
        isim[24], 
        soyisim[24], 
        tel[10 + 2], 
        adres[18],
        aranan[24];

    FILE *dosya;

    printf("\n--- ARAMA MENUSU ---\n\n");
    printf("1 - Isme Gore Ara\n");
    printf("2 - Soyisme Gore Ara\n");
    printf("3 - Sehire Gore Ara\n\n");
    printf("---------------------\n\n");

    printf("Lutfen bir secim yapiniz. (1-3)\n\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);

    printf("\nSeciminize gore sorgulayacaginiz degeri girin: ");
    scanf("%s", aranan);

    convertToLower(aranan);

    dosya = fopen("kullanicilar.txt", "r");

    if(dosya == NULL)
    {
        printf("Dosya bulunamadi.\n");
        return 0;
    }

    while(fscanf(dosya, "%d, %[^,], %[^,], %[^,], %[^\n]", &id, isim, soyisim, tel, adres) == 5)
    {   
        bool 
            eslesme = false;

        char
            orijinalIsim[24],
            orijinalSoyisim[24],
            orijinalAdres[18];

        strcpy(orijinalIsim, isim);
        strcpy(orijinalSoyisim, soyisim);
        strcpy(orijinalAdres, adres);

        convertToLower(isim);
        convertToLower(soyisim);
        convertToLower(adres);

        if(secim == 1 && strcmp(isim, aranan) == 0) 
            eslesme = true;
        else if(secim == 2 && strcmp(soyisim, aranan) == 0) 
            eslesme = true;
        else if(secim == 3 && strcmp(adres, aranan) == 0) 
            eslesme = true;

        if(eslesme == true)
        {
            if(zatenGonderildi == false)
                printf("\n------------------- Kisi(ler) Bulundu --------------------\n\n");

            printf("#%d - Ad Soyad: %s %s - Tel: %s - Adres: %s\n", id, orijinalIsim, orijinalSoyisim, tel, orijinalAdres);

            bulundu = true;
            zatenGonderildi = true;
            sayi++;
        }
    }

    if(bulundu == false) 
        printf("\nAranan kriterde kimse bulunamadi.\n");
    else
        printf("\n----------------- Bulunan Kisi Sayisi: %d -----------------\n", sayi);
        

    fclose(dosya);
    
    printf("\n------------------ Gelistirici Ekip :D -------------------\n\n");
    printf("- Ibrahim Tas - Adnan Peker - Lutfi Uluad - Zekeriya Han -\n");
    printf("\n----------------------------------------------------------\n");

    getchar();
    getchar();
    return 0;
}