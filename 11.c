#include <stdio.h>

int main() {
	float a[3][4] = { {0.71,0.10,0.12,0.29},{0.10,0.34,-0.04,0.32},{0.12,-0.04,0.10,-0.10} };  //будет изменён
	float a1[3][4] = { {0.71,0.10,0.12,0.29},{0.10,0.34,-0.04,0.32},{0.12,-0.04,0.10,-0.10} }; //для проверки
	int i, j;
	float x1, x2, x3, v;
	float tmp, tmp2;

	/// РУЧНОЙ ВВОД=>
	/*
	printf("vvedite el-ti of sistems");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("\n[%d][%d]",i+1,j+1);
			if(!(scanf("%f",&a[i][j]))) {
				puts("error on input");
				j=0; i=0;
				printf("try agen");
			}
		}
	}

	printf("vvedite svobodnit chleni");
	for(int i=0;i<=2;i++){
		printf("\n[%d]= ",i+1);
		scanf("%f",&b[i]);
	}
		  <=   */
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 3; j++) {
			printf("[%d][%d]=%0.2f  ", i + 1, j + 1, a[i][j]);
		}
		printf("\n");
	}

	//start
	tmp = a[0][0];

	for (j = 0; j <= 3; j++) {       ////T1
		a[0][j] /= tmp;
	}

	tmp = 0 - a[1][0];
	tmp2 = 0 - a[2][0];
	for (j = 0; j <= 3; j++) {       ////T2
		a[1][j] += tmp * a[0][j];
		a[2][j] += tmp2 * a[0][j];
	}

	tmp = a[1][1];
	for (j = 0; j <= 3; j++) {      /////T3
		a[1][j] /= tmp;
	}
	
	tmp = 0-a[2][1];
	for (j = 0; j <= 3; j++) {      /////T4
		a[2][j] += a[1][j] * tmp;
	}

	tmp = a[2][2];
	for (j = 0; j <= 3; j++) {       ////T5
		a[2][j] /= tmp;
	}

	puts("\n mass: ");
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 3; j++) {
			if (a[i][j] == -0) a[i][j] = 0; //-0!
			printf("[%d][%d]=%0.4f ", i + 1, j + 1, a[i][j]);
		}
		printf("\n");
	}
	puts("");
	x3 = a[2][3];
	x2 = a[1][3] - a[1][2] * x3;
	x1 = a[0][3] - (a[0][1] * x2 + a[0][2] * x3);  
	printf("x1= %0.4f\nx2= %0.4f\nx3= %0.4f\n", x1, x2, x3);

	puts("\nproverka:\n");

	v = x1 * a1[0][0] + x2 * a1[0][1] + x3 * a1[0][2];
	printf("rezult: %0.4f ?= %0.2f \n", v, a1[0][3]);

	v = x1 * a1[1][0] + x2 * a1[1][1] + x3 * a1[1][2];
	printf("rezult: %0.4f ?= %0.2f \n", v, a1[1][3]);

	v = x1 * a1[2][0] + x2 * a1[2][1] + x3 * a1[2][2];
	printf("rezult: %0.4f ?= %0.2f", v, a1[2][3]);

	return 0;
}
