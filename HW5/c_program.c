#include<stdio.h>
#define PI 3.14159265359

/*	Author : Soner Türkoðlu
 *	c program to calculate the sinus of an angle using the Taylor expansion of the sinus
 *	
 *
 *
 */


long factorial (int m){
	int i ;
	long f=1 ;
	for(i=1; i<=m; i++)
		f=f*i ;
	return(f);
}
double pow (double x ,int n){
	int j ;
	double p=1 ;
	for(j=1; j<=n; j++)
		p=p*x ;
	return(p);
}
double sin_fonk(double a , int b ){
	double sonuc=0;
	int k;
	for(k=0; k<b; k++)
		sonuc += pow(-1,k) * pow(a,2*k+1) / factorial(2*k+1);
	return (sonuc);
	
}
int main()
{
	double a , derece  ;
	int b ;
	printf("Lutfen bir derece ve bir hassaslik giriniz:\n");
	scanf("%lf %d",&derece,&b);
	a=(derece*PI/180) ;
	sin_fonk(a,b);
	printf("\nsin%lf esittir %lf dir.",derece,sin_fonk(a,b));
	
	return 0 ;
}


