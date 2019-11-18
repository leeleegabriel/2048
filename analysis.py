
import numpy as np
import matplotlib.pyplot as plt 
import pandas as pd

def getStats(file):
	runtimes = np.array([])
	scores =  np.array([])
	with open(file, 'r') as f:
		for line in f.readlines():
			if ("best: " in line):
				runtimes = np.append(runtimes, float(line.replace("best: ", "")))
			elif ("score: " in line):
				scores = np.append(scores, int(line.replace("score: ", "")))
			else:
				print(line)
	return runtimes, scores

def getDataFrame(x, y, x_name, y_name):
	scores = pd.Series(x, name=x_name)
	path_size = pd.Series(y, name=y_name)
	return pd.concat([path_size, scores], axis=1)


def getCSV(benchmarks):
	runtimes, scores = getStats(benchmarks[0] + '.txt')
	df = getDataFrame([int(benchmarks[0])]*len(scores), scores, 'path_size', 'score')
	for bench in benchmarks[1:]:
		runtimes, scores = getStats(bench + '.txt')
		test = getDataFrame([int(bench)]*len(scores), scores, 'path_size', 'score')
		df = pd.concat([df, test], axis=0)
	df.to_csv('scores.csv')

#benchmarks = ['100', '1000', '10000', '25000']	
#getCSV(benchmarks)

df = pd.read_csv('scores.csv').drop(axis=0, columns='index')
#df.plot(kind='scatter', x='path size', y='scores', color='red')
plt.scatter(df.path_size, df.score, s=10)
plt.show()


