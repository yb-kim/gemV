class GlobalSpmConfig:
    startAddress = 0x00100000
    size = 4096

    @staticmethod
    def getEndAddress():
        return GlobalSpmConfig.startAddress + GlobalSpmConfig.size - 1
