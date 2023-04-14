BASE_SIZE = 4
INSTRUCTION_SIZE = 4
ADDRESS_SIZE = 2


def get_digit(number: int, n: int) -> int:
      return (number >> (BASE_SIZE * (INSTRUCTION_SIZE - 1 - n))) & 0xF


def concatenate_digits(*numbers: int) -> int:
      return sum([number * 16 ** (len(numbers) - 1 - i) for i, number in enumerate(numbers)])


"""
operators
1 is load
3 is store
B is jump
C is stop
"""

memory_1 = {0XB3: 0X0000, 0XD8: 0XFFFF}
"""
swap the content of d8 and b3
0 10D8 loads the content of d8 in memory to 0 in registers
1 11B3 loads the content of b3 in memory to 1 in registers
2 30B3 stores the content of 0 in registers to b3 in memory
3 31D8 stores the content of 1 in registers to d8 in memory
4 C000 stops the program
"""
swap_d8_b3 = [0X10D8, 0X11B3, 0X30B3, 0X31D8, 0XC000]

memory_2 = {0X00: 0X0000, 0X01: 0X0001, 0X02: 0X1DF5, 0X03: 0X1DF5, 0X04: 0X0000}
"""
if 02 == 03 store 0001 in 03 else store 0000 in 03
0 1000 loads the content of 00 in memory to 0 in registers
1 1101 loads the content of 01 in memory to 1 in registers
2 1202 loads the content of 02 in memory to 2 in registers
3 1303 loads the content of 03 in memory to 3 in registers
4 B238 jumps to instruction 6 if register 2 == register 3
5 3004 stores the content of 0 in registers to 04 in memory
6 B008 jumps to instruction 8
7 3104 stores the content of 1 in registers to 04 in memory
8 C000 stops the program
"""
check_equality = [0X1000, 0X1101, 0X1202, 0X1303, 0XB238, 0X3004, 0XB008, 0X3104, 0XC000]


class CPU:
      def __init__(self, memory: dict[int, int]) -> None:
            self.registers: dict[int, int] = dict()
            self.memory = memory
            self.counter = 0
      
      def restart(self) -> None:
            self.registers.clear()
            self.counter = 0
      
      def execute_program(self, program: list[int]) -> None:
            instruction = program[self.counter]
            i = 0
            while instruction != 0XC000:
                  i += 1
                  if i > 20: break
                  self.execute_instruction(instruction)
                  instruction = program[self.counter]

      def execute_instruction(self, instruction: int) -> None:
            operator = get_digit(instruction, 0)
            functions = {0X1: self.load, 0X3: self.store, 0XB: self.jump}
            functions[operator](instruction)

      def load(self, instruction: int) -> None:
            register_address = get_digit(instruction, 1)
            memory_address = concatenate_digits(*[get_digit(instruction, i + 2) for i in range(ADDRESS_SIZE)])
            self.registers[register_address] = self.memory[memory_address]
            self.counter += 1
            

      def store(self, instruction: int) -> None:
            register_address = get_digit(instruction, 1)
            memory_address = concatenate_digits(*[get_digit(instruction, i + 2) for i in range(ADDRESS_SIZE)])
            self.memory[memory_address] = self.registers[register_address]
            self.counter += 1
            
      def jump(self, instruction: int) -> None:
            register_address_1 =  get_digit(instruction, 1)
            register_address_2 = get_digit(instruction, 2)
            position = get_digit(instruction, 3)
            check = self.registers[register_address_1] == self.registers[register_address_2]
            self.counter = int(position) if check else self.counter + 1

      def __str__(self) -> str:
            return str({hex(key): hex(value) for key, value in self.memory.items()})
            

cpu = CPU(memory_1)
cpu.execute_program(swap_d8_b3)
print(cpu)

cpu.restart()
cpu.memory = memory_2
cpu.execute_program(check_equality)
print(cpu)