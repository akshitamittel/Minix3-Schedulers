MFQ

Change the following files:
/usr/src/servers/sched/schedule.c
/usr/src/servers/sched/schedproc.h
/usr/src/include/minix/config.h

cp /mnt/shared/MFQ/schedule.c /usr/src/servers/sched/schedule.c
cp /mnt/shared/MFQ/schedproc.h /usr/src/servers/sched/schedproc.h
cp /mnt/shared/MFQ/config.h  /usr/src/include/minix/config.h

To run the scheduler:
	in /usr/src/include/minix/
		# make 
		# make install
	in /usr/src/servers/sched
		# make
		# make install

Then, go to /usr/src
	# make clean
	# make build
	# make install

Then,
	# reboot


To test the algorithm
This can be done within the shared folder. 
cc test.c -o test
./test