#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arrayUtil.h"

int areEqual(ArrayUtil a1,ArrayUtil a2){
	int i,a2_i=0;
	int *x=(int *)a1.base;
	int *y=(int *)a2.base;
	if(a1.length!=a2.length || a1.typeSize!=a2.typeSize){
		return 0;
	}
	for (i = 0; i < a1.length; ++i){
		if(x[i]==y[i]){
			++a2_i;
			if(a2_i==a1.length){
				return 1;
			}
		}
	}
	return 0;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil arr;
	int i;
	arr.base=(int *)malloc(typeSize*length);
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
	resized.base=(int *)malloc(util.typeSize*length);
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
	int i;
	int *array=(int *)util.base;
	int *ele=(int *)element;
	for (i = 0; i < util.length; ++i){
		if(array[i]==*ele){
			return i;
		}
	}
	return -1;
}