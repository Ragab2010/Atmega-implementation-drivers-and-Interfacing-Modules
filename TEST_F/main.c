/*
 * main.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠١٧
 *      Author: RAGAB
 */
#include <stdio.h>
#include <stdlib.h>
#define SMALL 3
#define LARG 5
void swap(int arr1[],int arr2[],int size1,int size2)
{
    int max= size1 > size2 ?  size1:size2;
    //printf("%d\n",size1);
    int i;
    int *temp;
    temp=(int*)malloc(max*sizeof(int));
    for(i = 0; i < max; i++) {
         temp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }
}

int main(){
	int i,a1[SMALL]={1,2,3};
	int a2[LARG]={7,8,9,10,11};
	swap(a1 , a2 , SMALL, LARG);
	for(i =0 ; i<SMALL;i++ )
		printf("%d\t" , a1[i]);
	printf("\n");
	for(i =0 ; i<LARG;i++ )
			printf("%d\t" , a2[i]);
	return 0;
}
