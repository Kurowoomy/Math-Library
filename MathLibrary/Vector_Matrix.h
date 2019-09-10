#pragma once
#include <math.h>

/// has no use so far, can ignore this class
class MyVector3 {
public:
	float x, y, z;

	MyVector3() 
	{
	}

	MyVector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	MyVector3 operator+(const MyVector3& v) {
		MyVector3 vect;
		vect.x = this->x + v.x;
		vect.y = this->y + v.y;
		vect.z = this->z + v.z;
		return vect;
	}
	MyVector3 operator-(const MyVector3& v) {
		MyVector3 vect;
		vect.x = this->x - v.x;
		vect.y = this->y - v.y;
		vect.z = this->z - v.z;
		return vect;
	}
	MyVector3 operator*(const float scalar) {
		MyVector3 vect;
		vect.x = this->x * scalar;
		vect.y = this->y * scalar;
		vect.z = this->z * scalar;
		return vect;
	}
	MyVector3& operator=(const MyVector3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	float length() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	MyVector3 normalize() {
		MyVector3 vect;
		vect.x = this->x / this->length();
		vect.y = this->y / this->length();
		vect.z = this->z / this->length();
		return vect;
	}
	float dotProduct(MyVector3 v) {
		return this->x * v.x + this->y * v.y + this->z * v.z;
	}
	MyVector3 crossProduct(MyVector3 v) {
		MyVector3 vect;
		vect.x = this->y * v.z - this->z * v.y;
		vect.y = this->z * v.x - this->x * v.z;
		vect.z = this->x * v.y - this->y * v.x;
		return vect;
	}

	~MyVector3() 
	{
	}
};

class MyVector4 {
public:
	float x, y, z, w;

	MyVector4()
	{
	}
	///assigns values to x, y, z, and w
	MyVector4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	///vector + vector operator
	MyVector4 operator+(const MyVector4& v) {
		MyVector4 vect;
		vect.x = this->x + v.x;
		vect.y = this->y + v.y;
		vect.z = this->z + v.z;
		vect.w = this->w + v.w;
		return vect;
	}
	///vector - vector operator
	MyVector4 operator-(const MyVector4& v) {
		MyVector4 vect;
		vect.x = this->x - v.x;
		vect.y = this->y - v.y;
		vect.z = this->z - v.z;
		vect.w = this->w - v.w;
		return vect;
	}
	///vector * float operator
	MyVector4 operator*(const float scalar) {
		MyVector4 vect;
		vect.x = this->x * scalar;
		vect.y = this->y * scalar;
		vect.z = this->z * scalar;
		vect.w = this->w * scalar;
		return vect;
	}
	///vector = vector operator
	MyVector4& operator=(const MyVector4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	///returns length of vector
	float length() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	///uses length(), normalizes vector
	MyVector4 normalize() {
		MyVector4 vect;
		vect.x = this->x / this->length();
		vect.y = this->y / this->length();
		vect.z = this->z / this->length();
		return vect;
	}
	///computes dot product of vector
	float dotProduct(MyVector4 v) {
		return this->x * v.x + this->y * v.y + this->z * v.z;
	}
	///computes cross product of vector
	MyVector4 crossProduct(MyVector4 v) {
		MyVector4 vect;
		vect.x = this->y * v.z - this->z * v.y;
		vect.y = this->z * v.x - this->x * v.z;
		vect.z = this->x * v.y - this->y * v.x;
		return vect;
	}

	~MyVector4()
	{
	}
};


class MyMatrix4 {
public:
	float matrix[16];

	MyMatrix4()
	{
	}
	///sets diagonal to given float, other numbers to 0
	MyMatrix4(float diagonal) {
		matrix[0] = diagonal;
		matrix[5] = diagonal;
		matrix[10] = diagonal;
		matrix[15] = diagonal;
		matrix[1] = matrix[2] = matrix[3] = matrix[4] = 0;
		matrix[6] = matrix[7] = matrix[8] = matrix[9] = 0;
		matrix[11] = matrix[12] = matrix[13] = matrix[14] = 0;
	}
	
