#ifndef _MAIN_H_
#define _MAIN_H_
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
void handle_interactive(int argc, char *argv[], char **env);
void handle_noninteractive(int argc, char *argv[], char **env);
int _fileno(FILE *stream);
size_t _getline(char **buffer, size_t *n, FILE *stream);
size_t _read(char **buffer, size_t *n);
int prompt(char *outputtxt, char **buffer, size_t *n);
char *_strtok(char *buffer, char *delimiter);
void _strtoarr(char *arr[], char *buffer, int num);
void handle_env(void);
void handle_exit(char *arr[], char *lineptr);
void handle_cd(char *curr, char *arr[]);
int _strlen(char *s);
int _strtoint(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _charfinder(char *s, char c);
void _execve(char *curr, char *arr[], char **env);
void _fork(char *curr, char *arr[], char **env);
int _strcmp(char *s1, char *s2);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int handle_exceptional_inputs(char *curr, char *arr[],
		char *lineptr);
#endif
