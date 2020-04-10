# sprd
A blazing-fast (possibly) speedreading program

## Usage
`sprd` is super simple to run! Just run:
```sh
$ sprd -f file [-w wpm] [-c chunk_number] [-r resume_point]
```

## Installation
`sprd` is maintained using the GNU autotools. To build, simply download the tarball, unzip it, and follow the ritual:
```sh
./configure
make
sudo make install
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
* Reading from `stdin` or a file

## Planned features
Some features that (if I have time) may be added are:
* built-in file decoders

As a side note, I wrote a `.docx` decoder called [`redocx`](https://github.com/Barthandelous01/redocx) that synergizes well with reading from Word document archives.

## Benchmarks
Though this is anecdotal, I personally can read with 100% comprehension at 1050 WPM using 2-word chunks.

## Contributing
All contributions are welcome! To contribute, fork the repo, make a branch with your new feature, push it to GitHub, and submit a PR. The autotools files are left in the repo, so you can make the build system easily.
