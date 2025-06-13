#ifndef RKM_VEC4_H
#define RKM_VEC4_H

#include "../core/common.h"

#define RKM_VEC4_TYPE_GEN(name, type)\
typedef struct {\
    union {\
        struct { type e[4]; };\
        struct { type x, y, z, w; };\
        struct { type r, g, b, a; };\
        struct { type s, t, p, q; };\
    };\
} name##_t;\
\
RKMAPI name##_t rkm_##name##_new(type e1, type e2, type e3, type e4) {\
    return (name##_t) { { e1, e2, e3, e4 } };\
}\
RKMAPI name##_t rkm_##name##_zeros(void) {\
    return rkm_##name##_new(0, 0, 0, 0);\
}\
RKMAPI name##_t rkm_##name##_ones(void) {\
    return rkm_##name##_new(1, 1, 1, 1);\
}\
RKMAPI name##_t rkm_##name##_add(name##_t lhs, name##_t rhs) {\
    return rkm_##name##_new(\
        lhs.x + rhs.x,\
        lhs.y + rhs.y,\
        lhs.z + rhs.z,\
        lhs.w + rhs.w\
    );\
}\
RKMAPI name##_t rkm_##name##_sub(name##_t lhs, name##_t rhs) {\
    return rkm_##name##_new(\
        lhs.x - rhs.x,\
        lhs.y - rhs.y,\
        lhs.z - rhs.z,\
        lhs.w - rhs.w\
    );\
}\
RKMAPI name##_t rkm_##name##_scale(type s, name##_t v) {\
    return rkm_##name##_new(\
        s * v.x,\
        s * v.y,\
        s * v.z,\
        s * v.w\
    );\
}\
RKMAPI type rkm_##name##_dot(name##_t lhs, name##_t rhs) {\
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;\
}\
RKMAPI type rkm_##name##_lensqr(name##_t v) {\
    return rkm_##name##_dot(v, v);\
}\
RKMAPI type rkm_##name##_len(name##_t v) {\
    return (type) sqrt((double) rkm_##name##_lensqr(v));\
}\
RKMAPI name##_t rkm_##name##_norm(name##_t v) {\
    const type len = rkm_##name##_len(v);\
    RKM_ASSERT(len != 0, RKM_DIVIDE_BY_ZERO);\
    return rkm_##name##_new(v.x / len, v.y / len, v.z / len, v.w / len);\
}\

RKM_VEC4_TYPE_GEN(vec4, float)
RKM_VEC4_TYPE_GEN(vec4d, double)
RKM_VEC4_TYPE_GEN(vec4i, int32_t)
RKM_VEC4_TYPE_GEN(vec4u, uint32_t)

#endif /* RKM_VEC4_H */

