#include <stdio.h>
#include <stdlib.h>

int Hash(int k) {
	double A = 0.618033;
	int f;
	return f=(13*fmod(k*A,5));
}

int main() {
	int a[10];
	int b[10];
	int key,maxkey,maxhash,i;
	for (i = 0; i < 10; i++) {
		key = 0 + rand()%1000;
		printf("Hash: (%d) = ", key);
		b[i] = key;
		a[i] = Hash(key);
		printf("%d\n", a[i]);
	}
	puts("");
	maxkey = b[0];
	maxhash = a[0];
	for (i = 1; i < 10; i++) {
		if (b[i] > maxkey) {
			maxkey = b[i];
			maxhash = a[i];
		}
	}
	printf("max Key = %d; this hash = %d", maxkey, maxhash);
	return 0;
}
