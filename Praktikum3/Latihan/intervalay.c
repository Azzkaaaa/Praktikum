#include <stdio.h>

#include "listdin.h"

int min(ElType x, ElType y) {
	if (x < y) return x;
	return y;
}

int main() {
	ListDin ld;
	CreateListDin(&ld, 10000);
	readList(&ld);
	int start, stop;
	scanf("%d%d", &start, &stop);

	ListDin ld2;
	CreateListDin(&ld2, listLength(ld) + 2);

	IdxType i;
	int minEl = 0;
	boolean iris = false;
	boolean merged = false;
	for (i = 0; i < listLength(ld); i += 2) {
		ElType str = ELMT(ld, i);
		ElType stp = ELMT(ld, i + 1);
		// printf("%d%d\n", str, stp);

		if (!merged) {
			if (stop < str) {
				if (iris) {
					insertLast(&ld2, minEl);
					insertLast(&ld2, stop);
					iris = false;
					merged = true;
				} else {
					insertLast(&ld2, start);
					insertLast(&ld2, stop);
				}
			} else if (stop == str) {
				if (iris) {
					insertLast(&ld2, minEl);
					insertLast(&ld2, stp);
					iris = false;
					merged = true;
					continue;
				} else {
					insertLast(&ld2, start);
					insertLast(&ld2, stp);
				}
			} else if ((stop > str && stop < stp) &&
					   (start > str && start < stp)) {
			} else if (start > str && start < stp) {
				minEl = str;
				iris = true;
			} else if (stop > str && stop < stp) {
				// printf("halo");
				if (iris) {
					str = minEl;
					iris = false;
					merged = true;
				}
			}
		}
		if (!iris) {
			insertLast(&ld2, str);
			insertLast(&ld2, stp);
		}
	}
	if (!merged) {
		insertLast(&ld2, start);
		insertLast(&ld2, stop);
	}
	// printf("\n");
	// printList(ld);
	// printf("\n");
	// printList(ld2);

	for (i = 0; i < NEFF(ld2); ++i) {
		printf("%d", ELMT(ld2, i));
		if (i == NEFF(ld2) - 1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	return 0;
}