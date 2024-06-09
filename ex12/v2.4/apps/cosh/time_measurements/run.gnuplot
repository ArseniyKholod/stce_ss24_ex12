set xlabel "Dimensions of objective"
set ylabel "time, s"
set title "Execution time comparison, cosh example"
set term wxt size 1000,500
set multiplot layout 1,2
plot "time.plt" using 1:2 title 'v2.4 with exception handling' with lines, \
     "../../../../../v2.4/apps/cosh/time_measurements/time.plt" using 1:2 title 'v2.4 original' with lines
set xlabel "Dimensions of objective"
set ylabel "Relative time difference, %"
set title "Execution time difference, cosh example"
plot "time_difference.plt" using 1:2 title "Difference" with lines
unset multiplot
pause -1 "Close gnuplot window. "

