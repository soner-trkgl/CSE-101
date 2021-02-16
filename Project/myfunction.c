#include <stdio.h>
#include <stdlib.h>
#include "myfunction.h"

char* int_to_char(int num){

	int temp = num;
	int digit = 0 ,index = 0; 
	while(temp != 0){
		digit++;
		temp/=10;
	}

	char* arr = (char*)calloc(digit + 1,sizeof(char));
	char arr_temp[digit];

	temp=num;
	while(temp != 0){
		arr_temp[index] = temp % 10 + '0';
		temp /= 10;
		index++;
	}
	index = 0;
	while(index < digit){
		arr[index] = arr_temp[digit - 1 - index];
		index++;
	}
	arr[digit] = '\0';
	return arr;
}




int char_to_int(char* char_array){

	int element_num = 0 , result = 0 , index1 = 0 , index2 = 0 , weight_of_step = 1;
	

	while(char_array[element_num] != '\0'){
		element_num++;
	}

	while(char_array[index1] != '\0'){
		weight_of_step = 1;
		index2 = element_num-1;
		while(index2 != 0){
			weight_of_step *= 10;
			index2--;
		}
		result += ( char_array[index1] - '0' ) * weight_of_step ;
		index1++;
		element_num--;
	}

	return result;

}

long char_to_long(char* char_array){

	int element_num = 0 ,  index1 = 0 , index2 = 0 , weight_of_step = 1;
	long result = 0 ;

	while(char_array[element_num] != '\0'){
		element_num++;
	}

	while(char_array[index1] != '\0'){
		weight_of_step = 1;
		index2 = element_num-1;
		while(index2 != 0){
			weight_of_step *= 10;
			index2--;
		}
		result += ( char_array[index1] - '0' ) * weight_of_step ;
		index1++;
		element_num--;
	}

	return result;

}