splot [x_0=-5:5] [x_1=-5:5] 0.5*(0.68+x_0)**2+0.5*(-0.21+x_1)**2+0.2*(x_0-0.68)**4+0.2*(x_1+0.21)**4, "steps.plt" with lines
pause -1 "Close gnuplot window. "
