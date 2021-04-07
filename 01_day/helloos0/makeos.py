
def main():
    with open("helloos_header.img", "rb") as f:
        binary = bytearray(f.read())
    binary += b"\x00" * (0x168000-len(binary))
    binary[0x1FE:0x203] = b"\x55\xAA\xF0\xFF\xFF"
    binary[0x1400:0x1403] = b"\xF0\xFF\xFF"
    with open("helloos.img", "wb") as f:
        f.write(binary)

if __name__ == "__main__":
    main()