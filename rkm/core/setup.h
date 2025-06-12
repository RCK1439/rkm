#ifndef RKM_SETUP_H
#define RKM_SETUP_H

#if defined(RKM_IMPLEMENTATION)
#define RKMAPI extern inline
#elif defined(RKM_STATIC_INLINE)
#define RKMAPI static inline
#else
#define RKMAPI inline
#endif

#if defined(NDEBUG)
#define RKM_ASSERT(expr, ...) (void)0
#else
#include <stdio.h>
#include <stdlib.h>
#define RKM_ASSERT(expr, ...) if (!(expr)) {\
        fprintf(stderr, "rkm_assertion failed: " __VA_ARGS__);\
        exit(EXIT_FAILURE);\
    }
#endif

#endif /* RKM_SETUP_H */

