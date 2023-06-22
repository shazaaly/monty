#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct col_s
{
    char *arg;
    char *line;
    FILE *file;
} col_t;

extern col_t col;

int execute(char *line, unsigned int line_number, stack_t **stack);
/*void parse_line(char *line, char *opcode, char *arg); */
void push(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, int value);
void free_stack(stack_t **stack);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
#endif
