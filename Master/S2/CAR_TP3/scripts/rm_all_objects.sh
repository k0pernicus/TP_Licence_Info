printf "Kill rmiregistry process...\t"
kill `ps -ef | grep usr/bin/rmiregistry | awk '{print $2}'` > /dev/null 2>&1
printf "Done!\n"

printf "Kill all node process...\t"
kill `ps -ef | grep "java rmi.main" | awk '{print $2}'` > /dev/null 2>&1
printf "Done!\n"
