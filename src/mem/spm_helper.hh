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
        
        /** Return true if spms are set (used in simulation). */
        static bool isSpmSet();

        /** Translate vaddr to paddr. */
        static Addr translate(Addr vaddr);

        static void setDspmStartAddress(Addr vaddr);
        static void setDspmEndAddress(Addr vaddr);
        static void setSpmSet(bool use);

        static Addr dspmStartAddress;
        static Addr dspmEndAddress;
        static bool spmSet;
};

#endif //__SPM_HELPER_HH
