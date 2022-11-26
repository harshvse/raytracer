// what are the functionality which we need from out vec3 class?
/*
    two constructors: one to default all the values to 0 another to construct with 3 double values
    3 getters to return the values of x y z respectively
    a '-' operator which inverts the values of all three doubles
    overloading the [] operator in order to access the values of the vectors in array style
    overloading the arithmetic operators +, *, /
    a function which returns the length of the vector ie. sqrt(a^2 + b^2 + c^2)
*/

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
private:
    double e[3];

public:
    // constructors
    vec3() : e{0, 0, 0} {}                                   // when no argument is passed the vector is initialized with zero values
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} // we pass 3 double values which are used to initialize the vector

    // getters
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // operators
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec3 &operator+=(const vec3 &v) {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    vec3 &operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3 &operator/=(const double t) {
        return *this *= 1 / t; // calls the multiply assignment operator in order to do the divide
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    double length() const {
        return sqrt(length_squared());
    }
};

using point3 = vec3; // type alias for vec3 points #X Y Z
using color = vec3;  // type alias of vec3 for color #RGB

// we also need utility functions to handle different operations performed on the vec3 class like the stream operator >> << or the arithmetic operators

inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
    out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v[0], t * v[1], t * v[2]);
}

inline vec3 operator/(const vec3 &v, double t) {
    return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u[1] * v[2] - u[2] * v[1],
                u[2] * v[0] - u[0] * v[2],
                u[0] * v[1] - u[1] * v[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif