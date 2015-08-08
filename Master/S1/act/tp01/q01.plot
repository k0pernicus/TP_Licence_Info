set term png;
set output 'comparaisons_AleaT_AleaL.png';
plot 'cas1.txt' using 1:2 title 'aleaT noRep' with lines, \
'cas1.txt' using 1:3 title 'aleaL noRep' with lines, \
'cas1.txt' using 1:4 title 'aleaT Rep' with lines, \
'cas1.txt' using 1:5 title 'aleaL Rep' with lines;