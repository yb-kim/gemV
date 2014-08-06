//Youngbin Kim
//yb.kim@yonsei.ac.kr

#ifndef __VUL_ESTIMATOR_HH__
#define __VUL_ESTIMATOR_HH__

#include "mem/cache/blk.hh"

template<class TagStore>
class Vul_estimator {
public:
    typedef typename TagStore::BlkType BlkType;
    Vul_estimator(unsigned int _blkSize, unsigned int _wordSize);
    void calc(BlkType *blk, PacketPtr pkt, Operation op);

private:
    unsigned int blkSize;
    unsigned int wordSize;
};

#include "vul_estimator_impl.cc"
#endif //__VUL_ESTIMATOR_HH__
