#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-2-3

import csv
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

#score1 = [None]*150
#score2 = [None]*150
#score3 = [None]*150
#score4 = [None]*150
genres = (['ACTION', 'ROMANCE', 'COMEDY'])

with open('Dataset-film-data.csv') as film_data_file:
	film_data = csv.reader(film_data_file, delimiter=',')
	line_count = 0
	action_sum = 0.00
	action_ct = 0.00
	romance_sum = 0.00
	romance_ct = 0.00
	comedy_sum = 0.00
	comedy_ct = 0.00
	read_head = False
	for row in film_data:
		if not read_head:
			read_head = True
			continue
		else:
			#score1[line_count] = float(row[1])
			#score2[line_count] = float(row[2])
			#score3[line_count] = float(row[3])
			#score4[line_count] = float(row[4])
			if row[5] == 'ACTION':
				action_sum = action_sum + float(row[1])
				action_ct = action_ct + 1
			elif row[5] == 'ROMANCE':
				romance_sum = romance_sum + float(row[1])
				romance_ct = romance_ct + 1
			elif row[5] == 'COMEDY':
				comedy_sum = comedy_sum + float(row[1])
				comedy_ct = comedy_ct + 1
			line_count = line_count + 1

data = [float(action_sum/action_ct), float(romance_sum/romance_ct), float(comedy_sum/comedy_ct)]
plt.bar([1,2,3], data)
plt.xticks([1,2,3], genres)
plt.xlabel('Genres')
plt.ylabel('Average of Website 1 Scores')
plt.title('Bar Chart of Website 1 Movie Rating Averages by Genre')
plt.show()
