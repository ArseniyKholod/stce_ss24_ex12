set xlabel "Number of fountains"
set ylabel "time, s"
set title "Execution time comparison, fountain_-chain example"
set term wxt size 1000,500
set multiplot layout 1,2
plot "time.plt" using 1:2 title 'v2.5 with exception handling' with lines, \
     "../../../../../v2.5/apps/fountain_chain/time_measurements/time.plt" using 1:2 title 'v2.5 original' with lines
set xlabel "Number of fountains"
set ylabel "Relative time difference, %"
set title "Execution time difference, fountain_-chain example"
plot "time_difference.plt" using 1:2 title "Difference" with lines
unset multiplot
pause -1 "Close gnuplot window. "

