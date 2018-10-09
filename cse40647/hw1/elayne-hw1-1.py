#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-1

import csv
import numpy as np
from scipy import stats
#import pandas as pd

score1 = [None]*150
score2 = [None]*150
score3 = [None]*150
score4 = [None]*150

with open('Dataset-film-data.csv') as film_data_file:
	film_data = csv.reader(film_data_file, delimiter=',')
	line_count = 0
	read_head = False
	for row in film_data:
		if not read_head:
			read_head = True
			continue
		else:
			score1[line_count] = float(row[1])
			score2[line_count] = float(row[2])
			score3[line_count] = float(row[3])
			score4[line_count] = float(row[4])
			line_count = line_count + 1

zscore1 = stats.zscore(score1)
zscore2 = stats.zscore(score2)
zscore3 = stats.zscore(score3)
zscore4 = stats.zscore(score4)

zscore1_max = max(zscore1)
zscore1_min = min(zscore1)
zscore2_max = max(zscore2)
zscore2_min = min(zscore2)
zscore3_max = max(zscore3)
zscore3_min = min(zscore3)
zscore4_max = max(zscore4)
zscore4_min = min(zscore4)

print('zscore1 | max: ' + str(zscore1_max) + '\tmin: ' + str(zscore1_min))
print('zscore2 | max: ' + str(zscore2_max) + '\tmin: ' + str(zscore2_min))
print('zscore3 | max: ' + str(zscore3_max) + '\tmin: ' + str(zscore3_min))
print('zscore4 | max: ' + str(zscore4_max) + '\tmin: ' + str(zscore4_min))

