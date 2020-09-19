
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
 linked list: herhangi bir tipten düğümün yine kendi tipindeki düğümü işaret etmesiyle oluşturulan zincire verilen addır.
 Buna göre her düğümde kendi tipinden bir pointer olacak ve bu pointer bir sonraki düğümü işaret edecektir
 avantajı: hafızayı dinamik olarak kullanmasıdır. Eklenen bilgi kadar alan açılır ve silinen bilgi için o alan boşaltılır
 
 -TÜRLERİ
 tek yönlü bağlı liste; her düğüm bir sonraki düğümü işaret eder geri dönüş yoktur
 çift yönlü bağlı liste; her düğüm bir önceki ve bir sonraki düğümü işaret eder.
 dairesel bağlı liste; her düğüm bir sonrakini işaret eder. Sondan sonra ilk düğüm gelir
 
 Bağlı liste tanımlanırken liste üzerinde bir iterator(dolaşıcı) gösterici tanımlanır. Bu dolaşıcı veri aranması, ekleme veya silme gibi işlemlerde listenin ilgili elemanına kadar gidilmesini sağlar.
 */



/*TEK YÖNLÜ BAĞLI LİSTE İŞLEMLERİ*/

struct dugum{
    int veri;
    struct dugum *sonraki; //sonraki dugumu işaret eder
};

struct dugum *ilk=NULL;
struct dugum *gecici;

struct dugum* dugum_olustur(){
    struct dugum *yeni_dugum=(struct dugum *)malloc(sizeof(struct dugum));
    return yeni_dugum;
}

void sona_ekle(int eklenecek_veri){
    struct dugum *yeni_alan = dugum_olustur();
    yeni_alan->veri=eklenecek_veri;
    yeni_alan->sonraki=NULL;
    if(ilk==NULL){
        ilk = yeni_alan;
    }
    else{
        gecici=ilk;
        while(gecici->sonraki!=NULL){
            gecici = gecici->sonraki;
        }
        gecici->sonraki=yeni_alan;
    }
}

void basa_ekle(int eklenecek_veri){
    struct dugum *yeni_alan=dugum_olustur();
    yeni_alan->veri=eklenecek_veri;
    if(ilk==NULL){
        yeni_alan->sonraki=NULL;
        ilk=yeni_alan;
    }
    else{
        gecici=ilk;
        ilk=yeni_alan;
        ilk->sonraki=gecici;
    }
}

void araya_ekle(int eklenecek_veri, int eklenecek_index){
    struct dugum *yeni_dugum=dugum_olustur();
    yeni_dugum->veri=eklenecek_veri;
    int bir_onceki=0;
    if(eklenecek_index==0)
    {
        basa_ekle(eklenecek_veri);
    }
    else{
        gecici=ilk;
        while(gecici!=NULL)
        {
            if(bir_onceki+1==eklenecek_index)
            {
                break;
            }
            gecici=gecici->sonraki;
            bir_onceki++;
        }
        struct dugum *bir_sonraki = (struct dugum *)malloc(sizeof(struct dugum));
        bir_sonraki=gecici->sonraki;
        gecici->sonraki=yeni_dugum;
        yeni_dugum->sonraki=bir_sonraki;
    }
}

void sondan_sil(){
    if(ilk==NULL)
    {
        printf("Liste Bos!\n");
    }
    else{
        gecici=ilk;
        struct dugum *gecici_alan=(struct dugum *)malloc(sizeof(struct dugum));
        while (gecici->sonraki!=NULL) {
            gecici_alan=gecici;
            gecici=gecici->sonraki;
        }
        free(gecici);
        gecici_alan->sonraki=NULL;
    }
        
}

void bastan_sil(){
    if(ilk==NULL){
        printf("Liste Bos!\n");
    }
    else{
        if(ilk->sonraki != NULL){
            gecici=ilk;
            ilk=ilk->sonraki;
            free(gecici);
        }
        else{
            free(ilk);
            ilk=NULL;
        }
    }
}

void aradan_sil(int silinecek_index){
    if(ilk==NULL){
        printf("Listede Bos!\n");
    }
    else{
        if (silinecek_index==0) {
            bastan_sil();
        }
        else{
            struct dugum *silinecek_dugum = (struct dugum *)malloc(sizeof(struct dugum));
            gecici=ilk;
            int aranan=0;
            while(gecici!=NULL)
            {
                if(aranan==silinecek_index-1){
                    silinecek_dugum=gecici->sonraki;
                    break;
                }
                gecici=gecici->sonraki;
                aranan++;
            }
            gecici->sonraki=gecici->sonraki->sonraki;
            free(silinecek_dugum);
        }
    }
}

void ara(int aranan_eleman){
    if(ilk==NULL){
        printf("Liste Bos!\n");
    }
    else{
        gecici=ilk;
        int kontrol = 0;
        while(gecici != NULL){
            if(gecici->veri == aranan_eleman)
            {
                printf("Eleman Listede Mevcut!\n");
                kontrol = 1;
                break;
            }
            else{
                gecici=gecici->sonraki;
            }
        }
        if(kontrol == 0)
        {
            printf("Eleman Listede Mevcut Değil!\n");
        }
    }
}

void goster(){
    gecici=ilk;
    if(ilk == NULL){
        printf("Liste Bos!\n");
    }
    else{
        while(gecici != NULL)
        {
            printf("%d\n",gecici->veri);
            gecici = gecici->sonraki;
        }
    }
}
int main(int argc, const char * argv[]) {
  
    //goster();
    basa_ekle(5);
    basa_ekle(10);
    araya_ekle(7, 1);
    sona_ekle(13);
    basa_ekle(3);
    sona_ekle(15);
    //goster();
    sondan_sil();
    //goster();
    bastan_sil();
    //goster();
    aradan_sil(2);
    //goster();
    ara(10);
    //goster();
    
    return 0;
}
