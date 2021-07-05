#include "Utils.h"
#include <iostream>
#include <cstdio>

void Utils::abort(int line){
	printf("%02d: Operação inválida\n", line);
	exit(1);

}

void Utils::ioob(int line){
	printf("%02d: Index Out Of Bounds\n", line);
	exit(1);

}
