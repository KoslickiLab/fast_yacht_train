# Fast `yacht train`
This implements a fast version of yacht train, as of v1.2.3: 
https://github.com/KoslickiLab/YACHT/releases/tag/v1.2.3

## Why is it important?
Its many times faster, and should consume a whole lot less memory. The main improvement in terms of speed comes from implementing a faster many-vs-many sketch comparator as an alternative of sourmash branchwater multisearch (as of Nov 2024, link: https://github.com/sourmash-bio/sourmash_plugin_branchwater), which is quadratic in nature. Our implementation here takes advantage of the sparsity in data (if any), avoids unnecessary computation, and can run in almost linearly (again, if there is enough sparsity to take advantage of).

## Installation
After downloading, just do:
```
make
```

The bin directory should contain the executable.

## Usage
```
yacht_train -h
```

## Assumptions
1. All input sketches were computed using the same scale factor.
1. The input sketches have only a single sketch inside of them.

## Arguments
| Argument                 | Description                                                                                   |
|--------------------------|-----------------------------------------------------------------------------------------------|
| `file_list`              | A file where each line is a path to a sketch                                                  |
| `working_directory`      | Where similarity values are written                                                           |
| `output_filename`        | Output file, this will contain a subset of the paths given as input in file_list              |
| `threads`                | Number of threads to use                                                                      |
| `passes`                 | Number of passes to make. More passes make the program slower but uses more memory            |
| `containment_threshold`  | Containmnet threshold                                                                         |
