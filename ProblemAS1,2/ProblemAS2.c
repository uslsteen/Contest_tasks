#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum command_name
{
	MOVI = 0,
	ADD = 1,
	SUB = 2,
	MUL = 3,
	DIV = 4,
	IN = 5,
	OUT = 6,
};


struct command_t
{
	enum command_name name;

	char reg;
	char r_reg, l_reg;

	int data;
	int cond;

};

const int FALSE = 0;
const int TRUE = 1;
const int STOP = 2;

int Read_hex_code(struct command_t* com, int cmd_code);
int Read_regs(struct command_t* com, int cmd_code);
int Check_reg(char reg);
void Convert_code(struct command_t* com);

int main()
{
	struct command_t cmd;
	int cmd_code = 0;

	while (1)
	{
		if (scanf("0x%x ", &cmd_code) != 1)
		{
			break;
		}

		Read_hex_code(&cmd, cmd_code);
		if (cmd.cond == FALSE)
		{
			printf("ERROR");
			break;
		}
		else
		{
			Convert_code(&cmd);
		}
	}

	return 0;
}


int Read_hex_code(struct command_t* cmd, int cmd_code)
{
	cmd->cond = TRUE;

	if ((cmd_code >> 4) == 0x8)
	{
		cmd->name = ADD;
		cmd->cond = Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code >> 4) == 0x9)
	{
		cmd->name = SUB;
		cmd->cond =  Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code >> 4) == 0xA)
	{
		cmd->name = MUL;
		cmd->cond =  Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code >> 4) == 0xB)
	{
		cmd->name = DIV;
		cmd->cond =  Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code & 252) == 192)
	{
		cmd->name = IN;
		cmd->cond =  Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code & 252) == 196)
	{
		cmd->name = OUT;
		cmd->cond =  Read_regs(cmd, cmd_code);
	}
	else if ((cmd_code & 255) <= 255 && (cmd_code & 255) >= 0)
	{
		cmd->name = MOVI;
		cmd->data = cmd_code;

		if ((cmd->data > 127) || (cmd->data < 0))
		{
			cmd->cond = FALSE;
		}
	}
	else
	{
		cmd->cond = FALSE;
	}

	return TRUE;
}


int Read_regs(struct command_t* cmd, int cmd_code)
{
	int check = 0;

	if (cmd->name == IN || cmd->name == OUT)
	{
		cmd->reg = (cmd_code & 3) + 65;

		check = Check_reg(cmd->reg);
	}
	else
	{
		cmd->l_reg = ((cmd_code & 15) >> 2) + 65;
		cmd->r_reg = ((cmd_code & 3)) + 65;

		check = Check_reg(cmd->l_reg);
		check = Check_reg(cmd->r_reg);
	}

	return check;
}

int Check_reg(char reg)
{
	if (reg < 'A' || reg > 'D')
	{
		return FALSE;
	}
	else
		return TRUE;
}


void Convert_code(struct command_t* cmd)
{
	switch (cmd->name)
	{
	case MOVI:
		{
			printf("MOVI %d\n", cmd->data);
			break;
		}
	case ADD:
		{
			printf("ADD %c, %c\n", cmd->l_reg, cmd->r_reg);
			break;
		}
	case SUB:
		{
			printf("SUB %c, %c\n", cmd->l_reg, cmd->r_reg);
			break;
		}
	case MUL:
		{
			printf("MUL %c, %c\n", cmd->l_reg, cmd->r_reg);
			break;
		}
	case DIV:
		{
			printf("DIV %c, %c\n", cmd->l_reg, cmd->r_reg);
			break;
		}
	case IN:
		{
			printf("IN %c\n", cmd->reg);
			break;
		}
	case OUT:
		{
			printf("OUT %c\n", cmd->reg);
			break;
		}
	default:
		break;
	}
}
