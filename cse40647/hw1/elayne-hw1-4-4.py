#!/usr/bin/env python2.7

# Eric Layne
# CSE40647
# hw1-4-4

import csv
import numpy as np
from scipy import stats
import pandas as pd
from sklearn.decomposition import PCA
from sklearn.preprocessing import normalize
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

zscore1 = stats.zscore(score1)
zscore2 = stats.zscore(score2)
zscore3 = stats.zscore(score3)
zscore4 = stats.zscore(score4)

data = pd.DataFrame(
	{'score1': zscore1,
	'score2': zscore2,
	'score3': zscore3,
	'score4': zscore4})

pca = PCA(n_components=2)
principalComponents = pca.fit_transform(data)
principalDf = pd.DataFrame(data = principalComponents, columns = ['PC1', 'PC2'])

genresDf = pd.DataFrame({'genre': genres})

finalDf = pd.concat([principalDf, genresDf], axis=1)
#print(finalDf)

u = data / np.linalg.norm(data)
#print(u)
for i in range(0,1):
	v = u*(np.transpose(data))
	v = normalize(v)
	u = normalize(np.matmul(data,v))
print(u)
print(v)
