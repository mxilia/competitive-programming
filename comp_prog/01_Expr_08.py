#
# 01_Expr_08: 01_Cube_Root (Function) 
#

def sqrt_n_times(x, n):
    return x**(1/(2**n))


def cube_root(y):
    y1 = sqrt_n_times(y, 2)
    y2 = y1*sqrt_n_times(y1, 2)
    y3 = y2*sqrt_n_times(y2, 4)
    y4 = y3*sqrt_n_times(y3, 8)
    y5 = y4*sqrt_n_times(y4, 16)
    y6 = y5*sqrt_n_times(y5, 32)
    return y6


def main():
    q = float(input())
    print(cube_root(q))


exec(input()) # DON'T remove this line
