# printable-books
A simple C++ tool to convert a pdf into a printable document. Works great for printing out and binding books.

Tested and works well on Arch Linux. Requires pdftk to automatically generate the printable pdf.


The logic behind the program is it takes the path to a pdf file, 

takes that file and splits it into smaller chunks (referred to as "bundles" in the code), 

and rearranges the pages so that you could simply print out the pages and fold the sheets into small bundles, then combine the bundles into a full book that can be bound together. (I did it with hot glue, tape, and staples.

The program assumes you are printing DOUBLE SIDED with 2 PAGES per PAGE / 4 PAGES PER SHEET.

For the end user, all you have to do is give the path to a file, specify the page count THEN a bundle size (20 page bundlesize works fine in my experience), then take the resulting pdf and print it out as double sided with 4 pages per sheet. (IN CHROME THE OPTION IS CONFUSING, so select double-sided and 2 pages per sheet. Since it's double sided it will actually be 4 pages per sheet. I think Chrome confuses page/sheet ¯\\_(ツ)_/¯)

Then, take each 20-page bundle (should be 5 sheets), fold them into a booklet, and staple it together. Do this with each of the bundles.

Yes, the program does work for ANY pdf, even if the page count isn't even or divisible by bundleSize. Just read the code, shouldn't be too hard. this is obviously a quick summary, and it's a late night and I'm not too intersted in writing this out more clearly for my audience of zero people.

Here is an example final product: (todo get picture of my copy of guenon's Infinitesimal Calculus)

maybe make example video. contact me if ur reading this and actually care about this xdxdxd
