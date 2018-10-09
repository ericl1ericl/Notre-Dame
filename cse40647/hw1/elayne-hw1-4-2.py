#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-4-2

import csv
import numpy as np
from scipy import stats
import pandas as pd
from sklearn.decomposition import TruncatedSVD
import matplotlib.pyplot as plt

score1 = [None]*150
score2 = [None]*150
score3 = [None]*150
score4 = [None]*150
genres = [None]*150

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
			genres[line_count] = row[5]

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

svd = TruncatedSVD(algorithm='arpack', n_components=2)
principalComponents = svd.fit_transform(data)
principalDf = pd.DataFrame(data = principalComponents, columns = ['PC1', 'PC2'])

genresDf = pd.DataFrame({'genre': genres})

finalDf = pd.concat([principalDf, genresDf], axis=1)
#print(finalDf)

print('Singular Values:')
print(svd.fit(data).singular_values_)

actionx = []
actiony = []
romancex = []
romancey = []
comedyx = []
comedyy = []
for index, line in finalDf.iterrows():
	if line['genre'] == 'ACTION':
		actionx.append(line['PC1'])
		actiony.append(line['PC2'])
	elif line['genre'] == 'ROMANCE':
		romancex.append(line['PC1'])
		romancey.append(line['PC2'])
	elif line['genre'] == 'COMEDY':
		comedyx.append(line['PC1'])
		comedyy.append(line['PC2'])

plt.scatter(actionx, actiony, c='b', marker='o', label='ACTION')
plt.scatter(romancex, romancey, c='r', marker='^', label='ROMANCE')
plt.scatter(comedyx, comedyy, c='g', marker='s', label='COMEDY')
plt.xlabel('Vector 1')
plt.ylabel('Vector 2')
plt.legend(loc='upper right')
plt.title('SVD of Movie Scores by Genres from Different Ratings')
plt.show()


