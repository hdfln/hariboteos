
# デフォルト動作

default :
	make img

# ファイル生成規則

ipl.bin : ipl.nas Makefile
	nasm -o ipl.bin -l ipl.lst ipl.nas

helloos.img : ipl.bin Makefile
	cp ipl.bin helloos.img
	truncate -s 1745460 helloos.img

# コマンド

asm :
	make -r ipl.bin

img :
	make -r helloos.img

run :
	make img
	qemu-system-i386 -drive file=helloos.img,index=0,if=floppy,format=raw -boot order=a

install :
	make img
	@echo "本当はフロッピーディスクに書き込む\tdd if=helloos.img of=/dev/fd0 bs=512 count=2880"

clean :
	rm -f ipl.bin
	rm -f ipl.lst

src_only :
	make clean
	rm -f helloos.img
