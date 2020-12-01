#include<stdio.h>

/* Author : Soner Türkoðlu
 * Friendly Pair Number Finder Program
 * 
 * Friendly Pair Number is that one number's sum of position divisors equals other numbers and vice versa
 *
 */


int fonk(int top1,int sayi){
	int i ; 
	for(i=1; i<sayi; i++){
		if (sayi%i == 0){
			top1=top1+i ;
		}
	}
	sayi=top1;
	return(0+sayi);
}

	

	

int main(){
	int sayi, top1,top2,top3 ;
	printf("Lutfen arkadasini bulmak istedigin sayiyi gir:");
	scanf("%d",&sayi);
	fonk(0,sayi);
	top2=fonk(0,sayi);
	fonk(0,top2);
	top3=fonk(0,top2);
	if (top3==sayi){
		printf("%d nin arkadas sayisi:%d",sayi,top2);
	}
	else printf("%d sayisinin arkadas sayisi bulunmamaktadir.",sayi);
	
		
	
	return 0;
}
