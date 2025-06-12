#include <stdio.h>
#define RKM_IMPLEMENTATION
#include "rkm/rkm.h"

#define PI 3.14159265359f

int main(void) {
    const vec2_t v0 = rkm_vec2_new(40.0f, 30.0f);
    const vec2_t v1 = rkm_vec2_norm(v0);

    const vec2_t v2 = rkm_rotate2(1.5f * PI, v1);

    printf("vec2[%.2f, %.2f]\n", v2.x, v2.y);
}
