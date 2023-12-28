//Radoslav Peev 7MI0600261
void squareArr(int* a, size_t len) {
	for (int i = 0; i < len; i++) {
		a[i] = a[i] * a[i];
	}
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (a[i] > a[j]) {
				int swap = a[j];
				a[j] = a[i];
				a[i] = swap;
			}
		}
	}
}
int checkNum(long N, unsigned int m, unsigned int l) {
	if (N > pow(10, 9)) {
		return -1;
	}
	int Nlen = 0,n=N;
	while (n != 0) {
		Nlen++;
		n /= 10;
	}
	if ((m > Nlen) || (l > Nlen)) {
		return -1;
	}
	int* arr = new int[Nlen];
	int i = 1, nCopy = N;;
	while (nCopy != 0) {
		arr[i] = nCopy % 10;
		i++;
		nCopy /= 10;
	}
	for (int j = Nlen; j >=1; j--) {
		if (j == m) {
			int swap = arr[j];
			arr[j] = arr[l];
			arr[l] = swap;
		}
	}
}
int CheckDate(char* a) {
	if (a == nullptr) {
		return -1;
	}
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	if (i > 10) {
		return 0;
	}
	bool flagOne = false;
	if (a[3]=='0' && a[4]=='1') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '1') {
			return 0;
		}
	}
	else if (a[3] == '0' && a[4] == '2') {
		int year=0;
		for (int i = 6; i <= 9; i++) {
			year *= 10;
			year += (int)a[i]-48;
		}

		if (year % 4 == 0) {
			if ((a[0] >= '0' && a[0] <= '2') && (a[1] >= '0' && a[1] <= '9')) {
				flagOne = true;
			}
		}
		else if (year % 400 == 0) {
			if ((a[0] >= '0' && a[0] <= '2') && (a[1] >= '0' && a[1] <= '9')) {
				flagOne = true;
			}
		}
		else {
			if ((a[0] >= '0' && a[0] <= '2') && (a[1] >= '0' && a[1] <= '9')) {
				flagOne = true;
			}
			if (a[0] == '2' && a[1] > '8') {
				return 0;
			}
		}
	}
	else if (a[3] == '0' && a[4] == '4') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '0') {
			return 0;
		}
	}
	else if (a[3] == '0' && a[4] == '5') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '1') {
			return 0;
		}

	}
	else if (a[3] == '0' && a[4] == '6') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '0') {
			return 0;
		}

	}
	else if (a[3] == '0' && a[4] == '7') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '1') {
			return 0;
		}

	}
	else if (a[3] == '0' && a[4] == '8') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '1') {
			return 0;
		}

	}
	else if (a[3] == '0' && a[4] == '9') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '0') {
			return 0;
		}

	}
	else if (a[3] == '1' && a[4] == '0') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '1') {
			return 0;
		}
	}
	else if (a[3] == '1' && a[4] == '1') {
		if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
			flagOne = true;
		}
		if (a[0] == '3' && a[1] > '0') {
			return 0;
		}
	}
	else if (a[3] == '1' && a[4] == '2') {
			if ((a[0] >= '0' && a[0] <= '3') && (a[1] >= '0' && a[1] <= '9')) {
				flagOne = true;
			}
			if (a[0] == '3' && a[1] > '1') {
				return 0;
			}
	}
	else {
			return 0;
		}
	if (flagOne && a[2] == '.' && a[5] == '.') {
			return 1;
	}
}
