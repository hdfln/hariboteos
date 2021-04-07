void io_hlt(void);

void HariMain(void)
{
	// int i; /* 変数宣言。iという変数は、32ビットの整数型 */
	// char *p; /* pという変数は、BYTE [...]用の番地 */

	// for (i = 0xa0000; i <= 0xaffff; i++) {

	// 	p = (char *) i; /* 番地を代入 */
	// 	*p = i & 0x0f;

	// 	/* これで write_mem8(i, i & 0x0f); の代わりになる */
	// }

	// char *p;
	// for (p = (char *) 0xa0000; p <= (char *) 0xaffff; p++) {

	// 	// ポインタにANDは適用できないので一旦intにする
	// 	// ポインタの長さは32bitなので、intでなくcharにするとwarningが出る
	// 	*p = (char)((int) p & 0x0f);
	// }

	// int i;
	// for (i = 0xa0000; i <= 0xaffff; i++) {
	// 	// アセンブラにとってサイズがわからなくなってしまうので、ポインタ型にしか間接参照演算子 ( * ) は使えない
	// 	// invalid type argument of `unary *'
	// 	*i = i & 0x0f;
	// }

	int i;
	for (i = 0xa0000; i <= 0xaffff; i++) {
		*((char *) i) = i & 0x0f;
	}

	for (;;) {
		io_hlt();
	}
}
