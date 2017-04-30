#!/bin/env python

import fnmatch
import filecmp
import random
import sys
import os


def main(argc, argv):
	error = 0
	if (argc >= 5):
		find_div = False
		if (argc > 5):
			find_div = True
		corev1 = argv[1]
		corev2 = argv[2] 
		total = int(argv[4])
		open(corev1 + ".log","w").close()
		open(corev2 + ".log","w").close()
		open("Failure.log","w").close()
		open("diff.log","w").close()
		champ_list = create_champlist(argv[3])
		for i in range(0, total):
			error = error + test_corewar(corev1, corev2, champ_list, i, find_div)
		percentage = ((total - error) * 100 / total)
		grade = 91
		if (percentage == 100):
			grade = 92
		elif (percentage > 75):
			grade = 93
		print("Times ran:{} Number of fails:\033[91m{}\033[0m Percentage passed:\033[{}m{}\033[0m".format(total, error, grade, percentage))
	else:
		print("\033[1mUsage\033[0m: python test_corewar.py \033[92mcorewar_v1 \033[91mcorewar_v2 \033[94mchampion_directory \033[95mnbr_tests\033[0m div_flag")

def	create_champlist(direct):
	ret = []
	for root, dirnames, filenames in os.walk(direct):
		for filenames in fnmatch.filter(filenames, "*.cor"):
			ret.append(os.path.join(root, filenames))
	return (ret)

def test_corewar(v1, v2, champ_list, iteration, find_div):
	nbr_player = random.randint(1, 4)
	cycles = random.randint(1, 10000)
	player_list = []
	i = 0
	while i < nbr_player:
		player_list.append(champ_list[random.randint(0, len(champ_list) - 1)])
		i = i + 1
	player_list = ' '.join(player_list)
	if is_diff(v1, v2, cycles, player_list):
		fail_at = "Did not search for cycle"
		if find_div:
			fail_at = find_divergence(v1, v2, cycles, player_list)
		with open("Failure.log", "a") as log:
			log.write("\033[1mFailed Test {}:\033[0m\ncycles: {}\nplayers: {}\nFail at cycle: {}\n\n".format(iteration, cycles, player_list, fail_at))
		print("\033[91m\033[1mTest {} failure\033[0m".format(iteration))
		return (1)
	return (0)

#runs corewar executable and returns a lowercase string of the output
def run_corewar(corewar, command_line):
	log = corewar + ".log"
	command = "./{} {} | grep 0x > {}".format(corewar, command_line, log)
	os.system(command)
	result = ""
	with open(log, "r") as out:
		result = out.read()
		out.close()
	return result.lower()

#Checks to see if the output is different for i number of cycles returns true if they are different
def	is_diff(v1, v2, i, player_list):
	command = "-d {} {}".format(i, player_list)
	out1 = run_corewar(v1, command)
	out2 = run_corewar(v2, command)
	if (out1 == out2):
		return 0
	with open("diff.log", "a") as diff:
		diff.write("\nPlayers: {}\nCycles: {}\n".format(player_list, i))
		os.system("diff -i {} {} >> diff.log".format(v1 + ".log", v2 + ".log"))
	return 1


#binary search for the cycle count that starts the divergence
def find_divergence(v1, v2, cycles, player_list):
	start = 0
	end = cycles

	while (start < end):
		mid = (end - start) / 2 + start
		check = is_diff(v1, v2, mid, player_list)
		color = 92
		if check == 1:
			color = 91
#		print("\033[{}mcheck: {} start: {} mid: {} end: {}\033[0m".format(color, check, start, mid, end)) #useful for seeing binary search in action
		if (check == 1):
			end = mid
		else:
			start = mid + 1
	return end
	
main(len(sys.argv), sys.argv)
