#ifndef RKM_VEC2_H
#define RKM_VEC2_H

#include "../core/common.h"

#define RKM_VEC2_TYPE_GEN(name, type)\
    typedef struct {\
        union {\
            struct { type e[2]; };\
            struct { type x, y; };\
            struct { type r, g; };\
            struct { type s, t; };\
        };\
    } name##_t

#define RKM_VEC2_FUNC_GEN(name, type)\
    RKMAPI name##_t rkm_##name##_new(type e1, type e2) {\
        return (name##_t) { { e1, e2 } };\
    }\
    RKMAPI name##_t rkm_##name##_zeros(void) {\
        return rkm_##name##_new((type)0, (type)0);\
    }\
    RKMAPI name##_t rkm_##name##_ones(void) {\
        return rkm_##name##_new((type)1, (type)1);\
    }\
    RKMAPI name##_t rkm_##name##_add(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x + rhs.x,\
            lhs.y + rhs.y\
        );\
    }\
    RKMAPI name##_t rkm_##name##_sub(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x - rhs.x,\
            lhs.y - rhs.y\
        );\
    }\
    RKMAPI name##_t rkm_##name##_mul(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x * rhs.x,\
            lhs.y * rhs.y\
        );\
    }\
    RKMAPI name##_t rkm_##name##_div(name##_t lhs, name##_t rhs) {\
        RKM_ASSERT(rhs.x != 0 && rhs.y != 0, RKM_DIVIDE_BY_ZERO);\
        return rkm_##name##_new(\
            lhs.x / rhs.x,\
            lhs.y / rhs.y\
        );\
    }\
    RKMAPI name##_t rkm_##name##_scale(type s, name##_t v) {\
        return rkm_##name##_new(\
            s * v.x,\
            s * v.y\
        );\
    }\
    RKMAPI type rkm_##name##_dot(name##_t lhs, name##_t rhs) {\
        return (lhs.x * rhs.x) + (lhs.y * rhs.y);\
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
        return rkm_##name##_new(v.x / len, v.y / len);\
    }\

#define RKM_VEC2_GEN(name, type)\
    RKM_VEC2_TYPE_GEN(name, type);\
    RKM_VEC2_FUNC_GEN(name, type)

RKM_VEC2_GEN(vec2, float)
RKM_VEC2_GEN(dvec2, double)
RKM_VEC2_GEN(ivec2, int32_t)
RKM_VEC2_GEN(uvec2, uint32_t)
RKM_VEC2_TYPE_GEN(bvec2, bool);

#endif /* RKM_VEC2_H */

