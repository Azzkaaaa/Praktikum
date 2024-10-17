#include <stdio.h>

#include "listdin.h"

int main() {
	ListDin ld;
	CreateListDin(&ld, 1000);
	readList(&ld);

	int total = 0;
	IdxType i;
	for (i = 1; i < listLength(ld); ++i) {
		IdxType j;

		for (j = i; j > 0; --j) {
			ElType e1 = ELMT(ld, j);
			ElType e2 = ELMT(ld, j - 1);

			if (e1 < e2) {
				ELMT(ld, j) = e2;
				ELMT(ld, j - 1) = e1;
				total++;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}