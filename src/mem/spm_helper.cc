/*
 * Author: Youngbin Kim
 */

#include "mem/spm_helper.hh"
#include "base/trace.hh"
#include "debug/Spm.hh"

Addr SpmHelper::dspmStartAddress = 0;
Addr SpmHelper::dspmEndAddress = 0;
bool SpmHelper::spmSet = false;

bool SpmHelper::inSpmAddress(Addr addr) {
    if(addr >= SpmHelper::dspmStartAddress &&
            addr <= SpmHelper::dspmEndAddress) {
        return true;
    }
    return false;
}

Addr SpmHelper::translate(Addr vaddr) {
    return vaddr-SpmHelper::dspmStartAddress;
}

void SpmHelper::setDspmStartAddress(Addr vaddr) {
    SpmHelper::dspmStartAddress = vaddr;
    DPRINTF(Spm, "Dspm start address is set: %d\n", vaddr);
}

void SpmHelper::setDspmEndAddress(Addr vaddr) {
    SpmHelper::dspmEndAddress = vaddr;
    DPRINTF(Spm, "Dspm end address is set: %d\n", vaddr);
}

void SpmHelper::setSpmSet(bool use) {
    SpmHelper::spmSet = use;
    DPRINTF(Spm, "Spm simulation is turned on\n");
}

bool SpmHelper::isSpmSet() {
    return SpmHelper::spmSet;
}
