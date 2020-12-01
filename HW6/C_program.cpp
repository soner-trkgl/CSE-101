#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Author : Soner Türkoðlu
 * Tree dimensional vector and program that find its norm , sum and dot product
 *
 *
 *	
 */
int main(){
	int i, a=0, c=0, b=0, d=0, e=0, sonuc_2=0 ,sonuc_3=0;
	float sonuc=0 ,result;
	int dizi_1[20];
	int dizi_2[20];
	int dizi_3[20];
	srand(time(NULL));
	for(i=0; i<20; i++)
		dizi_1[i]=rand()%11;
	for(i=0; i<20; i++)
		dizi_2[i]=rand()%11;
	printf("Vektorler:\nv1:");
	for(i=0; i<20; i++)
		printf("%d,",dizi_1[i]);
	printf("\nv2:");
	for(i=0; i<20; i++)
		printf("%d,",dizi_2[i]);
	for(i=0; i<20; i++)
		if(dizi_1[i]>0)
			a++ ;
	printf("\n\nv1 LO norm:%d\n",a);
	for(i=0; i<20; i++)
		if(dizi_2[i]>0)
			b++ ;
	printf("v2 LO norm:%d",b);
	for(i=0; i<20; i++)
		dizi_3[i]=dizi_1[i]+dizi_2[i];
	printf("\n\nv1+v2=");
	for(i=0; i<20; i++)
		printf("%d,",dizi_3[i]);
	for(i=0; i<20; i++){
		c=dizi_1[i]*dizi_2[i];
		sonuc+=c;
	}
	for(i=0; i<20; i++){	
		d=pow(dizi_1[i],2);
		sonuc_2+=d;
		e=pow(dizi_2[i],2);
		sonuc_3+=e;
	}
	sonuc_2=sqrt(sonuc_2);
	sonuc_3=sqrt(sonuc_3);
	result=sonuc/(sonuc_2*sonuc_3);
	printf("\n\nsim:%f",result);
	
	
	
	
	
	
	
	
	return 0;
}
