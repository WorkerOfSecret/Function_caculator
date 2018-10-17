import sys
import matplotlib.pyplot as pyplot
import numpy as np

rows = int(sys.argv[1])

def sample(x1, x2, x3):
    x1 = (10.0 - x2 - x3)/5.0
    x2 = (12.0 - x1 - x3)/4.0
    x3 = ( 13.0 - 2.0*x1 - x2)/3.0
    return x1, x2, x3

def sample1():
    x1 = x2 = x3 = 10.0
    list1 = []
    list2 = []
    list3 = []

    for i in range(20):
        list1.append(x1)
        list2.append(x2)
        list3.append(x3)

        x1, x2, x3 = sample(x1, x2, x3)
    
    pyplot.plot(list1, 'blue', list2, 'red', list3, 'green')
    pyplot.show()

def get_covariance(arrays):
    for row_array in arrays:
        for col_vari in len(row_array):
            pass

def get_A_arrays():
    print ("Input A arrays:\n")
    list = []
    for num in range(rows):
        list.append(map(float,raw_input().split(' ')))
    return list

def get_b_arrays():
    list = []
    print("Input b arrays:\n")
    for vari in range(rows):
        list.append(input()) 
    return list

if __name__ == '__main__':
    A_arrays = np.array(get_A_arrays())
    b_arrays = np.array(get_b_arrays())
    variable = np.zeros((rows,1))
