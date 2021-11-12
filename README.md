# 🚽 pipex

This project aims to make you understand a bit deeper two concets, the redirections and the pipes.
 
## ✍️ Usage

`$> ./pipex file1 cmd1 cmd2 file2`

Just in case: `file1` and `file2` are file names, `cmd1` and `cmd2` are shell commands with
their parameters.

The execution of the pipex program should do the same as the next shell command:

`$> < file1 cmd1 | cmd2 > file2`

## ⏏️ Examples

`$> ./pipex infile ``ls -l'' ``wc -l'' outfile`

should be the same as `< infile ls -l | wc -l > outfile`

`$> ./pipex infile ``grep a1'' ``wc -w'' outfile`

should be the same as `< infile grep a1 | wc -w > outfile`
