#!/bin/env python

import fnmatch
import filecmp
import random
import sys
import os


def main(argv):
	error = 0
	if (len(argv) == 5):
		corev1 = argv[1]
		corev2 = argv[2] 
		total = int(argv[4])
		open(corev1 + ".log","w").close()
		open(corev2 + ".log","w").close()
		champ_list = create_champlist(argv[3])
		for i in range(0, total):
			error = error + test_corewar(corev1, corev2, champ_list, i)
		percentage = ((total - error) / total) * 100
		grade = 91
		if (percentage == 100):
			grade = 92
		elif (percentage > 75):
			grade = 93
		print("Times ran:{} Number of fails:\033[91m{}\033[0m Percentage passed:\033[{}m{}\033[0m".format(total, error, grade, percentage))
	else:
		print("\033[1mUsage\033[0m: python test_corewar.py \033[92mcorewar_v1 \033[91mcorewar_v2 \033[94mchampion_directory \033[95mnbr_tests\033[0m")

def	create_champlist(direct):
	ret = []
	for root, dirnames, filenames in os.walk(direct):
		for filenames in fnmatch.filter(filenames, "*.cor"):
			ret.append(os.path.join(root, filenames))
	return (ret)

def test_corewar(v1, v2, champ_list, iteration):
	nbr_player = random.randint(1, 4)
	cycles = random.randint(1, 10000)
	player_list = []
	i = 0
	while i < nbr_player:
		player_list.append(champ_list[random.randint(0, len(champ_list) - 1)])
		i = i + 1
	player_list = ' '.join(player_list)
	out1 = execute_corewar(v1, "-d", cycles, player_list, iteration)
	out2 = execute_corewar(v2, "-d", cycles, player_list, iteration)
	if not out1 == out2:
		print("\033[91m\033[1mTest {} failure\033[0m".format(iteration))
		return (1)
	return (0)

def execute_corewar(corewar, flags, cycles, arguments, iteration):
	log = corewar + ".log"
	command = "./{} {} {} {} | grep 0x >> {}".format(corewar, flags, cycles, arguments, log)
	with open(log, "a") as header:
		header.write("Test {}\ncycles: {}\nplayers: {}\n".format(iteration, cycles, iteration))
	print("Test: \033[96m{}\033[0m {}".format(iteration, command))
	os.system(command)
	with open(log, "r") as out:
		result = out.read()
	return result.lower()

main(sys.argv)
