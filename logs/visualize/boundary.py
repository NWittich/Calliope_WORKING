import csv
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

labels = { 
    "2" : "red", #high visibility point marker
    "1" : "#eb8034",  #green dot
    "-1" : "#348ceb", #blue dot
    }

def readLog(fileHandler, csvReader):
    fileHandler.seek(0)
    next(csvReader, None)
    logpoints = []
    for row in csvReader:
        slope = float(row[3])
        intercept = float(row[4])
        logpoints.append([slope, intercept])
    return logpoints

def readData(fileHandler, csvReader):
    fileHandler.seek(0)
    datapoints = []
    for row in csvReader:
        x = float(row[1])
        y = float(row[2])
        label = row[3]
        datapoints.append([x, y, label])
    return datapoints

def plotFigure(point,i,datapoints):
    y = point[0] * x + point[1]
    fig = plt.figure(i)
    ax = fig.add_subplot()
    ax.spines['left'].set_position('zero')
    ax.spines['bottom'].set_position('zero')
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.set_aspect('equal','box')
    ax.set_xlim(0, 8)
    ax.set_ylim(0, 5)
    ax.xaxis.set_major_locator(ticker.MultipleLocator(1))
    ax.yaxis.set_major_locator(ticker.MultipleLocator(1))
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')
    ax.spines['bottom'].set_color('#868686')
    ax.spines['top'].set_color('#868686') 
    ax.spines['right'].set_color('#868686')
    ax.spines['left'].set_color('#868686')
    ax.tick_params(axis='x', colors='#868686')
    ax.tick_params(axis='y', colors='#868686')
    k = 2
    for data in datapoints:
        color=labels.get(data[2])
        plt.scatter([data[0]],[data[1]],c=color,s=3,marker='o')
        plt.text(data[0], data[1], str(k), color=color, fontsize=5)
        k = k + 1
    plt.plot(x,y,'#eb343d',linewidth=1)
    fig.savefig('frames/%04d.png'%i, format='png',bbox_inches='tight',dpi=200)
    plt.close()


logFile = open('logfile.csv')
logReader = csv.reader(logFile, delimiter=';');
logpoints = readLog(logFile, logReader);

dataFile = open('datafile.csv')
dataReader = csv.reader(dataFile, delimiter=';')
datapoints = readData(dataFile, dataReader)

x = np.linspace(0,8,2)
i = 0

for log in logpoints:
    plotFigure(log,i,datapoints)    
    i = i + 1
