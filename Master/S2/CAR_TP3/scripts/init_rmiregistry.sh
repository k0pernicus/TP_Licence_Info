cd bin/
printf "rmic for SiteImpl...\t"
rmic rmi.rmi.SiteImpl
printf "Done!\n"
printf "rmiregistry called...\t"
rmiregistry &
printf "Done!\n"
