#include <regex.h>
#include <sstream>
#include <utility>

#include <devices/environment/temperature/thermometers/DS18B20.hpp>

DS18B20::DS18B20(string name, TemperatureScale scale, uint8_t decimalPrecision, string deviceAddress)
  : OneWireDevice(name, OWFC_DS18B20, deviceAddress), // NOLINT do not std::move strings here
    Thermometer(scale, decimalPrecision) {
    log->debug("Instantiating new DS18B20");
}

DS18B20::DS18B20(string name, string deviceAddress)
  : Thermometer(ScaleCelsius, 2),
    OneWireDevice(name, OWFC_DS18B20, deviceAddress) { // NOLINT do not std::move strings here
    log->debug("Instantiating new DS18B20");
}

double DS18B20::readTempFromDevice_() {

    const char *pattern = "t=[0-9]+";
    char       buf[128] = "";
    regex_t    regex;
    char       regex_buf[8] = "";
    regmatch_t matches[2]; // Size must be 2 because matches[0] will be the whole string
    char       error_buf[128] = "";
    float      temp;

    read(buf, 75);

    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        log->error("Failed to compile regex: %s", pattern);
        // Return here, regfree should not get called after a failed regcomp
        return -501;
    }

    int regex_res = regexec(&regex, buf, 2, matches, 0);

    if (!regex_res) {
        memcpy(regex_buf, (buf + matches[1].rm_so + 70), static_cast<size_t>(matches[1].rm_eo - matches[1].rm_so + 5));
        temp = strtof(regex_buf, nullptr);
    } else if (regex_res == REG_NOMATCH) {
        log->error("Nothing matched regex pattern: %s", pattern);
        temp = -502;
    } else {
        regerror(regex_res, &regex, error_buf, sizeof(error_buf));
        log->error("Failed to match regex: %s (error: %s)", pattern, error_buf);
        temp = -503;
    }

    regfree(&regex);

    return temp / 1000;
}

string DS18B20::toString() {
    stringstream sstream;
    // scale_ and precision_ boil down to 8 bits, which are scanned verbatim, thus resulting in them being interpreted
    // as ASCII
    sstream << "DS18B20: { Name: " << getName()
            << ", Scale: " << (uint32_t)scale_
            << ", Precision: " << (uint32_t)precision_
            << ", Family Code: 0x" << std::hex << (uint32_t)getFamilyCode() // this is a hex value
            << ", Device Address: " << getAddress()
            << " }";
    return sstream.str();
}
