set term png;
set output 'comparaisons_q09.png';
plot 'cas3.txt' using 1:2 title 'minimumSimpleT' with lines, \
'cas3.txt' using 1:3 title 'minimumSimpleL' with lines, \
'cas3.txt' using 1:4 title 'minimumTriT' with lines, \
'cas3.txt' using 1:5 title 'minimumTriL' with lines;