#!/bin/perl
use warnings;
use strict;

#variables
my $filename;
my $filetype;
my $filesize;
my $cval = 0;
my $csize = 0;
my $plval = 0;
my $plsize = 0;
my $txtval = 0;
my $txtsize = 0;
my $naval = 0;
my $nasize = 0;
my $tval = 0;
my $tsize = 0;

#find files of type .pl and their sizes
for my $filename ( glob("*")) 
{
   if ( -f $filename ) {
      if ( $filename =~ /.+\.([^.]+)$/ ){
         $filetype = '.' . $1;
      } else {
         $filetype = '<no type>';
      }

   $filesize = -s $filename;
  if ($filetype =~ '.pl')
  {
      $plval = $plval + 1;
      $plsize = $plsize + $filesize;
  }
}
}
#find files of type .c and their sizes
for my $filename ( glob("*")) {
   if ( -f $filename ) {
      if ( $filename =~ /.+\.([^.]+)$/ ){
         $filetype = '.' . $1;
      } else {
         $filetype = '<no type>';
      }

   $filesize = -s $filename;
  if ($filetype =~ '.c')
  {
      $cval = $cval + 1;
      $csize = $csize + $filesize;
   }
}
}
#find files of type .txt and their sizes
for my $filename ( glob("*")) {
   if ( -f $filename ) {
      if ( $filename =~ /.+\.([^.]+)$/ ){
         $filetype = '.' . $1;
      } else {
         $filetype = '<no type>';
      }

   $filesize = -s $filename;
  if ($filetype =~ '.txt')
  {
      $txtval = $txtval + 1;
       $txtsize = $txtsize + $filesize;
   }
}
}
#find files of no type and their sizes (no directories)
for my $filename ( glob("*")) {
   if ( -f $filename ) {
      if ( $filename =~ /.+\.([^.]+)$/ ){
         $filetype = '.' . $1;
      } else {
         $filetype = '<no type>';
      }

   $filesize = -s $filename;
  if ($filetype =~ '')
  {
      $naval = $naval + 1;
       $nasize = $nasize + $filesize;
   }
   if (-d $filename)
   {
       $naval = $naval - 1;
        $nasize = $nasize - $filesize;
   }
}
}
#add number of each type to hash table
my %hash = 
(
        '.c' => $cval,
        '.pl' => $plval,
        '.txt' => $txtval,
        '*' => $naval,
);
#add sizes of each type to hash table2
my %hash2 = 
(
        '.c' => $csize,
        '.pl' => $plsize,
        '.txt' => $txtsize,
        '*' => $nasize,
);
#print chart for numbers of each type
print "file extension       count\n";
print "----------------    -------\n";
for my $key(keys %hash) 
{
        my $value = $hash{$key};
        $tval = $tval + $value;
        printf("%-10s %15d\n", $key, $value);
}
#print total
print "--------------------------\n";
#print chart for sizes of each type
printf("%-10s %15d\n", "total", $tval);
print "\nfile extension       total size\n";
print "----------------    -----------\n";
for my $key(keys %hash2) 
{
        my $value = $hash2{$key};
        $tsize = $tsize + $value;
        printf("%-10s %20d\n", $key, $value);
}
#print total size
print "-------------------------------\n";
printf("%-10s %20d\n", "total", $tsize);



