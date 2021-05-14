static volatile int *uart = (int *)(void *)0x10010000;

#define UART_REG_TXFIFO 0x0

static int putchar(char ch)
{
    while (uart[UART_REG_TXFIFO] < 0);
    return uart[UART_REG_TXFIFO] = ch & 0xFF;
}

void main(void)
{
    const char *s = "RISCV: Show me the light\n";
    while (*s) putchar(*s++);
    while (1);
}
