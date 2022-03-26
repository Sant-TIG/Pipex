# Pipex

FIFO = First In First Out

Tambien conocidos como "named pipe" o tuberia con nombre. Estos son un canal de intercomunicacion entre procesos (IPC). Cuentan con una representacion grafica en el FileSystem.

Los FIFOs deben estar abiertos simultaneamente en los dos extremos para funcionar. 
```
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/* WRITTER FIFO */

int main(void)
{
  int fd;
  char buf[] = "mensaje 1 ...";
  
  mkfifo ("/tmp/mi_fifo", 0666); //el path donde se va a crear el fifo, y los permisos que le queremos dar. El 0 es para representarlo de forma octal. El 666 es para darle derechos de escritura.
  fd = open ("/tmp/mi_fifo", O_WRONLY); //abrimos el fifo en modo escritura solamente
  write (fd, buf, sizeof(buf));
  close(fd);
  return (0);
}
```
