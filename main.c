#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int menuSecme,musteriSayac=0,urunSayac=0,mevcutUrun,calisma=-1,satisSayac=0,calismaSatis=-1,goruntulemeSayac=0, toplamGelir=0;

void baslangic(){
   char superMarket="IZBU";
   char magazalar[15][20]={"IZMIR IZBU","ISTANBUL IZBU","ANKARA IZBU","BERLIN IZBU","HAMBURG IZBU","MUNIH IZBU","OTTAWA IZBU","TORONTO IZBU","MOTREAL IZBU",
   "TOKYO IZBU","DELHI IZBU","SANGHAY IZBU","SEUL IZBU","BUSAN IZBU","INCHEON IZBU"};
   char kitalar[3][10]={"ASYA","AVRUPA","KUZEY AMERÝKA"};
   char ulkeler[5][10]={"Turkiye","Almanya","Kanada","Cin","Kore"};
   char sehirler[15][20]={"Izmir","Istanbul","Ankara","Berlin","Hamburg","Munih","Ottawa","Toronto","Motreal","Tokyo","Delhi","Sanghay","Seul","Busan","Incheon"};
   char urunTurleri[5][20]={"Giyim","Elektronik","Mobilya","Temizlik","Gida"};
   char calisanlar[15][40]={"Ali Tas","Dincer Kaan Turanli","Ege Bayrak","Deniz Kilinc","Orhan Er","Pelin Yildirim Taser","Fatma Bozyigit","Cem Kosemen","Cevhernur Soylemez",
   "Arda Bilgin","Melih Kara","Mehmet Koc","Berkay Kahveci","Ozge Nur Aslan","Esra Kozlu"};
}
struct musteri {
char baslangicBilgi[20][40];
char musteriAd[100][20];
char musteriSoyad[100][20];
char musteriMail[100][40];
int musteriID[100];
char musteriTelefon[100][40];
}musteri1={"Can","Kaya","cankaya@gmail.com","05537458653"},musteri2={"Nur","Ak","nurak@bakircay.edu.tr","05547965428"},yeni[100];

struct urun{
char baslagicUrun[20][40];
int urunID[100];
char urunAd[100][40];
char urunKategori[100][40];
char urunMense[100][40];
int urunMiktar[100];
int urunFiyat[100];
}urun1={"Pasta","Yiyecek","TR"},urun2={"TV","Elektronik","PRC"},yeniUrun[100];

struct satis{
int satisUrunID[100];
int satisMusteriID[100];
int satisGun[100];
int satisAy[100];
int satisYil[100];
int satisTarih[100];
int satisAdet[100];
int satisFiyat[100];
char satisUrunAd[100][40];
char satisKategori[100][40];
}yeniSatis[100];

struct toplamSatis{
int toplamSatisGun[40];
int toplamSatisAy[40];
int toplamSatisYil[40];
}satisGoruntuleme[100];

void musteriEkleme(){
    printf("\nMusterinin adini giriniz:");
    scanf("%s",&yeni[musteriSayac].musteriAd[musteriSayac]);
    printf("Musterinin soyadini giriniz:");
    scanf("%s",&yeni[musteriSayac].musteriSoyad[musteriSayac]);
    printf("Musterinin e-posta adresini giriniz:");
    scanf("%s",&yeni[musteriSayac].musteriMail[musteriSayac]);
    printf("Musterinin telefon numarasini giriniz:");
    scanf("%s",&yeni[musteriSayac].musteriTelefon[musteriSayac]);
    yeni[musteriSayac].musteriID[musteriSayac]=musteriSayac+3;
}

