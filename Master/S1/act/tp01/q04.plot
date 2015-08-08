set term png;
set output 'comparaisons_RechercheT_RechercheL.png';
plot 'cas2.txt' using 1:2 title 'rechercheT noRep' with lines, \
'cas2.txt' using 1:3 title 'rechercheL noRep' with lines, \
'cas2.txt' using 1:4 title 'rechercheT Rep' with lines, \
'cas2.txt' using 1:5 title 'rechercheL Rep' with lines;