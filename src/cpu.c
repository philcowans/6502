#include <stdlib.h>
enum addressing_modes {
  A, ABS, ABS_X, ABS_Y, I, IMPL, IND, X_IND, IND_Y, REL, ZPG, ZPG_X, ZPG_Y, AM_INVALID
};

enum instructions {
  ADC, // add with carry
  AND, // and (with accumulator)
  ASL, // arithmetic shift left
  BCC, // branch on carry clear
  BCS, // branch on carry set
  BEQ, // branch on equal (zero set)
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
  LDX, // load X
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
  I_INVALID // undefined
};


enum instructions instruction_table[] = {BRK, ORA, I_INVALID, I_INVALID, I_INVALID, ORA, ASL, I_INVALID, PHP, ORA, ASL, I_INVALID, I_INVALID, ORA, ASL, I_INVALID, BPL, ORA, I_INVALID, I_INVALID, I_INVALID, ORA, ASL, I_INVALID, CLC, ORA, I_INVALID, I_INVALID, I_INVALID, ORA, ASL, I_INVALID, JSR, AND, I_INVALID, I_INVALID, BIT, AND, ROL, I_INVALID, PLP, AND, ROL, I_INVALID, BIT, AND, ROL, I_INVALID, BMI, AND, I_INVALID, I_INVALID, I_INVALID, AND, ROL, I_INVALID, SEC, AND, I_INVALID, I_INVALID, I_INVALID, AND, ROL, I_INVALID, RTI, EOR, I_INVALID, I_INVALID, I_INVALID, EOR, LSR, I_INVALID, PHA, EOR, LSR, I_INVALID, JMP, EOR, LSR, I_INVALID, BVC, EOR, I_INVALID, I_INVALID, I_INVALID, EOR, LSR, I_INVALID, CLI, EOR, I_INVALID, I_INVALID, I_INVALID, EOR, LSR, I_INVALID, RTS, ADC, I_INVALID, I_INVALID, I_INVALID, ADC, ROR, I_INVALID, PLA, ADC, ROR, I_INVALID, JMP, ADC, ROR, I_INVALID, BVS, ADC, I_INVALID, I_INVALID, I_INVALID, ADC, ROR, I_INVALID, SEI, ADC, I_INVALID, I_INVALID, I_INVALID, ADC, ROR, I_INVALID, I_INVALID, STA, I_INVALID, I_INVALID, STY, STA, STX, I_INVALID, DEY, I_INVALID, TXA, I_INVALID, STY, STA, STX, I_INVALID, BCC, STA, I_INVALID, I_INVALID, STY, STA, STX, I_INVALID, TYA, STA, TXS, I_INVALID, I_INVALID, STA, I_INVALID, I_INVALID, LDY, LDA, LDX, I_INVALID, LDY, LDA, LDX, I_INVALID, TAY, LDA, TAX, I_INVALID, LDY, LDA, LDX, I_INVALID, BCS, LDA, I_INVALID, I_INVALID, LDY, LDA, LDX, I_INVALID, CLV, LDA, TSX, I_INVALID, LDY, LDA, LDX, I_INVALID, CPY, CMP, I_INVALID, I_INVALID, CPY, CMP, DEC, I_INVALID, INY, CMP, DEX, I_INVALID, CPY, CMP, DEC, I_INVALID, BNE, CMP, I_INVALID, I_INVALID, I_INVALID, CMP, DEC, I_INVALID, CLD, CMP, I_INVALID, I_INVALID, I_INVALID, CMP, DEC, I_INVALID, CPX, SBC, I_INVALID, I_INVALID, CPX, SBC, INC, I_INVALID, INX, SBC, NOP, I_INVALID, CPX, SBC, INC, I_INVALID, BEQ, SBC, I_INVALID, I_INVALID, I_INVALID, SBC, INC, I_INVALID, SED, SBC, I_INVALID, I_INVALID, I_INVALID, SBC, INC, I_INVALID};

