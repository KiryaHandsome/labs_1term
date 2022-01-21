
#include "pch.h"
#include "framework.h"



int raiseNumber(int a, unsigned int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}
