#include <stdio.h>
#include "rkm/rkm.h"

#define PI 3.14159265359f

int main(void) {
    const vec4_t v0 = rkm_vec4_new_single(PI);
    const vec4_t v1 = rkm_vec4_new(3.0f, 2.0f, 4.0f, 5.0f);
    const vec4_t v2 = rkm_vec4_max(v0, v1);

    printf("vec4[%.2f, %.2f, %.2f, %.2f]\n", v2.x, v2.y, v2.z, v2.w);
}
