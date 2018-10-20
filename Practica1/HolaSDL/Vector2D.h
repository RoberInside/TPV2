#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <iostream>

using namespace std;
class Vector2D
{
public:
	Vector2D();
	Vector2D(const Vector2D &v);
	Vector2D(double x, double y);
	virtual ~Vector2D();
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void set(const Vector2D &v);
	void set(double x, double y);
	double escalar() const;
	void rotate(double degrees);
	double angle(const Vector2D& v) const;
	void normalize();
	Vector2D sumaVectores(Vector2D v1, Vector2D v2);
	Vector2D restaVectores(Vector2D v1, Vector2D v2);
	Vector2D vectorXescalar(double n);


	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator *(const Vector2D& d) const;
	Vector2D operator/(double d) const;
	friend std::ostream& operator<<(std::ostream& os, const Vector2D &v);


private:
	double x_, y_;
};
#endif 

