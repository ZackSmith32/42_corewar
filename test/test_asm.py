#!/usr/bin/env python

import fnmatch
import sys
import os

Usage ="""\033[1mUsage:
./{} \033[0m\033[91masmv1 \033[92masmv2 \033[93mchampion_directory
\t\033[91masmv1:\t\texperimental assembler program
\t\033[92masmv2:\t\tcontrol assembler program
\t\033[93mchamp_directory:directory containing .s files""".format(os.path.basename(__file__))

def	main(argc, argv):
	if (argc == 4):
		if (argv[3] != '~' and argv[3] != '/'):
			direct1 = create_champions(argv[1], argv[3])
			direct2 = create_champions(argv[2], argv[3])
			diff_champions(direct1, direct2)
	elif (argc == 3):
		if (argv[2] != '~' and argv[2] != '/'):
			direct1 = create_champions(argv[1], argv[2])
	else:
		print(Usage)

def	diff_champions(direct1, direct2):
	direct1_list = create_ext_list(direct1, ".cor")
	direct2_list = create_ext_list(direct2, ".cor")
	list_len = len(direct1_list)
	if (list_len != len(direct2_list)):
		print("\033[91mError number of champions does not match\033[0m")
	else:
		for i in range(0, list_len):
			os.system("diff {} {} >> asm_diff.log".format(direct1_list[i], direct2_list[i]))
	

def create_champions(asm, direct):
	champ_dir = asm + "_champions"
	os.system("cp -rf {} {}".format(direct, champ_dir))
	champ_list = create_ext_list(champ_dir, ".s")
	for champ in champ_list:
		os.system("./{} {}".format(asm, champ))
	return (champ_dir)
	
def	create_ext_list(direct, extension):
	ret = []
	for root, dirnames, filenames in os.walk(direct):
		for filenames in fnmatch.filter(filenames, "*" + extension):
			ret.append(os.path.join(root, filenames))
	return (ret)

main(len(sys.argv), sys.argv)
