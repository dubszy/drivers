#ifndef _BOARD_CONFIG_TYPES_H_
#define _BOARD_CONFIG_TYPES_H_

#include "board_type.h"

typedef struct {
    BoardType board_type;
    const char *friendly_name;
} BoardConfig;

#endif /* _BOARD_CONFIG_TYPES_H_ */
