#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-2-6

import csv
import numpy as np
from scipy import stats
from scipy.stats import entropy
import matplotlib.pyplot as plt
import statsmodels.api as sm

#score1 = [None]*150
#score2 = [None]*150
#score3 = [None]*150
#score4 = [None]*150
#genres = (['ACTION', 'ROMANCE', 'COMEDY'])
score1 = np.empty(150)
score3 = np.empty(150)

with open('Dataset-film-data.csv') as film_data_file:
	film_data = csv.reader(film_data_file, delimiter=',')
	read_head = False
	line_num = 0
	for row in film_data:
		if not read_head:
			read_head = True
			continue
		else:
			score1[line_num] = float(row[1])
			score3[line_num] = float(row[3])
			line_num = line_num + 1

print('KL Divergence of 1 compared to 3: ' + str(entropy(score1,score3)))
print('KL Divergence of 3 compared to 1: ' + str(entropy(score3,score1)))
