#ifndef RKM_MAT2X2_H
#define RKM_MAT2X2_H

#include "../core/common.h"

#define RKM_MAT2_TYPE_GEN(name, type)\
typedef struct {\
    union {\
        struct { type e[2 * 2]; };\
        struct {\
            type e11, e21;\
            type e12, e22;\
        };\
    };\
} name##_t

#define RKM_MAT2_FUNC_GEN(name, type)\
    RKMAPI name##_t rkm_##name##_new(type e11, type e12, type e21, type e22) {\
        return (name##_t) { { e11, e21, e12, e22 } };\
    }\
    RKMAPI name##_t rkm_##name##_ident(void) {\
        return rkm_##name##_new(\
            (type)1, (type)0,\
            (type)0, (type)1\
        );\
    }\
    RKMAPI name##_t rkm_##name##_add(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.e11 + rhs.e11, lhs.e12 + rhs.e12,\
            lhs.e21 + rhs.e21, lhs.e22 + rhs.e22\
        );\
    }\
    RKMAPI name##_t rkm_##name##_sub(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.e11 - rhs.e11, lhs.e12 - rhs.e12,\
            lhs.e21 - rhs.e21, lhs.e22 - rhs.e22\
        );\
    }\
    RKMAPI name##_t rkm_##name##_mul(name##_t lhs, name##_t rhs) {\
        return rkm_##name##_new(\
            lhs.e11 * rhs.e11 + lhs.e12 * rhs.e21,\
            lhs.e11 * rhs.e12 + lhs.e12 * rhs.e22,\
            lhs.e21 * rhs.e11 + lhs.e22 * rhs.e21,\
            lhs.e21 * rhs.e12 + lhs.e22 * rhs.e22\
        );\
    }\
    RKMAPI name##_t rkm_##name##_scale(type s, name##_t m) {\
        return rkm_##name##_new(\
            s * m.e11,\
            s * m.e12,\
            s * m.e21,\
            s * m.e22\
        );\
    }\
    RKMAPI type rkm_##name##_det(name##_t m) {\
        return m.e11 * m.e22 - m.e12 * m.e21;\
    }\
    RKMAPI name##_t rkm_##name##_inv(name##_t m) {\
        const type det = rkm_##name##_det(m);\
        RKM_ASSERT(det != (type)0, RKM_DIVIDE_BY_ZERO);\
        return rkm_##name##_new(\
            m.e22 / det, -m.e12 / det,\
           -m.e21 / det,  m.e11 / det\
        );\
    }\
    RKMAPI name##_t rkm_##name##_trans(name##_t m) {\
        return rkm_##name##_new(\
            m.e11, m.e21,\
            m.e12, m.e22\
        );\
    }\

#define RKM_MAT2_GEN(name, type)\
    RKM_MAT2_TYPE_GEN(name, type);\
    RKM_MAT2_FUNC_GEN(name, type)

RKM_MAT2_GEN(mat2, float);
RKM_MAT2_GEN(dmat2, double);

#endif /* RKM_MAT2X2_H */

