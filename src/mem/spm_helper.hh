/*
 * Author: Youngbin Kim
 */

/*
 * @file
 * Class providing helper functions related to spm.
 */

#ifndef __SPM_HELPER_HH__
#define __SPM_HELPER_HH__

#include "base/types.hh"

/**
 * Class providing helper functions related to spm. 
 */
class SpmHelper {
    public:
        /** Returns true if the given address is in
         * the spm address space. */
        static bool inSpmAddress(Addr addr);

        /** Translate vaddr to paddr. */
        static Addr translate(Addr vaddr);
};

#endif //__SPM_HELPER_HH
