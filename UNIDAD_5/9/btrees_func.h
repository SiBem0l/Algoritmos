#ifndef BTREES_FUNC_H
#define BTREES_FUNC_H

#include "..\btrees\tree_basic.h"

int fusion(btn** ptr_root1, btn** ptr_root2);
btn* rmv_leave(btn** ptr_leave);

#endif