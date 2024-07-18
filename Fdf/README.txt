If you watnt to change a function/folder/file make sure to change it in the responsible headerfile, in the suources.mk file and inside the README.txt file. In addition make sure, that the funktion still works when calling it (considere, that the function already could get called.


Project struktur (small):
root
	Makefile
	sources.mk 			#all the sources for the makefile
	main.c				#the main funktion
	fdf				#executable program --DO NOT HAND THIS IN--
	(folder) utils			#contains all the self written function the program makes use of
		Get_next_line
		Read_file
		Libft
	((folder) maps)			#contains some test maps --DO NOT HAND IN THIS FOLDER--
	(folder) MiniLibX - Linux	#contains the MiniLibX libary - used to create the Graphical environment



Functions:
Get_next_line
get_next_line.c:	
	Definition:	char	*get_next_line(int fd)
	Location:	utils/Get_next_line/get_next_line.c
	Parameters:	int fd	- filedescriptor
	Returnval:	pointer to a string (char *) string contains a line from the file, NULL if it fails.
	Explanation:	gets a file descriptor and reads from it (first call first line, second call second line...)
	makes use of:	free, read, have_n, print_line, malloc, ft_strjoin_free;
	gets used by:	read_file;
	Comment:


get_next_line_utils.c
	Definition:	char	*ft_strdup_gnl(char *str, int len)
	Location:	utils/Get_next_line/get_next_line_utils.c
	Parameters:	char *str	- the string you want to dublicate
			int len		- the index until where you want to copy
	Returnval:	pointer to a string (char *) - a new malloced string which contais everything between *str and *str[len]
	Explanation:	copies a sting into a new malloced str(the original still exist) and returns a pointer to the copy (already null terminated)- NULL if fail
	makes use of:	malloc;
	gets used by:	ft_strjoin_free, print_line;
	Comment:

get_next_line_utils.c:	
	Definition:	char	*ft_strjoin_free(char *s1, char *s2)
	Location:	utils/Get_next_line/get_next_line_utils.c
	Parameters:	char *s1	- the left part of the new string
			char *s2	- the right part of the new string
	Returnval:	pointer to a string (char *) string contains both strings without any seperator between the 2 strings (s1+s2) - NULL if fail
	Explanation:	creates a new malloced string which contains s1 and s2 (s1+s2). While s1 gets freed s2 still exist afterwars. 
	makes use of:	ft_strlen, ft_strdup_gnl, malloc, free;
	gets used by:	(not filled out yet)
	Comment:	WATCH OUT - the function free only s1 so you can't use it afterwards, while s2 still exist (you have to free it by yourself) 

get_next_line_utils.c:	
	Definition:	int	have_n(char *temp)
	Location:	utils/Get_next_line/get_next_line_utils.c
	Parameters:	char *temp 
	Returnval:	int - the number of new line characters ('\n') in the string(temp)
	Explanation:	gets a string and counts the nwe line characters inside it ('\n')
	makes use of:	- 
	gets used by:	(not filled out yet)
	Comment:



	
template:
get_next_line.c:	
	Definition:	char	*get_next_line(int fd)
	Location:	utils/Get_next_line/get_next_line.c
	Parameters:	int fd - filedescriptor
	Returnval:	pointer to a string (char *) string contains a line from the file, NULL if it fails.
	Explanation:	gets a file descriptor and reads from it (first call first line, second call second line...)
	makes use of:	free, read, have_n, print_line, malloc, ft_strjoin_free
	gets used by:	read_file
	Comment:
	

