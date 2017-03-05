## Hangman

`$` `gcc hangman.c -o hangman`
`$` `./hangman`
```
Allowed tries: 5
Word(s) to be guessed: hello
```

```
[Tries: 5]
h
[Right]			h****
e
[Right]			he***
l
[Right]			hell*
l
[Already Guessed]	hell*
o
[Right]			hello
You win!

```
or
```
[Tries: 5]
he
[Right]			h****
[Right]			he***
l
[Right]			hell*
o
[Right]			hello
You win!
```
or
```
[Tries: 5]
helo
[Right]			h****
[Right]			he***
[Right]			hell*
[Right]			hello
You win!

```
or
```
[Tries: 5]
a 
[Wrong] [Tries: 3]	*****
f
[Wrong] [Tries: 1]	*****
.
.
.

```

#### Interesting Part!
`$` `./hangman words.txt`
##### Get a random word and random number of tries!