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