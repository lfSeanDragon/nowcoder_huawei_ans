#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int can_send(int id, int n, ...)
{
	va_list valist;
	va_start(valist, n);

	printf("n:%d,id:%d\n", n, id);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", (uint8_t)va_arg(valist, int));
	}

	va_end(valist);

	return 0;
}

int main(void)
{
	can_send(1, 1, 1);
	can_send(1, 2, 1, 2);
}
