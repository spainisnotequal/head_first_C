hfcal.o: hfcal.c
	gcc -I./includes -fPIC -c hfcal.c -o hfcal.o

elliptical.o: elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o

libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o ./libs/libhfcal.so

elliptical: elliptical.o libhfcal.so
	gcc elliptical.o -L./libs -lhfcal -o elliptical
