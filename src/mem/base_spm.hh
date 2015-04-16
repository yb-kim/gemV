/*
 * Author: Youngbin Kim
 */

/*
 * @file
 * BaseSpm declaration
 */

#ifndef __BASE_SPM_HH__
#define __BASE_SPM_HH__

#include "mem/simple_mem.hh"
#include "params/BaseSpm.hh"

/**
 * BaseSpm is local store attached to a core. 
 */
class BaseSpm : public SimpleMemory {
    public:
        BaseSpm(const BaseSpmParams* p);
};

#endif //__BASE_SPM_HH__
