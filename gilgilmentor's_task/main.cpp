#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

uint32_t read_32bit_number(FILE* file) {
    uint32_t number;
    fread(&number, sizeof(number), 1, file);
    // 네트워크 바이트 순서로 저장된 경우,빅 엔디안으로 변환
    number = ntohl(number);
    return number;
}

int main() {
    char* binary1 = "thousand.bin";
    char* binary2 = "five-hundred.bin";

    FILE* file1 = fopen(binary1, "rb");
    FILE* file2 = fopen(binary2, "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    uint32_t number1 = read_32bit_number(file1);
    uint32_t number2 = read_32bit_number(file2);

    fclose(file1);
    fclose(file2);

    uint32_t total = number1 + number2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", number1,number1,number2,number2,total,total);

    return 0;
}

