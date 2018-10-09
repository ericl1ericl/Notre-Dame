#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-2-5

import csv
import numpy as np
from scipy import stats
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

pp_x = sm.ProbPlot(score1, fit=True)
pp_y = sm.ProbPlot(score3, fit=True)
fig = pp_x.qqplot(line='45', other=pp_y)
plt.xlabel('Website 1 Quantiles')
plt.ylabel('Website 3 Quantiles')
plt.title('Q-Q Plot of Movie Scores from Website 1 vs Website 3')
plt.show()
