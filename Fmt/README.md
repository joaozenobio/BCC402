# 3.8.8 Fmt

PC/UVa IDs:110308/848, Popularity:C, Success rate:low, Level: 2.

The UNIX programfmtreads lines of text, combining and breaking them so as to create an output file with lines as close to 72 characters long as possible without exceeding this limit. The rules for combining and breaking lines are as follows:

- A new line may be started anywhere there is a space in the input. When a new line is started, blanks at the end of the previous line and at the beginning of the new line are eliminated.
- A line break in the input may be eliminated in the output unless (1) it is at the end of a blank or empty line, or (2) it is followed by a space or another line break. When a line break is eliminated, it is replaced by a space.
- Spaces must be removed from the end of each output line.
- Any input word containing more than 72 characters must appear on an output line by itself. You may assume that the input text does not contain any tabbing characters.

## Example

**Sample Input**

Unix fmt

The unix fmt program reads lines of text, combining
and breaking lines so as to create an
output file with lines as close to without exceeding
72 characters long as possible. The rules for combining and breaking
lines are as follows.

1. A new line may be started anywhere there is a space in the input.
If a new line is started, there will be no trailing blanks at the
end of the previous line or at the beginning of the new line.
2. A line break in the input may be eliminated in the output, provided
it is not followed by a space or another line break. If a line
break is eliminated, it is replaced by a space.

**Sample Output**

Unix fmt

The unix fmt program reads lines of text, combining and breaking lines
so as to create an output file with lines as close to without exceeding
72 characters long as possible. The rules for combining and breaking

