#! /usr/bin/env python

import fnmatch
import filecmp
import random
import sys
import os

Usage ="""\033[1mUsage:
./{} \033[0m\033[91mcorewarv1 \033[92mcorewarv2 \033[94mchampion_directory \033[95mcycle_limit
\t\033[91mcorewarv1:\t\texperimental corewar program
\t\033[92mcorewarv2:\t\tcontrol corewar program
\t\033[94mchampion_directory:\tdirectory containing champions to be tested
\t\033[95mcycle_limit:\t\toptional number of cycles to run (10000 default)""".format(os.path.basename(__file__))

multi_tests = [
		"test/champs/championships/2014/srabah-m/littlepuppy.cor test/champs/championships/2014/dcohen/loose.cor test/champs/championships/2014/gbir/_.cor test/champs/slider2.cor",
		"test/champs/Octobre_Rouge_V4.2.cor test/champs/championships/2014/ldesgoui/_honeybadger.cor test/champs/championships/2014/gjestin/salamahenagalabadoun.cor",
		"test/champs/championships/2014/ldesgoui/_honeybadger.cor test/champs/championships/2014/gleger/Machine-gun.cor test/champs/jumper.cor",
		]

def init_files(corev1, corev2):
	open(corev1 + ".log","w").close()
	open(corev2 + ".log","w").close()
	open("unit_diff.log","w").close()
	
def main(argc, argv):
	error = 0
	if (argc >= 4):
		if (argc == 5):
			limit = int(argv[4])
		else:
			limit = 10000
		corev1 = argv[1]
		corev2 = argv[2]
		init_files(corev1, corev2)
		champ_list = create_champlist(argv[3])
		error = loop_list(corev1, corev2, champ_list, limit)
		error = error + loop_list(corev1, corev2, multi_tests, limit)
		total = len(champ_list) + len(multi_tests)
		print_grade(error, total)
	else:
		print(Usage)

def	loop_list(corev1, corev2, champ_list, limit):
	error = 0
	for champion in champ_list:
		fail_cycle = test_corewar(corev1, corev2, champion, limit)
		pa = 0
		if (fail_cycle != limit):
			pa = 1
			print("\033[9{}m{} Fails at:{}\033[0m".format(2 - pa, champion, fail_cycle))
		else:
			print("\033[9{}m{} Does not Fail ({} cycles ran)\033[0m".format(2 - pa, champion, fail_cycle))
		error = error + pa
	return (error)

#creates a list of all the champions in the current directory
def	create_champlist(direct):
	ret = []
	for root, dirnames, filenames in os.walk(direct):
		for filenames in fnmatch.filter(filenames, "*.cor"):
			ret.append(os.path.join(root, filenames))
	return (ret)

def test_corewar(v1, v2, champion, cycles):
	fail_at = find_divergence(v1, v2, cycles, champion)
	if (fail_at != cycles):
		if is_diff(v1, v2, fail_at, champion, 1):
			app_log(v1, v2, champion, fail_at)
		else:
			fail_at = cycles
	return (fail_at)

#appends the diff to the log file
def app_log(v1, v2, player, i):
	with open("unit_diff.log", "a") as diff:
		diff.write("< {}\n> {}\nplayers: {}\nFail at cycle: {}\n\n".format(v1, v2, player, i))
		os.system("diff -i {} {} >> unit_diff.log".format(v1 + ".log", v2 + ".log"))

#Checks to see if the output is different for i number of cycles returns true if they are different
def	is_diff(v1, v2, i, player_list, final_flag):
	command = "-d {} {}".format(i, player_list)
	out1 = run_corewar(v1, command)
	out2 = run_corewar(v2, command)
	if (out1 == out2):
		return 0
	elif final_flag == 1 and len(out1) == 0 or len(out2) == 0:
		return 0
	return 1

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

#binary search for the cycle count that starts the divergence
def find_divergence(v1, v2, cycles, player_list):
	start = 0
	end = cycles

	while (start < end):
		mid = (end - start) / 2 + start
		check = is_diff(v1, v2, mid, player_list, 0)
		color = 92
		if check == 1:
			color = 91
#		print("\033[{}mcheck: {} start: {} mid: {} end: {}\033[0m".format(color, check, start, mid, end)) #useful for seeing binary search in action
		if (check == 1):
			end = mid
		else:
			start = mid + 1
	return end

#print the final grade for the unit test
def print_grade(error, total):
	percent = (total - error) * 100  / total
	grade = 91
	if (percent == 100):
		grade = 92
	elif (percent > 75):
		grade = 93
	print("\033[1mFailed {} out of {} tests. Grade:\033[{}m{}\033[0m".format(error, total, grade, percent))
	with open("unit_diff.log", "a") as out:
		out.write("Failed {} out of {} tests. Grade:{}".format(error, total, percent))

main(len(sys.argv), sys.argv)
