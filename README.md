#  Project 01 : 42_Get_next_line

Always reading one line, entirely, but one only, one at a time, from a file descriptor, giving a BUFFER_SIZE that you determine in the command line through the flag: -D BUFFER_SIZE=32.

My program will read from the file descriptor 32 bytes at a time.
- If the line is less than 32, it will fill the string which address you pass as a parameter, keep in another static string what was read but not part of the first line and return 1.
- If the line is more than 32, it will read again 32 bytes, until it reads a \n to indicate a new line in the file descriptor and keep as well what is after that \n if needed.
- When there is the EOF character in the 32 bytes read from the file descriptor, so when we are indeed at the end of the file that we are asked to read, we will fill the string and return 0 to indicate that there is no other line to be read from this file descriptor.

So in the end, when you call get_next_line for the first time, indicating a BUFFER_SIZE, a fd and the address of a string to fill, it will fill said string with the whole first line in the file descriptor, regardless of the BUFFER_SIZE, and return 1. If you call it a second time, it will fill the string again, regardless of the BUFFERSIZE, and return 1. And so on. Until you are asking to get the final line of the file descriptor, in which case, it will certainly fill the string but it will return 0.
