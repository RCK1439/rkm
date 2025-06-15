#ifndef RKM_COMP_H
#define RKM_COMP_H

#include "../core/common.h"
#include "../vector/vec.h"

#define RKM_MIN(a, b) (a) < (b) ? (a) : (b)
#define RKM_MAX(a, b) (a) > (b) ? (a) : (b)

#define RKM_CLAMP(a, min, max) RKM_MIN(RKM_MAX(a, min), max)

#define RKM_MIX(a, b, wb) (a) * (1.0f - (wb)) + (b) * (wb)

/* --- scalar operations --------------------------------------------------- */

RKMAPI float rkm_min(float a, float b) {
    return RKM_MIN(a, b);
}

RKMAPI float rkm_max(float a, float b) {
    return RKM_MAX(a, b);
}

RKMAPI float rkm_clamp(float a, float min, float max) {
    return RKM_CLAMP(a, min, max);
}

RKMAPI float rkm_mix(float a, float b, float wb) {
    return RKM_MIX(a, b, wb);
}

/* --- vec2 operations ----------------------------------------------------- */

RKMAPI vec2_t rkm_vec2_min(vec2_t a, vec2_t b) {
    return rkm_vec2_new(
        rkm_min(a.x, b.x),
        rkm_min(a.y, b.y)
    );
}

RKMAPI vec2_t rkm_vec2_min_single(vec2_t a, float b) {
    return rkm_vec2_min(a, rkm_vec2_new_single(b));
}

RKMAPI vec2_t rkm_vec2_max(vec2_t a, vec2_t b) {
    return rkm_vec2_new(
        rkm_max(a.x, b.x),
        rkm_max(a.y, b.y)
    );
}

RKMAPI vec2_t rkm_vec2_max_single(vec2_t a, float b) {
    return rkm_vec2_max(a, rkm_vec2_new_single(b));
}

RKMAPI vec2_t rkm_vec2_clamp(vec2_t a, vec2_t min, vec2_t max) {
    return rkm_vec2_new(
        rkm_clamp(a.x, min.x, max.x),
        rkm_clamp(a.y, min.y, max.y)
    );
}

RKMAPI vec2_t rkm_vec2_clamp_single(vec2_t a, float min, float max) {
    return rkm_vec2_clamp(a, rkm_vec2_new_single(min), rkm_vec2_new_single(max));
}

RKMAPI vec2_t rkm_vec2_mix(vec2_t a, vec2_t b, vec2_t wb) {
    return rkm_vec2_new(
        rkm_mix(a.x, b.x, wb.x),
        rkm_mix(a.y, b.y, wb.y)
    );
}

RKMAPI vec2_t rkm_vec2_mix_single(vec2_t a, vec2_t b, float wb) {
    return rkm_vec2_mix(a, b, rkm_vec2_new_single(wb));
}

/* --- vec3 operations ----------------------------------------------------- */

RKMAPI vec3_t rkm_vec3_min(vec3_t a, vec3_t b) {
    return rkm_vec3_new(
        rkm_min(a.x, b.x),
        rkm_min(a.y, b.y),
        rkm_min(a.z, b.z)
    );
}

RKMAPI vec3_t rkm_vec3_min_single(vec3_t a, float b) {
    return rkm_vec3_min(a, rkm_vec3_new_single(b));
}

RKMAPI vec3_t rkm_vec3_max(vec3_t a, vec3_t b) {
    return rkm_vec3_new(
        rkm_max(a.x, b.x),
        rkm_max(a.y, b.y),
        rkm_max(a.z, b.z)
    );
}

RKMAPI vec3_t rkm_vec3_max_single(vec3_t a, float b) {
    return rkm_vec3_max(a, rkm_vec3_new_single(b));
}

RKMAPI vec3_t rkm_vec3_clamp(vec3_t a, vec3_t min, vec3_t max) {
    return rkm_vec3_new(
        rkm_clamp(a.x, min.x, max.x),
        rkm_clamp(a.y, min.y, min.y),
        rkm_clamp(a.z, min.z, max.z)
    );
}

RKMAPI vec3_t rkm_vec3_clamp_single(vec3_t a, float min, float max) {
    return rkm_vec3_clamp(a, rkm_vec3_new_single(min), rkm_vec3_new_single(max));
}

RKMAPI vec3_t rkm_vec3_mix(vec3_t a, vec3_t b, vec3_t wb) {
    return rkm_vec3_new(
        rkm_mix(a.x, b.x, wb.x),
        rkm_mix(a.y, b.y, wb.y),
        rkm_mix(a.z, b.z, wb.z)
    );
}

RKMAPI vec3_t rkm_vec3_mix_single(vec3_t a, vec3_t b, float wb) {
    return rkm_vec3_mix(a, b, rkm_vec3_new_single(wb));
}

/* --- vec4 operations ----------------------------------------------------- */

RKMAPI vec4_t rkm_vec4_min(vec4_t a, vec4_t b) {
    return rkm_vec4_new(
        rkm_min(a.x, b.x),
        rkm_min(a.y, b.y),
        rkm_min(a.z, b.z),
        rkm_min(a.w, b.w)
    );
}

RKMAPI vec4_t rkm_vec4_min_single(vec4_t a, float b) {
    return rkm_vec4_min(a, rkm_vec4_new_single(b));
}

RKMAPI vec4_t rkm_vec4_max(vec4_t a, vec4_t b) {
    return rkm_vec4_new(
        rkm_max(a.x, b.x),
        rkm_max(a.y, b.y),
        rkm_max(a.z, b.z),
        rkm_max(a.w, b.w)
    );
}

RKMAPI vec4_t rkm_vec4_max_single(vec4_t a, float b) {
    return rkm_vec4_max(a, rkm_vec4_new_single(b));
}

RKMAPI vec4_t rkm_vec4_clamp(vec4_t a, vec4_t min, vec4_t max) {
    return rkm_vec4_new(
        rkm_clamp(a.x, min.x, max.x),
        rkm_clamp(a.y, min.y, max.y),
        rkm_clamp(a.z, min.z, max.z),
        rkm_clamp(a.w, min.w, max.w)
    );
}

RKMAPI vec4_t rkm_vec4_clamp_single(vec4_t a, float min, float max) {
    return rkm_vec4_clamp(a, rkm_vec4_new_single(min), rkm_vec4_new_single(max));
}

RKMAPI vec4_t rkm_vec4_mix(vec4_t a, vec4_t b, vec4_t wb) {
    return rkm_vec4_new(
        rkm_mix(a.x, b.x, wb.x),
        rkm_mix(a.y, b.y, wb.y),
        rkm_mix(a.z, b.z, wb.z),
        rkm_mix(a.w, b.w, wb.w)
    );
}

RKMAPI vec4_t rkm_vec4_mix_single(vec4_t a, vec4_t b, float wb) {
    return rkm_vec4_mix(a, b, rkm_vec4_new_single(wb));
}

#endif /* RKM_COMP_H */
