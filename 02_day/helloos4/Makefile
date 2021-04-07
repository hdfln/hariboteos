ipl.bin : ipl.nas Makefile
	nasm -o ipl.bin -l ipl.lst ipl.nas

helloos.img : ipl.bin Makefile
	cp ipl.bin helloos.img
	truncate -s 1745460 helloos.img

img :
	make -r helloos.img

run :
	make -r img
	qemu-system-i386 -drive file=helloos.img,index=0,if=floppy,format=raw -boot order=a
