# bin2c
Utility to convert any binary file into C source that can be compiled and linked to the executable.

# bin2o
Utility to convert any binary file into *.o which can be directly linked with other object files to final executable. 
It also creates appropriate header with symbols required to access the file from the C sources.

## Requirements

* standard make utility
* gcc 

## Usage

```bash
$ bin2c <file> <identifier>
```

* &lt;file&gt; specifies a binary file to read and convert
* &lt;identifier&gt; specifies identifier which will be used to access the file from the C source code

You can use '-' as name of the file to specify the standard input as input file.  
Result is sent to the standard output.

---

```bash
$ bin2o <file> <identifier> [<output>] [<header>]
```

* &lt;file&gt; specified a binary file to read and convert
* &lt;identifier&gt; specifies identifier which will be used to access the file from the C source code
* &lt;output&gt; optional argument - name of output object file. Default is &lt;file&gt;.o
* &lt;header&gt; optional argument - name of output header file. Default is &lt;file&gt;.h
