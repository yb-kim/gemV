import json
import os
import sys

GEMV_HOME = "/home/ybkim/workspace/gemV"

sys.path.append(GEMV_HOME+'/configs/common')

import SpmParameters

CONFIG_FILE = GEMV_HOME + "/gem-spm/config.json"
GENERATED_DIRECTORY = "generated"
GENERATED_FILE = "spm_config.h"
COMPILE_SCRIPT = "compile.sh"
COMPILER = "arm-linux-gnueabi-gcc"

comment = "//This is auto generated header from generate.py."
constants = {}

with open(CONFIG_FILE) as configFile:
    config = json.loads(configFile.read())

if not os.path.exists(GENERATED_DIRECTORY):
    os.makedirs(GENERATED_DIRECTORY)

with open("%s/%s" % (GENERATED_DIRECTORY, GENERATED_FILE), "w") as generatedFile:
    startAddress = SpmParameters.GlobalSpmConfig.startAddress
    spmSize = SpmParameters.GlobalSpmConfig.size
    constants.update({
        'DSPM_START_ADDRESS': str(startAddress),
        'DSPM_SPAN': str(spmSize),
        'DSPM_END_ADDRESS': str(startAddress + spmSize - 1)
    })

    generatedFile.write(comment+'\n\n')
    for key in constants:
        generatedFile.write("#define %s %s\n" % (key, constants[key]))

    generatedFile.write('\nunsigned char dspm[DSPM_SPAN] __attribute__((section(".dspm")));')

with open("%s/%s" % (GENERATED_DIRECTORY, COMPILE_SCRIPT), "w") as compileScript:
    compileScript.write(
        "%s -static -Wl,--section-start=.dspm=%x $1" % (COMPILER, int(constants["DSPM_START_ADDRESS"])))

os.system("chmod 755 %s/%s" % (GENERATED_DIRECTORY, COMPILE_SCRIPT))
