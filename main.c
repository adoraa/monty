#include "monty.h"
#define OP_VALUE 128
/**
 * main - entry point of the program
 * @argc: argument counter
 * @argv: array of arguments
 * Return: 0 if successful else return a non-zero value and updates errno
 */
int main(int argc, char *argv[])
{
	char opcode[OP_VALUE];
	int value;
	unsigned int line_num = 0;
	FILE *file = fopen(argv[1], "r");
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	} stack = NULL;
	while (fscanf(file, "%127s", opcode) == 1)
	{
		line_num++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				fclose(file);
				return (EXIT_FAILURE);
			} _push(&stack, line_num, value);
		}
		if (strcmp(opcode, "pall") == 0)
			_pall(stack);
		while (fgetc(file) != '\n')
			;
		while (fscanf(file, "%1[\n ]", opcode) == 1)
			;
	} fclose(file);
	return (EXIT_SUCCESS);
}
