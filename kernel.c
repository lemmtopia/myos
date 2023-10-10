char *vidmem;

void kprintf(char* text, int size);
void kclear();

int z;

void kernel_main() {
	vidmem = (char*)0xb8000;
	kclear();
	kprintf("Hello from lemmtopia!", 21);
	return;
}

void kclear() {
	for (int i = 0; i < 2 * 80 * 24; i += 2) {
		vidmem[i] = ' ';
		vidmem[i + 1] = 0x07;
	}
}

void kprintf(char* text, int size) {
	for (int i = 0; i < size; i++) {
		vidmem[z + i * 2] = text[i];
		vidmem[z + i * 2 + 1] = 0x07;
	}
	z += size;
	return;
}