void musteriListeleme(){
    int i=0;
    int dongu=0;
    musteri1.musteriID[0]=1;
    musteri2.musteriID[0]=2;

    printf("\nID \tAd/Soyad \t\tE-posta \t Telefon Numarasi");
    printf("\n____ \t________ \t____________________ \t _________________");
    printf("\n%d \t%s %s \t%s \t%s",musteri1.musteriID[0],musteri1.baslangicBilgi[0],musteri1.baslangicBilgi[1],musteri1.baslangicBilgi[2],musteri1.baslangicBilgi[3]);
    printf("\n%d \t%s %s  \t%s \t%s",musteri2.musteriID[0],musteri2.baslangicBilgi[0],musteri2.baslangicBilgi[1],musteri2.baslangicBilgi[2],musteri2.baslangicBilgi[3]);

    for(i;i<=musteriSayac;i++){
        printf("\n%d \t%s %s \t%s \t%s",yeni[dongu].musteriID[dongu],yeni[dongu].musteriAd[dongu],yeni[dongu].musteriSoyad[dongu],yeni[dongu].musteriMail[dongu],yeni[dongu].musteriTelefon[dongu]);
        dongu+=1;
    }
}
void urunEkleme(){
    int mevcutUrun=0;
    int gezici=0;
    int c=0;
    int kontrol=0;
    int idTest;
    int a=0;
    int sira=0;


    printf("\nUrunun ID'sini giriniz (orn:1,48):");
    scanf("%d",&idTest);

    if(idTest==1){
       printf("Urun miktarini giriniz:");
       scanf("%d",&mevcutUrun);
       urun1.urunMiktar[0]=urun1.urunMiktar[0]+mevcutUrun;
       kontrol=1;
    }

    if(idTest==2){
       printf("Urun miktarini giriniz:");
       scanf("%d",&mevcutUrun);
       urun2.urunMiktar[1]=urun2.urunMiktar[1]+mevcutUrun;
       kontrol=1;
    }

    for(c;c<=urunSayac;c++){
        if(idTest==yeniUrun[gezici].urunID[gezici+2]){
            printf("Urun miktarini giriniz:");
            scanf("%d",&mevcutUrun);
            yeniUrun[gezici].urunMiktar[gezici+2]=yeniUrun[gezici].urunMiktar[gezici+2]+mevcutUrun;
            kontrol=1;
        }
        gezici+=1;
    }

    if(kontrol==0){
        yeniUrun[urunSayac].urunID[urunSayac+2]=idTest;
        printf("Urunun adini giriniz:");
        scanf("%s",&yeniUrun[urunSayac].urunAd[urunSayac]);
        printf("Urunun kategorisini giriniz (orn:Giyim,Elektronik):");
        scanf("%s",&yeniUrun[urunSayac].urunKategori[urunSayac]);
        printf("Urunun mensesini giriniz (orn:TR,PRC):");
        scanf("%s",&yeniUrun[urunSayac].urunMense[urunSayac]);
        printf("Urunun miktarini giriniz:");
        scanf("%d",&yeniUrun[urunSayac].urunMiktar[urunSayac+2]);
        printf("Urun fiyatini giriniz:");
        scanf("%d",&yeniUrun[urunSayac].urunFiyat[urunSayac+2]);
        urunSayac+=1;
        calisma+=1;
    }

    printf("\nID \tAd \t\tKategori \tAdet \tFiyat \tMense");
    printf("\n____ \t________ \t___________ \t____ \t______ \t____");
    printf("\nURN%d \t%s \t\t%s \t%d \t%d \t%s",urun1.urunID[0],urun1.baslagicUrun[0],urun1.baslagicUrun[1],urun1.urunMiktar[0],urun1.urunFiyat[0],urun1.baslagicUrun[2]);
    printf("\nURN%d \t%s \t\t%s \t%d \t%d \t%s",urun2.urunID[1],urun2.baslagicUrun[0],urun2.baslagicUrun[1],urun2.urunMiktar[1],urun2.urunFiyat[1],urun2.baslagicUrun[2]);

    for(a;a<=calisma;a++){
        printf("\nURN%d \t%s \t\t%s \t%d \t%d \t%s",yeniUrun[sira].urunID[sira+2],yeniUrun[sira].urunAd[sira],
               yeniUrun[sira].urunKategori[sira],yeniUrun[sira].urunMiktar[sira+2],yeniUrun[sira].urunFiyat[sira+2],yeniUrun[sira].urunMense[sira]);
            sira+=1;
    }
}


