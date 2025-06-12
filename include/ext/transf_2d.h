#ifndef RKM_TRANS2D_H
#define RKM_TRANS2D_H

#include "../core/common.h"
#include "../matrix/mat2.h"
#include "../vector/vec2.h"

RKMAPI mat2_t rkm_mat2_rotation(float radians) {
    const float cosine = cosf(radians);
    const float sine = sinf(radians);

    return rkm_mat2_new(cosine, -sine, sine, cosine);
}

RKMAPI mat2_t rkm_mat2_projection(vec2_t a) {
    return rkm_mat2_scale(
        rkm_vec2_dot(a, a),
        rkm_mat2_new(
            a.x * a.x, a.x * a.y,
            a.y * a.x, a.y * a.y
        )
    );
}

RKMAPI mat2_t rkm_mat2_reflection(vec2_t n) {
    return rkm_mat2_sub(
        rkm_mat2_scale(2.0f, rkm_mat2_projection(n)),
        rkm_mat2_ident()
    );
}

RKMAPI vec2_t rkm_transform2(mat2_t A, vec2_t x) {
    return rkm_vec2_new(
        A.e11 * x.x + A.e12 * x.y,
        A.e21 * x.x + A.e22 * x.y
    );
}

RKMAPI vec2_t rkm_rotate2(float radians, vec2_t v) {
    return rkm_transform2(rkm_mat2_rotation(radians), v);
}

RKMAPI vec2_t rkm_proj2(vec2_t a, vec2_t b) {
    return rkm_transform2(rkm_mat2_projection(a), b);
}

RKMAPI vec2_t rkm_reflect2(vec2_t a, vec2_t b) {
    return rkm_transform2(rkm_mat2_reflection(a), b);
}

#endif /* RKM_TRANS2D_H */

