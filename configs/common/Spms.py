from m5.objects import *

class SmallSpm(BaseSpm):
    _size = "4kB"
    range = AddrRange(_size)
