#!/usr/bin/env python

import fnmatch
import sys
import os

def	main(argv):
	if (argv[1] and argv[2]):
		asm = argv[1]
		direct = argv[2]
		champ_list = create_champlist(argv[2])
		for champ in champ_list:
			os.system("./{} {}".format(asm, champ))
	else:
		print("Usage: python test_asm.py asm directory")

def	create_champlist(direct):
	ret = []
	for root, dirnames, filenames in os.walk(direct):
		for filenames in fnmatch.filter(filenames, "*.s"):
			ret.append(os.path.join(root, filenames))
	return (ret)

main(sys.argv)
