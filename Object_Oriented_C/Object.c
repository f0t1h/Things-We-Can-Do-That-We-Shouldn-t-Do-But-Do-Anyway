#include <stdio.h>
#include <stdlib.h>


typedef struct __Object{
	int id;
	int (*getId)();
	int (*idFactorial)();
} Object;



void __ObjectFunctionInit (Object *a){
	int __getId(void){
		return a->id;
	}
	int __idFactorial( Object *a){
		int i;
		int sum = 1;
		for(i=2;i<=a->id;i++){
			sum*=i;
		}
		return sum;
	}
	a->idFactorial = &__idFactorial;
	a->getId = &__getId;
}

Object *ObjectInit(int id){
	Object *n_object = malloc(sizeof(Object));
	n_object->id = id;
	__ObjectFunctionInit(n_object);
	return n_object;
}

int main(){
	Object o = *ObjectInit(5);
	printf("%d! = %d \n",o.getId(),o.idFactorial());
	return 0;
}
