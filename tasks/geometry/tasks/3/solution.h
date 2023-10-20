#include <iostream>
#include <stdio.h> 

const int ITERATIONS = 50;
const int cord_X1 = 10;
const int cord_Y1 = 10;
const int rad_1 = 5;
const int rad_2 = 10;
typedef struct {
	int x;
	int y;
} Point;

int CheckZone(Point p) {
	int cord_x = p.x;
	int cord_y = p.y;
	int first_x = (cord_x - cord_X1) * (cord_x - cord_X1);
	int first_y = (cord_y - cord_Y1) * (cord_y - cord_Y1);
	int rad_square_1 = rad_1 * rad_1;
	int rad_square_2 = rad_2 * rad_2;
	if ((first_x + first_y >= rad_square_1) && (first_x + first_y <= rad_square_2)) {
		return 1;
	} else {
		return 2;
	}
}

int mod(int x, int y) {
	if (y != 0) {
		return x % y;
	} else {
		return 0;
	}
}
int abs(int x) {
	if (x > 0) {
		return x;
	} else {
		return x * -1;
	}
}

int sign(int x) {
	if (x > 0) {
		return 1;
	}
	if (x == 0) {
		return 0;
	} else {
		return -1;
	}
}

int maxz(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

int minz(int x, int y) {
	if (x < y) {
		return x;
	} else {
		return y;
	}
}

int Task() {
	const int i = 0;
	const int j = 0;
	const int k = 0;
	const int l = 0;
	const int ik = 1;
	const int jk = -30;
	const int lk = 1;
	const int b = 0;
	int i_0 = ik;
	int j_0 = jk;
	int l_0 = lk;
	for (int i = 0; i < ITERATIONS; ++i) {
		Point p;
		p.x = i_0;
		p.y = j_0;
		int i_1 = 0;
		int j_1 = 0;
		if (CheckZone(p) == 1) {
			printf("x = %d, y = %d\n", i_0, j_0);
		}
		i_1 = i_0 / ik - (i_0 - i) * sign(l_0 - j_0);
		j_1 = mod(j_0, lk) - mod(maxz(i_0, l_0), 10) % (i + 1);
		int l_1 = i_0 + mod(j_0 * i, ik) + l_0 / jk + ik;
		i_0 = i_1;
		j_0 = j_1;
		l_0 = l_1;
	}
	return 0;
}
