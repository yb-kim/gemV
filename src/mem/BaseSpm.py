# Author: Youngbin Kim

from m5.params import *
from SimpleMemory import *

class BaseSpm(SimpleMemory):
    type = 'BaseSpm'
    cxx_header = "mem/base_spm.hh"

    # each core can access only its own spm
    in_addr_map = False
