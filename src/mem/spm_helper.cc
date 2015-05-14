/*
 * Author: Youngbin Kim
 */

#include "mem/spm_helper.hh"

bool SpmHelper::inSpmAddress(Addr addr) {
    //STUB
    if(addr == 0x8acc0) return true;
    return false;
}

Addr SpmHelper::translate(Addr vaddr) {
    //STUB
    return 0x80;
}
