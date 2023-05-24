#include "shell.h"

/**
 * sigint_handler -function resets the prompt by writing a
 * newline character to the standard output, followed by
 * the prompt string.
 *
 * @sig: Integer value representing signal.
 */

void sigint_handler(int __attribute__((unused))sig)
{/* Reset the prompt and clear the input buffer */
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, PROMPT, 4);
	fflush(stdout);
}
