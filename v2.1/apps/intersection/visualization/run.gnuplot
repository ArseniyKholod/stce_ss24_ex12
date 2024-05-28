plot [-1:2] exp(-x/0.5), x**3-0.5
pause -1 "Close gnuplot window. "
splot [x=0:1][y=-1:1] sqrt((exp(x/-0.5)+y)**2+(x**3-0.5-y)**2), "newton_steps.plt" with linespoints
pause -1 "Close gnuplot window. "
