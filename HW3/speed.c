#include<stdio.h>
int main()
/* Author : Soner T�rko�lu
 * Current speed and target speed comparision program
 *
 *
 */
{
	int guncel_hiz , hedef_hiz ;                    /*guncel_hiz ve hedef_hiz ad�nda iki de�i�ken tan�mlad�m.*/
	printf("Lutfen guncel hizi girin:\n");          /*"Lutfen guncel hizi girin" yaz�s�n� ekrana bast�rd�m*/
	scanf("%d", &guncel_hiz);                       /*girilen guncel_hiz de�erini ald�m.*/
	printf("Lutfen hedef hizi girin:\n");           /*"Lutfen hedef hizi girin" yaz�s�n� ekrana bast�rd�m*/
	scanf("%d", &hedef_hiz);                        /*girilen hedef_hiz de�erini ald�m*/
	printf("%d %d\n",guncel_hiz ,hedef_hiz);        /*al�nan gucel_hiz ve hedef_hiz de�erlerini ekrana bast�rd�m*/
	
	while(guncel_hiz<=hedef_hiz)                    /*while d�g�s�yle guncel_hiz de�erinin hedef_hiz de�erine e�it oluncaya  kadar +1 artt�rarak ekrana yazd�rd�m*/ 
		printf("%d\n",guncel_hiz++);
	
	if (guncel_hiz>hedef_hiz);                      /*if yap�s�yla guncel_hiz de�eri hedef_hiz de�erinden b�y�k olmas� takdirde ekrana "Hiziniz hedef hizdan yuksektir" yaz�s�n� yazd�rd�m*/
		printf("\nHiziniz hedef hizdan yuksektir");
	return 0 ;
	
	
}
