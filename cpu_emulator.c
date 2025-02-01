#include <stdio.h>
#include <stdint.h>

#define MEMORY_SIZE 1024

typedef struct {
    uint8_t memory[MEMORY_SIZE];  // Emulated memory
    uint16_t pc;                  // Program Counter
    uint8_t reg_a;                // General-purpose register A
    uint8_t reg_b;                // General-purpose register B
} CPU;

void cpu_init(CPU *cpu) {
    cpu->pc = 0;
    cpu->reg_a = 0;
    cpu->reg_b = 0;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        cpu->memory[i] = 0;
    }
}

uint8_t fetch(CPU *cpu) {
    return cpu->memory[cpu->pc++];
}

void execute(CPU *cpu, uint8_t instruction) {
    switch (instruction) {
        case 0x01:  // LOAD_A
            cpu->reg_a = cpu->memory[cpu->pc++];
            break;
        case 0x02:  // LOAD_B
            cpu->reg_b = cpu->memory[cpu->pc++];
            break;
        case 0x03:  // ADD
            cpu->reg_a += cpu->reg_b;
            break;
        case 0x04:  // STORE_A
            cpu->memory[cpu->memory[cpu->pc++]] = cpu->reg_a;
            break;
        case 0xFF:  // HALT
            printf("HALT\n");
            break;
        default:
            printf("Unknown instruction: %02X\n", instruction);
            break;
    }
}

int main() {
    CPU cpu;
    cpu_init(&cpu);

    // Load a simple program into memory
    cpu.memory[0] = 0x01;  // LOAD_A
    cpu.memory[1] = 0x10;  // Value to load into A
    cpu.memory[2] = 0x02;  // LOAD_B
    cpu.memory[3] = 0x20;  // Value to load into B
    cpu.memory[4] = 0x03;  // ADD
    cpu.memory[5] = 0x04;  // STORE_A
    cpu.memory[6] = 0x00;  // Address to store A
    cpu.memory[7] = 0xFF;  // HALT

    // Run the emulator
    while (1) {
        uint8_t instruction = fetch(&cpu);
        execute(&cpu, instruction);
        if (instruction == 0xFF) break;  // HALT
    }

    // Print the result
    printf("Result: %d\n", cpu.memory[0]);

    return 0;
}
