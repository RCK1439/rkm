#ifndef RKM_COMPLEX_H
#define RKM_COMPLEX_H

#include "../core/common.h"

typedef struct {
    float re;
    float im;
} complex_t;

RKMAPI complex_t rkm_complex_new(float re, float im) {
    return (complex_t) { re, im };
}

RKMAPI complex_t rkm_complex_conj(complex_t z) {
    return rkm_complex_new(z.re, -z.im);
}

RKMAPI float rkm_complex_abssqr(complex_t z) {
    return z.re * z.re + z.im * z.im;
}

RKMAPI float rkm_complex_abs(complex_t z) {
    return sqrtf(rkm_complex_abssqr(z));
}

RKMAPI complex_t rkm_complex_add(complex_t lhs, complex_t rhs) {
    return rkm_complex_new(lhs.re + rhs.re, lhs.im + rhs.im);
}

RKMAPI complex_t rkm_complex_adds(float s, complex_t z) {
    return rkm_complex_new(z.re + s, z.im);
}

RKMAPI complex_t rkm_complex_sub(complex_t lhs, complex_t rhs) {
    return rkm_complex_new(lhs.re - rhs.re, lhs.im - rhs.im);
}

RKMAPI complex_t rkm_complex_subs(float s, complex_t z) {
    return rkm_complex_new(z.re - s, z.im);
}

RKMAPI complex_t rkm_complex_mul(complex_t lhs, complex_t rhs) {
    return rkm_complex_new(
        lhs.re * rhs.re - lhs.im * rhs.im,
        lhs.re * rhs.im + lhs.im * rhs.re
    );
}

RKMAPI complex_t rkm_complex_muls(float s, complex_t z) {
    return rkm_complex_new(s * z.re, s * z.im);
}

RKMAPI complex_t rkm_complex_div(complex_t lhs, complex_t rhs) {
    const float abssqr = rkm_complex_abssqr(rhs);
    RKM_ASSERT(abssqr != 0.0f, RKM_DIVIDE_BY_ZERO);

    return rkm_complex_muls(
        1.0f / abssqr,
        rkm_complex_mul(lhs, rkm_complex_conj(rhs))
    );
}

RKMAPI complex_t rkm_complex_divs(float s, complex_t z) {
    RKM_ASSERT(s != 0.0f, RKM_DIVIDE_BY_ZERO);
    return rkm_complex_muls(1.0f / s, z);
}

#endif /* RKM_COMPLEX_H */

