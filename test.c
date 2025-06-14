#include <stdio.h>
#define RKM_IMPLEMENTATION
#include "rkm/rkm.h"

#define PI 3.14159265359f

int main(void) {
    const vec2_t v0 = rkm_vec2_new(2.0f, 3.0f);
    const mat2_t m0 = rkm_mat2_new(2.0f, 3.0f, 3.0f, 2.0f);

    const float det = rkm_mat2_det(m0);
    if (det != 0.0f)
    {
        printf("det=%.2f\n", det);

        const mat2_t m0_inv = rkm_mat2_inv(m0);
        printf("inv[%.2f, %.2f]\n", m0_inv.e11, m0_inv.e12);
        printf("   [%.2f, %.2f]\n", m0_inv.e21, m0_inv.e22);
    }

    const vec2_t v1 = rkm_transform2(m0, v0);
    printf("v1[%.2f, %.2f]\n", v1.x, v1.y);
}
