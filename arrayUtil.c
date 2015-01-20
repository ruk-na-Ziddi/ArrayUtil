#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arrayUtil.h"

int areEqual(ArrayUtil a1,ArrayUtil a2){
	int i,a2_i=0;
	char *x=(char *)a1.base;
	char *y=(char *)a2.base;
	if(a1.length!=a2.length || a1.typeSize!=a2.typeSize){
		return 0;
	}
	for (i = 0; i < a1.length*a1.typeSize; ++i){
		if(x[i]==y[i]){
			++a2_i;
			if(a2_i==a1.length*a1.typeSize){
				return 1;
			}
		}
	}
	return 0;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil arr;
	int i;
	arr.base=malloc(typeSize*length);
	arr.typeSize=typeSize;
	arr.length=length;
	for(i=0;i<length;++i){
		((int *)arr.base)[i]=0;
	}
	return arr;
}

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil resized;
	int i;
	resized.base=malloc(util.typeSize*length);
	resized.typeSize=util.typeSize;
	resized.length=length;
	for(i=0;i<length;++i){
		if(i>=util.length){
			((int *)resized.base)[i]=0;
		}else{
			((int *)resized.base)[i]=((int *)util.base)[i];
		}
	}
	return resized;
}

int findIndex(ArrayUtil util, void* element){
	int i,ele_i=0;
	char *array=(char *)util.base;
	char *ele=(char *)element;
	for (i = 0; i < util.length*util.typeSize; ++i){
		if(ele_i>0 && array[i]!=ele[ele_i]){
			ele_i=0;
		}
		if(array[i]==ele[ele_i]){
			++ele_i;
			if(ele_i==util.typeSize){
				return (i+1)/(util.typeSize)-1;
			}
		}
	}
	return -1;
}