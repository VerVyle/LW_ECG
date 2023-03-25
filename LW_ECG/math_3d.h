#pragma once

#ifndef MATH_3D_H
#define	MATH_3D_H

struct Vector3f {
    float x;
    float y;
    float z;

    Vector3f() : x(0),y(0),z(0) {}

    Vector3f(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif	/* MATH_3D_H */
