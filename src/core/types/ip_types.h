#ifndef _IP_TYPES_H_
#define _IP_TYPES_H_

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
} IPAddress;

const char *ip_address_to_cstr(IPAddress ipAddress) {
    char *cstr;
    sprintf(cstr, "%d.%d.%d.%d", ipAddress.a, ipAddress.b, ipAddress.c, ipAddress.d);
    return cstr;
}

#endif /* _IP_TYPES_H_ */
