# pipex

Mini-shell permettant de chaîner des commandes UNIX via des pipes, à la manière de `< infile cmd1 | cmd2 > outfile`.

## Compilation

```bash
make
```

## Utilisation

```bash
./pipex infile "cmd1" "cmd2" outfile
```