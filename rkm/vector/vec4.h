#ifndef RKM_VEC4_H
#define RKM_VEC4_H

#include "../core/common.h"

#define RKM_VEC4_TYPE_GEN(name, base_type)\
typedef struct name##_s {\
    union {\
        struct { base_type e[4]; };\
        struct { base_type x, y, z, w; };\
        struct { base_type r, g, b, a; };\
        struct { base_type s, t, u, v; };\
    };\
} name##_t

RKM_VEC4_TYPE_GEN(vec4, float);

RKMAPI vec4_t rkm_vec4_new(float e1, float e2, float e3, float e4) {
    return (vec4_t) { { e1, e2, e3, e4 } };
}

RKMAPI vec4_t rkm_vec4_zeroed(void) {
    return rkm_vec4_new(0.0f, 0.0f, 0.0f, 0.0f);
}

RKMAPI vec4_t rkm_vec4_ones(void) {
    return rkm_vec4_new(1.0f, 1.0f, 1.0f, 1.0f);
}

RKMAPI vec4_t rkm_vec4_add(vec4_t lhs, vec4_t rhs) {
    return rkm_vec4_new(
        lhs.x + rhs.y,
        lhs.x + rhs.y,
        lhs.z + rhs.z,
        lhs.w + rhs.w
    );
}

RKMAPI vec4_t rkm_vec4_sub(vec4_t lhs, vec4_t rhs) {
    return rkm_vec4_new(
        lhs.x - rhs.y,
        lhs.x - rhs.y,
        lhs.z - rhs.z,
        lhs.w - rhs.w
    );
}

RKMAPI vec4_t rkm_vec4_scale(float s, vec4_t v) {
    return rkm_vec4_new(
        s * v.x,
        s * v.y,
        s * v.z,
        s * v.w
    );
}

RKMAPI float rkm_vec4_dot(vec4_t lhs, vec4_t rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

RKMAPI float rkm_vec4_lensqr(vec4_t v) {
    return rkm_vec4_dot(v, v);
}

RKMAPI float rkm_vec4_len(vec4_t v) {
    return sqrtf(rkm_vec4_lensqr(v));
}

RKMAPI vec4_t rkm_vec4_norm(vec4_t v) {
    return rkm_vec4_scale(1.0f / rkm_vec4_len(v), v);
}

#endif /* RKM_VEC4_H */

