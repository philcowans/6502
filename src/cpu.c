#include <stdlib.h>
enum addressing_modes {
  A, ABS, ABS_X, ABS_Y, I, IMPL, IND, X_IND, IND_Y, REL, ZPG, ZPG_X, ZPG_Y, XXX
};

enum instructions {
  ADC, // Add with carry
  AND, // And (with accumulator)
  ASL, // Arithmetic shift left
  BCC, // Branch on carry clear
  BCS, // Branch on carry set
  BEQ, // Branch on equal (zero set)
  BIT, // bit test
  BMI, // branch on minus (negative set)
  BNE, // branch on not equal (zero clear)
  BPL, // branch on plus (negative clear)
  BRK, // interrupt
  BVC, // branch on overflow clear
  BVS, // branch on overflow set
  CLC, // clear carry
  CLD, // clear decimal
  CLI, // clear interrupt disable
  CLV, // clear overflow
  CMP, // compare (with accumulator)
  CPX, // compare with X
  CPY, // compare with Y
  DEC, // decrement
  DEX, // decrement X
  DEY, // decrement Y
  EOR, // exclusive or (with accumulator)
  INC, // increment
  INX, // increment X
  INY, // increment Y
  JMP, // jump
  JSR, // jump subroutine
  LDA, // load accumulator
  LDY, // load X
  LDY, // load Y
  LSR, // logical shift right
  NOP, // no operation
  ORA, // or with accumulator
  PHA, // push accumulator
  PHP, // push processor status (SR)
  PLA, // pull accumulator
  PLP, // pull processor status (SR)
  ROL, // rotate left
  ROR, // rotate right
  RTI, // return from interrupt
  RTS, // return from subroutine
  SBC, // subtract with carry
  SEC, // set carry
  SED, // set decimal
  SEI, // set interrupt disable
  STA, // store accumulator
  STX, // store X
  STY, // store Y
  TAX, // transfer accumulator to X
  TAY, // transfer accumulator to Y
  TSX, // transfer stack pointer to X
  TXA, // transfer X to accumulator
  TXS, // transfer X to stack pointer
  TYA, // transfer Y to accumulator
  XXX  // undefined
};


{BRK, IMPL},
{ORA, X_IND},
{XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ORA zpg
ASL zpg
XXX, XXX},
{PHP, IMPL},
{ORA #
ASL A
XXX, XXX},
{XXX, XXX},
{ORA abs
ASL abs
XXX, XXX},
{BPL rel
ORA ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ORA zpg,X
ASL zpg,X
XXX, XXX},
{CLC, IMPL},
{ORA abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ORA abs,X
ASL abs,X
XXX, XXX},
{JSR abs
AND, X_IND},
{XXX, XXX},
{XXX, XXX},
{BIT zpg
AND zpg
ROL zpg
XXX, XXX},
{PLP, IMPL},
{AND #
ROL A
XXX, XXX},
{BIT abs
AND abs
ROL abs
XXX, XXX},
{BMI rel
AND ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{AND zpg,X
ROL zpg,X
XXX, XXX},
{SEC, IMPL},
{AND abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{AND abs,X
ROL abs,X
XXX, XXX},
{RTI, IMPL},
{EOR, X_IND},
{XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{EOR zpg
LSR zpg
XXX, XXX},
{PHA, IMPL},
{EOR #
LSR A
XXX, XXX},
{JMP abs
EOR abs
LSR abs
XXX, XXX},
{BVC rel
EOR ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{EOR zpg,X
LSR zpg,X
XXX, XXX},
{CLI, IMPL},
{EOR abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{EOR abs,X
LSR abs,X
XXX, XXX},
{RTS, IMPL},
{ADC, X_IND},
{XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ADC zpg
ROR zpg
XXX, XXX},
{PLA, IMPL},
{ADC #
ROR A
XXX, XXX},
{JMP ind
ADC abs
ROR abs
XXX, XXX},
{BVS rel
ADC ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ADC zpg,X
ROR zpg,X
XXX, XXX},
{SEI, IMPL},
{ADC abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{ADC abs,X
ROR abs,X
XXX, XXX},
{XXX, XXX},
{STA, X_IND},
{XXX, XXX},
{XXX, XXX},
{STY zpg
STA zpg
STX zpg
XXX, XXX},
{DEY, IMPL},
{XXX, XXX},
{TXA, IMPL},
{XXX, XXX},
{STY abs
STA abs
STX abs
XXX, XXX},
{BCC rel
STA ind,Y
XXX, XXX},
{XXX, XXX},
{STY zpg,X
STA zpg,X
STX zpg,Y
XXX, XXX},
{TYA, IMPL},
{STA abs,Y
TXS, IMPL},
{XXX, XXX},
{XXX, XXX},
{STA abs,X
XXX, XXX},
{XXX, XXX},
{LDY #
LDA, X_IND},
{LDX #
XXX, XXX},
{LDY zpg
LDA zpg
LDX zpg
XXX, XXX},
{TAY, IMPL},
{LDA #
TAX, IMPL},
{XXX, XXX},
{LDY abs
LDA abs
LDX abs
XXX, XXX},
{BCS rel
LDA ind,Y
XXX, XXX},
{XXX, XXX},
{LDY zpg,X
LDA zpg,X
LDX zpg,Y
XXX, XXX},
{CLV, IMPL},
{LDA abs,Y
TSX, IMPL},
{XXX, XXX},
{LDY abs,X
LDA abs,X
LDX abs,Y
XXX, XXX},
{CPY #
CMP, X_IND},
{XXX, XXX},
{XXX, XXX},
{CPY zpg
CMP zpg
DEC zpg
XXX, XXX},
{INY, IMPL},
{CMP #
DEX, IMPL},
{XXX, XXX},
{CPY abs
CMP abs
DEC abs
XXX, XXX},
{BNE rel
CMP ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{CMP zpg,X
DEC zpg,X
XXX, XXX},
{CLD, IMPL},
{CMP abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{CMP abs,X
DEC abs,X
XXX, XXX},
{CPX #
SBC, X_IND},
{XXX, XXX},
{XXX, XXX},
{CPX zpg
SBC zpg
INC zpg
XXX, XXX},
{INX, IMPL},
{SBC #
NOP, IMPL},
{XXX, XXX},
{CPX abs
SBC abs
INC abs
XXX, XXX},
{BEQ rel
SBC ind,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{SBC zpg,X
INC zpg,X
XXX, XXX},
{SED, IMPL},
{SBC abs,Y
XXX, XXX},
{XXX, XXX},
{XXX, XXX},
{SBC abs,X
INC abs,X
XXX, XXX},
{

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