enum addressing_modes addressing_modes_table[] = {IMPL, X_IND, AM_INVALID, AM_INVALID, AM_INVALID, ZPG, ZPG, AM_INVALID, IMPL, I, A, AM_INVALID, AM_INVALID, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID, ABS, X_IND, AM_INVALID, AM_INVALID, ZPG, ZPG, ZPG, AM_INVALID, IMPL, I, A, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID, IMPL, X_IND, AM_INVALID, AM_INVALID, AM_INVALID, ZPG, ZPG, AM_INVALID, IMPL, I, A, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID, IMPL, X_IND, AM_INVALID, AM_INVALID, AM_INVALID, ZPG, ZPG, AM_INVALID, IMPL, I, A, AM_INVALID, IND, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID, AM_INVALID, X_IND, AM_INVALID, AM_INVALID, ZPG, ZPG, ZPG, AM_INVALID, IMPL, AM_INVALID, IMPL, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, ZPG_Y, AM_INVALID, IMPL, ABS_Y, IMPL, AM_INVALID, AM_INVALID, ABS_X, AM_INVALID, AM_INVALID, I, X_IND, I, AM_INVALID, ZPG, ZPG, ZPG, AM_INVALID, IMPL, I, IMPL, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, ZPG_Y, AM_INVALID, IMPL, ABS_Y, IMPL, AM_INVALID, ABS_X, ABS_X, ABS_Y, AM_INVALID, I, X_IND, AM_INVALID, AM_INVALID, ZPG, ZPG, ZPG, AM_INVALID, IMPL, I, IMPL, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID, I, X_IND, AM_INVALID, AM_INVALID, ZPG, ZPG, ZPG, AM_INVALID, IMPL, I, IMPL, AM_INVALID, ABS, ABS, ABS, AM_INVALID, REL, IND_Y, AM_INVALID, AM_INVALID, AM_INVALID, ZPG_X, ZPG_X, AM_INVALID, IMPL, ABS_Y, AM_INVALID, AM_INVALID, AM_INVALID, ABS_X, ABS_X, AM_INVALID};


struct processor_state {
  int A;
  int X;
  int Y;
  int PC;
  int SR;
  int SP;
};

// Status register bitmap
const char SR_N = 1 << 7; // Negative
const char SR_V = 1 << 6; // Overflow
                          // Unused
const char SR_B = 1 << 4; // Break
const char SR_D = 1 << 3; // Decimal
const char SR_I = 1 << 2; // Interrupt (IRQ disable)
const char SR_Z = 1 << 1; // Zero
const char SR_C = 1 << 0; // Carry

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
    case ADC: // add with carry
    case AND: // and (with accumulator)
      state.A &= argument_value;
      break;
    case ASL: // arithmetic shift left
      // TODO: Need to support in place operations
    case BCC: // branch on carry clear
      
    case BCS: // branch on carry set
    case BEQ: // branch on equal (zero set)
    case BIT: // bit test
    case BMI: // branch on minus (negative set)
    case BNE: // branch on not equal (zero clear)
    case BPL: // branch on plus (negative clear)
    case BRK: // interrupt
    case BVC: // branch on overflow clear
    case BVS: // branch on overflow set
    case CLC: // clear carry
    case CLD: // clear decimal
    case CLI: // clear interrupt disable
    case CLV: // clear overflow
    case CMP: // compare (with accumulator)
    case CPX: // compare with X
    case CPY: // compare with Y
    case DEC: // decrement
    case DEX: // decrement X
    case DEY: // decrement Y
    case EOR: // exclusive or (with accumulator)
    case INC: // increment
    case INX: // increment X
    case INY: // increment Y
    case JMP: // jump
    case JSR: // jump subroutine
    case LDA: // load accumulator
    case LDX: // load X
    case LDY: // load Y
    case LSR: // logical shift right
    case NOP: // no operation
    case ORA: // or with accumulator
    case PHA: // push accumulator
    case PHP: // push processor status (SR)
    case PLA: // pull accumulator
    case PLP: // pull processor status (SR)
    case ROL: // rotate left
    case ROR: // rotate right
    case RTI: // return from interrupt
    case RTS: // return from subroutine
    case SBC: // subtract with carry
    case SEC: // set carry
    case SED: // set decimal
    case SEI: // set interrupt disable
    case STA: // store accumulator
    case STX: // store X
    case STY: // store Y
    case TAX: // transfer accumulator to X
    case TAY: // transfer accumulator to Y
    case TSX: // transfer stack pointer to X
    case TXA: // transfer X to accumulator
    case TXS: // transfer X to stack pointer
    case TYA: // transfer Y to accumulator

    default:
      exit(1);
    }
  }

  free(memory);
  return 0;
}
