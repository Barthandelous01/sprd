# sprd
A blazing-fast (possibly) speedreading program

## Usage
`sprd` is super simple to run! Just run:
```sh
$ sprd -f file [-w wpm] [-c chunk_number] [-r resume_point]
```

## Installation
`sprd` does not have any libraries it depends on; all you need is a `c++11` or later complient compiler. To install, simply clone the repo, and run:
```sh
cd /path/to/cloned/repo/sprd/src
make
make install # this may require root
```

## Inspiration
I was (as a RSVP-using speedreader myself) in search of a command-line based speedreading software. I found [one well-made project](https://github.com/pasky/speedread), but it did not have some features I wanted (namely, chunking and the ability to read from a file). Therefore, I set about to write my own. In keeping with my own philosophy, I wanted to keep it elegant, fast, and minimal. Ideally, this means no libraries or external dependencies, and written in `C/C++`. 

## Features
`sprd` has a good number of features that are common to all speedreaders, and a few that are (relatively) unique. They include:
* variable chunking
* adaptive WPM based on chunking
* static centering of text
* complied, not interpreted
* auto-centering output
* resuming from a point
* dynamically handeled `sigterm`

## Planned features
Some features that (if I have time) may be added are:
* built-in file decoders

As a side note, I wrote a `.docx` decoder called [`redocx`](https://github.com/Barthandelous01/redocx) that synergizes well with reading from Word document archives.

## Benchmarks
Though this is anecdotal, I personally can read with 100% comprehension at 1050 WPM using 2-word chunks.
