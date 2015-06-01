gemV_home=/home/ybkim/workspace/gemV
script_home=$gemV_home/gem-spm/script
out_dir=$script_home/m5out
debug_flags=Spm
program=gem-spm/include/generated/a.out
nCores=1
cd $gemV_home
scons $gemV_home/build/ARM/gem5.debug && $gemV_home/build/ARM/gem5.debug --outdir=$out_dir --debug-flags=$debug_flags --debug-file=debug.txt $gemV_home/configs/example/se.py -c $gemV_home/$program --cpu-type="arm_detailed" --caches -n $nCores --use-spms
