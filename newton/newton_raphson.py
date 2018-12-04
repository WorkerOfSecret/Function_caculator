import math_func as mf
import matplotlib.pyplot as plt
import sys

if __name__ == '__main__':
    order = int(sys.argv[1])
    loop_time = 1000
    x_l = {}
    func, d_func = mf.math_funcs_list[order]

    for x0_val in range(-100, 100):
        x0 = float(x0_val)
        all_x_vals = []

        for loop in range(loop_time):
            if d_func(x0) != 0:
                x0 -= (func(x0))/(d_func(x0))
            all_x_vals.append(x0)

        if x0 not in x_l.keys(): 
            x_l[x0] = all_x_vals
    
    plt.title('all values of x'+str(order))
    for val_list in x_l.values():
        plt.plot(val_list)
    plt.show()
