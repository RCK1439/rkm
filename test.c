#include <stdio.h>
#define RKM_IMPLEMENTATION
#include "rkm/rkm.h"

#define PI 3.14159265359f

int main(void) {
    const vec3_t v0 = rkm_vec3_ones();
    const vec3_t v1 = rkm_vec3_zeros();
    const vec3_t v2 = rkm_vec3_cross(v0, v1);

    printf("vec3[%.2f, %.2f, %.2f]\n", v2.x, v2.y, v2.z);
}
