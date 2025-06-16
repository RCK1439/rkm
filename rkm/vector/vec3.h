#ifndef RKM_VEC3_H
#define RKM_VEC3_H

#include "../core/common.h"

#define RKM_VEC3_TYPE_GEN(name, type)\
    typedef struct {\
        union {\
            struct { type e[3]; };\
            struct { type x, y, z; };\
            struct { type r, g, b; };\
            struct { type s, t, p; };\
        };\
    } name##_t

#define RKM_VEC3_FUNC_GEN(name, type)\
    RKMAPI name##_t rkm_##name##_new(type e1, type e2, type e3) {\
        return (name##_t) { { e1, e2, e3 } };\
    }\
    RKMAPI name##_t rkm_##name##_fill(type v) {\
        return rkm_##name##_new(v, v, v);\
    }\
    RKMAPI name##_t rkm_##name##_zeros(void) {\
        return rkm_##name##_fill((type)0);\
    }\
    RKMAPI name##_t rkm_##name##_ones(void) {\
        return rkm_##name##_fill((type)1);\
    }\
    RKMAPI name##_t rkm_##name##_add(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x + rhs.x,\
            lhs.y + rhs.y,\
            lhs.z + rhs.z\
        );\
    }\
    RKMAPI name##_t rkm_##name##_sub(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x - rhs.x,\
            lhs.y - rhs.y,\
            lhs.z - rhs.z\
        );\
    }\
    RKMAPI name##_t rkm_##name##_mul(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.x * rhs.x,\
            lhs.y * rhs.y,\
            lhs.z * rhs.z\
        );\
    }\
    RKMAPI name##_t rkm_##name##_div(name##_t lhs, name##_t rhs) {\
        RKM_ASSERT(rhs.x != (type)0 && rhs.y != (type)0 && rhs.z != (type)0, RKM_DIVIDE_BY_ZERO);\
        return rkm_##name##_new(\
            lhs.x / rhs.x,\
            lhs.y / rhs.y,\
            lhs.z / rhs.z\
        );\
    }\
    RKMAPI name##_t rkm_##name##_cross(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.y * rhs.z - rhs.y * lhs.z,\
            rhs.x * lhs.z - lhs.x * rhs.z,\
            lhs.x * rhs.y - rhs.x * lhs.y\
        );\
    }\
    RKMAPI name##_t rkm_##name##_scale(type s, name##_t v) {\
        return rkm_##name##_new(\
            s * v.x,\
            s * v.y,\
            s * v.z\
        );\
    }\
    RKMAPI type rkm_##name##_dot(name##_t lhs, name##_t rhs) {\
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);\
    }\
    RKMAPI type rkm_##name##_lensqr(name##_t v) {\
        return rkm_##name##_dot(v, v);\
    }\
    RKMAPI type rkm_##name##_len(name##_t v) {\
        return (type)sqrt((double)rkm_##name##_lensqr(v));\
    }\
    RKMAPI name##_t rkm_##name##_norm(name##_t v) {\
        const type len = rkm_##name##_len(v);\
        RKM_ASSERT(len != (type)0, RKM_DIVIDE_BY_ZERO);\
        return rkm_##name##_new(v.x / len, v.y / len, v.z / len);\
    }\

#define RKM_VEC3_GEN(name, type)\
    RKM_VEC3_TYPE_GEN(name, type);\
    RKM_VEC3_FUNC_GEN(name, type)

RKM_VEC3_GEN(vec3, float)
RKM_VEC3_GEN(dvec3, double)
RKM_VEC3_GEN(ivec3, int32_t)
RKM_VEC3_GEN(uvec3, uint32_t)
RKM_VEC3_TYPE_GEN(bvec3, bool);

#endif /* RKM_VEC3_H */

