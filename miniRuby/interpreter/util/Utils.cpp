#include "Utils.h"
#include <iostream>
#include <cstdio>

void Utils::abort(int line){
	printf("%02d: Operação inválida\n", line);
	exit(1);

}

