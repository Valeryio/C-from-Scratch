**EXERCICE 1**

**PRINCIPAL Lesson Learned :**

***I've learned that we cannot use char without give them a length***

**DESCRIPTION**

In this program, I've wrote an algorithm to put the mirror of a string 
in another string. And what I've learned is that, you have to give a 
length to your string. N-E-C-E-S-SA-R-I-L-Y !
After that, you can use a pointer to manipulate each case, but, you have
to give a length before. 

***Now I assume that I could be tempted to write directly this : ***


***************************************************************

char *mychain = "That's a string", *mymirror;

mirror(mymirror, mychain);

***************************************************************

Now that... It's gonna work, but, it's not secured, in terms of usage of memory.
It's not a good Idea. 

**Using char like this make you feel free, and a kind mastering of the memory but, 
you can fault.**

**BE WISE AND PAY ATTENTION**
