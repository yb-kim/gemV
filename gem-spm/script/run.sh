gemV_home=/home/ybkim/workspace/gemV
script_home=$gemV_home/gem-spm/script
out_dir=$script_home/matmul_spm
debug_flags=Spm
#program=gem-spm/include/generated/a.out
#program=gem-spm/bench/spm_ver/basicmath/basicmath_small
#program=gem-spm/bench/mibench/automotive/basicmath/basicmath_small
#program=gem-spm/bench/matmul/a.out
program=gem-spm/bench/spm_ver/matmul/matmul
nCores=1
cd $gemV_home
scons $gemV_home/build/ARM/gem5.debug && $gemV_home/build/ARM/gem5.debug --outdir=$out_dir -r --debug-flags=$debug_flags --debug-file=debug.txt $gemV_home/configs/example/se.py -c $gemV_home/$program --cpu-type="arm_detailed" --caches -n $nCores --use-spms
