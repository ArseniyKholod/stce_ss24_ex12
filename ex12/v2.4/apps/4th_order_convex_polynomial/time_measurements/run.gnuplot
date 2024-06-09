set xlabel "Dimensions of objective"
set ylabel "time, s"
set title "Execution time comparison, 4th_-order_-convex_-polynomial example"
set term wxt size 1000,500
set multiplot layout 1,2
plot "time.plt" using 1:2 title 'v2.4 with exception handling' with lines, \
     "../../../../../v2.4/apps/4th_order_convex_polynomial/time_measurements/time.plt" using 1:2 title 'v2.4 original' with lines
set xlabel "Dimensions of objective"
set ylabel "Relative time difference, %"
set title "Execution time difference, 4th_-order_-convex_-polynomial example"
plot "time_difference.plt" using 1:2 title "Difference" with lines
unset multiplot
pause -1 "Close gnuplot window. "

