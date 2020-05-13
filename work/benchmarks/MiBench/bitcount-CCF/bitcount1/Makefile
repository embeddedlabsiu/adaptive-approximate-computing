FILE = bitcnt_1.c bitcnt_2.c bitcnt_3.c bitcnt_4.c bitcnts.c bitfiles.c bitstrng.c bstr_i.c 

bitcnts: ${FILE} Makefile
	#gcc -g -static ${FILE} -O3 -o bitcnts
	cgracc -O3 -static ${FILE}-o bitcnts

clean:
	rm -rf bitcnts output* *.ll m5out CGRAExec
