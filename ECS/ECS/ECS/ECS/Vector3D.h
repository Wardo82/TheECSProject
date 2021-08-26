#pragma once

#include <iostream>

template <typename T>
class Vector3D {

public:
    T x, y, z;
    // Default constructor
    Vector3D() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    // Coordinate constructor
    Vector3D(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    // Copy constructor
    Vector3D(const Vector3D &v){
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }

    /* ----- Operators overloading ----- */
    // Vector sumation
    inline Vector3D<T> operator+(const Vector3D &v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }
    inline friend Vector3D<T> operator+=(Vector3D &v1, const Vector3D &v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;
        return v1;
    }
    // Vector substraction
    inline Vector3D<T> operator-(const Vector3D &v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }
    inline friend Vector3D<T> operator-=(Vector3D &v1, const Vector3D &v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        v1.z -= v2.z;
        return v1;
    }
    // Vector multiplication by a scalar
    inline Vector3D<T> operator*(const T &scalar) const {
        return Vector3D(x*scalar, y*scalar, z*scalar);
    }
    // Vector division by a scalar
    inline Vector3D<T> operator/(const T &d) {
        return (d != 0 ? Vector3D(x/d, y/d, z/d) : Vector3D<T>() );;
    }
    
    /* ----- Helper functions for Vector3D initialization ----- */
    inline Vector3D<T>& zero() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        return *this;
    }
    inline Vector3D<T>& ones() {
        this->x = 1;
        this->y = 1;
        this->z = 1;
        return *this;
    }
    inline friend std::ostream& operator<<(std::ostream& stream, const Vector3D<T>& v) {
        stream << "(" << v.x << "," << v.y << "," << v.z << ")";
        return stream;
    }
    
private:

};
