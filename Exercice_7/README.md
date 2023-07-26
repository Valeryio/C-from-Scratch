## EXERCICE 7

### PRINCIPAL Lesson Learned :

**A - L - R - I - G - H - T**
**Everything is alright now. I spend a bunch of time on this program. And NEW STUFF, I 
started file gestion in C. With function in some kind pretty weird like fread... and All these things!**

THREE DAYS to debug my code, understand my mistakes and learn some fantastic and beautiful new things...
**


> If there's something you wanna do, just DO IT. Don't let your HEAD stop your HEART from moving...


### DESCRIPTION

***I wrote an algorithm to concatenate two text files in another. Simple! Right ?***

### 1 - FILE MANAGEMENT Is Not The SAME ON ALL THE OS

**The algorithm was simple, but running the code have been a little difficult. Because...
I learned that OS can manage some characters differently. By example :**

**WINDOWS consider '\n' like two different characters in text editors : '\r\n'
That is not the same for LINUX that consider '\n' as it is. So when you use a function like
`ftell(FILE *file)` to get the number of characters in a file on windows. This will happen :**

1. ftell will count the number of bytes of all the characters between the first and the position of the cursor (we assume that the cursor is at the end of the file) 

1. And it will count 2 bytes, each time instead of 1 byte when it comes to '\n' cause for the OS, (WINDOWS in our case), this one is represented by two characters '\r\n' for text editors.

1. You will get the number of characters you want, but with each number of `NL` symbol in the file. 

***Exemple :***
`Yeah! That is my text


With Three new lines!`

**If you run the code file_length for LINUX_OS (it's on the main file of the project 8), you will get
48 characters instead fof 45.**

				**WHY ?**

***We have three new line characters '\n' who are considered as two different characters by windows '\r\n', so it will add three additionnal Char ! That is all.***

> Be careful and be Wise!



#### 2 - WARNING WHEN USING `feof(FILE *file)`

**When you use feof to make a loop, iterating until the end to get the number of characters, there is
some little things that could make the code seems trouble and does not execute as it should.

In fact `feof(FILE *file)` just verify if the cursor is at the end of the file. So at the beginning...
Before continue, we assume that our cursor is that : @.
The file is like that : 

`@That is the new file I want to use !`

And, the cursor '@' is at the beginning of the file. It doesn't take in account that, it's not after a
letter, you loop will just iterate it, and if you use that condition to count the number of letters, it will add 1 (one) to the real number of letters, cause the feof was right before the first character.

> Be careful and be Wise!



#### 3 - LEARN TO KNOW WHAT FUNCTIONS REALLY DO WHEN YOU MANIPULATE FILES

**If there is one skill I get here, in file manipulation, is to really understand the functions of C programming language I'm using. When you use a function, please, make sure you understand the most what it's doing on background on you data structure. 



#### 4 - THIS IS LOGIC, CODE, NOT MAGIC

**Some times the result works, and another times no. WHY ????
That's not possible, it's not magic, just try to understand the code.**

## Never free the memory of the pointers you used to write in a file, before closing this one!
***The string will never be wrote in the file**



> If there's something you want to do, just do it, don't let your head stop your heart from moving!

K G
