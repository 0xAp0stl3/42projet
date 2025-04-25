# get_next_line

Fonction C permettant de lire un fichier ligne par ligne, de façon efficace et sans fuite mémoire.

## Compilation

Inclure les fichiers `.c` et `.h` dans votre projet.

## Utilisation

```c
char *line;
int fd = open("fichier.txt", O_RDONLY);
while ((line = get_next_line(fd)))
{
    // Utiliser la ligne
    free(line);
}
close(fd);
```