void satis(){
    int d=0;
    int e=0;
    int kontrol=0;
    printf("Satilacak urunun ID'sini giriniz (orn:1,40):");
    scanf("%d",&yeniSatis[satisSayac].satisUrunID[satisSayac]);
    printf("Satin alacak musteri ID'sini giriniz:");
    scanf("%d",&yeniSatis[satisSayac].satisMusteriID[satisSayac]);
    printf("Satisin yapildigi gun (orn:2,24):");
    scanf("%d",&yeniSatis[satisSayac].satisGun[satisSayac]);
    printf("Satisin yapildigi ay(orn:2,12):");
    scanf("%d",&yeniSatis[satisSayac].satisAy[satisSayac]);
    printf("Satisin yapildigi yil(orn:2000,2021):");
    scanf("%d",&yeniSatis[satisSayac].satisYil[satisSayac]);
    printf("Kac adet urun satildi:");
    scanf("%d",&yeniSatis[satisSayac].satisAdet[satisSayac]);

    if(yeniSatis[satisSayac].satisUrunID[satisSayac]==1){
        strcpy(yeniSatis[satisSayac].satisUrunAd[satisSayac],"Pasta");
        strcpy(yeniSatis[satisSayac].satisKategori[satisSayac],"Yiyecek");
        yeniSatis[satisSayac].satisFiyat[satisSayac]=20;
        urun1.urunMiktar[0]=urun1.urunMiktar[0]-yeniSatis[satisSayac].satisAdet[satisSayac];
    }
    if(yeniSatis[satisSayac].satisUrunID[satisSayac]==2){
        strcpy(yeniSatis[satisSayac].satisUrunAd[satisSayac],"TV");
        strcpy(yeniSatis[satisSayac].satisKategori[satisSayac],"Elektronik");
        yeniSatis[satisSayac].satisFiyat[satisSayac]=1400;
        urun2.urunMiktar[1]=urun2.urunMiktar[1]-yeniSatis[satisSayac].satisAdet[satisSayac];
    }

    for(d;d<=calisma;d++){
        if(yeniSatis[satisSayac].satisUrunID[satisSayac]==yeniUrun[kontrol].urunID[kontrol+2]){
            strcpy(yeniSatis[satisSayac].satisUrunAd[satisSayac],yeniUrun[kontrol].urunAd[kontrol]);
            strcpy(yeniSatis[satisSayac].satisKategori[satisSayac],yeniUrun[kontrol].urunKategori[kontrol]);
            yeniSatis[satisSayac].satisFiyat[satisSayac]=yeniUrun[kontrol].urunFiyat[kontrol+2];
            yeniUrun[kontrol].urunMiktar[kontrol+2]= yeniUrun[kontrol].urunMiktar[kontrol+2]-yeniSatis[satisSayac].satisAdet[satisSayac];
        }
        kontrol+=1;
    }

    if(yeniUrun[kontrol].urunMiktar[kontrol+2]<10){
        printf("\nUYARI: URN%d ID'li urunun stogu 10'un altina dusmustur!",yeniSatis[satisSayac].satisUrunID[satisSayac]);
    }
    printf("\n\nSatis Listesi");
    printf("\nID \tUrun Ad \t Musteri ID \t   Tarih \t Adet \t\t Fiyat");
    printf("\n______ \t_________ \t__________ \t____________ \t_______  \t_______ ");
    printf("\nURN%d \t   %s \t\t   %d  \t\t%d.%d.%d \t  %d \t\t %d",yeniSatis[satisSayac].satisUrunID[satisSayac],yeniSatis[satisSayac].satisUrunAd[satisSayac],yeniSatis[satisSayac].satisMusteriID[satisSayac],
        yeniSatis[satisSayac].satisGun[satisSayac],yeniSatis[satisSayac].satisAy[satisSayac], yeniSatis[satisSayac].satisYil[satisSayac],
        yeniSatis[satisSayac].satisAdet[satisSayac],yeniSatis[satisSayac].satisFiyat[satisSayac]);
}

