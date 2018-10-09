#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-2-1

import csv
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

score1 = [None]*150
#score2 = [None]*150
#score3 = [None]*150
#score4 = [None]*150

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
			#score2[line_count] = float(row[2])
			#score3[line_count] = float(row[3])
			#score4[line_count] = float(row[4])
			line_count = line_count + 1

plt.boxplot(score1, 0, 'rs', 0)
plt.xlabel('Score')
plt.title('Boxplot of Website 1 Movie Ratings')
plt.show()
