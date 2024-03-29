#include "monty.h"
/**
 * _ops - compare functions to tokens and executes them
 * @token: command recieved
 * @stk: stack
 * @linenum: number of line
 * Return: void
 */
void _ops(char *token, stack_t **stk, unsigned int linenum)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	if (strcmp(token, "stack") == 0)
	{
		variables.check = 0;
		return;
	}
	if (strcmp(token, "queue") == 0)
	{
		variables.check = 1;
		return;
	}
	if (strcmp(token, "swap") == 0)
	{
		swap(stk, linenum);
		return;
	}
	if (variables.check == 1 && strcmp(token, "push") == 0)
	{
		_queue(stk, linenum);
		return;
	}
	while (op[a].opcode != NULL)
	{
		if (strcmp(token, op[a].opcode) == 0)
		{
			op[a].f(stk, linenum);
			return;
		}
		a++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", linenum, token);
	free_stk(stk, linenum);
	exit(EXIT_FAILURE);
}
