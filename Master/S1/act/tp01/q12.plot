set term png;
set output 'comparaisons_q12_v1.png';
plot 'cas4.txt' using 1:2 title 'refLog' with lines, \
'cas4.txt' using 1:3 title 'refNpK' with lines, \
'cas4.txt' using 1:4 title 'refNlogn' with lines, \
'cas4.txt' using 1:5 title 'refExp' with lines, \
'cas4.txt' using 1:6 title 'refKpN' with lines;

set term png;
set output 'comparaisons_q12_v4.png';
plot 'cas4.txt' using 1:5 title 'refExp' with lines, \
'cas4.txt' using 1:6 title 'refKpN' with lines;

set term png;
set xrange [0:500000];
set yrange[0:200000000];
set output 'comparaisons_q12_v2.png';
plot 'cas4.txt' using 1:2 title 'refLog' with lines, \
'cas4.txt' using 1:3 title 'refNpK' with lines, \
'cas4.txt' using 1:4 title 'refNlogn' with lines, \
'cas4.txt' using 1:5 title 'refExp' with lines, \
'cas4.txt' using 1:6 title 'refKpN' with lines;

set term png;
set xrange [0:50];
set output 'comparaisons_q12_v3.png';
plot 'cas4.txt' using 1:2 title 'refLog' with lines, \
'cas4.txt' using 1:3 title 'refNpK' with lines, \
'cas4.txt' using 1:4 title 'refNlogn' with lines, \
'cas4.txt' using 1:5 title 'refExp' with lines, \
'cas4.txt' using 1:6 title 'refKpN' with lines;
