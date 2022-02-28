import matplotlib
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os
import sys

# data directory relative to the "scripting" folder
# assumes we run the script while in the scripting folder
data_filename="../data/times.csv"


def crunch_data(filename):
    # num_threads, num_random_points, pi_approximation, time_elapsed
    df = pd.read_csv(filename)
    plot_threads_to_time(df[['num_threads','num_random_points', 'time_elapsed']])


"""
Plot number of threads to the time elapsed. One line for each data size.
"""
def plot_threads_to_time(times_df):
    df = times_df[times_df["num_random_points"]==100000000][['num_threads', 'time_elapsed']]

    x = df['num_threads']
    y = df['time_elapsed']
    x_labels=[str(i) for i in x]
    y_labels=[i+1 for i in range(int(max(y))+1)]

    fix, ax = plt.subplots(1,1)
    ax.set_ylim(ymin=0)
    ax.set_yticks(y_labels)
    ax.set_yticklabels(y_labels)
    plt.xlabel('Number of Threads')
    plt.ylabel('Time Elapsed (seconds)')
    plt.plot(x_labels, y)
    matplotlib.pyplot.show()
    #fig.savefig("plot.pdf")


if __name__=="__main__":
    if len(sys.argv) > 1:
        data_filename = sys.argv[1]

    crunch_data(data_filename)