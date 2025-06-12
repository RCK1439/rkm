#include <stdio.h>
#define RKM_IMPLEMENTATION
#include "rkm/rkm.h"

#define PI 3.14159265359f

static void vec2_dbg(vec2_t v) {
    printf("vec2[%.2f, %.2f]\n", v.x, v.y);
}

int main(void) {
    const vec2_t v0 = rkm_vec2_new(1.0f, 2.0f);
    const mat2_t m = rkm_mat2_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec2_t v1 = rkm_transform2(m, v0);

    vec2_dbg(v1);
}
