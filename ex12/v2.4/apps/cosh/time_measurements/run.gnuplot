set xlabel "Dimensions of objective"
set ylabel "time, s"
set title "Execution time comparison, cosh example"
plot "time.plt" using 1:2 title 'v2.4 with exception handling' with lines, \
     "../../../../../v2.4/apps/cosh/time_measurements/time.plt" using 1:2 title 'v2.4 original' with lines
pause -1 "Close gnuplot window. "

