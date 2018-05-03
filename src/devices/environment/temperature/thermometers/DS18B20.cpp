#include <regex.h>
#include <thread>

#include <devices/environment/temperature/thermometers/DS18B20.hpp>

float DS18B20::readTempFromDevice_() {

    const char        *pattern = "t[=]\\d+";
    char       buf[75];
    regex_t    regex;
    char       regex_buf[8];
    regmatch_t matches[2]; // Size must be 2 because matches[0] will be the whole string
    char       error_buf[128];
    float      temp;

    OneWireDevice::read(buf, 75);

    if (regcomp(&regex, pattern, 0)) {
        printf("Failed to compile regex: %s\n", pattern);
        // Return here, regfree should not get called after a failed regcomp
        return -501;
    }

    int regex_res = regexec(&regex, buf, 2, matches, 0);

    if (!regex_res) {
        memcpy(regex_buf, (buf + matches[1].rm_so + 2), (matches[1].rm_eo - matches[1].rm_so + 2));
        temp = strtof(regex_buf, NULL);
    } else if (regex_res == REG_NOMATCH) {
        printf("Nothing matched regex pattern: %s\n", pattern);
        temp = -502;
    } else {
        regerror(regex_res, &regex, error_buf, sizeof(error_buf));
        printf("Failed to match regex: %s (error: %s)\n", pattern, error_buf);
        temp = -503;
    }

    regfree(&regex);

    return temp;
}
