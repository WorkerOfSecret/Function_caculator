def f0(x):
    return x**2 - 3*x + 2

def df0(x):
    return 2*x - 3

def f1(x):
    return x**3 + x**2 - x + 2

def df1(x):
    return 3*x**2 + 2*x - 1 

def f2(x):
    return x**2 + 4*x + 4

def df2(x):
    return 2*x + 4

def f3(x):
    return (x + 4)**4

def df3(x):
    return 4 * (x + 4)**3

def f4(x):
    return (2*x**2 + 3*x + 1)**3

def df4(x):
    return 3 * (2*x**2 + 3*x + 1)**2 * (4*x + 3)

math_funcs_list = [(f0, df0), (f1, df1), (f2, df2), (f3, df3), (f4, df4)]
