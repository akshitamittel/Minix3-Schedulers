Priority


Change the following files:
/usr/src/servers/schedule.c

cp /mnt/shared/Priority/schedule.c /usr/src/servers/sched/schedule.c


To run the scheduler:
	in /usr/src/lib/libc/
		# make
		# make install
	in /usr/src/include/minix/
		# make 
		# make install
	in /usr/src/servers/pm
		# make
		# make install
	in /usr/src/servers/sched
		# make
		# make install

go to /usr/src
	# make clean
	# make build
	# make install


	# reboot

In order to test it we do the following:
In the shared folder:
cc longrun0.c -o longrun0
cc mytest.c -o mytest
./mytest