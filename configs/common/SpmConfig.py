import m5
from m5.objects import *
from Spms import *

def config_spm(options, system):
    for i in xrange(options.num_cpus):
        spmEnabled = ['dspm', 'ispm']
        for spmName in spmEnabled:
            spm = SmallSpm()
            setattr(system.cpu[i], spmName, spm)
            setattr(system.cpu[i], spmName+'_port', spm.port)

        #spm.port = system.cpu[i].dspm_port
