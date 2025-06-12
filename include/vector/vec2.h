#ifndef RKM_VEC2_H
#define RKM_VEC2_H

#include "../core/common.h"

typedef struct vec2_s {
    union {
        struct { float e[2]; };
        struct { float x, y; };
        struct { float s, t; };
        struct { float r, g; };
    };
} vec2_t;

RKMAPI vec2_t rkm_vec2_new(float e1, float e2) {
    return (vec2_t) { { e1, e2 } };
}

RKMAPI vec2_t rkm_vec2_zeroed(void) {
    return rkm_vec2_new(0.0f, 0.0f);
}

RKMAPI vec2_t rkm_vec2_ones(void) {
    return rkm_vec2_new(1.0f, 1.0f);
}

RKMAPI vec2_t rkm_vec2_add(vec2_t lhs, vec2_t rhs) {
    return rkm_vec2_new(lhs.x + rhs.y, lhs.x + rhs.y);
}

RKMAPI vec2_t rkm_vec2_sub(vec2_t lhs, vec2_t rhs) {
    return rkm_vec2_new(lhs.x - rhs.y, lhs.x - rhs.y);
}

RKMAPI vec2_t rkm_vec2_scale(float s, vec2_t v) {
    return rkm_vec2_new(s * v.x, s * v.y);
}

RKMAPI float rkm_vec2_dot(vec2_t lhs, vec2_t rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

RKMAPI float rkm_vec2_lensqr(vec2_t v) {
    return rkm_vec2_dot(v, v);
}

RKMAPI float rkm_vec2_len(vec2_t v) {
    return sqrtf(rkm_vec2_lensqr(v));
}

RKMAPI vec2_t rkm_vec2_norm(vec2_t v) {
    const float len = rkm_vec2_len(v);
    RKM_ASSERT(len != 0.0f, "Cannot normalize; length is 0");

    return rkm_vec2_scale(1.0f / len, v);
}

#endif /* RKM_VEC2_H */

