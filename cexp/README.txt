Start here to solve the cexp task.

In this task, you will modify the command interpreter framework to
perform "tab completion" on commands.  For example, when you type "h"
followed by the TAB key, the remainder of the "Help" command will be
automatically entered. Typing RETURN will then run the command.

Details: ../cmcmd contains sources and some documentation for the
command interpreter. You can run make in that directory to build the
command interpreter. However, for this task you should work in this
directory (named cexp). A copy of cmd.c is here for you to
alter. Also, Makefile is provided to compile cmd.c and link it with the
other command interpreter sources.

You should modify ONLY cmd.c in this directory. No other files will be
used to grade your work.

The TAB key should automatically type in any characters that are
needed to complete every matching command.  For example, if you type
"h" and then TAB, "elp" should be automatically typed. The command
line will now be "CMD> help", cmdbuf (where the command is stored)
will contain the string "help", and typing RETURN will run the "Help"
command.

Similarly, typing "t" then TAB then RETURN will run the "Test"
command, entering the Test subsystem.

Now, in the Test subsystem, if you type "h" then <TAB> there are two
matching commands: "Help" and "Hello".  Since both start with "Hel",
the letters "el" will be automatically entered. No more letters can be
automatically entered because at this point, it is ambiguous whether
you will type "l" for "Hello" or "p" for "Help". If you type "l" (the
command is now "hell") and TAB, the only matching command is "Hello",
so "o" is automatically entered.

HINT: The logic to determine what commands are available is
non-trivial. All global commands are always available, subsystem names
(such as "Test") are available when no subsystem is selected, and
subsystem commands are available only after entering the subsystem
(until you leave with the global Exit command). However, you do not
really need to fully understand or implement these rules because they
are already implemented in the cmdid_search() function. As described
in the comments above this function, cmdid_search() looks for a
case-insensitive match to available commands. You can copy and modify
this function as part of your solution.


DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
======================
You may not add new source files, you must change only cmd.c.

Modifications/extensions to ../cmcmd will be REMOVED when Proxor tests
your solution.

Do NOT make changes to cmd.c that are not in these requirements.

Do NOT print debugging information or any extra text.
