#include <unistd.h>
#define BUFFER_SIZE 1024
/**
* flush_buffer - Writes the contents of the buffer to stdout and resets the buffer index.
* @buffer: The buffer containing the data to be written.
* @nb: The number of characters in the buffer.
* Return: The number of characters written.
*/
int flush_buffer(char *buffer, int nb)
{
write(1, buffer, nb);
return ((0));
}