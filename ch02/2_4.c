#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
	int i;
	for(i = 0; i < len; i++){
		printf("%.2x", start[i]);
		//表明整数必须用至少两个数字的十六进制格式输出
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
	int ival = val;
	float fval = (float)ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);

//  39300000
//  00e44046
//  087a6bfffe7f0000
}

int main() {
	int a = 12345;
	test_show_bytes(a);
	return(0);
}