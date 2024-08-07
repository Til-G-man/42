
char	*readfile(int fd)
{
	char	*file;
	char	*temp;

	while (temp = get_next_line(fd))
	{
		file = fd_fd_strjoin(file, temp);
	}
int	main()
{

}