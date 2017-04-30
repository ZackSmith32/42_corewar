#!/bin/env python

import glob
import sys
import os

def	main(argv):
	asm = argv[1]
	direct = argv[2]
	champ_list = create_champlist(argv[2])
	for champ in champ_list:
		os.system("./{} {}".format(asm, champ))

def	create_champlist(direct):
	ret = glob.glob(direct + "/*/**/*.s")
	print(direct + "/*/**/*.s")
	print(ret)
	return (ret)
#	layer3 = glob.glob("{}/*/*/*/*.s".format(direct))
#	layer2 = glob.glob("{}/*/*.s".format(direct)) 
#	layer1 = glob.glob("{}/*.s".format(direct)) 
#	ret = layer3 + layer1 + layer2
	#return (os.listdir(direct))
	#champ_str = os.system("find {} | grep '\.s'".format(direct))
	#return (champ_str.split())

main(sys.argv)
