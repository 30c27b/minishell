#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include <stddef.h>
#include "carbon/llst.h"

typedef struct s_env
{
	char *key;
	char *def;
} t_env;

extern t_llst *g_msh_env;

void msh_env(char **envp);

char **msh_env_all(void);

t_env *msh_env_get(char *key);

// TODO: implement
char **msh_env_set(char *key, char*def);

// TODO: remove for production
void env_print(void);

#endif
