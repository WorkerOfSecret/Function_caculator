import math_func as mf
import matplotlib.pyplot as plt

if __name__ == '__main__':
    loop_time = 1000
    x1_l = {}
    x2_l = {}

    for x0_val in range(-100, 100):
        x1 = x2 = float(x0_val)
        all_x1_vals = []
        all_x2_vals = []

        for loop in range(loop_time):
            if mf.df1(x1) != 0:
                x1 -= (mf.f1(x1))/(mf.df1(x1))
            if mf.df2(x2) != 0:
                x2 -= (mf.f2(x2))/(mf.df2(x2))
            all_x1_vals.append(x1)
            all_x2_vals.append(x2)

        if x1 not in x1_l.keys(): 
            x1_l[x1] = all_x1_vals
        if x2 not in x2_l.keys(): 
            x2_l[x2] = all_x2_vals
    
    display_list = [x1_l, x2_l]
    
    for order, all_vals_list in enumerate(display_list):
        plt.figure(order)
        plt.title('all values of x'+str(order))
        for val_list in all_vals_list.values():
            plt.plot(val_list)
    plt.show()
