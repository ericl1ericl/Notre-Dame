#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-2-4

import csv
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

#score1 = [None]*150
#score2 = [None]*150
#score3 = [None]*150
#score4 = [None]*150
genres = (['ACTION', 'ROMANCE', 'COMEDY'])
actionx = []
actiony = []
romancex = []
romancey = []
comedyx = []
comedyy = []

with open('Dataset-film-data.csv') as film_data_file:
	film_data = csv.reader(film_data_file, delimiter=',')
	read_head = False
	for row in film_data:
		if not read_head:
			read_head = True
			continue
		else:
			if row[5] == 'ACTION':
				actionx.append(row[1])
				actiony.append(row[3])
			elif row[5] == 'ROMANCE':
				romancex.append(row[1])
				romancey.append(row[3])
			elif row[5] == 'COMEDY':
				comedyx.append(row[1])
				comedyy.append(row[3])

plt.scatter(actionx, actiony, c='b', marker='o', label='ACTION')
plt.scatter(romancex, romancey, c='r', marker='^', label='ROMANCE')
plt.scatter(comedyx, comedyy, c='g', marker='s', label='COMEDY')
plt.xlabel('Website 1 Scores')
plt.ylabel('Website 3 Scores')
plt.legend(loc='lower right')
plt.title('Scatter Plot of Movie Scores from Website 1 vs Website 3')
plt.show()
