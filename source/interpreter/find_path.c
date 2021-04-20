#include "msh/interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include "carbon/str.h"
#include "carbon/llst.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

static char	*search_dir(DIR *dir, char *cmd)
{
	struct dirent	*de;

	if (!dir)
		return (NULL);
	de = (struct dirent *)1;
	while (de)
	{
		de = readdir(dir);
		if (!de || de->d_type == 4 || str_cmp(de->d_name, cmd))
			continue ;
		closedir(dir);
		return (cmd);
	}
	closedir(dir);
	return (NULL);
}

char	*path_find(char *cmd)
{
	t_env			*env;
	char			*path;
	char			**strs;
	size_t			i;
	char			*tmp;

	path = NULL;
	env = msh_env_get("PATH");
	strs = str_split(env->def, ':');
	if (!strs)
		msh_exit(1, "nomem");
	i = 0;
	while (strs[i] && !path)
	{
		path = search_dir(opendir(strs[i]), cmd);
		if (path)
		{
			tmp = str_join(strs[i], "/");
			path = str_join(tmp, path);
			free(tmp);
			path = str_join(strs[i], path);
			str_split_free(strs);
			return (path);
		}
		i++;
	}
	str_split_free(strs);
	return (path);
}