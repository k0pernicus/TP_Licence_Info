set term png;
set output 'comparaisons_q14.png';
plot 'cas5.txt' using 1:2 title 'param=2.0' with lines, \
'cas5.txt' using 1:3 title 'param=1.0' with lines, \
'cas5.txt' using 1:4 title 'param=0.5' with lines, \
'cas5.txt' using 1:5 title 'param=0.2' with lines, \
'cas5.txt' using 1:6 title 'param=0.1' with lines;