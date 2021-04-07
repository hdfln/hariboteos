MAKE     = make -r
NASK     = nasm
COPY     = cp
DEL      = rm -f

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

ipl.bin : ipl.nas Makefile
	$(NASK) ipl.nas -o ipl.bin -l ipl.lst

haribote.img : ipl.bin Makefile
	cp ipl.bin haribote.img
	truncate -s 1745460 haribote.img

# コマンド

asm :
	$(MAKE) ipl.bin


img :
	$(MAKE) haribote.img
	qemu-system-i386 -drive file=haribote.img,index=0,if=floppy,format=raw -boot order=a

run :
	$(MAKE) img

install :
	$(MAKE) img
	@echo "本当はフロッピーディスクに書き込む\tdd if=haribote.img of=/dev/fd0 bs=512 count=2880"

clean :
	-$(DEL) ipl.bin
	-$(DEL) ipl.lst

src_only :
	$(MAKE) clean
	-$(DEL) haribote.img
