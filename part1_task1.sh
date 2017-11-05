#!/bin/bash
#make directory dir1
mkdir -p dir1
#make files with specified size
dd if=/dev/zero of=dir1/t001.txt  bs=1  count=1
dd if=/dev/zero of=dir1/t002.txt  bs=2  count=1
dd if=/dev/zero of=dir1/t003.txt  bs=3  count=1
dd if=/dev/zero of=dir1/c100.c  bs=100  count=1
dd if=/dev/zero of=dir1/c200.c  bs=200  count=1
dd if=/dev/zero of=dir1/c300.c  bs=300  count=1
dd if=/dev/zero of=dir1/p010.pl  bs=10  count=1
dd if=/dev/zero of=dir1/p020.pl  bs=20  count=1
dd if=/dev/zero of=dir1/p030.pl  bs=30  count=1
dd if=/dev/zero of=dir1/f100 bs=100  count=1
dd if=/dev/zero of=dir1/f200 bs=200  count=1
#make subdirectories dir11 and dir12
mkdir -p dir1/dir11
mkdir -p dir1/dir12
#make files with specified size in subdirectories
dd if=/dev/zero of=dir1/dir11/t001.txt  bs=1  count=1
dd if=/dev/zero of=dir1/dir11/t002.txt  bs=2  count=1
dd if=/dev/zero of=dir1/dir11/t003.txt  bs=3  count=1
dd if=/dev/zero of=dir1/dir11/c100.c  bs=100  count=1
dd if=/dev/zero of=dir1/dir11/c200.c  bs=200  count=1
dd if=/dev/zero of=dir1/dir11/c300.c  bs=300  count=1
dd if=/dev/zero of=dir1/dir11/p010.pl  bs=10  count=1
dd if=/dev/zero of=dir1/dir11/p020.pl  bs=20  count=1
dd if=/dev/zero of=dir1/dir11/p030.pl  bs=30  count=1
dd if=/dev/zero of=dir1/dir11/f100 bs=100  count=1
dd if=/dev/zero of=dir1/dir11/f200 bs=200  count=1
dd if=/dev/zero of=dir1/dir12/t001.txt  bs=1  count=1
dd if=/dev/zero of=dir1/dir12/t002.txt  bs=2  count=1
dd if=/dev/zero of=dir1/dir12/t003.txt  bs=3  count=1
dd if=/dev/zero of=dir1/dir12/c100.c  bs=100  count=1
dd if=/dev/zero of=dir1/dir12/c200.c  bs=200  count=1
dd if=/dev/zero of=dir1/dir12/c300.c  bs=300  count=1
dd if=/dev/zero of=dir1/dir12/p010.pl  bs=10  count=1
dd if=/dev/zero of=dir1/dir12/p020.pl  bs=20  count=1
dd if=/dev/zero of=dir1/dir12/p030.pl  bs=30  count=1
dd if=/dev/zero of=dir1/dir12/f100 bs=100  count=1
dd if=/dev/zero of=dir1/dir12/f200 bs=200  count=1
#make dir111 and dir121
mkdir -p dir1/dir11/dir111
mkdir -p dir1/dir12/dir121
