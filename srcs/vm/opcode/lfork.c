#include "corewar.h"

static void		registre_cpy(t_proc *proc, t_proc *new)
{
	int i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}

static void		clone_proc(t_proc *proc, t_proc *new)
{
	registre_cpy(proc, new);
	new->carry = proc->carry;
	new->last_live = proc->last_live;
	new->num = proc->num;
}

void			op_lfork(t_vm *vm, t_proc *proc)
{
	t_proc	*new;

	new = create_process(vm, proc->num);
	init_op(&new->op);
	new->pc = modulo(proc->op.pos_opcode + proc->op.ar[0], MEM_SIZE);//pareil sans le modulo IDX_MOD
	new->last_pc = new->pc;
	clone_proc(proc, new);
	add_process(vm, new);
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		printf(" (%d)\n", new->pc);//
	}
}
