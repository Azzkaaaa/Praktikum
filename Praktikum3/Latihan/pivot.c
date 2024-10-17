#include <stdio.h>

#include "listdin.h"

int main() {
	ListDin ld;
	CreateListDin(&ld, 100000);
	readList(&ld);
	int total = 0;
	IdxType i;

	// bjir time limit exceeded
	// for (i = 0; i < listLength(ld); ++i) {
	// 	ElType e = ELMT(ld, i);
	// 	IdxType left, right;
	// 	for (left = i - 1; left >= 0; --left) {
	// 		if (ELMT(ld, left) > e) {
	// 			goto skip;
	// 		}
	// 	}
	// 	for (right = i + 1; right < listLength(ld); ++right) {
	// 		if (ELMT(ld, right) < e) {
	// 			goto skip;
	// 		}
	// 	}
	// 	total++;
	// skip:
	// 	continue;
	// }

	ListDin left, right;
	CreateListDin(&left, listLength(ld));
	CreateListDin(&right, listLength(ld));

	insertLast(&left, 1);
	ElType max = ELMT(ld, 0);
	for (i = 1; i < listLength(ld); ++i) {
		ElType e = ELMT(ld, i);

		if (e > max) {
			max = e;
			insertLast(&left, 1);
		} else {
			insertLast(&left, 0);
		}
	}
	ElType min = ELMT(ld, listLength(ld) - 1);
	insertLast(&right, 1);
	for (i = listLength(ld) - 2; i >= 0; --i) {
		ElType e = ELMT(ld, i);

		if (e < min) {
			min = e;
			insertLast(&right, 1);
		} else {
			insertLast(&right, 0);
		}
	}

	for (i = 0; i < listLength(ld); ++i) {
		if (ELMT(left, i) == 1 && ELMT(right, listLength(ld) - 1 - i) == 1) {
			total++;
		}
	}
	// printList(left);
	// printList(right);
	printf("%d\n", total);
	return 0;
}