#include "msh/prompt.h"
#include "msh/shared.h"

#include "carbon/io.h"
#include "carbon/str.h"
#include "carbon/fmt.h"
#include <unistd.h>
#include <stdlib.h>

char*
	msh_prompt(char *prompt)
{
	char	*line;

	fmt_print(prompt);
	if (io_next_line(STDIN_FILENO, &line) < 0)
		msh_exit(1, "nomem");
	return (line);
}