	///makes it so one doesn't have to type matrix whenever referencing a position with []
	float& operator[](int index) {
		return matrix[index];
	}
	///matrix x matrix computation
	MyMatrix4 operator*(const MyMatrix4& m) {
		MyMatrix4 mat;
		mat[0] = this->matrix[0] * m.matrix[0] + this->matrix[1] * m.matrix[4] + this->matrix[2] * m.matrix[8] + this->matrix[3] * m.matrix[12]; //row 1, column 1
		mat[1] = this->matrix[0] * m.matrix[1] + this->matrix[1] * m.matrix[5] + this->matrix[2] * m.matrix[9] + this->matrix[3] * m.matrix[13]; //row 1, column 2
		mat[2] = this->matrix[0] * m.matrix[2] + this->matrix[1] * m.matrix[6] + this->matrix[2] * m.matrix[10] + this->matrix[3] * m.matrix[14]; //row 1, column 3
		mat[3] = this->matrix[0] * m.matrix[3] + this->matrix[1] * m.matrix[7] + this->matrix[2] * m.matrix[11] + this->matrix[3] * m.matrix[15]; //row 1, column 4
		mat[4] = this->matrix[4] * m.matrix[0] + this->matrix[5] * m.matrix[4] + this->matrix[6] * m.matrix[8] + this->matrix[7] * m.matrix[12]; //row 2, column 1
		mat[5] = this->matrix[4] * m.matrix[1] + this->matrix[5] * m.matrix[5] + this->matrix[6] * m.matrix[9] + this->matrix[7] * m.matrix[13]; //row 2, column 2
		mat[6] = this->matrix[4] * m.matrix[2] + this->matrix[5] * m.matrix[6] + this->matrix[6] * m.matrix[10] + this->matrix[7] * m.matrix[14]; //row 2, column 3
		mat[7] = this->matrix[4] * m.matrix[3] + this->matrix[5] * m.matrix[7] + this->matrix[6] * m.matrix[11] + this->matrix[7] * m.matrix[15]; //row 2, column 4
		mat[8] = this->matrix[8] * m.matrix[0] + this->matrix[9] * m.matrix[4] + this->matrix[10] * m.matrix[8] + this->matrix[11] * m.matrix[12]; //row 3, column 1
		mat[9] = this->matrix[8] * m.matrix[1] + this->matrix[9] * m.matrix[5] + this->matrix[10] * m.matrix[9] + this->matrix[11] * m.matrix[13]; //row 3, column 2
		mat[10] = this->matrix[8] * m.matrix[2] + this->matrix[9] * m.matrix[6] + this->matrix[10] * m.matrix[10] + this->matrix[11] * m.matrix[14]; //row 3, column 3
		mat[11] = this->matrix[8] * m.matrix[3] + this->matrix[9] * m.matrix[7] + this->matrix[10] * m.matrix[11] + this->matrix[11] * m.matrix[15]; //row 3, column 4
		mat[12] = this->matrix[12] * m.matrix[0] + this->matrix[13] * m.matrix[4] + this->matrix[14] * m.matrix[8] + this->matrix[15] * m.matrix[12]; //row 4, column 1
		mat[13] = this->matrix[12] * m.matrix[1] + this->matrix[13] * m.matrix[5] + this->matrix[14] * m.matrix[9] + this->matrix[15] * m.matrix[13]; //row 4, column 2
		mat[14] = this->matrix[12] * m.matrix[2] + this->matrix[13] * m.matrix[6] + this->matrix[14] * m.matrix[10] + this->matrix[15] * m.matrix[14]; //row 4, column 3
		mat[15] = this->matrix[12] * m.matrix[3] + this->matrix[13] * m.matrix[7] + this->matrix[14] * m.matrix[11] + this->matrix[15] * m.matrix[15]; //row 4, column 4
		return mat;
	}
	///matrix x vector computation
	MyVector4 operator*(const MyVector4& v) {
		MyVector4 vect;
		vect.x = this->matrix[0] * v.x + this->matrix[1] * v.y + this->matrix[2] * v.z + this->matrix[3] * v.w; //row 1
		vect.y = this->matrix[4] * v.x + this->matrix[5] * v.y + this->matrix[6] * v.z + this->matrix[7] * v.w; //row 2
		vect.z = this->matrix[8] * v.x + this->matrix[9] * v.y + this->matrix[10] * v.z + this->matrix[11] * v.w; //row 3
		vect.w = this->matrix[12] * v.x + this->matrix[13] * v.y + this->matrix[14] * v.z + this->matrix[15] * v.w; //row 4
		return vect;
	}
	///rotate v around x axis
	MyVector4 rotateX(MyVector4 v, float radians) {
		MyMatrix4 m(1);
		m[5] = cos(radians);
		m[6] = -sin(radians);
		m[9] = sin(radians);
		m[10] = cos(radians);
		return m * v;
	}
	///rotate v around y axis
	MyVector4 rotateY(MyVector4 v, float radians) {
		MyMatrix4 m(1);
		m[0] = cos(radians);
		m[2] = sin(radians);
		m[8] = -sin(radians);
		m[10] = cos(radians);
		return m * v;
	}
	///rotate v around z axis
	MyVector4 rotateZ(MyVector4 v, float radians) {
		MyMatrix4 m(1);
		m[0] = cos(radians);
		m[1] = -sin(radians);
		m[4] = sin(radians);
		m[5] = cos(radians);
		return m * v;
	}
	///rotate vect around v vector
	MyVector4 rotateVector(MyVector4 v, MyVector4 vect, float r) {
		MyMatrix4 m(1);
		m[0] = cos(r) + v.x * v.x * (1 - cos(r));
		m[1] = v.x * v.y * (1 - cos(r)) - v.z * sin(r);
		m[2] = v.x * v.z * (1 - cos(r)) + v.y * sin(r);
		m[4] = v.y * v.x * (1 - cos(r)) + v.z * sin(r);
		m[5] = cos(r) + v.y * v.y * (1 - cos(r));
		m[6] = v.y * v.z * (1 - cos(r)) - v.x * sin(r);
		m[8] = v.z * v.x * (1 - cos(r)) - v.y * sin(r);
		m[9] = v.z * v.y * (1 - cos(r)) + v.x * sin(r);
		m[10] = cos(r) + v.z * v.z * (1 - cos(r));
		return m * vect;
	}
	///make rows and columns switch place
	MyMatrix4 transpose() {
		MyMatrix4 m;
		//row 1 to column 1
		m[0] = this->matrix[0];
		m[1] = this->matrix[4];
		m[2] = this->matrix[8];
		m[3] = this->matrix[12];
		//row 2 to column 2
		m[4] = this->matrix[1];
		m[5] = this->matrix[5];
		m[6] = this->matrix[9];
		m[7] = this->matrix[13];
		//row 3 to column 3
		m[8] = this->matrix[2];
		m[9] = this->matrix[6];
		m[10] = this->matrix[10];
		m[11] = this->matrix[14];
		//row 4 to column 4
		m[12] = this->matrix[3];
		m[13] = this->matrix[7];
		m[14] = this->matrix[11];
		m[15] = this->matrix[15];
		return m;
	}
	///inverse computation
	MyMatrix4 inverse() {
		MyMatrix4 mat;
		float det, m[16];

		m[0] = this->matrix[5] * this->matrix[10] * this->matrix[15] -
				this->matrix[5] * this->matrix[11] * this->matrix[14] -
				this->matrix[9] * this->matrix[6] * this->matrix[15] +
				this->matrix[9] * this->matrix[7] * this->matrix[14] +
				this->matrix[13] * this->matrix[6] * this->matrix[11] -
				this->matrix[13] * this->matrix[7] * this->matrix[10];
		m[4] = -this->matrix[4] * this->matrix[10] * this->matrix[15] +
				this->matrix[4] * this->matrix[11] * this->matrix[14] +
				this->matrix[8] * this->matrix[6] * this->matrix[15] -
				this->matrix[8] * this->matrix[7] * this->matrix[14] -
				this->matrix[12] * this->matrix[6] * this->matrix[11] +
				this->matrix[12] * this->matrix[7] * this->matrix[10];
		m[8] = this->matrix[4] * this->matrix[9] * this->matrix[15] -
				this->matrix[4] * this->matrix[11] * this->matrix[13] -
				this->matrix[8] * this->matrix[5] * this->matrix[15] +
				this->matrix[8] * this->matrix[7] * this->matrix[13] +
				this->matrix[12] * this->matrix[5] * this->matrix[11] -
				this->matrix[12] * this->matrix[7] * this->matrix[9];
		m[12] = -this->matrix[4] * this->matrix[9] * this->matrix[14] +
				this->matrix[4] * this->matrix[10] * this->matrix[13] +
				this->matrix[8] * this->matrix[5] * this->matrix[14] -
				this->matrix[8] * this->matrix[6] * this->matrix[13] -
				this->matrix[12] * this->matrix[5] * this->matrix[10] +
				this->matrix[12] * this->matrix[6] * this->matrix[9];
		m[1] = -this->matrix[1] * this->matrix[10] * this->matrix[15] +
				this->matrix[1] * this->matrix[11] * this->matrix[14] +
				this->matrix[9] * this->matrix[2] * this->matrix[15] -
				this->matrix[9] * this->matrix[3] * this->matrix[14] -
				this->matrix[13] * this->matrix[2] * this->matrix[11] +
				this->matrix[13] * this->matrix[3] * this->matrix[10];
		m[5] = this->matrix[0] * this->matrix[10] * this->matrix[15] -
				this->matrix[0] * this->matrix[11] * this->matrix[14] -
				this->matrix[8] * this->matrix[2] * this->matrix[15] +
				this->matrix[8] * this->matrix[3] * this->matrix[14] +
				this->matrix[12] * this->matrix[2] * this->matrix[11] -
				this->matrix[12] * this->matrix[3] * this->matrix[10];
		m[9] = -this->matrix[0] * this->matrix[9] * this->matrix[15] +
				this->matrix[0] * this->matrix[11] * this->matrix[13] +
				this->matrix[8] * this->matrix[1] * this->matrix[15] -
				this->matrix[8] * this->matrix[3] * this->matrix[13] -
				this->matrix[12] * this->matrix[1] * this->matrix[11] +
				this->matrix[12] * this->matrix[3] * this->matrix[9];
		m[13] = this->matrix[0] * this->matrix[9] * this->matrix[14] -
				this->matrix[0] * this->matrix[10] * this->matrix[13] -
				this->matrix[8] * this->matrix[1] * this->matrix[14] +
				this->matrix[8] * this->matrix[2] * this->matrix[13] +
				this->matrix[12] * this->matrix[1] * this->matrix[10] -
				this->matrix[12] * this->matrix[2] * this->matrix[9];
		m[2] = this->matrix[1] * this->matrix[6] * this->matrix[15] -
				this->matrix[1] * this->matrix[7] * this->matrix[14] -
				this->matrix[5] * this->matrix[2] * this->matrix[15] +
				this->matrix[5] * this->matrix[3] * this->matrix[14] +
				this->matrix[13] * this->matrix[2] * this->matrix[7] -
				this->matrix[13] * this->matrix[3] * this->matrix[6];
		m[6] = -this->matrix[0] * this->matrix[6] * this->matrix[15] +
				this->matrix[0] * this->matrix[7] * this->matrix[14] +
				this->matrix[4] * this->matrix[2] * this->matrix[15] -
				this->matrix[4] * this->matrix[3] * this->matrix[14] -
				this->matrix[12] * this->matrix[2] * this->matrix[7] +
				this->matrix[12] * this->matrix[3] * this->matrix[6];
		m[10] = this->matrix[0] * this->matrix[5] * this->matrix[15] -
				this->matrix[0] * this->matrix[7] * this->matrix[13] -
				this->matrix[4] * this->matrix[1] * this->matrix[15] +
				this->matrix[4] * this->matrix[3] * this->matrix[13] +
				this->matrix[12] * this->matrix[1] * this->matrix[7] -
				this->matrix[12] * this->matrix[3] * this->matrix[5];
		m[14] = -this->matrix[0] * this->matrix[5] * this->matrix[14] +
				this->matrix[0] * this->matrix[6] * this->matrix[13] +
				this->matrix[4] * this->matrix[1] * this->matrix[14] -
				this->matrix[4] * this->matrix[2] * this->matrix[13] -
				this->matrix[12] * this->matrix[1] * this->matrix[6] +
				this->matrix[12] * this->matrix[2] * this->matrix[5];
		m[3] = -this->matrix[1] * this->matrix[6] * this->matrix[11] +
				this->matrix[1] * this->matrix[7] * this->matrix[10] +
				this->matrix[5] * this->matrix[2] * this->matrix[11] -
				this->matrix[5] * this->matrix[3] * this->matrix[10] -
				this->matrix[9] * this->matrix[2] * this->matrix[7] +
				this->matrix[9] * this->matrix[3] * this->matrix[6];
		m[7] = this->matrix[0] * this->matrix[6] * this->matrix[11] -
				this->matrix[0] * this->matrix[7] * this->matrix[10] -
				this->matrix[4] * this->matrix[2] * this->matrix[11] +
				this->matrix[4] * this->matrix[3] * this->matrix[10] +
				this->matrix[8] * this->matrix[2] * this->matrix[7] -
				this->matrix[8] * this->matrix[3] * this->matrix[6];
		m[11] = -this->matrix[0] * this->matrix[5] * this->matrix[11] +
				this->matrix[0] * this->matrix[7] * this->matrix[9] +
				this->matrix[4] * this->matrix[1] * this->matrix[11] -
				this->matrix[4] * this->matrix[3] * this->matrix[9] -
				this->matrix[8] * this->matrix[1] * this->matrix[7] +
				this->matrix[8] * this->matrix[3] * this->matrix[5];
		m[15] = this->matrix[0] * this->matrix[5] * this->matrix[10] -
				this->matrix[0] * this->matrix[6] * this->matrix[9] -
				this->matrix[4] * this->matrix[1] * this->matrix[10] +
				this->matrix[4] * this->matrix[2] * this->matrix[9] +
				this->matrix[8] * this->matrix[1] * this->matrix[6] -
				this->matrix[8] * this->matrix[2] * this->matrix[5];

		det = this->matrix[0] * m[0] + this->matrix[1] * m[4] + this->matrix[2] * m[8] + this->matrix[3] * m[12];

		for (int i = 0; i < 16; i++)
		{
			mat[i] = m[i] / det;
			if (mat[i] == -0) mat[i] = 0; 
		}

		return mat;
	}

	~MyMatrix4()
	{
	}
};