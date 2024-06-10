set xlabel "x"
set ylabel "y"
plot [x=0:4] (-sin(x)+cos(x))/exp(x), "steps.plt" with lines
pause -1 "Close gnuplot window. "