void toplamSatis(){
    int f=0;
    int g=0;
    int araToplam[40];
    printf("\nToplam satislari goruntulemek istediginiz tarihin gununu giriniz:");
    scanf("%d",&satisGoruntuleme[goruntulemeSayac].toplamSatisGun[goruntulemeSayac]);
    printf("Toplam satislari goruntulemek istediginiz tarihin ayini giriniz:");
    scanf("%d",&satisGoruntuleme[goruntulemeSayac].toplamSatisAy[goruntulemeSayac]);
    printf("Toplam satislari goruntulemek istediginiz tarihin yilini giriniz:");
    scanf("%d",&satisGoruntuleme[goruntulemeSayac].toplamSatisYil[goruntulemeSayac]);
    printf("Toplam Satis Listesi");
    printf("\nID \t Musteri ID \t Tarih \t\t Adet \t\t  Fiyat");
    printf("\n______ \t___________\t__________ \t_______ \t_________ ");

    for(f;f<=satisSayac;f++){
         if(satisGoruntuleme[goruntulemeSayac].toplamSatisGun[goruntulemeSayac]==yeniSatis[f].satisGun[f] &&
            satisGoruntuleme[goruntulemeSayac].toplamSatisAy[goruntulemeSayac]==yeniSatis[f].satisAy[f] &&
            satisGoruntuleme[goruntulemeSayac].toplamSatisYil[goruntulemeSayac]==yeniSatis[f].satisYil[f]){
            printf("\nURN%d \t     %d \t\t%d.%d.%d \t   %d \t          %d",yeniSatis[f].satisUrunID[f],yeniSatis[f].satisMusteriID[f],
        yeniSatis[f].satisGun[f],yeniSatis[f].satisAy[f], yeniSatis[f].satisYil[f],yeniSatis[f].satisAdet[f],yeniSatis[f].satisFiyat[f]);
        toplamGelir=toplamGelir+(yeniSatis[f].satisAdet[f]*yeniSatis[f].satisFiyat[f]);
       }
    }
    printf("\n\nBu tarihteki toplam satis: %d TL",toplamGelir);
    toplamGelir=0;
}

void menu(){
  printf("\n\t\tMENU");
  printf("\n1-Musteri Ekleme ve Listeleme");
  printf("\n2-Urun Ekleme ve Listeleme");
  printf("\n3-Satis");
  printf("\n4-Toplam Satislari Goruntuleme");
  printf("\n****Yapmak istediginiz islemi seciniz:");
  scanf("%d",&menuSecme);
  switch(menuSecme){
    case 1:
    musteriEkleme();
    musteriListeleme();
    musteriSayac+=1;
      break;
    case 2:
      urunEkleme();
      break;
    case 3:
        satis();
        satisSayac+=1;
        break;
    case 4:
        toplamSatis();
        goruntulemeSayac+=1;
        break;
    default  :
      printf("Lutfen gecerli bir deger giriniz!");
    }
    printf("\n\nAna menuye donmek icin '0' giriniz.");
    scanf("%d",&menuSecme);
    while(menuSecme == 0){
        menu();
    }
}

int main()
{
    urun1.urunID[0]=1;
    urun2.urunID[1]=2;
    urun1.urunMiktar[0]=10;
    urun2.urunMiktar[1]=8;
    urun1.urunFiyat[0]=20;
    urun2.urunFiyat[1]=1400;

    menu();

    return 0;
}


