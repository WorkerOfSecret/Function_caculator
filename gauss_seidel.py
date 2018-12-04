import sys
import matplotlib.pyplot as plt
import numpy as np

rows = int(sys.argv[1])
time_loop = int(sys.argv[2])

def get_A_arrays():
    print ("Input A arrays:")
    list = []
    for num in range(rows):
        list.append(map(float,raw_input().split(' ')))
    return list


def get_b_arrays():
    list = []
    print("Input b arrays:")
    for vari in range(rows):
        list.append(input()) 
    return list


def split_A_arrays(A):
    up = np.zeros((rows, rows))
    low = A.copy()

    for row in range(len(A_arrays)):
        up[row, (row+1):], low[row, (row+1):] = low[row, (row+1):], 0

    return up, low


def gauss_seidel(b, upper, lower, var):
    T = np.matmul(np.linalg.inv(lower), upper)
    C = np.matmul(np.linalg.inv(lower), b)
    return np.matmul(-T, var) + C


def make_plot_list():
    list = []
    for time in range(rows):
        list.append([]) 
    return list


def add_val_to_plot(list, var):
    for row in range(rows):
        list[row].append(var[row,0])


def graph(p_list):
    for list in p_list:
        plt.plot(list)
    plt.show()


def diagonally_dominant_matrix(A):
    for order, row in enumerate(A):
        if (abs(A[order, order]) < (sum([abs(val) for val in row]) - abs(A[order, order]))):
            return False 
    return True


def convergence_cond(A):
    if (False not in (A == A.T[0])) or diagonally_dominant_matrix(A):
        plt.title('Convergence')
    else:
        plt.title('Divergence')


if __name__ == '__main__':
    A_arrays = np.array(get_A_arrays())
    b_arrays = np.array(get_b_arrays()).reshape(rows,1)
    variable = np.ones((rows,1))
    upper_A, lower_A = split_A_arrays(A_arrays)
    plot_list = make_plot_list()

    print A_arrays.T

    for time in range(time_loop):
        variable = gauss_seidel(b_arrays, upper_A, lower_A, variable)
        add_val_to_plot(plot_list, variable)

    convergence_cond(A_arrays)
    graph(plot_list)
