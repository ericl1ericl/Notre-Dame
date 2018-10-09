#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-3-1

import csv
import numpy as np
from scipy import stats
import pandas as pd

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

#zscore1 = stats.zscore(score1)
#zscore2 = stats.zscore(score2)
#zscore3 = stats.zscore(score3)
#zscore4 = stats.zscore(score4)

data = pd.DataFrame(
	{'score1': score1,
	'score2': score2,
	'score3': score3,
	'score4': score4})
output = data.cov()

print(output)
