#include<stdio.h>
int main()
/* Author : Soner Türkoðlu
 * Current speed and target speed comparision program
 *
 *
 */
{
	int guncel_hiz , hedef_hiz ;                    /*guncel_hiz ve hedef_hiz adýnda iki deðiþken tanýmladým.*/
	printf("Lutfen guncel hizi girin:\n");          /*"Lutfen guncel hizi girin" yazýsýný ekrana bastýrdým*/
	scanf("%d", &guncel_hiz);                       /*girilen guncel_hiz deðerini aldým.*/
	printf("Lutfen hedef hizi girin:\n");           /*"Lutfen hedef hizi girin" yazýsýný ekrana bastýrdým*/
	scanf("%d", &hedef_hiz);                        /*girilen hedef_hiz deðerini aldým*/
	printf("%d %d\n",guncel_hiz ,hedef_hiz);        /*alýnan gucel_hiz ve hedef_hiz deðerlerini ekrana bastýrdým*/
	
	while(guncel_hiz<=hedef_hiz)                    /*while dögüsüyle guncel_hiz deðerinin hedef_hiz deðerine eþit oluncaya  kadar +1 arttýrarak ekrana yazdýrdým*/ 
		printf("%d\n",guncel_hiz++);
	
	if (guncel_hiz>hedef_hiz);                      /*if yapýsýyla guncel_hiz deðeri hedef_hiz deðerinden büyük olmasý takdirde ekrana "Hiziniz hedef hizdan yuksektir" yazýsýný yazdýrdým*/
		printf("\nHiziniz hedef hizdan yuksektir");
	return 0 ;
	
	
}
