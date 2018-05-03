#ifndef _ONEWIRE_SYSFS_H_
#define _ONEWIRE_SYSFS_H_

#include <stdint.h>

int onewire_read(char *buf, int len, const char *onewire_dir_path);

#endif /* _ONEWIRE_SYSFS_H_ */