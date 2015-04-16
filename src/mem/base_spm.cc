/*
 * Author: Youngbin Kim
 */

#include "mem/base_spm.hh"

BaseSpm::BaseSpm(const BaseSpmParams* p) :
    SimpleMemory(p) 
{
    //
}

BaseSpm*
BaseSpmParams::create() {
    return new BaseSpm(this);
}
