#include "corewar.h"

//pareil sans IDX_MOD, une func en + a cause des lignes => params ocp differents
void			lldi_verbose(t_proc *proc, unsigned int value,
				unsigned int addr)
{
	show_operations(proc);
	printf("\n| -> load from %d + %d = %d (with pc and mod %d)",
			proc->op.ar[0], proc->op.ar[1], value, addr);//
	printf("\n"); //
}

unsigned int	lldi_get_addr(t_proc *proc)
{
	unsigned int addr;

	addr = 0;
	addr = (proc->op.ar[0] + proc->op.ar[1]);
	addr = addr + proc->op.pos_opcode;
	return (addr);
}

unsigned int	lldi_get_value(t_vm *vm, unsigned int addr)
{
	unsigned int value;

	value = 0x0;
	value |= (unsigned char)vm->ram[modulo(addr, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 1, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 2, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 3, MEM_SIZE)].mem;
	return (value);
}

void			lldi(t_vm *vm, t_proc *proc)
{
	unsigned int		addr;
	int					value;

	if (!check_params(&proc->op))
		return ;
	if (proc->op.ar_typ[0] == REG_CODE)
		proc->op.ar[0] = proc->reg[proc->op.ar[0]];
	else if (proc->op.ar_typ[0] == IND_CODE)
		proc->op.ar[0] = get_indirect(vm, &proc->op, 0);
	if (proc->op.ar_typ[1] == REG_CODE && !check_reg(proc->op.ar[1]))
		return ;
	if (proc->op.ar_typ[1] == REG_CODE)
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
	addr = lldi_get_addr(proc);
	value = lldi_get_value(vm, addr);
	if (proc->op.ar_typ[2] == REG_CODE && !check_reg(proc->op.ar[2]))
		return ;
	if (check_reg(proc->op.ar[2]))
		proc->reg[proc->op.ar[2]] = value;
	if (0x4 & vm->verbosity)
		lldi_verbose(proc, value, addr);
}
