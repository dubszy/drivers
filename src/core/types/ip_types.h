#ifndef _IP_TYPES_H_
#define _IP_TYPES_H_

#define IP_MAX_CHAR 15

#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
} IPAddress;

in_addr_t ipton(IPAddress ipAddress) {
    return ipAddress.a << 24 +
           ipAddress.b << 16 +
           ipAddress.c << 8 +
           ipAddress.d;
}

int ip_address_to_cstr(IPAddress ipAddress, char *cstr) {
    return sprintf(cstr, "%d.%d.%d.%d", ipAddress.a, ipAddress.b, ipAddress.c, ipAddress.d);
}

#ifdef __cplusplus
#include <string>
std::string ip_address_to_string(IPAddress ipAddress) {
    char cstr[16];
    ip_address_to_cstr(ipAddress, cstr);
    return std::string(cstr);
}
#endif

#endif /* _IP_TYPES_H_ */
