#include <stdlib.h>
enum addressing_modes {
  A, ABS, ABS_X, ABS_Y, I, IMPL, IND, X_IND, IND_Y, REL, ZPG, ZPG_X, ZPG_Y
};

enum instructions {
  ADC, // Add with carry
  AND, // And (with accumulator)
  ASL, // Arithmetic shift left
  BCC, // Branch on carry clear
  BCS, // Branch on carry set
  BEQ, // Branch on equal (zero set)
};

struct processor_state {
  int A;
  int X;
  int Y;
  int PC;
  int SR;
  int SP;
};

int get_instruction(const char opcode) {
  return 0;
};

int get_addressing_mode(const char opcode) {
  return 0;
};

int dereference_argument(const char *memory, const int PC, const int addressing_mode, const struct processor_state state) {
  return 0;
}

int main(int argc, char **argv) {
  const int MEMORY_SIZE = 64 * 1024;
  char *memory = malloc(MEMORY_SIZE);
  struct processor_state state;

  while(1) {
    int opcode = memory[state.PC];
    int instruction = get_instruction(opcode);
    int addressing_mode = get_addressing_mode(opcode);
    int argument_value = dereference_argument(memory, state.PC, addressing_mode, state);

    // Initialize here

    switch(instruction) {
    default:
      exit(1);
    }
  }

  free(memory);
  return 0;
}
