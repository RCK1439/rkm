#ifndef RKM_MAT2X2_H
#define RKM_MAT2X2_H

#include "../core/common.h"

typedef struct mat2_s {
    union {
        struct { float e[4]; };
        struct {
            float e11, e21;
            float e12, e22;
        };
    };
} mat2_t;

RKMAPI mat2_t rkm_mat2_new(float e11, float e12, float e21, float e22) {
    return (mat2_t) { { e11, e21, e12, e22 } };
}

RKMAPI mat2_t rkm_mat2_ident(void) {
    return rkm_mat2_new(
        1.0f, 0.0f,
        0.0f, 1.0f
    );
}

RKMAPI mat2_t rkm_mat2_add(mat2_t lhs, mat2_t rhs) {
    return rkm_mat2_new(
        lhs.e11 + rhs.e11, lhs.e12 + rhs.e12,
        lhs.e21 + rhs.e21, lhs.e22 + rhs.e22
    );
}

RKMAPI mat2_t rkm_mat2_sub(mat2_t lhs, mat2_t rhs) {
    return rkm_mat2_new(
        lhs.e11 - rhs.e11, lhs.e12 - rhs.e12,
        lhs.e21 - rhs.e21, lhs.e22 - rhs.e22
    );
}

RKMAPI mat2_t rkm_mat2_mul(mat2_t lhs, mat2_t rhs) {
    return rkm_mat2_new(
        lhs.e11 * rhs.e11 + lhs.e12 * rhs.e21,
        lhs.e11 * rhs.e12 + lhs.e12 * rhs.e22,
        lhs.e21 * rhs.e11 + lhs.e22 * rhs.e21,
        lhs.e21 * rhs.e12 + lhs.e22 * rhs.e22
    );
}

RKMAPI mat2_t rkm_mat2_scale(float s, mat2_t m) {
    return rkm_mat2_new(
        s * m.e11,
        s * m.e12,
        s * m.e21,
        s * m.e22
    );
}

RKMAPI float rkm_mat2_det(mat2_t m) {
    return m.e11 * m.e22 - m.e12 * m.e21;
}

RKMAPI mat2_t rkm_mat2_inv(mat2_t m) {
    const float det = rkm_mat2_det(m);
    RKM_ASSERT(det != 0.0f, "Cannot invert; determinant is 0");

    return rkm_mat2_scale(1.0f / det, rkm_mat2_new(m.e22, -m.e12, -m.e21, m.e11));
}

RKMAPI mat2_t rkm_mat2_trans(mat2_t m) {
    return rkm_mat2_new(
        m.e11, m.e21,
        m.e12, m.e22
    );
}

#endif /* RKM_MAT2X2_H */

