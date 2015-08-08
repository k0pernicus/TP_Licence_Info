set term png;
set xrange [0:100];
set yrange[0:10];
set output 'comparaisons_q16.png';
plot 'cas6.txt' using 1:2 title 'param=5.0' with lines, \
'cas6.txt' using 1:3 title 'param=2.0' with lines, \
'cas6.txt' using 1:4 title 'param=1.5' with lines, \
'cas6.txt' using 1:5 title 'param=1.25' with lines, \
'cas6.txt' using 1:6 title 'param=1.1' with lines, \
'cas6.txt' using 1:7 title 'param=1.0' with lines;