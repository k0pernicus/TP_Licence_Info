if ! ps -ef | grep "[r]miregister"
  then ./scripts/init_rmiregistry.sh
  sleep 0.5
fi

cd bin/

for i in {1..6}
do
  printf "Initialization of node%d\t" $i
  java rmi.main.SiteInitializer $i &
  sleep 0.2
  printf "Done!\n"
done

printf "Connection between node 1 and 2...\t"
java rmi.main.InitConnectionMain 1 2
printf "Done!\n"
sleep 0.2
printf "Connection between node 2 and 3...\t"
java rmi.main.InitConnectionMain 2 3
printf "Done!\n"
sleep 0.2
printf "Connection between node 2 and 4...\t"
java rmi.main.InitConnectionMain 2 4
printf "Done!\n"
sleep 0.2
printf "Connection between node 1 and 5...\t"
java rmi.main.InitConnectionMain 1 5
printf "Done!\n"
sleep 0.2
printf "Connection between node 5 and 6...\t"
java rmi.main.InitConnectionMain 5 6
printf "Done!\n"
sleep 0.2
