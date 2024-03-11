#ifndef PIPEX_STRUCT_H
# define PIPEX_STRUCT_H

struct s_pipex {
	int		pid1;
	int		pid1status;
	int		p1fd;
	char	**argvs1;

	int		pid2;
	int		pid2status;
	int		p2fd;
	char	**argvs2;

	int		fdpipe[2];
	char	**paths;
};

#endif
