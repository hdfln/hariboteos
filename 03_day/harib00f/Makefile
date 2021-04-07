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

haribote.sys : haribote.nas Makefile
	$(NASK) haribote.nas -o haribote.sys -l haribote.lst

haribote.img : ipl.bin haribote.sys Makefile
	mformat -f 1440 -B ipl.bin -C -i haribote.img ::
	mcopy haribote.sys -i haribote.img ::

# コマンド

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	qemu-system-i386 -drive file=haribote.img,index=0,if=floppy,format=raw -boot order=a

install :
	$(MAKE) img
	@echo "本当はフロッピーディスクに書き込む\tdd if=haribote.img of=/dev/fd0 bs=512 count=2880"

clean :
	-$(DEL) ipl.bin
	-$(DEL) ipl.lst
	-$(DEL) haribote.sys
	-$(DEL) haribote.lst

src_only :
	$(MAKE) clean
	-$(DEL) haribote.img
