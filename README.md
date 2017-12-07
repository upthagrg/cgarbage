# cgarbage
A simple API to offload memory management to a subsystem, freeing the programmer from that responsibility. 
The only file you need to start using this is garbage.h. 
Once you have included it in a projects, replace any malloc() calls with gmalloc().
Also replace any free() calls with gfree().
Before you return from main, call gclear().
That is it, just let the system do its work and all your dynamic memory will be taken care of for you. 
