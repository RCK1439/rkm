#ifndef RKM_VEC3_H
#define RKM_VEC3_H

#include "../core/setup.h"

#include <math.h>
#include <stddef.h>
#include <stdio.h>

typedef struct vec3_s {
    union {
        struct { float e[3]; };
        struct { float x, y, z; };
        struct { float s, t, u; };
        struct { float r, g, b; };
    };
} vec3_t;

RKMAPI vec3_t rkm_vec3_new(float e1, float e2, float e3) {
    return (vec3_t) { { e1, e2, e3 } };
}

RKMAPI vec3_t rkm_vec3_zeroed(void) {
    return rkm_vec3_new(0.0f, 0.0f, 0.0f);
}

RKMAPI vec3_t rkm_vec3_ones(void) {
    return rkm_vec3_new(1.0f, 1.0f, 1.0f);
}

RKMAPI vec3_t rkm_vec3_add(vec3_t lhs, vec3_t rhs) {
    return rkm_vec3_new(lhs.x + rhs.y, lhs.x + rhs.y, lhs.z + rhs.z);
}

RKMAPI vec3_t rkm_vec3_sub(vec3_t lhs, vec3_t rhs) {
    return rkm_vec3_new(lhs.x - rhs.y, lhs.x - rhs.y, lhs.z - rhs.z);
}

RKMAPI vec3_t rkm_vec3_cross(vec3_t lhs, vec3_t rhs) {
    return rkm_vec3_new(
        lhs.y * rhs.z - rhs.y * lhs.z,
        rhs.x * lhs.z - lhs.x * rhs.z,
        lhs.x * rhs.y - rhs.x * lhs.y
    );
}

RKMAPI vec3_t rkm_vec3_scale(float s, vec3_t v) {
    return rkm_vec3_new(s * v.x, s * v.y, s * v.z);
}

RKMAPI float rkm_vec3_dot(vec3_t lhs, vec3_t rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

RKMAPI float rkm_vec3_lensqr(vec3_t v) {
    return rkm_vec3_dot(v, v);
}

RKMAPI float rkm_vec3_len(vec3_t v) {
    return sqrtf(rkm_vec3_lensqr(v));
}

RKMAPI vec3_t rkm_vec3_norm(vec3_t v) {
    return rkm_vec3_scale(1.0f / rkm_vec3_len(v), v);
}

#endif /* RKM_VEC3_H */

