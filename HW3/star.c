#include<stdio.h>
/* Author : Soner Türkoðlu
 * star sketching program
 *
 */
void menu_fonk () 
{
	
	int secenek, sayi, s, k, yildiz, bosluk, giris;
	printf("\t\t\t----MENU---- \n");
	printf("\t\t1. Yildizlardan elmas ciz\n");
	printf("\t\t2.Ogrenci bilgisini goster\n");
	printf("\t\t0.Cikis\n");
	printf("\t\tSeceneginiz:\n");
	scanf("%d",&secenek);
	
	if (secenek==1){
		printf("Lutfen sayi giriniz:\n");
		scanf("%d",&giris);
		sayi = (giris + 1) / 2 ;
		yildiz = 1 ;
		bosluk = sayi-1 ;
		for(k=0; k<sayi; k++){
			for(s=0; s<bosluk; s++){
				printf(" ");
			}
			for(s=0; s<yildiz; s++){
				printf("*");
			}
			printf("\n");
			bosluk--;
			yildiz += 2;
		}
		
		yildiz -= 4 ;
		bosluk = 1 ;
		
		for(k=0; k<sayi - 1; k++){
			for(s=0; s<bosluk; s++){
				printf(" ");
			}
			for(s=0; s<yildiz; s++){
				printf("*");
			}
			printf("\n");
			bosluk++;
			yildiz -= 2;

		}
		menu_fonk ( ) ;
	}
	else if(secenek==2){
			printf("Ad:Soner\n");
			printf("Soyad:Turkoglu\n");
			printf("Ogrenci No:161044013\n\n\n\n");
			menu_fonk ( ) ;
			
		}
		
}
int main(void)
{   
	int secenek, sayi, s, k, yildiz, bosluk, giris;
	printf("\t\t\t----MENU---- \n");
	printf("\t\t1. Yildizlardan elmas ciz\n");
	printf("\t\t2.Ogrenci bilgisini goster\n");
	printf("\t\t0.Cikis\n");
	printf("\t\tSeceneginiz:\n");
	scanf("%d",&secenek);
	
	if (secenek==1){
		printf("Lutfen sayi giriniz:\n");
		scanf("%d",&giris);
		sayi = (giris + 1) / 2 ;
		yildiz = 1 ;
		bosluk = sayi-1 ;
		for(k=0; k<sayi; k++){
			for(s=0; s<bosluk; s++){
				printf(" ");
			}
			for(s=0; s<yildiz; s++){
				printf("*");
			}
			printf("\n");
			bosluk--;
			yildiz += 2;
		}
		
		yildiz -= 4 ;
		bosluk = 1 ;
		
		for(k=0; k<sayi - 1; k++){
			for(s=0; s<bosluk; s++){
				printf(" ");
			}
			for(s=0; s<yildiz; s++){
				printf("*");
			}
			printf("\n");
			bosluk++;
			yildiz -= 2;

		}
			menu_fonk ( ) ;
	}
	else if(secenek==2){
			printf("Ad:Soner\n");
			printf("Soyad:Turkoglu\n");
			printf("Ogrenci No:161044013\n\n\n\n");
			menu_fonk ( ) ;
		}
		else if(secenek=3){
			return 0 ;
		}
	
	
	
		
		
	
	return 0;
	
}
