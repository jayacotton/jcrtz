# jcrtz


The plan is to create a Z80 multitasking kernel as a hobby project.

The ultimate goal is to have some fun building a multitasking kernel for 8 bit CPU's in general.
My first target is the Z80 because I have a lot of them.  Once I get a runnable kernel my plan
is to port to another 8 bit cpu of interest TBD.

Most of the documentation will be in C with semicolons at the end.  I will be documenting in
plain text as I go along.  Most of the interesting documents will be in the sub directories
with the code.

I am including the FAT file code base with a few minor tweaks for the special case of disk driver.

Also looking at busybox code as a possible way to get to a working command set quickly.  Size is an
issue however.

The astute observer may notice that I am creating a CP/M program that takes over the machine.  Well spotted.
