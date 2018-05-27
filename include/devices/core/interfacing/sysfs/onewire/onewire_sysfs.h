#ifndef _ONEWIRE_SYSFS_H_
#define _ONEWIRE_SYSFS_H_

#include <stdint.h>

size_t onewire_read(char *buf, size_t len, const char *onewire_dir_path);

#endif /* _ONEWIRE_SYSFS_H_ */