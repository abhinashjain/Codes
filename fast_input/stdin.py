#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

def main():
	first_in = stdin.readline()
	thing = first_in.split()
	n = int(thing[0])
	k = int(thing[1])
	total = 0

	list = stdin.readlines()
	for item in list:
		if int(item) % k == 0:
			total += 1

	stdout.write(str(total)+"\n")

if __name__ == "__main__":
	main()
