# sprd
A blazing-fast (possibly) speedreading program

## Usage
`sprd` is super simple to run! Just run:
```sh
$ sprd [-f] [-w \d\d\d] [-c \d]
```

## Installation
`sprd` does not have any libraries it depends on. To install, simply clone the repo, and run:
```sh
cd /path/to/cloned/repo/sprd/src
make
make install # this may require root
```

## Inspiration
I was (as a RSVP-using speedreader myself) in search of a command-line based speedreading software. I found [one well-made project](https://github.com/pasky/speedread), but it did not have some features I wanted (namely, chunking and the ability to read from a file). Therefore, I set about to write my own. In keeping with my own philosophy, I wanted to keep it simple and fast. Ideally, this means no libraries or external dependencies, and written in `C`. 

## Benchmarks
Though this is anecdotal, I personally can read with 100% comprehension at 1050 WPM using 2-word chunks. If you have any other benchmarks you'd like to share, `/msg` me at `barthandelous` on freenode IRC.
