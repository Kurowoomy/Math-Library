#include <iostream>
#include "Vector_Matrix.h"

int main() {

	MyVector4 vec(1, 2, 3, 1);
	MyVector4 vec1(0, 1, 0, 1);
	MyMatrix4 mat(1);
	mat[0] = 4;
	mat[5] = 0;
	mat[6] = 2;
	mat[9] = 1;
	mat[10] = 2;
	mat[12] = 1;
	MyMatrix4 m = mat.inverse();
	std::cout << vec1.x << std::endl;
	MyVector4 vec2 = m.rotateVector(vec, vec1, 3);
	
	std::cout << vec2.y;

	std::cin.get();
}